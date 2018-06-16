/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziabkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 19:59:35 by aziabkin          #+#    #+#             */
/*   Updated: 2018/03/31 20:22:16 by aziabkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrev(char *str)
{
	int		i;
	int		len;
	char	temp;

	i = -1;
	len = ((int)ft_strlen(str)) - 1;
	while (++i < len)
	{
		temp = str[i];
		str[i] = str[len];
		str[len] = temp;
		len--;
	}
	return (str);
}
