#include "../includes/tetro.h"


void puzzle_print(t_puzzle *pzl) {
  printf("\nPUZZLE build with %i on %i pieces\n",  pzl->tetro_used, pzl->tetro_num);
  while(pzl->line) {
    printf("%s\n",pzl->line->content);
    pzl->line = pzl->line->next;
  }
}