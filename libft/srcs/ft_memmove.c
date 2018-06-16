/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziabkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 17:53:38 by aziabkin          #+#    #+#             */
/*   Updated: 2018/03/26 17:56:37 by aziabkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*sr;

	i = -1;
	dest = (unsigned char *)dst;
	sr = (unsigned char *)src;
	if (dest <= sr)
		while (++i < len)
			dest[i] = sr[i];
	else
	{
		i = len;
		while (i > 0)
		{
			dest[i - 1] = sr[i - 1];
			i--;
		}
	}
	return (dest);
}
