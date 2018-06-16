/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziabkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 12:35:45 by aziabkin          #+#    #+#             */
/*   Updated: 2018/05/24 12:36:08 by aziabkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			exit_x(int key, t_structs *strs)
{
	(void)key;
	(void)strs;
	exit(0);
}

void		handle_3(int key, t_structs *strs)
{
	if (key == 12)
		while (strs->coords->next)
		{
			strs->coords->color = put_color("0FFFF33", 16);
			strs->coords = strs->coords->next;
		}
	else if (key == 13)
		while (strs->coords->next)
		{
			strs->coords->color = put_color("099004C", 16);
			strs->coords = strs->coords->next;
		}
	else if (key == 14)
		while (strs->coords->next)
		{
			strs->coords->color = put_color("0006633", 16);
			strs->coords = strs->coords->next;
		}
}

void		handle_2(int key, t_structs *strs)
{
	if (key == 69)
		strs->mm->k += 5;
	else if (key == 78 && strs->mm->k > 5)
		strs->mm->k -= 5;
	else if (key == 124)
		strs->mm->s_x += 3;
	else if (key == 123)
		strs->mm->s_x -= 3;
	else if (key == 125)
		strs->mm->s_y += 3;
	else if (key == 126)
		strs->mm->s_y -= 3;
	else if (key == 83)
		strs->mm->r_x += 0.07;
	else if (key == 84)
		strs->mm->r_y += 0.07;
	else if (key == 85)
		strs->mm->r_z += 0.07;
	else if (key == 86)
		strs->mm->r_x -= 0.07;
	else if (key == 87)
		strs->mm->r_y -= 0.07;
	else if (key == 88)
		strs->mm->r_z -= 0.07;
}

int			hadle_input_key(int key, t_structs *strs)
{
	t_coords	*tmp;

	tmp = strs->coords;
	if (key == 53)
		exit_x(key, strs);
	handle_2(key, strs);
	handle_3(key, strs);
	if (key == 15)
		while (strs->coords->next)
		{
			strs->coords->color = put_color("0FFFFFF", 16);
			strs->coords = strs->coords->next;
		}
	strs->coords = tmp;
	draw(strs);
	mlx_put_image_to_window(strs->wind->mlx, strs->wind->window,
		strs->wind->image, 0, 0);
	rot_coords(strs);
	hints(strs->wind);
	return (0);
}
