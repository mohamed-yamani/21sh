/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myamani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 14:51:15 by myamani           #+#    #+#             */
/*   Updated: 2019/10/05 15:51:55 by myamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		start;
	int		index;
	int		words;

	start = 0;
	index = 0;
	words = 0;
	if (!s)
		return (NULL);
	if (!(str = (char **)malloc(sizeof(char *) * (ft_countwords(s, c) + 1))))
		return (NULL);
	while (s[index])
	{
		while (s[index] == c)
			index++;
		start = index;
		while (s[index] != c && s[index])
			index++;
		if (index > start)
			str[words++] = ft_strsub(s, start, (index - start));
	}
	str[words] = NULL;
	return (str);
}
