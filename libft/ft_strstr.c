/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myamani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 13:50:17 by myamani           #+#    #+#             */
/*   Updated: 2018/10/10 12:20:25 by myamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *haystack, const char *needle)
{
	const char		*hay;
	const char		*need;

	need = needle;
	if (*need == '\0')
		return ((char *)haystack);
	while (*haystack != '\0')
	{
		if (*haystack == *need)
		{
			hay = haystack;
			while ((*hay == *need || *need == '\0'))
			{
				if (*need == '\0')
					return ((char *)haystack);
				hay++;
				need++;
			}
			need = needle;
		}
		haystack++;
	}
	return (0);
}
