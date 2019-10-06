#include "sh.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void        ft_file(char *file, char *txt)
{
    //int sz; 
    int fd;

    fd = open(file, O_WRONLY | O_CREAT , 0644);
    if (fd < 0) 
    { 
        perror("Error! opening file"); 
        return ; 
    }
    ft_putendl_fd(txt, fd);
    //ft_putendl_fd("thes is my file i work in here1", fd);
    close(fd);
}

int         main()
{

    char *file;
    char *txt;

    file = (char *)malloc(sizeof(char) * 10);
    txt = (char *)malloc(sizeof(char) * 20);

    file = "myfile";
    txt = "thes is my file i work in here";
    ft_file(file, txt);

    //write(fd, "hello geeks\n", strlen("hello geeks\n")); 
 
    return (0);
}
