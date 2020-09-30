#include "tetro.h"

void print_tetro(t_tetro *t) {
  while(t) {
    while(t->tetro_line) {
      printf("str: %s\n",t->tetro_line->str);
      printf("id: %i\n",t->tetro_line->id);
      t->tetro_line = t->tetro_line->next;
      printf("m->tetro_line %p\n", t->tetro_line);
      if(t->tetro_line == NULL) 
        printf("m->tetro_line NULL\n");
    }
    t = t->next;
  }
}

int main() {
	char *str = "truc";
	t_tetro_line *tl;
	tl = NULL;
  t_tetro *t;
	t = NULL;

	for(int i = 0 ; i < 4 ; i++) {
		add_tetro_line(&tl, i, str);
	}
	add_tetro(&t, tl);


  print_tetro(t);
	return(0);
}