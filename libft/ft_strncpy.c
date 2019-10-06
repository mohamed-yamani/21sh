/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myamani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 16:37:14 by myamani           #+#    #+#             */
/*   Updated: 2018/10/22 11:09:05 by myamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t		count;

	count = -1;
	while (src[++count] && count < len)
		dst[count] = src[count];
	while (count < len)
	{
		dst[count] = '\0';
		count++;
	}
	return (dst);
}
