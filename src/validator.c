/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziabkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 15:54:38 by aziabkin          #+#    #+#             */
/*   Updated: 2018/05/10 15:54:40 by aziabkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		check_dig(char *str)
{
	int	val;
	int	i;

	val = 1;
	i = -1;
	while (str[++i])
	{
		if (str[i] == '-')
		{
			if (ft_isdigit(str[i + 1]) || str[i + 1] == ',' ||
			(str[i + 1] >= 'A' && str[i + 1] <= 'F')
			|| (str[i + 1] >= 'a' && str[i + 1] <= 'f') || str[i + 1] == 'x')
				i++;
			else
				val *= 0;
		}
		else if (!(ft_isdigit(str[i]) || str[i] == ',' ||\
						(str[i] >= 'A' && str[i] <= 'F') ||\
						(str[i] >= 'a' && str[i] <= 'f') || str[i] == 'x'))
			val *= 0;
	}
	return (val);
}

void	free_arr(char **splitted_arr, char *str)
{
	int	i;

	i = 0;
	while (splitted_arr[i])
		ft_strdel(&(splitted_arr[i++]));
	free(splitted_arr);
	ft_strdel(&str);
}

void	free_arr1(char **splitted_arr)
{
	int	i;

	i = 0;
	while (splitted_arr[i])
		ft_strdel(&(splitted_arr[i++]));
	free(splitted_arr);
}

int		check_input(int fd, int len_first)
{
	char	*str;
	int		len;
	char	**splitted_arr;

	while (get_next_line(fd, &str) > 0)
	{
		len = 0;
		splitted_arr = ft_strsplit(str, ' ');
		while (splitted_arr[len])
			len++;
		if (len != len_first)
		{
			free_arr(splitted_arr, str);
			return (0);
		}
		while (len--)
			if (check_dig(splitted_arr[len]) != 1)
			{
				free_arr(splitted_arr, str);
				return (0);
			}
		free_arr(splitted_arr, str);
	}
	return (1);
}

int		validator_file(int fd)
{
	int		i;
	char	*str;
	char	**splitted_arr;
	int		len_first;

	str = NULL;
	len_first = 0;
	get_next_line(fd, &str);
	if (!str)
		error_exit(4);
	splitted_arr = ft_strsplit(str, ' ');
	while (splitted_arr[len_first] != NULL)
		len_first++;
	free(str);
	if (!(check_dig(splitted_arr[0])) || !(check_input(fd, len_first)))
	{
		free_arr1(splitted_arr);
		return (0);
	}
	i = 0;
	while (splitted_arr[i])
		ft_strdel(&(splitted_arr[i++]));
	free(splitted_arr);
	return (1);
}
