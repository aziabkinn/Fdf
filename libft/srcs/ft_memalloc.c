/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziabkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 13:48:10 by aziabkin          #+#    #+#             */
/*   Updated: 2018/03/27 13:48:18 by aziabkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*m;

	m = (void *)malloc(sizeof(m) * size);
	if (m)
	{
		ft_bzero(m, size);
		return (m);
	}
	return (NULL);
}
