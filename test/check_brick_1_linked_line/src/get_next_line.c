/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <stan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 09:48:53 by smarcais          #+#    #+#             */
/*   Updated: 2020/09/26 14:26:28 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <stdio.h>

static size_t	get_index(char *str, int *p_eol, char *target)
{
	char	*ptr;
	size_t	index;

	index = -1;
	ptr = ft_strstr(str, target);
	if (ptr)
	{
		index = (ptr - str);
		*p_eol = 1;
	}
	return (index);
}

static int		set_line(char **line, char *bridge, int *p_eol, int *p_eof)
{
	int		index;
	int		length;
	char	*temp;
	char	*rest;

	index = get_index(bridge, p_eol, "\n");
	if (index == -1)
		index = ft_strlen(bridge);
	length = ft_strlen(bridge);
	rest = ft_strsub(bridge, 0, index);
	if (index >= length)
		ft_memmove(bridge, bridge + index, length);
	else
		ft_memmove(bridge, bridge + index + 1, length);
	temp = *line;
	*line = ft_strjoin(temp, rest);
	free(rest);
	free(temp);
	if (index < BUFF_SIZE && *p_eol == 0 && *p_eof == 0)
		return (0);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_fd_content *bridge;
	int			is;
	int			eol;
	int			eof;

	is = -1;
	eof = BUFF_SIZE;
	if(!bridge) {
		bridge = (t_fd_content*)ft_memalloc(sizeof(t_fd_content));
		bridge->content = ft_memalloc(BUFF_SIZE + 1);
		eof = read(fd, bridge->content, BUFF_SIZE);
		bridge->fd = fd;
	}
	if (fd < 0 || fd != bridge->fd || BUFF_SIZE < 1 || read(fd, bridge->content, 0) < 0)
		return (is);
	eol = 0;
	*line = ft_memalloc(1);
	while (eol == 0 && is != 0)
	{
		if (!bridge->content)
		{
			bridge->content = ft_memalloc(BUFF_SIZE + 1);
			eof = read(fd, bridge->content, BUFF_SIZE);
		}
		is = set_line(line, bridge->content, &eol, &eof);
		if (bridge->content[0] == '\0')
			ft_strdel(&bridge->content);
	}
	if(ft_strlen(*line) > 0 && eof == 0)
		return (1);
	return (is);
}