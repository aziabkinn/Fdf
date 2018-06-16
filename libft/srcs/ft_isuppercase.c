/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isuppercase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziabkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 19:57:34 by aziabkin          #+#    #+#             */
/*   Updated: 2018/03/31 20:26:34 by aziabkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isuppercase(char *str)
{
	int i;
	int res;

	i = 0;
	res = 1;
	if (!str)
	{
		return (1);
	}
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			res *= 1;
		}
		else
		{
			res *= 0;
		}
		i++;
	}
	return (res);
}
