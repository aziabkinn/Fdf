/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziabkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 19:05:00 by aziabkin          #+#    #+#             */
/*   Updated: 2018/04/02 17:02:15 by aziabkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		sizes_w(int *sizes, char *str, char c)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && str[i] == c)
			i++;
		j = i;
		while (str[i] != '\0' && str[i] != c)
			i++;
		sizes[k++] = i - j;
	}
}

static void		rewrite_w(char *str, char **s, char c)
{
	int j;
	int k;
	int i;

	i = 0;
	k = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && str[i] == c)
			i++;
		if (str[i] == '\0')
			break ;
		j = 0;
		while (str[i] != '\0' && str[i] != c)
			s[k][j++] = str[i++];
		s[k][j] = '\0';
		k++;
	}
}

char			**ft_strsplit(char const *s, char c)
{
	char	**str_split;
	int		*arr;
	int		i;

	i = -1;
	if (s)
	{
		if (!(arr = ft_memalloc(ft_delimiter((char *)s, c) + 1)))
			return (NULL);
		sizes_w(arr, (char *)s, c);
		str_split = ft_memalloc(ft_delimiter((char *)s, c) + 1);
		if (!str_split)
			return (NULL);
		while (++i < ft_delimiter((char *)s, c))
			if (!(str_split[i] = ft_strnew(arr[i] + 1)))
				return (NULL);
		rewrite_w((char *)s, str_split, c);
		str_split[i] = NULL;
		free(arr);
		return (str_split);
	}
	return (NULL);
}
