#include "../includes/tetro.h"


void puzzle_print(t_puzzle *pzl, int print_info_is) {
  int index;

  if(print_info_is)
    printf("\nPUZZLE build with %i on %i pieces\n",  pzl->tetro_used, pzl->tetro_num);

  index = 0;
  while(index < pzl->size.y) {
    printf("%s\n",get_t_line(pzl->line,index)->content);
    index++;
  }
}