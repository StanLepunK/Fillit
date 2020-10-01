#include "tetro.h"

int add_tetro_line(t_tetro_line **ref, int rank, char *str) {
	t_tetro_line *temp;
	temp = NULL;
	if(!(temp = (t_tetro_line*)malloc(sizeof(t_tetro_line))))
		return (0);
	temp->id = rank;
	temp->str = strdup(str);
	temp->next = (*ref);
	(*ref) = temp;
	return(1);
}

int dup(t_tetro_line **ref, t_tetro_line *src) {
	int rank = 0;
	int ret = 0;

  while(src) {
		ret = add_tetro_line(ref, rank, src->str);
		if(!ret)
			break;
		rank++;
		src = src->next;
	}
	return(ret);
}

int add_tetro(t_tetro **ref, t_tetro_line *tl) {
	t_tetro *temp;
	int ret = 0;
	temp = NULL;
	if(!(temp = (t_tetro*)malloc(sizeof(t_tetro))))
		return (0);
	temp->tetro_line = NULL;
	ret = dup(&temp->tetro_line, tl);
	temp->next = (*ref);
  (*ref) = temp;
	return(ret);
}