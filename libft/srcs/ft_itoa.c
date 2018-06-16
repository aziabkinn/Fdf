/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziabkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 13:54:08 by aziabkin          #+#    #+#             */
/*   Updated: 2018/04/02 15:56:07 by aziabkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*transform(char *copy, int n, int len, int isnegative)
{
	copy[len] = '\0';
	len -= 1;
	while (len >= isnegative)
	{
		copy[len] = n % 10 + 48;
		n /= 10;
		len--;
	}
	return (copy);
}

char		*ft_itoa(int n)
{
	char	*copy;
	int		a;
	int		b;

	copy = NULL;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	a = 0;
	b = ft_count_char(n);
	if (!(copy = (char *)malloc(sizeof(*copy) * (b + 1))))
		return (NULL);
	if (n < 0)
	{
		copy[0] = '-';
		n = -n;
		a = 1;
	}
	return (transform(copy, n, b, a));
}
