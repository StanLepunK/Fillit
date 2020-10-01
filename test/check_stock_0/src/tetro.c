#include "../header/tetro.h"

int tetro_add_line(t_tetro_line **ref, int rank, char *str) {
	t_tetro_line *temp;
	temp = NULL;
	if(!(temp = (t_tetro_line*)malloc(sizeof(t_tetro_line))))
		return (0);
	temp->id = rank;
	temp->str = ft_strdup(str);
	temp->next = (*ref);
	(*ref) = temp;
	return(1);
}

int tetro_line_dup(t_tetro_line **ref, t_tetro_line *src) {
	int rank = 0;
	int ret = 0;
  while(src) {
		ret = tetro_add_line(ref, rank, src->str);    
		if(!ret)
			break;
		rank++;
		src = src->next;
	}
	return(ret);
}

int tetro_add(t_tetro **ref, t_tetro_line *tl) {
	t_tetro *temp;
	int ret = 0;
	temp = NULL;
	if(!(temp = (t_tetro*)malloc(sizeof(t_tetro))))
		return (0);
	temp->tetro_line = NULL;
	ret = tetro_line_dup(&temp->tetro_line, tl);
	temp->next = (*ref);
  (*ref) = temp;
  
	return(ret);
}



void tetro_print(t_tetro *t) {
  printf("ALL TETROMINOS\n");
  while(t) {
    printf("next tetromino\n");
    while(t->tetro_line) {
      printf("str: %s\n",t->tetro_line->str);
      t->tetro_line = t->tetro_line->next;
    }
    t = t->next;
  }
}

void tetro_clear_line(t_tetro_line **ref) {
  t_tetro_line *current = *ref;
  t_tetro_line *next;
  while(current) {
    next = current->next;
    free(current->str);
    free(current);
    current = next;
  }
  *ref = NULL;
}