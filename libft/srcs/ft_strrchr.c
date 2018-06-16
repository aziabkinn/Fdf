/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziabkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 19:01:33 by aziabkin          #+#    #+#             */
/*   Updated: 2018/04/04 18:48:53 by aziabkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;

	i = 0;
	if (ft_strchr(s, c) == NULL)
		return (NULL);
	while (s[i] != '\0')
		i++;
	while (s[i] != c)
		i--;
	return ((char *)s + i);
}
