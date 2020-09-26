#ifndef __block_h__
#define __block_h__


#include "libft.h"
#include "get_next_line.h"
#include <stdio.h>



typedef struct s_line t_line;
struct s_line {
	int id;
	char *content;
	size_t length;

	char a;
	char b;

	int valid;
	int state;
	int threshold;

	int brick;
	int col;
	int col_max;
};

typedef struct s_block t_block;
struct s_block {
  int id;

	t_line *p_line;

	int row;
	int row_max;
	int col;
	int col_max;
	
	int brick;
	int brick_max;
};


int checker(const int fd, t_block *temp_block);

void line_set_arguments(t_line *temp_line);
int line_init(t_line *temp_line);
void line_set(t_line *temp_line, char *line);
void line_check(t_line *temp_line, char *line);

void block_set_arguments(t_block *temp_block);
int block_init(t_block *temp_block);
void block_set(t_block *temp_block, t_line *temp_line, char *line);

void compare_lines(t_block *temp_block, t_line *temp_line);

#endif