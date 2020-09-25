/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarcais <smarcais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 12:08:29 by smarcais          #+#    #+#             */
/*   Updated: 2020/09/08 16:09:16 by smarcais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"
// clang src/*.c *.h -I ./ -I./libft -L ./libft/ -lft && ./a.out "./import/sample.fillit"
int main(int num, char **arg)
{
	if(num > 0) {
		int fd = open(arg[1], O_RDONLY);
		int count = 0;
		char *line;
		while (get_next_line(fd, &line) > 0)
		{
			printf("\033[0;32mligne %i %s\n", count, line);
			free(line);
			count++;
		}
		get_next_line(fd, &line);
		printf("ligne %i %s\n", count, line);
		free(line);
		close(fd);
	}
	
	return (0);
}