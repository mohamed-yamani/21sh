/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myamani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 10:53:35 by myamani           #+#    #+#             */
/*   Updated: 2018/10/22 10:58:50 by myamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		count;
	char		*str;

	str = (char *)s;
	count = -1;
	while (++count < n)
		if (str[count] == (char)c)
			return ((void *)s + count);
	return (0);
}
