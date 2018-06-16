/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islowercase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziabkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 19:58:49 by aziabkin          #+#    #+#             */
/*   Updated: 2018/03/31 20:26:23 by aziabkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_islowercase(char *str)
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
		if (str[i] >= 'a' && str[i] <= 'z')
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
