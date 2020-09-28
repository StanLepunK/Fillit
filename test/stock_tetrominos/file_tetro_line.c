#include "tetro.h"



int add_tetro_line(t_tetro_line **ref, char *str) {
	t_tetro_line *temp;
	if(!(temp = (t_tetro_line*)malloc(sizeof(t_tetro_line))))
		return (0);
	// temp->str = str; // may be strdup here
	temp->str = strdup(str);
  // swap part
	temp->next = (*ref);
  (*ref) = temp;
	return(1);
}

void print_tetro_line(t_tetro_line *tetro_line) {
	while(tetro_line) {
		printf("str: %s\n",tetro_line->str);
		// printf("0 print_tetro_line()\n");
		tetro_line = tetro_line->next;
		// printf("1 print_tetro_line()\n");
	}
}