#include "sh.h"

void        put_tst(t_list *lst)
{
    t_list          *redirections;
    t_redirection   *redirection;
    t_cmds *cmd;

	// printf("ptr = 2 %p\n", lst);
    // ft_putendl("and here put (lst)");

    while (lst)
    {
        //ft_putendl("sous lst ...");
        cmd = lst->content;
        int i = 0;
        ft_putendl("cmd->argv ------------------------------ >>> is");
        while (cmd->argv[i])
        {
            ft_putnbr(cmd->i);
            ft_putendl(cmd->argv[i]);
            i++;
        }
        redirections = cmd->redirections;
        ft_putnbr(i);ft_putendl("and put redirections lhamdo li allah   ");
        if (redirections)
        while (redirections)
        {
            ft_putendl("");
            if (redirections)
            {
                ft_putendl("i am here ---");
                redirection = redirections->content;
                ft_putstr("redirection->type            -->"); ft_putnbr(redirection->type); ft_putendl("");
                //ft_putstr("redirection->file            -->"); ft_putendl(redirection->file);
                ft_putstr("redirection->source_fd       -->"); ft_putnbr(redirection->source_fd);ft_putendl("");
                ft_putstr("redirection->destination_fd  -->"); ft_putnbr(redirection->destination_fd);ft_putendl("");
                ft_putstr("redirection->close           -->");ft_putnbr(redirection->close); ft_putendl("");
            }
            redirections = redirections->next;
        }
//        if ((*lst)->next)
        lst = lst->next;
        //  else
        //      break ;
    }
}

void        put_semicolones(t_list *semi)
{
    t_list **lst;
    
    ft_putendl("star put semicolon");
    while (semi)
    {
        ft_putendl("star put semicolon");
        lst = semi->content;
        put_tst(*lst);
        if (semi->next)
            semi = semi->next;
        else 
            break ;
    }
    ft_putendl("end put semicolon");  
}

void        put_environnement(t_params *params)
{
    t_list *env_lst;
    env_lst = params->environnement;
    t_environnement *environnement;
    while (env_lst)
    {
        environnement = env_lst->content;
        ft_putstr(environnement->key);
        ft_putstr(" -> ");
        ft_putendl(environnement->value);
        env_lst = env_lst->next;
    }
}