/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <stan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 12:08:29 by smarcais          #+#    #+#             */
/*   Updated: 2020/10/26 17:30:07 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../includes/get_next_line.h"
#include "libft.h"
#include "../includes/tetro.h"

// https://github.com/JemCopeCodes/42-Fillit  nice for displacement grid concept
int builder(const int fd, t_block *t_blk, t_tetro **ref_tetro) {
	char *line;
  t_line buffer;
	t_line *tl;
	t_tetro *temp_tetro;

	temp_tetro = (*ref_tetro);
	tl = NULL;
  checker_line_init(&buffer);
	checker_block_init(t_blk);
	while (get_next_line(fd, &line) > 0) {
		build_dict_tetrominos(t_blk, &temp_tetro, &tl, ft_strlen(line));
		checker_line_set(&buffer, line);
		checker_block_set(t_blk, &buffer, line);
		if(buffer.valid) {
			add_t_line(&tl, t_blk->row, &buffer);
		} else {
			tetro_line_free(&tl);
		}
		free(line);
	}
	get_next_line(fd, &line);
	free_line(&buffer);
	free_block(t_blk);
	free(line);
	close(fd);
	(*ref_tetro) = temp_tetro;
	return (1);
}


// clang src/*.c header/*.h -I ./ -I./libft -L ./libft/ -lft && ./a.out "./import/sample_0.fillit"
int main(int num, char **arg) {
	t_block checker_block;
	t_tetro *tetrominos;
	tetrominos = NULL;
	int print_info_is = 0;

	if(num > 0) {
		int fd = open(arg[1], O_RDONLY);
		builder(fd, &checker_block, &tetrominos);
	}
	// print_info_is = 0;
	tetro_clean_and_format(tetrominos, print_info_is);

	// print_info_is = 1;
	print_all_tetro(tetrominos, print_info_is);

	print_info_is = 1;
	puzzle(tetrominos, print_info_is);

	return (0);
}