#include "../includes/tetro.h"
void free_line(t_line *ln) {
  free(ln);
  free(ln->content);
}


void free_line_list(t_line **ref) {
  t_line *current;
  t_line *next;

	current = *ref;
  while(current) {
    next = current->next;
    free_line(current);
    current = next;
  }
  *ref = NULL;
}


void free_tetro(t_tetro *tetro) {
  free_line_list(&tetro->line);
  free(tetro);
}

void free_tetro_list(t_tetro **ref) {
  t_tetro *current;
  t_tetro *next;

	current = *ref;
  while(current) {
    next = current->next;
    free_tetro(current);
    current = next;
  }
  *ref = NULL;
}


void free_puzzle(t_puzzle *pzl) {
  while(pzl->line) {
    free_line(pzl->line);
    pzl->line = pzl->line->next;
  }
  free(pzl);
}



void free_block(t_block *blk) {
  free(blk->p_line.content);
}