/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <stan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 12:08:29 by smarcais          #+#    #+#             */
/*   Updated: 2020/11/06 17:21:39 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../includes/get_next_line.h"
#include "libft.h"
#include "../includes/tetro.h"

int builder(const int fd, t_block *t_blk, t_tetro **ref_tetro, t_pair *pair) {
	char *line;
  t_line *buffer;
	t_line *tl;
	t_tetro *temp_tetro;

	temp_tetro = (*ref_tetro);
	tl = NULL;
	buffer = NULL;
  if (!(buffer = (t_line*)malloc(sizeof(t_line))))
    return(0);
  line_init(buffer, pair);
	block_init(t_blk);
	while (get_next_line(fd, &line) > 0) {
		build_dict_tetrominos(t_blk, &temp_tetro, &tl, ft_strlen(line));
		checker_line_set(buffer, line);
		checker_block_set(t_blk, buffer, line);
		if(buffer->valid) {
			add_t_line(&tl, t_blk->row, buffer);
			// free(t_blk->p_line->content);
		} else {
			free_line_list(&tl);
			// free(t_blk->p_line->content);
		}
		free(line);
	}
	get_next_line(fd, &line);
	free_line(buffer);
	free(line);
	close(fd);
	(*ref_tetro) = temp_tetro;
	return (1);
}
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

	pzl_list = NULL;
	tetro = NULL;
	int print_info_is = 0;
	pair.a = '#';
	pair.b = '.';

	if(num > 0) {
		int fd = open(arg[1], O_RDONLY);
		builder(fd, &checker_block, &tetro, &pair);
	}
	tetro_clean_and_format(tetro);

	// print_info_is = 1;
	print_all_tetro(tetro, print_info_is);
	
	if(puzzle(&pzl_list, tetro, &pair)) {
		puzzle_list_print(pzl_list);
	} else {
		printf("\nNO SOLUTION TRY AGAIN LOOSER\n");
	}

	free_puzzle_list(&pzl_list);
	free_tetro_list(&tetro);
	free_block(&checker_block);
	return (0);
}