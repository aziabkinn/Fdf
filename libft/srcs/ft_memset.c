/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziabkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 19:12:48 by aziabkin          #+#    #+#             */
/*   Updated: 2018/03/26 17:05:24 by aziabkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*current;
	size_t			i;

	current = s;
	i = 0;
	while (i < n)
	{
		current[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
