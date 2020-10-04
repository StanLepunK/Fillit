#include "../header/tetro.h"

int tetro_add_line(t_line **ref, int rank, t_line *t_ln) {
	t_line *temp;
	temp = NULL;
	if(!(temp = (t_line*)malloc(sizeof(t_line))))
		return (0);
	temp->id = rank;
	temp->content = ft_strdup(t_ln->content);
	temp->empty = t_ln->empty;
	temp->offset = t_ln->offset;
	temp->next = (*ref);
	(*ref) = temp;
	return(1);
}

int tetro_line_dup(t_line **ref, t_line *src) {
	int rank = 0;
	int ret = 0;
  while(src) {
		ret = tetro_add_line(ref, rank, src);
		if(!ret)
			break;
		rank++;
		src = src->next;
	}
	return(ret);
}

int tetro_add(t_tetro **ref, t_line *tl) {
	t_tetro *temp;
	int ret = 0;
	temp = NULL;
	if(!(temp = (t_tetro*)malloc(sizeof(t_tetro))))
		return (0);
	temp->tetro_line = NULL;
	temp->offset_x = 0;
	temp->offset_y = 0;
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
      printf("str: %s, empty: %i, offset: %i\n",t->tetro_line->content, t->tetro_line->empty, t->tetro_line->offset);
      t->tetro_line = t->tetro_line->next;
    }
    t = t->next;
  }
}

void tetro_clear_line(t_line **ref) {
  t_line *current = *ref;
  t_line *next;
  while(current) {
    next = current->next;
    free(current->content);
    free(current);
    current = next;
  }
  *ref = NULL;
}