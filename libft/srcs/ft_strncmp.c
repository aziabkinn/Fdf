/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziabkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 18:07:55 by aziabkin          #+#    #+#             */
/*   Updated: 2018/04/02 15:01:47 by aziabkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int i;

	i = 0;
	if (!n)
		return (0);
	while (s1[i] == s2[i] && (s1[i] != '\0' && s2[i] != '\0') && --n)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
