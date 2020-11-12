#include "../includes/tetro.h"
int COUNT_FREE;
int COUNT_FREE_LIST;


void free_line(t_line *ln) {
  free(ln);
  free(ln->content);
  COUNT_FREE++;
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
  COUNT_FREE_LIST++;
}


void free_tetro(t_tetro *tetro) {
  free_line_list(&tetro->line);
  free(tetro);
  COUNT_FREE++;
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
  COUNT_FREE_LIST++;
}


void free_puzzle(t_puzzle *pzl) {
  while(pzl->line) {
    free_line(pzl->line);
    pzl->line = pzl->line->next;
  }
  free(pzl);
  COUNT_FREE++;
}

void free_puzzle_list(t_puzzle **ref_pzl_list) {
  while((*ref_pzl_list)) {
    free_puzzle((*ref_pzl_list));
    (*ref_pzl_list) = (*ref_pzl_list)->next;
  }
  COUNT_FREE_LIST++;
}


void free_block(t_block *blk) {
  free(blk);
  free_line(blk->p_line);
  COUNT_FREE++;
}