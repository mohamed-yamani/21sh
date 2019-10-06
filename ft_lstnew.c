/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myamani <myamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 11:03:50 by myamani           #+#    #+#             */
/*   Updated: 2019/03/28 19:51:44 by myamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_list	*ft_listnew(void *content)
{
	t_list *new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!content)
	{
		new->content = NULL;
		new->content_size = 0;
		return (new);
	}
	new->content = content;
	new->next = NULL;
	return (new);
}
