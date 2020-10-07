#include "../includes/tetro.h"

void puzzle_line_solve(t_line *ln) {
	while(ln) {
		printf("str: %s\n",ln->content);
		ln = ln->next;
  }
}

void puzzle(t_tetro *t) {
  printf("PRINT PUZZLE\n");
  while(t) {
    printf("\nnext piece to solve puzzle\n");
    puzzle_line_solve(t->tetro_line);

    t = t->next;
  }
}