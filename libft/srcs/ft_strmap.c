/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziabkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 18:13:59 by aziabkin          #+#    #+#             */
/*   Updated: 2018/04/04 18:45:16 by aziabkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		i;
	int		len;

	i = 0;
	if (s && f)
	{
		len = (int)ft_strlen(s);
		str = (char *)malloc(sizeof(*str) * (len + 1));
		if (str)
		{
			while (s[i] != '\0')
			{
				str[i] = f(s[i]);
				i++;
			}
			str[i] = '\0';
			return (str);
		}
		return (NULL);
	}
	return (NULL);
}
