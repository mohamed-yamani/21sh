/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myamani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 14:33:22 by myamani           #+#    #+#             */
/*   Updated: 2018/10/09 09:19:21 by myamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	const char	*srcs;
	char		*dest;

	srcs = (const char *)src;
	dest = (char *)dst;
	i = 0;
	while (i < n)
	{
		dest[i] = srcs[i];
		i++;
	}
	dst = (void *)dest;
	return (dst);
}
