#include "../header/checker.h"
// line
void checker_line_set_arguments(t_line *ln) {
  ln->state = 0;
  ln->valid = 0;
  ln->a = '#';
	ln->b = '.';
  ln->threshold = 3; // can be used like a failed
  ln->brick = 0;
  ln->col_max = 4;
}

int checker_line_init(t_line *ln) {
  checker_line_set_arguments(ln);
  if (!(ln->content = (char*)malloc(sizeof(char) *ln->col_max)))
		return (0);
  return(1);
}

// block
void checker_block_set_arguments(t_block *blk) {
  blk->valid = 0;
  blk->ready_to_add = 0;
  blk->row = 0;
	blk->brick = 0;
  blk->brick_max = 4;
	blk->row_max = 4;
	blk->col_max = 4;
}

int checker_block_init(t_block *blk) {
  checker_block_set_arguments(blk);
  if (!(blk->p_line.content = (char*)malloc(sizeof(char) *blk->col_max)))
		return (0);
  return(1);
}