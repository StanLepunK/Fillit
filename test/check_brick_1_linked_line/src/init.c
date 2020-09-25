#include "block.h"

int line_init(t_line *temp_line) {
  temp_line->state = 0;
  temp_line->valid = 0;
  temp_line->a = '#';
	temp_line->b = '.';
  temp_line->threshold = 3; // can be used like a failed
  temp_line->col_max = 4;
  // ft_bzero(temp_line->content, temp_line->col_max); // cause a
  if (!(temp_line->content = (char*)malloc(sizeof(char) *temp_line->col_max)))
		return (0);
  return(1);
}


int block_init(t_block *temp_block) {
	temp_block->line = NULL;

	temp_block->row = 0;
	temp_block->brick = 0;
  temp_block->brick_max = 4;
	temp_block->row_max = 4;
	temp_block->col_max = 4;


  if (!(temp_block->previous_line = (char*)malloc(sizeof(char) *temp_block->col_max)))
		return (0);
  return(1);
}