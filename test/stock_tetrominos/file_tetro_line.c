#include "tetro.h"



int add_tetro_line(t_tetro_line **ref, char *str, int rank) {
	t_tetro_line *temp;
	temp = NULL;
	if(!(temp = (t_tetro_line*)malloc(sizeof(t_tetro_line))))
		return (0);
	// temp_line->str = strdup(str);
	temp->id = rank;
	temp->next = (*ref);
  (*ref) = temp;
	return(1);
}

void print_tetro_line(t_tetro_line *tetro_line) {
	while(tetro_line) {
		// printf("str: %s\n",tetro_line->str);
		printf("id: %i\n",tetro_line->id);
		tetro_line = tetro_line->next;
		printf("print_tetro_line() tetro_line->next %p\n", tetro_line);
		// printf("after str: %s\n",tetro_line->str);
		if(tetro_line->str == NULL) 
			printf("print_tetro_line() tetro_line->str NULL\n");
		if(tetro_line == NULL) 
			printf("print_tetro_line() NULL\n");
	}
	// printf("print_tetro_line() out of while\n");
}