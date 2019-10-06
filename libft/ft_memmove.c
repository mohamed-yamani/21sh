/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myamani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 20:49:25 by myamani           #+#    #+#             */
/*   Updated: 2018/10/19 11:17:31 by myamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		tmp[65535];
	const char	*strsrc;
	char		*strdst;

	strsrc = (const char*)src;
	strdst = (char*)dst;
	if (len > 65535)
		return (0);
	ft_memcpy(tmp, strsrc, len);
	ft_memcpy(strdst, tmp, len);
	return (dst);
}
