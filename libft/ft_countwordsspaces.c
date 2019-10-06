/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwordsspaces.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myamani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 14:37:26 by myamani           #+#    #+#             */
/*   Updated: 2018/10/20 14:37:32 by myamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_countwordsspaces(const char *str)
{
	int		nbrofwords;
	int		len;

	len = 0;
	nbrofwords = 0;
	if (str == NULL)
		return (0);
	while (*str)
	{
		if (*str == ' ' || *str == '\n' || *str == '\t')
			len = 0;
		else if (++len == 1)
			nbrofwords++;
		str++;
	}
	return (nbrofwords);
}
