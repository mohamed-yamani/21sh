/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myamani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 15:45:01 by myamani           #+#    #+#             */
/*   Updated: 2018/10/22 11:05:56 by myamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dst, const char *src)
{
	int		count;

	count = -1;
	while (src[++count])
		dst[count] = src[count];
	dst[count] = '\0';
	return (dst);
}
