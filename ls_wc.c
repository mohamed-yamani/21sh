#include <stdio.h>
#include  <fcntl.h>                              //
#include  <stdio.h>                              //
#include  <stdlib.h>                             //
#include  <string.h>                             //
#include  <sys/types.h>                          //
#include  <sys/wait.h>                           //
#include  <sys/stat.h>                           //
#include  <termios.h>                            //
#include  <unistd.h>
#include "../libft/libft.h"

#define INPUT_END 1                              // INPUT_END means where the pipe takes input
#define OUTPUT_END 0 

void ft_exec(char *line)
{
pid_t pid;
int fd[2];

char **p;

p = ft_strsplit(line, '|');
pipe(fd);

pid = fork();


if(pid==0)
{
    dup2(fd[INPUT_END], STDOUT_FILENO);
    close(fd[OUTPUT_END]);
    close(fd[INPUT_END]);
    ft_putstr("thes is the arg 1"); ft_putendl(p[0]);
    execlp("ls", p[0], "-l",(char*) NULL);
    fprintf(stderr, "Failed to execute '%s'\n", "ls");
    exit(1);
}
else
{ 
    pid=fork();

    if(pid==0)
    {
        dup2(fd[OUTPUT_END], STDIN_FILENO);
        close(fd[INPUT_END]);
        close(fd[OUTPUT_END]);
        ft_putstr("thes is the arg 2"); ft_putendl(p[1]);
        execlp("wc", p[1],(char*) NULL);
        fprintf(stderr, "Failed to execute '%s'\n", "wc");
        exit(1);
    }
    else
    {
        int status;
        close(fd[OUTPUT_END]);
        close(fd[INPUT_END]);
        waitpid(pid, &status, 0);
    }
}
return ;
}

int     main(void)
{
    int len;
    char line[1024];
    while ((len = read(0, line, 1023))>0)
    {
        line[len] = '\0';
        ft_exec(line);
    }
    return (0);
}