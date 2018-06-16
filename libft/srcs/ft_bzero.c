/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziabkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 19:23:16 by aziabkin          #+#    #+#             */
/*   Updated: 2018/03/26 17:02:35 by aziabkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*current;
	size_t			i;

	current = s;
	i = 0;
	if (n == 0)
		return ;
	while (i < n)
	{
		current[i] = '\0';
		i++;
	}
}
