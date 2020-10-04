/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <stan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 12:08:29 by smarcais          #+#    #+#             */
/*   Updated: 2020/10/04 16:25:36 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../header/get_next_line.h"
#include "libft.h"
#include "../header/tetro.h"

// https://github.com/JemCopeCodes/42-Fillit  nice for displacement grid concept
void tetro_clean(t_tetro *t) {
  printf("CLEAN TETROMINOS\n");
	t_line tl;

	checker_line_set_arguments(&tl);
	int lock_x = 0;
	int lock_y = 0;
	// int offset_y = 0;
  while(t) {
    printf("next tetromino\n");
    while(t->tetro_line) {
			//printf("t->tetro_line->empty: %i, lock_y: %i \n",t->tetro_line->empty, lock_y);
			if(t->tetro_line->empty && !lock_y) {
				t->offset_y++;
			} else if(!t->tetro_line->empty) {
				lock_y = 1;
			} 
			if(t->offset_x < t->tetro_line->offset && !lock_x) {
				t->offset_x = t->tetro_line->offset;
				lock_x = 1;
			} else if(t->tetro_line->offset < t->offset_x) {
				t->offset_x = t->tetro_line->offset;
			}
      printf("str: %s offset y: %i\n",t->tetro_line->content,t->offset_y);
      t->tetro_line = t->tetro_line->next;
			// printf("offset y:  %i \n",t->offset_y);
    }
		printf("offset x: %i \n",t->offset_x);
		printf("offset y: %i \n",t->offset_y);
    t = t->next;
  }
	
}


// clang src/*.c header/*.h -I ./ -I./libft -L ./libft/ -lft && ./a.out "./import/sample_0.fillit"
int main(int num, char **arg) {
	t_block checker_block;
	t_tetro *tetrominos;
	tetrominos = NULL;

	if(num > 0) {
		int fd = open(arg[1], O_RDONLY);
		checker(fd, &checker_block, &tetrominos);
	}
	tetro_clean(tetrominos);
	// need to reboot the linked list to the first arguments.

	tetro_print(tetrominos);

	return (0);
}