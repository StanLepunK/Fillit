/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <stan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 12:08:29 by smarcais          #+#    #+#             */
/*   Updated: 2020/10/02 20:18:59 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../header/get_next_line.h"
#include "libft.h"
#include "../header/checker.h"
#include "../header/tetro.h"

// https://github.com/JemCopeCodes/42-Fillit  nice for displacement grid concept


// clang src/*.c header/*.h -I ./ -I./libft -L ./libft/ -lft && ./a.out "./import/sample_0.fillit"
int main(int num, char **arg) {
	t_block checker_block;
	t_tetro *tetrominos;
	tetrominos = NULL;

	if(num > 0) {
		int fd = open(arg[1], O_RDONLY);
		checker(fd, &checker_block, &tetrominos);
	}

	tetro_print(tetrominos);	
	return (0);
}