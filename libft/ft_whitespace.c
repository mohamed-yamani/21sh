/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_whitespace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myamani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 10:26:31 by myamani           #+#    #+#             */
/*   Updated: 2018/10/20 14:03:39 by myamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_whitespace(char const *s)
{
	char	**str;
	int		star;
	int		word;
	int		index;

	star = 0;
	index = 0;
	word = 0;
	if (!s)
		return (NULL);
	if (!(str = (char**)malloc(sizeof(char*) * ft_countwordsspaces(s) + 1)))
		return (NULL);
	while (s[index])
	{
		while (s[index] == ' ' || s[index] == '\t' || s[index] == '\n')
			index++;
		star = index;
		while (s[index] &&
				(s[index] != ' ' && s[index] != '\t' && s[index] != '\n'))
			index++;
		if (index > star)
			str[word++] = ft_strsub(s, star, (index - star));
	}
	str[word] = NULL;
	return (str);
}
