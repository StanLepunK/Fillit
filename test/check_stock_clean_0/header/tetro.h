#ifndef __tetro_h__
#define __tetro_h__

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "get_next_line.h"


typedef struct s_line t_line;
struct s_line {
	int id;
	char *content;
	size_t length;

	char a;
	char b;

	int empty;
	int offset;

	int valid;
	int state;
	int threshold;

	int brick;
	int col;
	int col_max;
	t_line *next;
};

typedef struct s_block t_block;
struct s_block {
  int id;
	int valid;
	int ready_to_add;

	t_line p_line;

	int offset_x;
	int offset_y;
	int row;
	int row_max;
	int col;
	int col_max;
	
	int brick;
	int brick_max;
};


typedef struct s_tetro t_tetro;
struct s_tetro {
	int offset_x;
	int offset_y;
	t_line *tetro_line;
	t_tetro *next;
};



int checker(const int fd, t_block *temp_block, t_tetro **ref_tetro);
void checker_line_set_arguments(t_line *temp_line);
int checker_line_init(t_line *temp_line);
void checker_line_set(t_line *temp_line, char *line);
void checker_line(t_line *temp_line, char *line);
void checker_block_set_arguments(t_block *temp_block);
int checker_block_init(t_block *temp_block);
void checker_compare_lines(t_block *temp_block, t_line *temp_line);

int tetro_add_line(t_line **ref, int rank, t_line *t_ln);
int tetro_line_dup(t_line **ref, t_line *src);
int tetro_add(t_tetro **ref, t_line *src);
void tetro_clear_line(t_line **ref);
void tetro_print(t_tetro *t);

#endif