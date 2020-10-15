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
	int space;
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

	ivec2 offset;

	int row;
	int row_max;
	int col;
	int col_max;
	
	int brick;
	int brick_max;
};



typedef struct s_puzzle t_puzzle;
struct s_puzzle {
	int id;
	int brick;
	int space;

	ivec2 size;

	t_line *tetro_line;
	t_puzzle *next;

};

typedef struct s_tetro t_tetro;
struct s_tetro {
	int id;
	char name;
	ivec2 offset;
	ivec2 size;
	ivec2 canvas;
	ivec2 start;
	ivec2 end;

	t_line *tetro_line;
	t_tetro *next;
};


// utils
int fill_line(char **ref, char c, size_t len);
int fill_t_line(t_line **ref, char c, size_t len);
void reverse_t_line(t_line **ref);
int add_t_line(t_line **ref, int rank, t_line *t_ln);
char	*strcpy_from_to(const char *src, int start, int end);
void copy_t_line_struct(t_line *dst, const t_line *src);
void copy_t_puzzle_struct(t_puzzle *dst, t_puzzle *src);
// checker
void checker_block_set(t_block *t_blk, t_line *t_ln, char *line);
void checker_line_set_arguments(t_line *temp_line);
int checker_line_init(t_line *temp_line);
void checker_line_set(t_line *temp_line, char *line);
void checker_line(t_line *temp_line, char *line);
void checker_block_set_arguments(t_block *temp_block);
int checker_block_init(t_block *temp_block);
void checker_compare_lines(t_block *temp_block, t_line *temp_line);
// tetro
void tetro_init(t_tetro *t);
void build_dict_tetrominos(t_block *t_blk , t_tetro **ref_tetro, t_line **ref_tl, int length);
int tetro_line_dup(t_line **ref, t_line *src);
void tetro_line_free(t_line **ref);
void tetro_print(t_tetro *t, int print_info_is);
void tetro_clean_and_format(t_tetro *t, int print_info_is);
// puzzle
void puzzle_init(t_puzzle *pzl);
int puzzle(t_tetro *t, int print_info_is);
void puzzle_print(t_puzzle *pzl);

#endif