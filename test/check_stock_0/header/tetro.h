#ifndef __tetro_h__
#define __tetro_h__

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

typedef struct s_tetro_line t_tetro_line;
struct s_tetro_line {
	char *str;
	int id;
	t_tetro_line *next;
};

typedef struct s_tetro t_tetro;
struct s_tetro {
	t_tetro_line *tetro_line;
	t_tetro *next;
};


int tetro_add_line(t_tetro_line **ref, int rank, char *str);
int tetro_line_dup(t_tetro_line **ref, t_tetro_line *src);
int tetro_add(t_tetro **ref, t_tetro_line *src);
void tetro_clear_line(t_tetro_line **ref);
void tetro_print(t_tetro *t);

#endif