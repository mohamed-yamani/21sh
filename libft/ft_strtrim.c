/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myamani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 20:18:59 by myamani           #+#    #+#             */
/*   Updated: 2018/10/21 21:46:45 by myamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strtrim(char const *s)
{
	char		*str;
	size_t		start;
	size_t		fin;

	if (!s)
		return (0);
	fin = ft_strlen(s) - 1;
	start = 0;
	while (s[start] == ' ' || s[start] == '\t' || s[start] == '\n')
		start++;
	while (s[fin] == ' ' || s[fin] == '\t' || s[fin] == '\n')
		fin--;
	if (start == ft_strlen(s))
		return (ft_strsub(s, 0, 0));
	str = ft_strsub(s, start, (fin - start + 1));
	return (str);
}
