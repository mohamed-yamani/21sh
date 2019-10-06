/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myamani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 14:59:29 by myamani           #+#    #+#             */
/*   Updated: 2018/10/18 10:08:59 by myamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_strequ(char const *s1, char const *s2)
{
	int				index;

	if (s1 && s2)
	{
		index = 0;
		while (s1[index] || s2[index])
		{
			if (s1[index] != s2[index])
				return (0);
			index++;
			if (s1[index] == '\0' && s2[index] == '\0')
				return (1);
		}
	}
	return (1);
}
