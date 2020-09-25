/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarcais <smarcais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 12:08:29 by smarcais          #+#    #+#             */
/*   Updated: 2020/09/08 12:36:09 by smarcais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<fcntl.h>
#include "get_next_line.h"
#include "libft.h"

int main(int num, char **arg)
{
	int fd = open(arg[1], O_RDONLY);
	int count = 0;
	char *line;
	while (get_next_line(fd, &line) > 0)
	{
		printf("ligne %i %s\n", count, line);
		free(line);
		count++;
	}
	get_next_line(fd, &line);
	printf("ligne %i %s\n", count, line);
	free(line);
	close(fd);
	return (0);
}