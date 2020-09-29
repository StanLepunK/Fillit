#include "tetro.h"


void tetro_line_dup(t_tetro_line *src, t_tetro_line *dst) {
  while(src) {
		// dst->str = strdup(src->str);
		add_tetro_line(&dst, src->str);
		// printf("tetro_line_dup() from strdup()%s\n",dst->str);
    
		src = src->next;
		// dst = dst->next;
	}
}


int add_tetro(t_tetro **ref, t_tetro_line *tetro_line) {
	t_tetro *temp;
	if(!(temp = (t_tetro*)malloc(sizeof(t_tetro))))
		return (0);
		// can work try to pass a pointer to char *str
	temp->tetro_line = tetro_line; // objectif / goal




	// tetro_line_dup(tetro_line, &temp->tetro_line); // cause seg fault
	// while(tetro_line) {
	// 	// add_tetro_line(&temp->tetro_line, tetro_line->str);
	// 	tetro_line->next;
	// }
//	printf("tetro line is duplicate\n");
  // swap part
	temp->next = (*ref);
  (*ref) = temp;
	return(1);
}


void print_tetro(t_tetro *tetro) {
  while(tetro) {
		printf("O print_tetro()\n");
    print_tetro_line(tetro->tetro_line);
		// printf("1 print_tetro()\n");
		tetro = tetro->next;
		// printf("2 print_tetro()\n");
  }
}