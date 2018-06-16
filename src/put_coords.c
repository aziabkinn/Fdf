/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_coords.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziabkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 14:33:43 by aziabkin          #+#    #+#             */
/*   Updated: 2018/05/12 14:33:51 by aziabkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		put_links(t_coords *lst)
{
	t_coords	*tmp;
	t_coords	*head;

	head = lst;
	while (lst->next)
	{
		if (lst->x + 1 != lst->width)
			lst->right = lst->next;
		lst = lst->next;
	}
	lst = head;
	tmp = head;
	while (!head->y)
		head = head->next;
	while (head->next)
	{
		tmp->down = head;
		tmp = tmp->next;
		head = head->next;
	}
	while (tmp->next)
	{
		tmp->down = NULL;
		tmp = tmp->next;
	}
}

t_coords	*new_elem(void)
{
	t_coords *lst;

	if (!(lst = (t_coords*)malloc(sizeof(t_coords))))
		return (NULL);
	lst->next = NULL;
	return (lst);
}

void		init_elem(t_coords *lst, int len_first, int y, char **splitted_arr)
{
	int		i;
	char	*p;

	i = -1;
	while (++i < len_first)
	{
		lst->z = ft_atoi(splitted_arr[i]);
		lst->tmp_z = lst->z;
		lst->x = i;
		lst->tmp_x = i;
		lst->y = y;
		lst->tmp_y = y;
		lst->color = put_color("0FFFFFF", 16);
		if ((p = ft_strchr(splitted_arr[i], ',')))
			lst->color = put_color(p + 3, 16);
		lst->width = len_first;
		lst->next = new_elem();
		lst = lst->next;
	}
}

t_coords	*put_coords(char *str, int y, t_coords *lst)
{
	t_coords	*tmp;
	char		**splitted_arr;
	int			len_first;

	len_first = 0;
	splitted_arr = ft_strsplit(str, ' ');
	while (splitted_arr[len_first])
		len_first++;
	tmp = lst;
	if (!tmp)
	{
		lst = new_elem();
		tmp = lst;
	}
	while (lst->next)
		lst = lst->next;
	init_elem(lst, len_first, y, splitted_arr);
	len_first = 0;
	while (splitted_arr[len_first])
		ft_strdel(&(splitted_arr[len_first++]));
	free(splitted_arr);
	return (tmp);
}
