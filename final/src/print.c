#include "../includes/tetro.h"


void puzzle_print(t_puzzle *pzl) {
  printf("\nPUZZLE\n");
  while(pzl->line) {
    printf("%s\n",pzl->line->content);
    pzl->line = pzl->line->next;
  }
}