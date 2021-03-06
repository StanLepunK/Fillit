#include "../includes/tetro.h"
/**
 * color text in consol helper
 * http://web.theurbanpenguin.com/adding-color-to-your-output-from-c/
 * https://www.mudhalla.net/tintin/info/ansicolor/
 * 
 * 033[1;33m to enable
 * 033[0m to disable
 * 
 * [0... normal
 * [1... bold
 * [3... italic
 * [4... underline
 * [7... reverse background
 * 
 * [...30m black
 * [...31m red
 * [...32m green
 * [...33m yellow
 * [...34m blue
 * [...35m purple
 * [...36m cyan
 * [...37m white
*/
void try_print(t_try *try) {
  printf("\033[1;36mname: %c try: %i / %i\033[0m\n", try->name, try->num, try->max);
  printf("index: %i %i\n", try->index.x, try->index.y);
  printf("offset: %i %i\n", try->offset.x, try->offset.y);
}


void puzzle_list_print(t_puzzle *list) {
  while(list) {
    puzzle_print(list);
    // puzzle_print(&list);
    list = list->next;
  }
}

void puzzle_print_info (t_puzzle *pzl) {
  puzzle_analyze(pzl);
  printf("\nPUZZLE INFO");
  printf("\n\033[1;36mBuild with %i on %i pieces\033[0m\n",  pzl->tetro_used, pzl->tetro_num);
  printf("Start tetro pos: %i, %i\n", pzl->start_pos.x, pzl->start_pos.y);
  printf("Last tetro pos: %i, %i\n", pzl->last_pos.x, pzl->last_pos.y);
  printf("offset: %i, %i\n", pzl->offset.x, pzl->offset.y);
  printf("Size: %ix%i\n", pzl->size.x, pzl->size.y);
  printf("Brick used: %i\n", pzl->brick);
  printf("Space available: %i\n", pzl->space);
  printf("Space total: %i\n", pzl->size.x * pzl->size.y);
  printf("score: %i\n", pzl->score);
}

void puzzle_print(t_puzzle *pzl) {
  int index;

  index = 0;
  printf("\033[1;33mPUZZLE PRINT %i\033[0m\n", pzl->id);
  finalize_puzzle(&pzl);
  printf("\033[3;36mSCORE: %i\033[0m\n",pzl->score);
  while(index < pzl->size.y) {
    printf("%s\n",get_t_line(pzl->line,index)->content);
    index++;
  }
}




void print_all_tetro(t_tetro *t, int print_info_is) {
	printf("PRINT ALL TETROMINOS\n");
  while(t) {
    printf("\nprint tetromino %c\n", t->name);
		tetro_print(t, print_info_is);
    t = t->next;
  }
}


void tetro_line_print(t_line *ln) {
	while(ln) {
		printf("str: %s\n",ln->content);
		ln = ln->next;
  }
}

void tetro_print(t_tetro *t, int print_info_is) {
  if(print_info_is) {
		printf("\033[1;36mTETRO: %c\033[0m\n",t->name);
  }
	tetro_line_print(t->line);
	if(print_info_is) {
		printf("id: %i \n",t->id);
		printf("offset: %i %i\n",t->offset.x, t->offset.y);
		printf("size: %i %i\n",t->size.x, t->size.y);
    printf("pos: %i %i\n",t->pos.x, t->pos.y);
		printf("start.x: %i\n", t->start.x);
		printf("end.x: %i\n", t->end.x);
	}
}