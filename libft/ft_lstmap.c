/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myamani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 17:04:12 by myamani           #+#    #+#             */
/*   Updated: 2018/10/21 21:54:21 by myamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*list;
	t_list		*head_list;

	if (!(list = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	list = f(lst);
	head_list = list;
	if (lst)
	{
		while (lst->next)
		{
			list->next = f(lst->next);
			list = list->next;
			lst = lst->next;
		}
	}
	return (head_list);
}
