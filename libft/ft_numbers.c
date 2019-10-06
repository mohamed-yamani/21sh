/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myamani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 10:14:10 by myamani           #+#    #+#             */
/*   Updated: 2018/10/19 10:14:37 by myamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t				ft_numbers(int value)
{
	size_t		digitals;
	size_t		signe;

	signe = 0;
	digitals = 1;
	if (value < 0)
		signe = 1;
	while (value /= 10)
		digitals++;
	return (digitals + signe);
}
