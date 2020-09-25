#ifndef __block_h__
#define __block_h__


#include "libft.h"
#include "get_next_line.h"
#include <stdio.h>


typedef struct s_line t_line;
struct s_line {
	int id;
	char *content;

	char a;
	char b;

	int valid;
	int state;
	int threshold;

	int col;
	int col_max;

	t_line *next;
};

typedef struct s_block t_block;
struct s_block {
	
	t_line *line; // not used at this time 
	char *previous_line; // maybe must move to t_line ?
  int id;

	int row;
	int row_max;
	int col;
	int col_max;
	
	int brick;
	int brick_max;
};


void checker(const int fd, t_block *temp_block);

int line_init(t_line *temp_line);
void line_check(t_block *temp_block, t_line *temp_line);

int block_init(t_block *temp_block);
void block_set(t_block *temp_block, t_line *temp_line);

void compare_lines(t_block *temp_block, t_line *temp_line);

#endif