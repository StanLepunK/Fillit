/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <stan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 12:08:29 by smarcais          #+#    #+#             */
/*   Updated: 2020/09/23 18:21:07 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"
#include "libft.h"
#include "block.h"


// clang src/*.c *.h -I ./ -I./libft -L ./libft/ -lft && ./a.out "./import/sample.fillit"
int main(int num, char **arg) {
	t_block temp_block;
	if(num > 0) {
		int fd = open(arg[1], O_RDONLY);
		checker(fd, &temp_block);
	}	
	return (0);
}