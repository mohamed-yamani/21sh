/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myamani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 20:52:34 by myamani           #+#    #+#             */
/*   Updated: 2018/10/21 17:22:57 by myamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	ldest;
	size_t	lsrc;

	i = 0;
	ldest = ft_strlen(dst);
	lsrc = ft_strlen(src);
	if (size == 0)
		return (lsrc);
	if (ldest > size)
		lsrc = lsrc + size;
	else
		lsrc = lsrc + ldest;
	while (src[i] && (ldest + 1) < size)
		dst[ldest++] = src[i++];
	dst[ldest] = '\0';
	return (lsrc);
}
