#include "block.h"
// line
void line_set_arguments(t_line *temp_line) {
  temp_line->state = 0;
  temp_line->valid = 0;
  temp_line->a = '#';
	temp_line->b = '.';
  temp_line->threshold = 3; // can be used like a failed
  temp_line->brick = 0;
  temp_line->col_max = 4;
}

int line_init(t_line *temp_line) {
  line_set_arguments(temp_line);
  if (!(temp_line->content = (char*)malloc(sizeof(char) *temp_line->col_max)))
		return (0);
  return(1);
}

// block
void block_set_arguments(t_block *temp_block) {
  temp_block->row = 0;
	temp_block->brick = 0;
  temp_block->brick_max = 4;
	temp_block->row_max = 4;
	temp_block->col_max = 4;
}

int block_init(t_block *temp_block) {
  block_set_arguments(temp_block);
  if (!(temp_block->p_line.content = (char*)malloc(sizeof(char) *temp_block->col_max)))
		return (0);
  return(1);
}