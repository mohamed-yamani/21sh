/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myamani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 22:29:23 by myamani           #+#    #+#             */
/*   Updated: 2018/10/20 14:23:01 by myamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_del(void *content, size_t content_size)
{
	if (content)
	{
		free(content);
		content = NULL;
		content_size = 0;
	}
}
