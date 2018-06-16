/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziabkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 13:58:10 by aziabkin          #+#    #+#             */
/*   Updated: 2018/03/25 19:05:20 by aziabkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*copy;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (src[i] != '\0')
		i++;
	copy = (char *)malloc(sizeof(*copy) * (i + 1));
	if (!copy)
		return (NULL);
	while (j < i)
	{
		copy[j] = src[j];
		j++;
	}
	copy[j] = '\0';
	return (copy);
}
