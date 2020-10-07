#ifndef __tetro_h__
#define __tetro_h__

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "get_next_line.h"

typedef struct s_ivec2 ivec2;
struct  s_ivec2 {
	int x;
	int y;
	ivec2 *next;
};


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

typedef struct s_puzzle t_puzzle;
struct s_puzzle {
	t_line *tetro_line;
	t_puzzle *next;

};

typedef struct s_block t_block;
struct s_block {
  int id;
	int valid;
	int ready_to_add;

	t_line p_line;

	ivec2 offset;

	int row;
	int row_max;
	int col;
	int col_max;
	
	int brick;
	int brick_max;
};


typedef struct s_tetro t_tetro;
struct s_tetro {
	int id;
	char name;
	ivec2 offset;
	ivec2 size;

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
void tetro_line_free(t_line **ref);
void tetro_print(t_tetro *t);
void tetro_clean_and_format(t_tetro *t);

void puzzle(t_tetro *t);

#endif