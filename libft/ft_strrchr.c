/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myamani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 11:25:17 by myamani           #+#    #+#             */
/*   Updated: 2018/10/21 18:59:32 by myamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	int		len_s;

	len_s = ft_strlen(s) + 1;
	while (--len_s >= 0 || c == 0)
		if (s[len_s] == c)
			return ((char*)s + len_s);
	return (0);
}
