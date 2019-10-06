/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myamani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 14:26:10 by myamani           #+#    #+#             */
/*   Updated: 2018/10/21 21:00:27 by myamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t		index;

	index = -1;
	if (s1 && s2)
	{
		while (++index < n && (s1[index] || s2[index]))
			if (s1[index] != s2[index])
				return (0);
	}
	return (1);
}
