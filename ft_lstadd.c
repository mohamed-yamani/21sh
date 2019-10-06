/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myamani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 12:25:43 by myamani           #+#    #+#             */
/*   Updated: 2019/09/26 19:00:07 by myamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void		ft_lstadd1(t_list **alst, t_list *new)
{
	t_list *head;
	head = *alst;
	
	if (head != NULL)
	{
		while (head->next)
			head = head->next;
		head->next = new;
	}
	else
	{
		printf("ptr = %p\n", *alst);
		*alst = new;
	}
}
