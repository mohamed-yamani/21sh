#include "sh.h"

# define BUF 1

char *ft_read()
{
	char	*buf;
	char	*reads;
	char	**arr_reads;
	int		ret;
	char	*tmp;

	buf = (char *)malloc(sizeof(char) * BUF);
	reads = strdup("");
	while ((ret = read(0, buf, BUF)))
	{
		buf[1] = '\0';
		if (ft_strchr(buf, '\n'))
			break;
		tmp = reads;
		reads = ft_strjoin(reads, buf);
		free(tmp);
	}
	return (reads);
}

char **splie(char *read)
{
	char **splite;

	splite = ft_strsplit(read, ' ');
	return splite;
}

void handler_reads(char *read, t_list **lst)
{
	t_list	*list;
	t_cmd	*cmd;		
	int i = 0;
	int j = 0;
	//int k = 0;
	char *str;

	//str = (char **)malloc(sizeof(char) * 20);
	str = (char *)malloc(sizeof(char) * 265);
	cmd = (t_cmd *)malloc(sizeof(t_cmd)); /// lst
	while (1)
	{
		if (read[i] == '|' || read[i] == '\0')
		{
			cmd->pipe = 0;
			if (read[i] == '|')
				cmd->pipe = 1;
			i++;
			while (read[i] == ' ' || read[i] == '\t')
			{
				i++;
				if (read[i] != ' ' && read[i] != '\t')
					break;
			}
			str[j] = '\0';
			cmd->cmd = ft_strdup(str);
			list = ft_listnew(cmd);
			ft_lstadd1(lst, &list);
			cmd = (t_cmd *)malloc(sizeof(t_cmd)); /// lst
			j = 0;
			if (read[i] == '\0')
				break;
			continue;
		}
		str[j] = read[i];		
		j++;
		i++;
	}
	free(str);
	//return lst;
}

void		execve_child(char **read, char **environment, char *path, int pipe, int *pfd)
{
	//ft_putnbr(pipe);
	// if (pipe)
	// {
	// 	ft_putendl("i am in pipe");
	// 	close(pfd[0]); // close the unused read side
	// 	dup2(pfd[1], 1); // connect the write side with stdout
	// 	//close(pfd[1]);
	// }
	// else
	// {
	// 	ft_putendl("i am not in pipe");
	// 	//close (pfd[1]); // close the unused write side
	// 	dup2(pfd[0], 0); // connect the read side with stdin
	// 	//close(pfd[0]);
	// }
	
	execve(path, read, environment);
	ft_putstr(path);
	ft_putendl(" Permission Denied");
	exit(0);
}

void 	ft_check(t_cmd *cmds)
{
	char *handler;
	int i;
	int j;

	i = 0;
	j = 0;

	handler = (char *)malloc(sizeof(char) * 255);
	while (cmds->cmd[i] && !j)
	{
		handler[i] = cmds->cmd[i];
		if (cmds->cmd[i] == '>') //ls -la 2>& 1
		{
			j = 1;
			ft_putstr("> is");ft_putnbr(i);ft_putendl("");
			break;
		}
		i++;
	}
	handler[i] = '\0';
	free(cmds->cmd);
	cmds->cmd = ft_strdup(handler);
	ft_putendl(handler);
}

void	splite_cmd(t_cmd *cmds)
{
	ft_putstr("--> ");
	ft_putendl(cmds->cmd);
	ft_check(cmds);
	ft_putendl(cmds->cmd);
	cmds->flags = ft_strsplit(cmds->cmd, ' ');
}

int 	fork_pipe(char **env)
{
	char *read;
	t_list *lst;
	t_cmd *cmds;
	char **exec;
	int pfd[2];

	if (pipe(pfd) == -1)
	{
		printf("pipe failed\n");
		return 1;
	}

	lst = NULL;
	exec = (char **)malloc(sizeof(char *) * 20);
	while (1)
	{
		read = ft_read();
		if (!ft_strcmp(read, "exit"))
			break;
		handler_reads(read, &lst);

		int i = 0;
		while (lst)
		{
			cmds = lst->content;
			//ft_putnbr(cmds->pipe);
			exec[i] = ft_strdup(cmds->cmd);			
			splite_cmd(cmds);
			//ft_putendl(cmds->cmd);

			//// fork tst
			int pid;
			if ((pid = fork()) < 0) 
			{
				printf("fork failed\n");
				return 2;
			}
			if (pid == 0)
			{
				execve_child(cmds->flags , env, cmds->flags[0], cmds->pipe, pfd);
			}		
			else
			{
				wait(NULL);
			}
			//execve_child(cmds->flags , env, cmds->flags[0]);
			lst = lst->next;
			i++;
		}
		exec[i] = NULL;
		//break;
	}
	return (0);
}

// int		main(int ac, char **av, char **env)
// {

// 	//execve_child(exec , env, "/bin/ls");
// 	fork_pipe(env);
// 	return 0;
// }




int pipe_tst()
{
	char exec[2][2];
	int pfd[2];
	if (pipe(pfd) == -1)
	{
		printf("pipe failed\n");
		return 1;
	}

	//create the child
	int pid;
	if ((pid = fork()) < 0)
	{
		printf("fork failed\n");
		return 2;
	}

	if (pid == 0)
	{
		// child
	
		close (pfd[1]); // close the unused write side
		dup2(pfd[0], 0); // connect the read side with stdin
		close(pfd[0]);
		//execute the process (wc command)

		execlp(exec[1], exec[1], (char *) 0);
		printf("wc failed");//if execlp returns, it`s an error
		return 3;
	}
	else
	{
		// parent
		close(pfd[0]); // close the unused read side
		dup2(pfd[1], 1); // connect the write side with stdout
		close(pfd[1]); // close the write side
		// execute the process (ls command)
		execlp(exec[0], exec[0], (char *)0);
		printf("ls failed"); // if execlp returns, it`s an error
		return 4;
	}
	return(0);
}
