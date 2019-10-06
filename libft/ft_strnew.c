/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myamani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 10:04:34 by myamani           #+#    #+#             */
/*   Updated: 2018/10/18 13:47:18 by myamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	char		*str_new;

	str_new = (char*)malloc(sizeof(char) * size + 1);
	if (!str_new)
		return (0);
	ft_bzero(str_new, size + 1);
	return (str_new);
}
