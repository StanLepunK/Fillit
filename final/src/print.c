#include "../includes/tetro.h"


void puzzle_print(t_puzzle *pzl) {
  printf("\nPUZZLE\n");
  while(pzl->tetro_line) {
    printf("%s\n",pzl->tetro_line->content);
    pzl->tetro_line = pzl->tetro_line->next;
  }
}