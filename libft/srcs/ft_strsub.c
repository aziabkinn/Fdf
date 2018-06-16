/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziabkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 13:49:34 by aziabkin          #+#    #+#             */
/*   Updated: 2018/03/28 17:06:38 by aziabkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*copy;
	size_t	i;

	i = 0;
	if (s)
	{
		copy = (char *)malloc(sizeof(*copy) * (len + 1));
		if (copy)
		{
			while (i < len && s[start] != '\0')
				copy[i++] = s[start++];
			copy[i] = '\0';
			return (copy);
		}
		return (NULL);
	}
	return (NULL);
}
