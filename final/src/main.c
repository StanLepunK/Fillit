/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <stan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 12:08:29 by smarcais          #+#    #+#             */
/*   Updated: 2020/11/08 11:20:00 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../includes/get_next_line.h"
#include "libft.h"
#include "../includes/tetro.h"


/**
to launche setph code
make dans le dossier lidft
gcc -fsanitize=address -o fillit *.c libft/libft.a -I libft/
ou 
gcc -o fillit *.c -I -L libft/libft.a && ./fillit "../import/sample.fillit"
valgrind --leak-check=full --track-origins=yes --show-leak-kinds=definite,indirect ./fillit ..import/sample.fillit
*/


// clang src/*.c header/*.h -I ./ -I./libft -L ./libft/ -lft && ./a.out "./import/sample_0.fillit"
int main(int num, char **arg) {
	t_puzzle *pzl_list;
	t_block checker_block;
	t_tetro *tetro;
	t_pair pair;
	int *inc;

	inc[0] = 0;
	pzl_list = NULL;
	tetro = NULL;
	pair.a = '#';
	pair.b = '.';

	if(num > 0) {
		int fd = open(arg[1], O_RDONLY);
		build(fd, &checker_block, &tetro, &pair);
	}
	tetro_clean_and_format(&tetro);
	// tetro_clean_and_format(tetro);

	// print_info_is = 1;
	print_all_tetro(tetro, 0);
	
	if(puzzle(&pzl_list, tetro, &pair, inc)) {
		puzzle_list_print(pzl_list);
	} else {
		printf("\nNO SOLUTION TRY AGAIN LOOSER\n");
	}

	free_puzzle_list(&pzl_list);
	free_tetro_list(&tetro);
	free_block(&checker_block);
	return (0);
}