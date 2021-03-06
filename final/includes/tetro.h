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
	int score;

	t_ivec3 size;
	t_ivec2 start_pos;
	t_ivec2 last_pos;
	t_ivec2 offset;


	t_line *line;
	t_puzzle *next;
};


typedef struct s_tetro t_tetro;
struct s_tetro {
	int id;
	char name;
	t_ivec2 offset;
	t_ivec2 pos;
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
	int tetro_start;
	int num;
	int max;
};

// new
int new_t_puzzle(t_puzzle **ref_pzl, char blank);
int new_t_try(t_try **ref_try);
int new_t_line(t_line **ref_line, t_pair *pair);
int new_t_line_puzzle(t_line **ref_line, char c, size_t len);
int new_t_block(t_block **ref_blk);
int new_string(char **ref, size_t len);
int new_t_tetro(t_tetro **ref_tetro);


// init
void tetro_init(t_tetro *tetro);



// build
int build(const int fd, t_block **ref_blk, t_tetro **ref_tetro, t_pair *pair);
void checker_line_set(t_line *temp_line, char *line);
void checker_line(t_line *temp_line, char *line);
void checker_block_set(t_block *t_blk, t_line *t_ln, char *line);
void checker_compare_lines(t_block *temp_block, t_line *temp_line);
// block
void block_set_arguments(t_block *temp_block);

// tetro
t_tetro *tetro_dup(t_tetro **ref);
t_tetro *get_t_tetro(t_tetro *t, int index);
void build_dict_tetrominos(t_block *t_blk , t_tetro **ref_tetro, t_line **ref_tl, int length);
void reverse_t_tetro(t_tetro **ref_tetro);
int size_t_tetro(t_tetro *tetro);
void tetro_clean_and_format(t_tetro **ref_tetro);


// try
void try_print(t_try *try);
void set_try(t_try *try, t_puzzle *pzl, t_tetro *t);
void update_try(t_try *try);
void update_try(t_try *try);

// line
t_line *get_t_line(t_line *ln, int index);
void copy_t_line(t_line *dst, const t_line *src);
int fill_line(char **ref_string, char c, size_t len);
void reverse_t_line(t_line **ref_line);
int add_t_line(t_line **ref_line, int rank, t_line *t_ln);
void line_set_arguments(t_line *line, t_pair *pair);
int all_lines_dup(t_line **ref_line, t_line *src);


// puzzle
void finalize_puzzle(t_puzzle **ref_pzl);
void copy_t_puzzle(t_puzzle *dst, t_puzzle *src);
int add_t_puzzle(t_puzzle **ref_dst, t_puzzle *src);
int size_t_puzzle(t_puzzle *pzl);
void clear_puzzle(t_puzzle **ref_pzl, t_tetro *t);
void puzzle_analyze(t_puzzle *pzl);
void set_grid_size(t_puzzle *pzl, t_tetro *tetro, int *inc);
int build_grid_puzzle(t_puzzle **ref_pzl, t_tetro *tetro, int *inc);
t_puzzle *puzzle_dup(t_puzzle **ref_pzl);
// puzzle calc
int puzzle(t_puzzle **ref_pzl, t_tetro *tetro, t_pair *pair, int *inc);





// utils
int sqrt_ceil(float value);
// free
void free_puzzle(t_puzzle *pzl);;
void free_puzzle_list(t_puzzle **ref_pzl_list);
void free_block(t_block *blk);
void free_tetro(t_tetro *tetro);
void free_tetro_list(t_tetro **ref_tetro);
void free_line(t_line *line);
void free_line_list(t_line **ref_line);

// print
void puzzle_print(t_puzzle *pzl);
void puzzle_print_info(t_puzzle *pzl);
void puzzle_list_print(t_puzzle *list);
void tetro_print(t_tetro *tetro, int print_info_is);
void print_all_tetro(t_tetro *tetro, int print_info_is);

#endif