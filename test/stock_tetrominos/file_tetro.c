#include "tetro.h"


int tetro_dup(t_tetro_line **ref, t_tetro_line *src) {
	int rank = 0;
	int ret = 0;
  while(src) {
		ret = add_tetro_line(ref, src->str, rank);
		if(!ret)
			break;
		rank++;
		src = src->next;
	}
	return(ret);
}


int add_tetro(t_tetro **ref, t_tetro_line *tetro_line) {
	t_tetro *temp;
	int ret = 0;
	temp = NULL;
	if(!(temp = (t_tetro*)malloc(sizeof(t_tetro))))
		return (0);
	temp->tetro_line = NULL;
	ret = tetro_dup(&temp->tetro_line, tetro_line); // cause seg fault
	// add_tetro_line(&temp_tetro->tetro_line, tetro_line->str);
	temp->next = (*ref);
  (*ref) = temp;
	return(ret);
}


void print_tetro(t_tetro *tetro) {
  while(tetro) {
		printf("print_tetro()\n");
    print_tetro_line(tetro->tetro_line);
		// printf("1 print_tetro()\n");
		// printf("print_tetro() adress tetro %p\n", tetro);
		tetro = tetro->next;
		if(tetro == NULL) 
			printf("print_tetro() NULL\n");
		// printf("print_tetro() adress tetro->next %p\n", tetro);
  }
}