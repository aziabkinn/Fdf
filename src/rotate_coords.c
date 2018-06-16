/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_coords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziabkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 13:57:04 by aziabkin          #+#    #+#             */
/*   Updated: 2018/05/17 13:57:09 by aziabkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rot_center(t_structs *st)
{
	double		x[2];
	double		y[2];
	t_coords	*tmp;

	tmp = st->coords;
	x[0] = st->coords->tmp_x;
	x[1] = st->coords->tmp_x;
	y[0] = st->coords->tmp_y;
	y[1] = st->coords->tmp_y;
	while (st->coords->next)
	{
		if (st->coords->tmp_x < x[0])
			x[0] = st->coords->tmp_x;
		else if (st->coords->tmp_x > x[1])
			x[1] = st->coords->tmp_x;
		if (st->coords->tmp_y < y[0])
			y[0] = st->coords->tmp_y;
		else if (st->coords->tmp_y > y[1])
			y[1] = st->coords->tmp_y;
		st->coords = st->coords->next;
	}
	st->coords = tmp;
	st->mm->m_x = (x[0] + x[1]) / 2;
	st->mm->m_y = (y[0] + y[1]) / 2;
}

void	rot_coords(t_structs *st)
{
	double		tx;
	double		ty;
	double		tz;
	t_coords	*tmp;

	tmp = st->coords;
	while (st->coords->next)
	{
		tx = st->coords->x;
		ty = st->coords->y;
		tz = st->coords->z;
		st->coords->tmp_y = ty * cos(st->mm->r_x) + tz * -sin(st->mm->r_x);
		st->coords->tmp_z = ty * sin(st->mm->r_x) + tz * cos(st->mm->r_x);
		tz = st->coords->tmp_z;
		st->coords->tmp_x = tx * cos(st->mm->r_y) + tz * sin(st->mm->r_y);
		st->coords->tmp_z = tx * -sin(st->mm->r_y) + tz * cos(st->mm->r_y);
		ty = st->coords->tmp_y;
		tx = st->coords->tmp_x;
		st->coords->tmp_x = tx * cos(st->mm->r_z) + ty * -sin(st->mm->r_z);
		st->coords->tmp_y = tx * sin(st->mm->r_z) + ty * cos(st->mm->r_z);
		st->coords = st->coords->next;
	}
	st->coords = tmp;
}
