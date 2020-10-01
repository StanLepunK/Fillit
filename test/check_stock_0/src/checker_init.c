#include "../header/checker.h"
// line
void checker_line_set_arguments(t_line *temp_line) {
  temp_line->state = 0;
  temp_line->valid = 0;
  temp_line->a = '#';
	temp_line->b = '.';
  temp_line->threshold = 3; // can be used like a failed
  temp_line->brick = 0;
  temp_line->col_max = 4;
}

int checker_line_init(t_line *temp_line) {
  checker_line_set_arguments(temp_line);
  if (!(temp_line->content = (char*)malloc(sizeof(char) *temp_line->col_max)))
		return (0);
  return(1);
}

// block
void checker_block_set_arguments(t_block *blk) {
  blk->valid = 0;
  blk->row = 0;
	blk->brick = 0;
  blk->brick_max = 4;
	blk->row_max = 4;
	blk->col_max = 4;
}

int checker_block_init(t_block *temp_block) {
  checker_block_set_arguments(temp_block);
  if (!(temp_block->p_line.content = (char*)malloc(sizeof(char) *temp_block->col_max)))
		return (0);
  return(1);
}