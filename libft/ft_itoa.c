/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myamani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 19:46:44 by myamani           #+#    #+#             */
/*   Updated: 2018/10/19 10:16:06 by myamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	char			*str;
	int				lstr;
	int				index;
	unsigned int	numbrscpy;

	lstr = ft_numbers(n);
	index = 0;
	numbrscpy = n;
	if (n < 0)
		numbrscpy = -n;
	if (!(str = ft_strnew(lstr)))
		return (NULL);
	str[index++] = (numbrscpy % 10) + 48;
	while ((numbrscpy = numbrscpy / 10) != 0)
		str[index++] = (numbrscpy % 10) + 48;
	if (n < 0)
		*(str + lstr - 1) = '-';
	return (ft_strrev(str));
}
