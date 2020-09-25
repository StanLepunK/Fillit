/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgirard <sgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:50:30 by sgirard           #+#    #+#             */
/*   Updated: 2020/08/20 16:20:03 by sgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdlib.h"

int		ft_traitement(char **str, int fd, char *buf, int *eof)
{
	int		nb_read;
	char	*result;

	while (1)
	{
		if (ft_strchr(*str, '\n'))
			break ;
		if (!((nb_read = read(fd, buf, BUFF_SIZE)) > 0))
		{
			if (nb_read == -1)
				return (-1);
			*eof = 1;
			break ;
		}
		buf[nb_read] = '\0';
		if (*str == NULL)
			*str = ft_strdup(buf);
		else
		{
			result = ft_strjoin(*str, buf);
			ft_strdel(str);
			*str = result;
		}
	}
	return (*eof);
}

void	ft_make_line(char **line, char **str)
{
	int		i;
	char	*tmp;

	i = ft_strchr(*str, '\n') - *str;
	*line = ft_strsub(*str, 0, i);
	tmp = ft_strdup(*str + i + 1);
	ft_strdel(str);
	*str = tmp;
}

int		get_next_line(const int fd, char **line)
{
	int				ret;
	int				eof;
	char			buf[BUFF_SIZE + 1];
	static char		*str;

	eof = 0;
	ret = 0;
	if (fd < 0 || !line || BUFF_SIZE <= 0)
		return (-1);
	eof = ft_traitement(&str, fd, buf, &eof);
	if (eof == -1)
		return (-1);
	if (ft_strchr(str, '\n') || ((eof == 1) && (ft_strlen(str)) > 0))
	{
		if (eof)
		{
			*line = ft_strdup(str);
			ft_strdel(&str);
		}
		else
			ft_make_line(line, &str);
		return (1);
	}
	ft_strdel(&str);
	return (0);
}
