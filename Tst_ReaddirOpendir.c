#include <stdio.h>
#include <dirent.h>
#include "sh.h"

int     main(int ac, char *av[])
{
    DIR *dir;
    struct  dirent *sd;

    dir = opendir(".");
    if (!dir)
    {
        ft_putendl("Error ! Unable to open directory .\n");
        return (22);   
    }
    while ( (sd = readdir(dir)) != NULL )
    {   
        ft_putnbr(sd->d_type);
        ft_putstr(" * ");
        ft_putnbr(sd->d_ino);
        ft_putendl(sd->d_name);
    } 
    return (0);
}