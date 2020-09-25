/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <stan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 12:08:29 by smarcais          #+#    #+#             */
/*   Updated: 2020/09/21 18:26:36 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"
#include "libft.h"




typedef struct s_block {
  int id;

	char a;
	char b;

	int valid;
	int state;
	int threshold;

	int row;
	int row_max;
	int col;
	int col_max;
	
	int brick;
	int brick_max;

  char *content;
} t_block;

// clang src/*.c *.h -I ./ -I./libft -L ./libft/ -lft && ./a.out "./import/sample.fillit"
int line_is(t_block *temp, char *line, int *brick) {
	char	c;
	char previous;
	int score;
	int fail;

	fail = 3;
	if(ft_strlen(line) == temp->row_max) {
		score = 0;
		previous = 0;
		while((c = *line++) !=  '\0') {
			if(c == temp->b || c == temp->a) {
				if(c == temp->a) {
					*brick += 1;
				}
				if(previous != 0 && previous != c) {
					score++;
				}
				previous = c;
			} else {
				// return (fail);
				score = fail;
				break;		
			}
		}
		return (score);
	}
	return (fail);
}

void block_init(t_block *temp) {
	temp->state = 0;
	temp->row = 0;
	temp->brick = 0;
	temp->threshold = 3;
	temp->row_max = 4;
	temp->col_max = 4;
	temp->a = '#';
	temp->b = '.';
	temp->valid = 0;
}


void compare_lines(t_block *temp, char *line, char *previous_line) {
	// printf("compare previous line with line\n");
	int index;

	index = 0;
	temp->valid = 0;
	while(index < temp->col_max) {
		if(line[index] == temp->a && line[index] == previous_line[index] ) {
			temp->valid = 1;
		}
		if(line[index] == temp->b)
			temp->valid = 1;

		index++;
	}
}


void set_block(t_block *temp, char *line, char *previous_line) {
	temp->state = line_is(temp, line, &temp->brick);
	if(temp->state < temp->threshold) {
		// printf("ft_strcmp(line, previous_line) = %i\n", ft_strcmp(line, previous_line));
		if(ft_strlen(previous_line) == 4)
			compare_lines(temp, line, previous_line);
		previous_line = ft_strcpy(previous_line, line);
	}
	// printf("temp->brick = %i\n", temp->brick);
	// printf("temp->row = %i\n", temp->row);
	temp->row += 1;
	if(temp->row == 4  && temp->brick == 4 && temp->state < temp->threshold && temp->valid == 1) {
		printf("add block\n");
		block_init(temp);
		*previous_line = 0; // ft_bzero ???
	}	
	if(temp->state >= 3) {
		block_init(temp);
	}
}

void check_block(const int fd, t_block *temp) {
	char *previous_line;
	char *line;

	block_init(temp);
	while (get_next_line(fd, &line) > 0) {
		set_block(temp, line, previous_line);
		free(line);
	}
	get_next_line(fd, &line);
	// printf("%s\n", line);
	// set_block(&is, &count, line);
	free(line);
	close(fd);
}


int main(int num, char **arg) {
	t_block temp_block;
	if(num > 0) {
		int fd = open(arg[1], O_RDONLY);
		check_block(fd, &temp_block);
	}	
	return (0);
}