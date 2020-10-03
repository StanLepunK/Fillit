/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <stan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 12:08:29 by smarcais          #+#    #+#             */
/*   Updated: 2020/10/03 16:25:38 by stan             ###   ########.fr       */
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
// void tetro_clean(t_tetro *t) {
//   printf("CLEAN TETROMINOS\n");
// 	t_line tl;

// 	checker_line_set_arguments(&tl);
// 	int offset_x = 0;
// 	int offset_y = 0;
//   while(t) {
//     printf("next tetromino\n");
//     while(t->tetro_line) {
//       printf("str: %s\n",t->tetro_line->str);
//       t->tetro_line = t->tetro_line->next;
//     }
//     t = t->next;
//   }
// }


// clang src/*.c header/*.h -I ./ -I./libft -L ./libft/ -lft && ./a.out "./import/sample_0.fillit"
int main(int num, char **arg) {
	t_block checker_block;
	t_tetro *tetrominos;
	tetrominos = NULL;

	if(num > 0) {
		int fd = open(arg[1], O_RDONLY);
		checker(fd, &checker_block, &tetrominos);
	}
	// tetro_clean(tetrominos);
	// need to reboot the linked list to the first arguments.
	tetro_print(tetrominos);	

	return (0);
}