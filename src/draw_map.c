/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziabkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 13:00:11 by aziabkin          #+#    #+#             */
/*   Updated: 2018/05/24 13:00:13 by aziabkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	more(t_draw draw, int *f, t_structs *s, unsigned int c)
{
	int x;
	int y;
	int d;

	x = f[0];
	y = f[1];
	d = -draw.length_y;
	while (draw.length--)
	{
		if (x >= 0 && y >= 0 && x < SW && y < SW)
			s->wind->adress[y * SW + x] = c;
		y += draw.delta_y;
		d += 2 * draw.length_x;
		if (d > 0)
		{
			d -= 2 * draw.length_y;
			x += draw.delta_x;
		}
	}
}

void	less(t_draw draw, int *f, t_structs *s, unsigned int c)
{
	int x;
	int y;
	int d;

	x = f[0];
	y = f[1];
	d = -draw.length_x;
	while (draw.length--)
	{
		if (x >= 0 && y >= 0 && x < SW && y < SW)
			s->wind->adress[y * SW + x] = c;
		x += draw.delta_x;
		d += 2 * draw.length_y;
		if (d > 0)
		{
			d -= 2 * draw.length_x;
			y += draw.delta_y;
		}
	}
}

void	draw_line(int *f, int *sc, t_structs *s, unsigned int c)
{
	t_draw draw;

	draw.delta_x = (sc[0] - f[0] >= 0 ? 1 : -1);
	draw.delta_y = (sc[1] - f[1] >= 0 ? 1 : -1);
	draw.length_x = abs(sc[0] - f[0]);
	draw.length_y = abs(sc[1] - f[1]);
	draw.length = fmax(draw.length_x, draw.length_y) + 1;
	if (!draw.length)
	{
		if (f[0] >= 0 && f[1] >= 0 && f[0] < SW && f[1] < SW)
			s->wind->adress[f[1] * SW + f[0]] = c;
	}
	if (draw.length_y <= draw.length_x)
		less(draw, f, s, c);
	else
		more(draw, f, s, c);
}

void	draw(t_structs *s)
{
	int			f[2];
	int			sc[2];
	t_coords	*tmp;

	tmp = s->coords;
	rot_center(s);
	ft_bzero(s->wind->adress, SW * SW * 4);
	while (tmp->next->next)
	{
		f[0] = ((SW / 2) + D_X(tmp)) + s->mm->s_x;
		f[1] = ((SW / 2) + D_Y(tmp)) + s->mm->s_y;
		if (tmp->next->y == tmp->y)
		{
			sc[0] = ((SW / 2) + D_X(tmp->next)) + s->mm->s_x;
			sc[1] = ((SW / 2) + D_Y(tmp->next)) + s->mm->s_y;
			draw_line(f, sc, s, fmax(tmp->color, tmp->next->color));
		}
		if (tmp->down)
		{
			sc[0] = ((SW / 2) + D_X(tmp->down)) + s->mm->s_x;
			sc[1] = ((SW / 2) + D_Y(tmp->down)) + s->mm->s_y;
			draw_line(f, sc, s, fmax(tmp->color, tmp->down->color));
		}
		tmp = tmp->next;
	}
}
