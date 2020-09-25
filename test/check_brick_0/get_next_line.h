/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarcais <smarcais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 10:25:05 by smarcais          #+#    #+#             */
/*   Updated: 2020/03/10 17:59:16 by smarcais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 1

#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

int	get_next_line(const int fd, char **line);


typedef struct		s_fd_content 
{
	int		fd;
	char	*content;

}									t_fd_content;

#endif
