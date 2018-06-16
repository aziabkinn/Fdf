/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziabkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 13:11:54 by aziabkin          #+#    #+#             */
/*   Updated: 2018/05/15 13:12:04 by aziabkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			hints(t_window *w)
{
	mlx_string_put(w->mlx, w->window, 700, 850, 0xFFB3B3,\
		"Change of size: + -");
	mlx_string_put(w->mlx, w->window, 700, 875, 0xFFB3B3,\
		"Rotate: 1, 2, 3, 4, 5, 6");
	mlx_string_put(w->mlx, w->window, 700, 900, 0xFFB3B3,\
		"Move: < /\\ \\/ >");
	mlx_string_put(w->mlx, w->window, 700, 925, 0xFFB3B3,\
		"Change of color: Q, W, E, R");
}

unsigned int	put_color(char *str, int base)
{
	unsigned int	i;
	int				k;

	i = 0;
	k = 0;
	if (!str)
		return (0);
	while (str[k] == ' ' || (str[k] >= 9 && str[k] <= 13))
	{
		i++;
		k++;
	}
	while (str[k] && ((ft_isdigit(str[k]) || (str[k] >= 'A' && str[k] <= 'F'))
		|| (str[k] >= 'a' && str[k] <= 'f')))
	{
		i = (i * base);
		if (str[k] < 97)
			i += (str[k] - (str[k] <= 57 ? 48 : 55));
		else
			i += str[k] - 87;
		k++;
	}
	return (i);
}

t_window		*new_window(void)
{
	t_window	*new;

	new = (t_window *)malloc(sizeof(t_window));
	new->image = NULL;
	new->window = NULL;
	new->adress = NULL;
	new->endian = 0;
	new->size_line = 0;
	new->bpp = 0;
	return (new);
}

void			create_window(t_window **wind)
{
	(*wind)->mlx = mlx_init();
	(*wind)->window = mlx_new_window((*wind)->mlx, SW, SW,
		"Project FDF aziabkin");
}
