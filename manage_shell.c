#include "sh.h"

void    change_directory(t_cmds *cmds, t_params *params)
{

}

void    ft_env(t_params *params)
{
	t_list          *environnement;
	t_environnement *env;


	ft_putendl("ft_env here 1");
	environnement = params->environnement;
	while (environnement)
	{
		env = environnement->content;
		ft_putstr(env->key);
		ft_putstr("=");
		ft_putendl(env->value);
		environnement = environnement->next;
	}
}

void    ft_setenv(char **cmds, t_params *params)
{
	if (cmds[3])
	{
		ft_putendl("setenv: Too many arguments.");
		free2d(cmds);
		return ;
	}
	add_environnement(cmds[1], cmds[2],  params); 
}

void    ft_unsetenv(char **cmds, t_params *params)
{
	t_list          *environnement;
	t_list          *tmp;
	t_environnement *env;
	t_environnement *next_env;

	ft_putendl("ft_unsetenv here 1");
	environnement = params->environnement;
	env = environnement->content;

	if (!ft_strcmp(env->key, cmds[1]))
	{
		environnement = environnement->next;
		params->environnement = environnement;
		return;
	}
	while (environnement)
	{
		env = environnement->content;
		if (environnement->next)
			next_env = environnement->next->content;
		if (!ft_strcmp(next_env->key, cmds[1]))
		{
			tmp = environnement->next;
			environnement->next = environnement->next->next;
			free(tmp);
		}
		environnement = environnement->next;
	}
}

void    ft_echo(char **arr)
{ 
	int i;

	i = 1;
	while (arr[i])
	{
		ft_putstr(arr[i]);
		if (arr[i + 1])
			ft_putchar(' ');
		i++;
	}
	ft_putendl("");
}

int     manage_shell(t_cmds  *cmds, t_params *params)
{
	int value;

	value = 0;
	//ft_putstr("manage sh here ---> ");
	// ft_putstr(cmds->argv[0]);ft_putendl("...");
	// ft_putendl(cmds->argv[0]);
	if (!ft_strcmp(cmds->argv[0], "exit") && (value = 1))
		ft_exit(cmds, params);
	else if (!ft_strcmp(cmds->argv[0], "cd") && value++)
		change_directory(cmds, params);
	else if (!ft_strcmp(cmds->argv[0], "setenv") && ++value)
		!cmds->argv[1] ? ft_env(params) : ft_setenv(cmds->argv, params);
	else if (!ft_strcmp(cmds->argv[0], "unsetenv") && cmds->argv[1])
		ft_unsetenv(cmds->argv, params);
	else if (!ft_strcmp(cmds->argv[0], "env") && (value = 1))
		ft_env(params);
	else if (!ft_strcmp(cmds->argv[0], "echo") && (value = 1))
		ft_echo(cmds->argv);
	return(value);
}

char    *remove_quotes(char *string)
{
	int backslash;
	int i;
	int j;
	char *tmp;

	backslash = 0;
	i = 0;
	j = 0;
	tmp = (char *)malloc(sizeof(char) * (ft_strlen(string) + 1));
	while (string[i])
	{
		if (string[i] == '"' && string[i - 1] != '\\')
		{
			i++;
			while(string[i] && (string[i] != '"' || string[i - 1] == '\\'))
			{
				if (string[i] == '\\' && (string[i + 1] == '\'' || string[i + 1] == '"'))
					i++;

				if (string[i] == '\\')
				{
					if (backslash == 1)
					{ 
						i++;
						backslash = 0;
					}
					else
						backslash = 1;
				}
				tmp[j] = string[i];
				j++;
				i++;
			}
			i++;
		}
		if (string[i] == '\'' && string[i - 1] != '\\')
		{
			i++;
			while(string[i] && (string[i] != '\'' || string[i - 1] == '\\'))
			{
				if (string[i] == '\\' && (string[i + 1] == '\'' || string[i + 1] == '"'))
					i++;

				if (string[i] == '\\')
				{
					if (backslash == 1)
					{ 
						i++;
						backslash = 0;
					}
					else
						backslash = 1;
				}
				tmp[j] = string[i];
				j++;
				i++;
			}
			i++;
		}
		if (string[i] == '\\')
		{
			if (backslash == 0)
			{ 
				i++;
				backslash = 1;
			}
			else
			{
				backslash = 0;
				i++;
			}
		}
		if ((string[i] != '"' && string[i] != '\'') || (string[i - 1] == '\\'))
		{
			tmp[j] = string[i];
			j++;
			i++;
		}
	}
	tmp[j] = '\0';
	free(string);
	//ft_putendl("\nremove_quotes end");
	return (tmp);
}

char		*get_path(t_environnement *args, char *rd)
{
	char **paths;
	int  i = 0;
	char *path;

	if (args->key && !ft_strcmp(args->key, "PATH"))
	{
		paths = ft_strsplit(args->value, ':');
		while (paths[i])
		{
			path = ft_strjoin(paths[i], rd);
			if (!access(path, F_OK))
			{
				//free(rd);
				rd = NULL;
				//free2d(paths);
				return (path);
			}
			//free(path);
			path = NULL;
			i++;
		}
		//free2d(paths);
		//paths = NULL;
		path = NULL;
	}
	return (NULL);
}

char    *get_cmd(char *argv, t_params *params)
{
	t_list          *environnements;
	char            *path;
	int             i;
	char            *ret;
	t_environnement *environnement;

	path = NULL;
	if (argv[0] != '\0')
		path = ft_strjoin("/", argv);
	environnements = params->environnement;
	while (environnements)
	{
		environnement = environnements->content;
		if ((ret = get_path(environnement, path)))
		{
			// ft_putstr(" ----------- >> ");
			// ft_putendl(ret);
			return (ret);
		}
		if (!access(argv, F_OK) && ft_strchr(argv, '/'))
		{
			free(path);
			path = NULL;
			return (ft_strdup(argv));
		}
		//ft_putendl(environnement->key);
		environnements = environnements->next;
	}
	return (NULL);
}

char    **get_tab_environnement(t_params *params)
{
	t_environnement *env;
	t_list *environnements;
	char **tab;
	char *tmp;
	int  i;

	i = 0;
	tab = (char **)malloc(sizeof(char *) * (params->envs + 1));
	environnements = params->environnement;
	while (environnements)
	{
		env = environnements->content;
		tmp = ft_strjoin(env->key, "=");
		tab[i] = ft_strjoin(tmp, env->value);
		free(tmp);
		// ft_putstr("get tab environnement here");
		// ft_putendl(env->key);
		environnements = environnements->next;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

void		execve_child(char **read, char **environment, char *path)
{
	printf("env %p, read: %p\n", environment, read);
	execve(path, read, environment);
	perror("exec");
	ft_putstr(path);
	ft_putendl(" Permission Denied");
	exit(0);
}

t_cmds    *remove_quotes_2d(t_cmds *cmds)
{
	int     i;
	char    *tmp;

	i = 0;
	while (cmds->argv[i])
	{
		cmds->argv[i] = remove_quotes(cmds->argv[i]);
		i++;
	}
	return (cmds);
}

int 	manage_sh1(t_params *params)
{
	t_list *lst;

	lst = params->lst;
	t_cmds *tcmds;
	t_cmds  *cmds;
	//t_list	**head;
	int     prev;
	int     next;
	int     pipefd[2];

	//ft_putendl("\n\n\n");
	//put_tst(params->lst);
	//return (1);
	//ft_putendl("\n\n\n");

	int     std[3] = {dup(0), dup(1), dup(2)};
	prev = 0;
	next = 0;

	while (lst)
	{
		char    **args;
		int     fd;
		t_list *redirections = NULL;
		t_redirection *redirection = NULL;
		int err = 0;
		cmds = remove_quotes_2d(lst->content);
		args = cmds->argv;
		redirections = cmds->redirections;
		if (prev != 0)
		{
			dup2(pipefd[0], 0);
			close(pipefd[0]);
		}
		//ft_putendl("je suis ici et merci !  manage_sh5");
		if ((lst)->next || cmds->heredoc)
		{
		//ft_putendl("je suis ici et merci !  manage_sh 5.1");
			pipe(pipefd);
		//			ft_putendl("je suis ici et merci !  manage_sh 5.11");
			dup2(pipefd[1], 1); ////
			close(pipefd[1]);
		}
		else
		{
			dup2(std[1], 1);
			dup2(std[2], 2);
		}
		while (redirections)
		{
			redirection = redirections->content;
			//int mode = redirection->type == 1 ? O_WRONLY | O_TRUNC | O_CREAT : O_WRONLY | O_APPEND | O_CREAT;
			if (redirection->type == 4)
			{
				redirections = redirections->next;
				continue ;
			}
			ft_putstr("redirections\n");
			if (redirection->file)
			{
				if ((fd = open(redirection->file, redirection->type , 0644)) > 0) 
				{
					dup2(fd, redirection->source_fd);
					close(fd);
				}
				else if (redirection->type == (O_RDONLY))
				{
					ft_putstr("21sh: ");
					ft_putstr(redirection->file);
					ft_putendl(": No such file or directory");
					//return (0) ;
					err = 1;
					//continue ;
				}
				else if (redirection->type == one || redirection->type == two) // tst ls > /Applications/fdfgls
				{
					ft_putstr("sh: ");
					ft_putstr(redirection->file);
					ft_putendl(": Permission denied");
					//return(0);
					err = 1;
					//continue;
				}
			}
			else if (!redirection->close)
			{
				dup2(redirection->destination_fd, redirection->source_fd);
			}
			else if (redirection->close)
			{
				close(redirection->source_fd);
			}
			redirections = redirections->next;
		}
		//ft_putendl("je suis ici et merci !  manage_sh7");
		int is_heredoc = 0;
		if (cmds->heredoc)
		{
		//				ft_putendl("je suis ici et merci !  manage_sh7.1");
			ft_putstr(cmds->heredoc);
			free(cmds->heredoc);
			cmds->heredoc = NULL;
			prev++;
			continue ;
		}
		//ft_putendl("je suis ici et merci !  manage_sh8");
		if (err)
		{
			err = 0;
			(lst) = (lst)->next;
			continue ;
		}
		if(!manage_shell(cmds, params))
		{
			char *path;
			if ((path = get_cmd(cmds->argv[0], params)))
			{
				params->environnement_tab = get_tab_environnement(params);
				int pid;

				if (!(pid = fork()))
					execve_child(cmds->argv, params->environnement_tab, path);
				else 
				{
					g_child = 1;
					waitpid(pid, 0, 0);
					g_child = 0;
				}
			}
			else
			{
				ft_putstr(cmds->argv[0]);
				ft_putendl(": command not found");
			}

		}
		(lst) = (lst)->next;
		prev++;

		if (cmds->heredoc)
		{
			// dup2(std[0], 0);
			// close(std[0]);
		}
	}
	dup2(std[1], 1);
	close(std[1]);
	dup2(std[0], 0);
	close(std[0]);
	dup2(std[2], 2);
	close(std[2]);
	//printf("ptr = 1 %p\n", lst);
	
	//put_tst(params->lst);
	return (0);
}


























int     manage_sh(t_params *params)
{
	exit(1);
	t_list  *semicolones;
	t_list  **lst;
	t_cmds  *cmds;
	//t_list	**head;
	int     prev;
	int     next;
	int     pipefd[2];

//exit(1);
					ft_putendl(" i am here in ex3 1");
					semicolones = params->semicolones;
					lst = (semicolones->content);
                    t_cmds *tcmds;
                    t_list *head;
                    head = (*lst);
                    while (head)
                    {
                        tcmds = (head)->content;
                        printf("ex3 arg0 = %s\n", tcmds->argv[0]);
                        printf("ex3 arg1 = %s\n", tcmds->argv[1]);
                        (head) = (head)->next;
                    }
					ft_putendl(" i am here in ex3 2");
//exit(1);




//semicolones = NULL;
//if (params->semicolones != NULL)
	semicolones = params->semicolones;
	//semicolones = semicolones->next;
	// put_semicolones(params->semicolones);
	// return 0;

	ft_putendl("je suis ici et merci !  manage_sh");
	

	int pipeon = 0;

	while (semicolones)
	{
		int     std[3] = {dup(0), dup(1), dup(2)};
		prev = 0;
		next = 0;
		lst = semicolones->content;

		ft_putendl("je suis ici et merci !  manage_sh2 semicolones");
		//head = semicolones->content;

		t_cmds *tcmds;
        t_list *head1;
        head1 = (*lst);

		while (head1)
		{
			char    **args;
			int     fd;
			t_list *redirections = NULL;
			t_redirection *redirection = NULL;
			int err = 0;
			ft_putendl("je suis ici et merci !  manage_sh3");
			//if (cmds->heredoc)
			cmds = (head1)->content;//remove_quotes_2d*head1->content);
			//ft_putendl(cmds->argv[0]);
			args = cmds->argv;
			ft_putendl("je suis ici et merci !  manage_sh4");
			redirections = cmds->redirections;
			if (prev != 0)
			{
				dup2(pipefd[0], 0);
				close(pipefd[0]);
			}
			ft_putendl("je suis ici et merci !  manage_sh5");
			if ((head1)->next || cmds->heredoc)
			{
			ft_putendl("je suis ici et merci !  manage_sh 5.1");
				pipe(pipefd);
				dup2(pipefd[1], 1);
				close(pipefd[1]);
			}
			else
			{
				ft_putendl("je suis ici et merci !  manage_sh 5.2");
				dup2(std[1], 1);
				dup2(std[2], 2);
			}
			ft_putendl("je suis ici et merci !  manage_sh6");

			while (redirections)
			{
				redirection = redirections->content;
				//int mode = redirection->type == 1 ? O_WRONLY | O_TRUNC | O_CREAT : O_WRONLY | O_APPEND | O_CREAT;
				if (redirection->type == 4)
				{
					redirections = redirections->next;
					continue ;
				}
				ft_putstr("redirections\n");
				if (redirection->file)
				{
					if ((fd = open(redirection->file, redirection->type , 0644)) > 0) 
					{
						dup2(fd, redirection->source_fd);
						close(fd);
					}
					else if (redirection->type == (O_RDONLY))
					{
						ft_putstr("21sh: ");
						ft_putstr(redirection->file);
						ft_putendl(": No such file or directory");
						//return (0) ;
						err = 1;
						//continue ;
					}
					else if (redirection->type == one || redirection->type == two) // tst ls > /Applications/fdfgls
					{
						ft_putstr("sh: ");
						ft_putstr(redirection->file);
						ft_putendl(": Permission denied");
						//return(0);
						err = 1;
						//continue;
					}
				}
				else if (!redirection->close)
				{
					dup2(redirection->destination_fd, redirection->source_fd);
				}
				else if (redirection->close)
				{
					close(redirection->source_fd);
				}
				redirections = redirections->next;
			}
			ft_putendl("je suis ici et merci !  manage_sh7");
			int is_heredoc = 0;
			if (cmds->heredoc)
			{
				ft_putstr(cmds->heredoc);
				free(cmds->heredoc);
				cmds->heredoc = NULL;
				prev++;
				continue ;
			}

			if (err)
			{
				err = 0;
				(head1) = (head1)->next;
				continue ;
			}

			if(!manage_shell(cmds, params))
			{
				char *path;
				if ((path = get_cmd(cmds->argv[0], params)))
				{
					params->environnement_tab = get_tab_environnement(params);
					int pid;

					if (!(pid = fork()))
						execve_child(cmds->argv, params->environnement_tab, path);
					else 
					{
						g_child = 1;
						waitpid(pid, 0, 0);
						g_child = 0;
					}
				}
				else
				{
					ft_putstr(cmds->argv[0]);
					ft_putendl(": command not found");
				}

			}
			(head1) = (head1)->next;
			prev++;

			if (cmds->heredoc)
			{
				// dup2(std[0], 0);
				// close(std[0]);
			}
		}
		dup2(std[1], 1);
		close(std[1]);
		dup2(std[0], 0);
		close(std[0]);
		dup2(std[2], 2);
		close(std[2]);
		semicolones = semicolones->next;
	}
	///ft_putendl("yassine\n");
	//put_semicolones(params->semicolones); 
	return(0);
}
