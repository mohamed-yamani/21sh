#include "sh.h"

int    replace_environnement(t_params *params, char *key, char *value)
{
    t_list          *environnement;
    t_environnement *env;

    environnement = params->environnement;
    while (environnement)
    {
        env = environnement->content;

        if (!ft_strcmp(env->key, key))
        {
            free(env->value);
            env->value = value;
            return (1);
        }
        environnement = environnement->next;
    }
    return (0);
}

void    add_environnement(char *key, char *value, t_params *params)
{
    t_environnement *environnement;
    t_list *new;
    t_list **env_lst;

    if (replace_environnement(params, key, value))
        return ;
    env_lst = &params->environnement;
    environnement = (t_environnement *)malloc(sizeof(t_environnement));
    //environnement = NULL;
    environnement->key = ft_strdup(key);
    environnement->value = ft_strdup(value);
    new = ft_listnew(environnement);
    ft_lstadd(env_lst, new);
    params->envs++;
    params->environnement = *env_lst;
}

void    find_environnement(char *env, t_params *params)
{
    char **splite;

    splite = ft_strsplit(env, '=');
    add_environnement(splite[0], splite[1], params);
    free2d(splite);
}

void    get_environnement(t_params *params, char **env)
{
    int i;
    params->environnement = NULL;
    i = 0;
    while (env[i])
    {
        find_environnement(env[i], params);
        i++;
    }
}