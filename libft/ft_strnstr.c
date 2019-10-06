/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myamani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 18:24:30 by myamani           #+#    #+#             */
/*   Updated: 2018/10/18 14:43:57 by myamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char		*hstack;
	const char		*ndl;
	size_t			index;

	ndl = needle;
	index = 0;
	if (needle == haystack || !*ndl)
		return ((char *)haystack);
	while (*haystack)
	{
		hstack = haystack;
		while ((*hstack == *ndl || !*ndl))
		{
			if (!*ndl && index + ft_strlen(needle) <= len)
				return ((char *)haystack);
			hstack++;
			ndl++;
		}
		ndl = needle;
		index++;
		haystack++;
	}
	return (0);
}
