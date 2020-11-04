#ifndef __tetro_h__
#define __tetro_h__

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "get_next_line.h"
#include "vec.h"


typedef struct s_pair t_pair;
struct s_pair {
	int id;
	char a;
	char b;
	t_pair *next;
};

typedef struct s_line t_line;
struct s_line {
	int id;
	char *content;
	size_t length;

	t_pair pair;

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

	t_line *p_line;

	t_ivec2 offset;

	int row;
	int row_max;
	int col;
	int col_max;
	
	int brick;
	int brick_max;
};



typedef struct s_puzzle t_puzzle;
struct s_puzzle {
	char blank;
	int id;
	int brick;
	int space;
	int tetro_num;
	int tetro_used;

	t_ivec3 size;

	t_line *line;
	t_puzzle *next;
};


typedef struct s_tetro t_tetro;
struct s_tetro {
	int id;
	char name;
	t_ivec2 offset;
	t_ivec2 size;
	t_ivec2 canvas;
	t_ivec2 start;
	t_ivec2 end;

	t_line *line;
	t_tetro *next;
};


typedef struct s_try t_try;
struct  s_try {
	char name;
	t_ivec2 index;
	t_ivec2 offset;
	int num;
	int max;
	int put;
};

// try
t_try *new_try();
void try_print(t_try *try);
void set_try(t_try *try, t_ivec3 size_pzl, t_tetro *t);
void update_try(t_try *try);

// utils
int sqrt_ceil(float value);
char	*strcpy_from_to(const char *src, int start, int end);
// free
void free_puzzle(t_puzzle *pzl);
void free_block(t_block *blk);

void free_tetro(t_tetro *tetro);
void free_tetro_list(t_tetro **ref);

void free_line(t_line *line);
void free_line_list(t_line **ref);


// line
t_line *get_t_line(t_line *ln, int index);
int copy_t_line_at(t_line *dst, const t_line *src, int index);
void copy_t_line(t_line *dst, const t_line *src);
int malloc_line(char **ref, size_t len);
int fill_line(char **ref, char c, size_t len);
int fill_t_line(t_line **ref, char c, size_t len);
void reverse_t_line(t_line **ref);
int add_t_line(t_line **ref, int rank, t_line *t_ln);
int line_init(t_line *temp_line);
void line_set_arguments(t_line *temp_line);
int all_lines_dup(t_line **ref, t_line *src);


// block
void block_set_arguments(t_block *temp_block);
int block_init(t_block *temp_block);

// checker
void checker_line_set(t_line *temp_line, char *line);
void checker_line(t_line *temp_line, char *line);
void checker_block_set(t_block *t_blk, t_line *t_ln, char *line);
void checker_compare_lines(t_block *temp_block, t_line *temp_line);
// tetro
t_tetro *tetro_dup(t_tetro **ref);
t_tetro *get_t_tetro(t_tetro *t, int index);
void tetro_init(t_tetro *t);
void build_dict_tetrominos(t_block *t_blk , t_tetro **ref_tetro, t_line **ref_tl, int length);
int size_t_tetro(t_tetro *tetro);
void tetro_print(t_tetro *t, int print_info_is);
void print_all_tetro(t_tetro *t, int print_info_is);
void tetro_clean_and_format(t_tetro *t);
// puzzle
void puzzle_init(t_puzzle *pzl);
int puzzle(t_tetro *t, int print_info_is);
void puzzle_print(t_puzzle *pzl, int print_info_is);
void copy_t_puzzle_struct(t_puzzle *dst, t_puzzle *src);

#endif