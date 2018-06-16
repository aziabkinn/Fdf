/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziabkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 12:30:52 by aziabkin          #+#    #+#             */
/*   Updated: 2018/05/24 12:30:55 by aziabkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error_exit(int a)
{
	if (a == 1)
		ft_putendl("Error! File does not open!");
	else if (a == 2)
		ft_putendl("Error! The map is not valid!");
	else if (a == 3)
		ft_putendl("usage: ./fdf [file]");
	else if (a == 4)
		ft_putendl("Error!");
	exit(0);
}

void	add(t_structs *strs, t_coords *tmp)
{
	strs->mm->max_x = tmp->x;
	strs->mm->max_y = tmp->y;
	strs->mm->s_x = 0;
	strs->mm->s_y = 0;
	strs->mm->r_x = 0.05;
	strs->mm->r_y = 0.05;
	strs->mm->r_z = 0.05;
	rot_coords(strs);
	strs->mm->m_x = (tmp->x) / 2;
	strs->mm->m_y = (tmp->y) / 2;
	strs->mm->k = fmin((SW - 600) / strs->mm->max_x, \
												(SW - 600) / strs->mm->max_y);
	strs->wind ? free(strs->wind) : NULL;
	strs->wind = new_window();
	create_window(&strs->wind);
	strs->wind->image = mlx_new_image(strs->wind->mlx, SW, SW);
	strs->wind->adress = (int *)mlx_get_data_addr(strs->wind->image, \
			&strs->wind->endian, &strs->wind->size_line, &strs->wind->bpp);
	draw(strs);
	mlx_put_image_to_window(strs->wind->mlx, strs->wind->window, \
		strs->wind->image, 0, 0);
	hints(strs->wind);
	mlx_hook(strs->wind->window, 2, 0, hadle_input_key, strs);
	mlx_hook(strs->wind->window, 17, 0, exit_x, strs);
	mlx_loop(strs->wind->mlx);
}

void	add1(char *av, t_structs *strs)
{
	int		fd;
	int		i;
	int		check_f;
	char	*str;

	if ((fd = open(av, O_RDONLY)) == -1)
		error_exit(1);
	check_f = validator_file(fd);
	close(fd);
	fd = open(av, O_RDONLY);
	if (check_f != 1)
	{
		close(fd);
		error_exit(2);
	}
	i = 0;
	while (get_next_line(fd, &str) > 0)
	{
		strs->coords = put_coords(str, i++, strs->coords);
		free(str);
	}
	if (!strs->coords)
		error_exit(4);
	strs->coords->height = i;
	put_links(strs->coords);
}

int		main(int argc, char const **argv)
{
	t_structs	*strs;
	t_coords	*tmp;

	if (!(strs = (t_structs *)malloc(sizeof(t_structs))))
		return (0);
	strs->coords = NULL;
	strs->wind = NULL;
	if (!(strs->mm = (t_mm *)malloc(sizeof(t_mm))))
		return (0);
	if (argc != 2)
	{
		error_exit(3);
		return (0);
	}
	add1((char *)argv[1], strs);
	tmp = strs->coords;
	while (tmp->next->next)
		tmp = tmp->next;
	add(strs, tmp);
	return (0);
}
