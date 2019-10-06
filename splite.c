#include "sh.h"

char        **split(char *read)
{
    char **split;
    int i;

    i = 0;
    split = ft_strsplit(read, '|');

    while (split[i])
    {
        ft_strsplit(split[i], '|');
        ft_putendl(split[i]);
        i++;
    }
    return (split);
}

char        **splite_semicolon(char *read)
{
    char **semicolon;
    semicolon = ft_strsplit(read, '|');
    return (semicolon);
}