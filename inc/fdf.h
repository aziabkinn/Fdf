/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziabkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 13:43:59 by aziabkin          #+#    #+#             */
/*   Updated: 2018/05/15 13:12:23 by aziabkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "mlx.h"
# include <math.h>

# define SW 1000

#include <stdio.h>

# define D_X(v) (s->mm->k * (v->tmp_x - s->mm->m_x))
# define D_Y(v) (s->mm->k * (v->tmp_y - s->mm->m_y))

typedef	struct				s_coords
{
	double					x;
	double					y;
	double					z;
	double					tmp_x;
	double					tmp_y;
	double					tmp_z;
	unsigned int			color;
	int						width;
	int						height;
	struct s_coords			*right;
	struct s_coords			*down;
	struct s_coords			*next;
}							t_coords;

typedef struct				s_mm
{
	double					max_x;
	double					max_y;
	double					max_z;
	double					m_x;
	double					m_y;
	double					k;
	double					r_x;
	double					r_y;
	double					r_z;
	double					s_x;
	double					s_y;
}							t_mm;

typedef struct				s_draw
{
	double					delta_x;
	double					delta_y;
	double					length_x;
	double					length_y;
	double					length;
}							t_draw;

typedef struct				s_window
{
	void					*mlx;
	void					*image;
	void					*window;
	int						*adress;
	int						endian;
	int						size_line;
	int						bpp;
}							t_window;

typedef struct				s_structs
{
	t_coords				*coords;
	t_window				*wind;
	t_mm					*mm;
	t_draw					*draw;
}							t_structs;

int							validator_file(int fd);
int							check_dig(char *str);
t_coords					*put_coords(char *str, int i, t_coords *lst);
t_coords					*new_elem(void);
void						put_links(t_coords *lst);
void						create_window(t_window **window);
t_window					*new_window(void);
int							exit_x(int key, t_structs *strs);
unsigned int				put_color(char *s, int base);
void						draw(t_structs *s);
int							hadle_input_key(int key, t_structs *strs);
void						handle_2(int key, t_structs *strs);
void						handle_3(int key, t_structs *strs);
void						init_elem(t_coords *lst, int len_first, int y,\
													char **splitted_arr);
void						rot_coords(t_structs *st);
void						rot_center(t_structs *st);
void						hints(t_window *wind);
void						add(t_structs *strs, t_coords *tmp);
void						add1(char *av, t_structs *strs);
void						error_exit(int a);
int							check_input(int fd, int len_first);
void						free_arr(char **splitted_arr, char *str);
void						free_arr1(char **splitted_arr);
void						more(t_draw draw, int *f, t_structs *s,\
														unsigned int c);
void						less(t_draw draw, int *f, t_structs *s,\
														unsigned int c);
void						draw_line(int *f, int *sc, t_structs *s,\
														unsigned int c);

#endif
