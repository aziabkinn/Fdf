/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziabkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 16:34:31 by aziabkin          #+#    #+#             */
/*   Updated: 2018/03/30 22:05:12 by aziabkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *f, size_t len)
{
	size_t	i;
	int		j;

	i = 0;
	if (*f == '\0')
		return ((char*)s);
	while (i < len && s[i] != '\0')
	{
		j = 0;
		while (s[i + j] == f[j] && (i + j) < len &&
				f[j] != '\0' && s[i + j] != '\0')
			j++;
		if (f[j] == '\0')
			return ((char*)s + i);
		i++;
	}
	return (NULL);
}
