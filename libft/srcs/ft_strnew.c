/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziabkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 17:02:37 by aziabkin          #+#    #+#             */
/*   Updated: 2018/03/28 17:02:09 by aziabkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *s;

	s = (char *)malloc(sizeof(*s) * size + 1);
	if (!s)
		return (NULL);
	ft_bzero(s, size + 1);
	return (s);
}
