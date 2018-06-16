/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziabkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 18:28:08 by aziabkin          #+#    #+#             */
/*   Updated: 2018/03/27 13:32:45 by aziabkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t dlen;
	size_t slen;
	size_t i;
	size_t res;

	i = 0;
	res = 0;
	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	if (dstsize <= dlen)
		return (dstsize + slen);
	res = dlen + slen;
	while (src[i] != '\0')
	{
		if (dlen < dstsize - 1)
		{
			dst[dlen] = src[i];
			dlen++;
		}
		i++;
	}
	dst[dlen] = '\0';
	return (res);
}
