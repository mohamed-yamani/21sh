/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myamani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 15:38:16 by myamani           #+#    #+#             */
/*   Updated: 2018/10/17 20:32:30 by myamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*strsrc;
	char				*strdest;

	strdest = (char *)dst;
	strsrc = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		strdest[i] = strsrc[i];
		if (*(strsrc + i) == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (0);
}
