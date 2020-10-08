#include "../includes/tetro.h"

void add_line_puzzle() {

}
void add_to_puzzle(t_line *ln_dst, t_line *ln_src, ivec2 offset) {
  // t_puzzle *temp = (*ref_pzl);
  printf("offset: %i, %i\n",offset.x, offset.y);
	while(ln_src) {
		printf("str: %s\n",ln_src->content);
		ln_src = ln_src->next;
  }
  // (*ref_pzl) = temp;
}


void puzzle_line_solve(t_puzzle **ref_pzl, t_tetro *t) {
  t_puzzle *temp = (*ref_pzl);
  printf("offset: %i, %i\n",t->offset.x, t->offset.y);
  int iter = t->offset.y;
  // add_to_puzzle(temp->tetro_line, t->tetro_line, t->offset);
	while(iter < t->size.y + t->offset.y) {
		printf("str: %s\n",t->tetro_line->content);
		t->tetro_line = t->tetro_line->next;
    iter++;
  }
  (*ref_pzl) = temp;
}

int puzzle(t_tetro *t) {
  printf("PRINT PUZZLE\n");
  t_puzzle *pzl;
  pzl = NULL;
  if(!(pzl = (t_puzzle*)malloc(sizeof(t_puzzle))))
		return (0);

  while(t) {
    printf("\nnext piece to solve puzzle\n");
    puzzle_line_solve(&pzl, t);

    t = t->next;
  }
  return (1);
}