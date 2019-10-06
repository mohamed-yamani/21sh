/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myamani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 10:24:53 by myamani           #+#    #+#             */
/*   Updated: 2018/10/21 17:37:02 by myamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if (alst)
	{
		while (*alst)
		{
			del((*alst), (*alst)->content_size);
			*alst = (*alst)->next;
		}
		free(*alst);
		*alst = NULL;
	}
}
