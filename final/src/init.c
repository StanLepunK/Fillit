#include "../includes/tetro.h"
// puzzle
void puzzle_init(t_puzzle *pzl) {
  pzl->id = 0;
  pzl->line = NULL;
  ivec3_init(&pzl->size);
  pzl->brick = 0;
  pzl->space = 0;
  pzl->tetro_num = 0;
  pzl->tetro_used = 0;
}

// tetro
void tetro_init(t_tetro *t) {
  t->id = 0;
  t->name = 0;
  t->line = NULL;
  ivec2_init(&t->canvas);
  ivec2_init(&t->size);
  ivec2_init(&t->offset);
  ivec2_init(&t->start);
  t->start.set(&t->start,-1,-1);
  ivec2_init(&t->end);
  t->end.set(&t->end,-1,-1);
}

// line
void checker_line_set_arguments(t_line *ln) {
  ln->state = 0;
  ln->valid = 0;
  ln->empty = 1;
  ln->offset = 0;
  ln->a = '#';
	ln->b = '.';
  ln->threshold = 3; // can be used like a failed
  ln->brick = 0;
  ln->col_max = 4;
  ln->space = ln->col_max;
}

int checker_line_init(t_line *ln) {
  checker_line_set_arguments(ln);
  if (!(ln->content = (char*)malloc(sizeof(char) *ln->col_max)))
		return (0);
  return(1);
}

// block
void checker_block_set_arguments(t_block *blk) {
  ivec2_init(&blk->offset);
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
