/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziabkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 15:34:36 by aziabkin          #+#    #+#             */
/*   Updated: 2018/05/04 15:37:53 by aziabkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		i_nl(char **str)
{
	int			index;

	index = 0;
	while ((*str)[index] && (*str)[index] != '\n')
		index++;
	return (index);
}

static int		is_written(char **mem, char **line)
{
	int			index;
	char		*trash;

	index = i_nl(mem);
	trash = *mem;
	if ((*mem)[0] == '\n')
	{
		*line = ft_strdup("\0");
		*mem = ft_strsub(*mem, index + 1, ft_strlen(*mem) - index);
		free(trash);
		return (1);
	}
	*line = ft_strsub(*mem, 0, index);
	*mem = ft_strsub(*mem, index + 1, ft_strlen(*mem) - index);
	free(trash);
	return (ft_strlen(*line) > 0 ? 1 : 0);
}

int				get_next_line(const int fd, char **line)
{
	char		buff[BUFF_SIZE + 1];
	static char *mem[400];
	char		*trash;
	int			bytes;

	if (read(fd, buff, 0) < 0)
		return (-1);
	if (!mem[fd])
		mem[fd] = ft_strdup("\0");
	while ((bytes = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[bytes] = '\0';
		trash = mem[fd];
		mem[fd] = ft_strjoin(trash, buff);
		free(trash);
		if (mem[fd] && ft_strchr(mem[fd], '\n'))
			break ;
	}
	if (mem[fd][0] == '\0')
		return (0);
	bytes = is_written(&mem[fd], line);
	return (bytes);
}
