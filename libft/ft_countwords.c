/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myamani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 10:18:23 by myamani           #+#    #+#             */
/*   Updated: 2018/10/17 10:18:28 by myamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_countwords(char const *pstr, char c)
{
	int		numwords;
	int		len;

	len = 0;
	numwords = 0;
	if (pstr == NULL)
		return (0);
	while (*pstr)
	{
		if (*pstr == c)
			len = 0;
		else if (++len == 1)
			numwords++;
		pstr++;
	}
	return (numwords);
}
