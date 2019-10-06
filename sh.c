#include "sh.h"

# define BUF 1

char    *ft_read(char *reads)
{
    char    *buf;
    char    *tmp;

    buf = (char *)malloc(sizeof(char) * (BUF + 1));
    reads = ft_strdup("");
    while (read(0, buf, BUF))
    {
        buf[1] = '\0';
        if (ft_strchr(buf, '\n'))
            break;
        tmp = reads;
        reads = ft_strjoin(reads, buf);
        free(tmp);
    }
    return(reads);
}



char    *del_startend_space(char *delete)
{
    int i;
    char *str;

    int len;
    i = 0;
    int j = 0;
    str = (char *)malloc(sizeof(char) * (len = ft_strlen(delete)));
    while (delete[i])
    {
        if (i == 0 && delete[i] == ' ')
            i++;
        str[j] = delete[i];
        if (i == len && delete[i] == ' ')
            break ;
        i++;
        j++;
    }
    str[j] = '\0';
    return (str);
}

int     ft_calcul_cmd(char *cmd)
{
    int i;
    char **tst;

    tst = ft_strsplit(cmd, ' ');
    while (tst[i])
        i++;
    return (i);
}

int     is_number(char *str)
{
    int i;
    i = 0;

    while (str[i])
    {
        if (ft_isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}

int     get_type(char *arg)
{
    int i;
    int type;

    i = 0;
    type = -1;
    while (arg[i])
    {
        if (!ft_isdigit(arg[i]))
        {
            if (arg[i] == '>' && type == -1)
                type = one;
            else if (arg[i] == '>' && type == one)
                type = two;
            else if (arg[i] == '>' && type == two)
            {
                ft_putstr("21sh: parse error near `>");
                if (arg[i + 1] == '>')
                    ft_putchar(arg[i++]);
                ft_putendl("\'");
                return(-1);
            }
            if (arg[i] == '<')
            {
                if (type == -1)
                    type = (O_RDONLY);    ///////////// here 3
                else if (type == (O_RDONLY))      ///////////// here 3
                    type = 4;
                else
                {
                  ft_putendl("21sh: parse error near `<\'");
                  return (0);
                }
            }
        }
        i++;
    }
    //ft_putnbr(type);
    return (type);
}

//$HOME
char    *dollar_value(t_params *params, char *dollar)
{
    t_list *env;
    t_environnement *environnement;
    t_list *head;
    char *value;

    env = params->environnement;
    head = env;
    value = strdup("");
    while (head)
    {
        environnement = head->content;
        if (!ft_strcmp(environnement->key, dollar))
            value = environnement->value;
        head = head->next;
    }
    head  = env;  
    return(value);
}

char    *checking_dollar(char *string, t_params *params)
{
    t_list *env;
    t_environnement *environnement;
    char *dollar;
    int i;
    char **dollars;
    int ds;
    int d;
    char    *str;
    char    *concatenation;
    int     s;

    ds = 0;
    concatenation = (char *)malloc(sizeof(char) * 255);
    dollars = (char **)malloc(sizeof(char *) * 30);
    dollar = (char *)malloc(sizeof(char) * ft_strlen(string));
    str = (char *)malloc(sizeof(char) * ft_strlen(string));
    i = 0;
    s = 0;
    env = params->environnement;
    while (string[i])
    {
        if (string[i] == '$')
        {
            d = 0;
            s = 0;
            i++;
            while (string[i] && string[i] != ':' && string[i] != '/' && string[i] != '$') 
            {
                dollar[d] = string[i];
                i++;
                d++;
            }
            dollar[d] = '\0';
            ft_strcat(concatenation, str);//
            str = ft_strdup("");
            ft_strcat(concatenation, dollar_value(params, dollar));
            continue ;
        }
        str[s] = string[i];
        i++;
        s++;
    }
    ft_strcat(concatenation, str);
    return (concatenation);
}

char    *tabs_to_spaces(char *str) //// d'ont forget '
{
    int i;
    i = 0;

    while (str[i])
    {
        if (str[i] == '"' || str[i] == '\'')
        {
            i++;
            while (str[i] && (str[i] != '"' || str[i] != '\'')) ///// dont forget '
                i++;
        }
        if (str[i] == '\t')
            str[i] = ' ';
        i++;
    }
    return (str);
}

int    get_source_fd(char *src)
{
    char *source;
    int i;
    int sr;

    i = 0;
    source = (char *)malloc(sizeof(char) * ft_strlen(src));
    if (strchr(src, '>'))
        while (src[i] != '>')
        {
            source[i] = src[i];
            i++;
        }
    else if (strchr(src, '<'))                          ////                for '<'
        return (0);
    else
        return (1);
    source[i] = '\0';
    sr = ft_atoi(source);
    free(source);
    if (src[0] == '>')
        return(1);
    return (sr);
}

// char      *stop_heredoc(char *buf)
// {
//     char *eof;
//     int i;

//     eof = (char *)malloc(sizeof(char) * 250);
//     i = 0;
//     while(buf[i] != '\n' && buf[i] != '\0')
//     {
//         eof[i] = buf[i];
//         i++;
//     }
//     eof[i] = '\0';
//     return (eof);
// }

// char    *heredoc_end(char *reads)
// {
//     int i;

//     i = 0;
//     while(reads[i])
//     {
//         if (reads[i + 1] == '\0' && reads[i] == '\n')
//             reads[i] = '\0';
//         i++;
//     }
//     return (reads);
// }

int     get_heredoc(t_redirection *redirection, t_cmds *tcmds)
{
    if (redirection->type == 4)
    {
        char    *buf;
        char    *tmp;
        char    *reads;
        char    *tmp1;
        int     len;
    
        if (redirection->file == NULL)
        {
            ft_putendl("21sh: parse error near `\\n'");
            return (0);
        }
        buf = (char *)malloc(sizeof(char) * 351);
        reads = strdup("");
        ft_putstr("heredoc> ");
        while ((len = read(0, buf, 350)))
        {
            buf[len - 1] = 0;
            if (!ft_strcmp(buf, redirection->file))
                break ;
            tmp = reads;
            reads = ft_strjoin(reads, ft_strjoin(buf, "\n"));
            free(tmp);
            ft_putstr("heredoc> ");
            ft_bzero(buf, 350);
        }
        tcmds->heredoc = reads; 
        free(redirection->file);
        redirection->file = NULL;
    }
    return (1);
}

int    ft_getargs(char **pipes, t_list **lst, t_params *params)
{
    int i;
    t_list *list;
    t_cmds *tcmds;
    char **args;
    t_redirection   *redirection;
    t_list          *redirections;
    t_list          *list_redi;
    int             red;


    i = 0;
    int redi = -5;
    int j;
    int k;

    red = 0;
    char **argv;
    int a;
    a = 0;
    // else
    redirections = NULL;
    while (pipes[i])
    {
        //(*lst) = NULL;
        pipes[i] = tabs_to_spaces(pipes[i]);
        args = quotes_splite(pipes[i], ' ');
        
        j = 0;
        k = -4;
        argv = (char **)malloc(sizeof(char *) * 10);
        tcmds = (t_cmds *)malloc(sizeof(t_cmds));
        tcmds->heredoc = NULL;
        while(args[j])
        {
            //ft_putendl(args[j]);
            if (ft_strchr(args[j], '>') || ft_strchr(args[j], '<'))
            {
                redirection = (t_redirection *)malloc(sizeof(t_redirection));
                redirection->source_fd = get_source_fd(args[j]);
                if (ft_strchr(args[j], '&') && ft_strchr(args[j], '-'))
                    redirection->close = 1;
                else if (ft_strchr(args[j], '&') && !is_number(args[j + 1]))
                    redirection->destination_fd = ft_atoi(args[j + 1]);       
                else if (args[j] && args[j + 1])
                    redirection->file = checking_dollar((args[j + 1]) ? args[j + 1] : NULL, params);
                redirection->type = get_type(args[j]); ///////


                printf("in here heredoc : %s\n", args[j]);
                if (get_heredoc(redirection, tcmds) == 0)
                    return (0);
                j++;
                k = j;
                list_redi = ft_listnew(redirection);
                ft_lstadd1(&redirections, list_redi);
                red++;
            }
            if (j != k)
            {
                if (ft_strchr(args[j], '$'))
                    args[j] = checking_dollar(args[j], params);
                //ft_putendl(args[j]);
                //printf("%d - arg = %s\n",a, args[j]);
                argv[a] = args[j];
                a++;
            }
            j++;
        }
        //                                           ft_putendl("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< 2");
        printf("a = %d\n", a);
        argv[a] = NULL;
        tcmds->argv = argv;
        tcmds->i = i;
        tcmds->redirections = redirections;
        a = 0;
        list = ft_listnew(tcmds);
        
        //                                ft_putendl(" *** *** *** *** in ft_getargs function  *** *** *** *** segmentation fault 1 ");  //// here  segmentation fault
        //  printf("1ptr = %p\n", list);        
        ft_lstadd1(lst, list);
        //                              ft_putendl(" *** *** *** *** in ft_getargs function  *** *** *** *** segmentation fault 2 ");
        //  printf("2ptr = %p\n", lst);
    
        tcmds = (*lst)->content;

        // printf("arg0 = %s\n", tcmds->argv[0]);
        // printf("arg1 = %s\n", tcmds->argv[1]);
        // printf("2ptr = %p\n", lst);
        i++;
    }
    return (1);
}

int        ft_separation(t_list **lst, char *read, t_params *params)  
{
    char **pipes;

    t_cmds *cmd;
    pipes = quotes_splite(read, '|');

    int i = 0;
    if (ft_getargs(pipes, lst, params) == 0)
        return (0);
    return (1);
}

int        handler_reads(char *read, t_list **lst , t_params *params)
{
    

    if ((read = ft_add_space(read)))
    {
        if (ft_separation(lst, read, params) == 0)
            return (0);
    }
    return (1);
}

int        splite_semi(char *read, t_list **lst, t_params *params)
{
    int i;
    i = 0;
    char **semicolone = NULL;
    t_list *semicolones = NULL;

    //semicolone = (char **)malloc(sizeof(char *) * 10);
    params->semicolones = NULL;
    semicolone = quotes_splite(read, ';');
    while (semicolone[i])
    {
        if (handler_reads(semicolone[i], lst, params) == 0)
            return (0);
        
        params->lst = *lst;
        manage_sh1(params);
        // semicolones = ft_listnew(lst);
        // ft_lstadd1(&params->semicolones, semicolones);////ft_lstadd_2 
        i++;
    }
    return (1);          
}

void    sh(t_params *params)
{
    char *read;
    t_list *lst;
    t_cmds *cmd = NULL;
   
    lst = NULL;
    params->semicolones = NULL;
    while ("21sh")
    {
        ft_putstr("$> ");
        read = ft_read(read);
        if (splite_semi(read, &lst, params) == 0)
            continue ;
        free(lst);
        lst = NULL;
        //manage_sh(params);
    }
}

int		main(int ac, char **av, char **env)
{
    t_params *params;
    params = (t_params*)malloc(sizeof(t_params));

    params->envs = 0;

    get_environnement(params, env);
    sh(params);
    //ls | cat > file; ls
	//execve_child(exec , env, "/bin/ls");
	return 0;
}
