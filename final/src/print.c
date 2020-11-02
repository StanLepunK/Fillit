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



void tetro_line_print(t_line *ln) {
	while(ln) {
		printf("str: %s\n",ln->content);
		ln = ln->next;
  }
}

void tetro_print(t_tetro *t, int print_info_is) {
  // int index;

  // index = 0;
  // while(index < t->canvas.y) {
  //   printf("%s\n",get_t_line(t->line,index)->content);
  //   index++;
  // }
	tetro_line_print(t->line);
	if(print_info_is) {
		printf("name: %c \n",t->name);
		printf("id: %i \n",t->id);
		printf("offset x: %i \n",t->offset.x);
		printf("offset y: %i \n",t->offset.y);
		printf("size x: %i \n",t->size.x);
		printf("size y: %i \n",t->size.y);
		printf("start.x: %i\n", t->start.x);
		printf("end.x: %i\n", t->end.x);
	}
}