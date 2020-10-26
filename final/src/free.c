#include "../includes/tetro.h"


void free_tetro(t_tetro *tetro) {
  while(tetro->line) {
    free(tetro->line);
    tetro->line = tetro->line->next;
  }
  free(tetro);
}


void free_puzzle(t_puzzle *pzl) {
  while(pzl->line) {
    free(pzl->line);
    pzl->line = pzl->line->next;
  }
  free(pzl);
}

void free_line(t_line *ln) {
  free(ln->content);
}

void free_block(t_block *blk) {
  free(blk->p_line.content);
}