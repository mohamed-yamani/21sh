/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myamani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 18:38:05 by myamani           #+#    #+#             */
/*   Updated: 2018/10/22 11:15:55 by myamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcat(char *s1, const char *s2)
{
	int		len_s1;
	int		len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = -1;
	while (s2[++len_s2])
		s1[len_s1 + len_s2] = s2[len_s2];
	s1[len_s1 + len_s2] = '\0';
	return (s1);
}
