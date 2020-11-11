#include "../includes/tetro.h"

// tetro
void tetro_init(t_tetro *tetro) {
  tetro->id = 0;
  tetro->name = 0;
  tetro->line = NULL;
  ivec2_init(&tetro->canvas);
  ivec2_init(&tetro->size);
  ivec2_init(&tetro->pos);
  ivec2_init(&tetro->offset);
  ivec2_init(&tetro->start);
  ivec2_init(&tetro->end);
  tetro->pos.set(&tetro->pos,-1,-1);
  tetro->start.set(&tetro->start,-1,-1);
  tetro->end.set(&tetro->end,-1,-1);
}

// line
void line_set_arguments(t_line *ln, t_pair *pair) {
  ln->state = 0;
  ln->valid = 0;
  ln->empty = 1;
  ln->offset = 0;
  ln->pair.a = pair->a;
	ln->pair.b = pair->b;
  ln->threshold = 3; // can be used like a failed
  ln->brick = 0;
  ln->col_max = 4;
  ln->space = ln->col_max;
}



// block
void block_set_arguments(t_block *blk) {
  ivec2_init(&blk->offset);
  blk->valid = 0;
  blk->ready_to_add = 0;
  blk->row = 0;
	blk->brick = 0;
  blk->brick_max = 4;
	blk->row_max = 4;
	blk->col_max = 4;
}


