/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziabkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 17:43:16 by aziabkin          #+#    #+#             */
/*   Updated: 2018/04/02 16:43:56 by aziabkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *list;
	t_list *temp_list;

	if (alst && del)
	{
		if (*alst)
		{
			list = *alst;
			temp_list = *alst;
			while (list)
			{
				temp_list = temp_list->next;
				del(list->content, list->content_size);
				free(list);
				list = NULL;
				list = temp_list;
			}
			*alst = NULL;
		}
	}
}
