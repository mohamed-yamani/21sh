/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myamani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 10:49:00 by myamani           #+#    #+#             */
/*   Updated: 2018/10/21 20:22:57 by myamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		index;

	index = -1;
	while (s1[++index] || s2[index])
		if (index < n && s1[index] != s2[index])
			return ((unsigned char)s1[index] - (unsigned char)s2[index]);
	return (0);
}
