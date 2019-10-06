#include "sh.h"

int             ft_isalnum1(char *read, int i)
{
    int r = 1;
    while (read[i] == ' ')
    {
        i++;
        r++;
    }
    while (read[i] >= '0' && read[i] <= '9')
        i++;
    if (read[i] == ' ' || read[i] == '\0')
    {
        i++;
        return (r);
    }
    else
        return (0);
}

char    *ft_add_space(char *reads)
{
    int i;
    int j;
    int k;
    char *tmp;
    char *tmp1;

    i = 0;
    j = 0;
    k = 0;
    //ft_putendl(" a file is here ft_add_space ");
    tmp = (char *)malloc(sizeof(char) * 255);
//    tmp1 = (char *)malloc(sizeof(char) * 255);

    while (reads[i])
    {
        if (reads[i] == '"')
        {
            tmp[j] = reads[i];
            i++;
            j++;
            while(reads[i] != '"')
            {
                tmp[j] = reads[i];
                i++;
                j++;
            }
            tmp[j] = reads[i];
            i++;
            j++;
        }
        if (reads[i] == '\'')
        {
            tmp[j] = reads[i];
            i++;
            j++;
            while(reads[i] != '\'')
            {
                tmp[j] = reads[i];
                i++;
                j++;
            }
            tmp[j] = reads[i];
            i++;
            j++;
        }

        if (ft_isdigit(reads[i]) && reads[i - 1] == ' ')
        {
            k = i;
            int x = 0;
            tmp1 = (char *)malloc(sizeof(char) * 255);
            while(reads[i])
            {
                tmp1[x] = reads[i];

                if (reads[i] == '>')
                {
                    // ft_putendl(" tmp1 is ... ");
                    // ft_putendl(tmp1);
                    i++;
                    j = j+x+1;
                    tmp1[x + 1] = '\0';
                    x = 0;
                    tmp = ft_strjoin(tmp, tmp1);
                    break;
                }
                if (!ft_isdigit(reads[i]) || !reads[i + 1] /*|| reads[i] != '>'*/)
                {
                    i = k;
                    x = 0;
                    free(tmp1);
                    break;
                }
                x++;
                i++;
            }
        }




        if (ft_isdigit(reads[i]) && reads[i - 1] == ' ')
        {
            k = i;
            int x = 0;
            tmp1 = (char *)malloc(sizeof(char) * 255);
            while(reads[i])
            {
                tmp1[x] = reads[i];

                if (reads[i] == '<')
                {
                    // ft_putendl(" tmp1 is ... ");
                    // ft_putendl(tmp1);
                    i++;
                    j = j + x + 1;
                    tmp1[x + 1] = '\0';
                    x = 0;
                    tmp = ft_strjoin(tmp, tmp1);
                    break;
                }
                if (!ft_isdigit(reads[i]) || !reads[i + 1] /*|| reads[i] != '>'*/)
                {
                    i = k;
                    x = 0;
                    free(tmp1);
                    break;
                }
                x++;
                i++;
            }
        }







        if (i > 0 && ((reads[i - 1] == '|' && reads[i] != ' ') || (reads[i - 1] == '>' && reads[i] != ' ' && reads[i] != '>' && reads[i] != '&') || (reads[i - 1] == '<' && reads[i] != ' ' && reads[i] != '<' && reads[i] != '&') || (reads[i - 1] == '&' && (reads[i] != '>' && reads[i] != '<') && reads[i] != '-')) /*&& !q && !dq && reads[i] != '"' && reads[i] != '\''*/)
            tmp[j++] = ' ';
        tmp[j] = reads[i];
        if (reads[i + 1] && ((reads[i + 1] == '|' && reads[i] != ' ') || (reads[i + 1] == '>' && reads[i] != ' ' && reads[i] != '>' && reads[i] != '&') || (reads[i + 1] == '<' && reads[i] != ' ' && reads[i] != '<' && reads[i] != '&') || (reads[i + 1] == '&' && (reads[i] != '>' && reads[i] != '<') && reads[i] != '-')) /*&& !q && !dq && !ft_isdigit(reads[i])*/)
            tmp[++j] = ' ';
        //int r = ft_isalnum1(reads, i + 1);
        if (reads[i] == '&' && !ft_isalnum1(reads, i + 1) && reads[i + 1] != '-' && (reads[i - 1] == '>' || reads[i - 1] == '<' ))                //tst here !
        {
            printf("ft_add_space tmp 1 is %s \n", tmp);
            ft_putendl("error >&file");
            free(reads);
            return (NULL) ;
        }
        // if (r > 1)
        // {
        //     i = i + 1 - r;
        //     r = 0;
        // }

        printf("i >>> is %d ---", i);
        i++;
        j++;
    }
    tmp[j] = '\0';
    printf("ft_add_space tmp is %s \n", tmp);
    free(reads);
    // if (q)
    //     ft_putendl("Unmatched '.");
    // else if (dq)
    //     ft_putendl("Unmatched \".");
    return (tmp);
}