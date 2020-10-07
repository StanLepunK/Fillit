#include "../includes/tetro.h"

int tetro_add_line(t_line **ref, int rank, t_line *t_ln) {
	t_line *temp;
	temp = NULL;
	if(!(temp = (t_line*)malloc(sizeof(t_line))))
		return (0);
	temp->id = rank;
	temp->content = ft_strdup(t_ln->content);
	temp->empty = t_ln->empty;
	temp->offset = t_ln->offset;
	temp->brick = t_ln->brick;
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
	temp->offset.x = 0;
	temp->offset.y = 0;
	ret = tetro_line_dup(&temp->tetro_line, tl);
	temp->next = (*ref);
  (*ref) = temp;
	return(ret);
}


void tetro_line_free(t_line **ref) {
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



void tetro_line_print(t_line *ln) {
	while(ln) {
		printf("str: %s\n",ln->content);
		ln = ln->next;
  }
}

void tetro_print(t_tetro *t) {
  printf("PRINT ALL TETROMINOS\n");
  while(t) {
    printf("\nprint next tetromino\n");
		tetro_line_print(t->tetro_line);
		printf("name: %c \n",t->name);
		printf("id: %i \n",t->id);
		printf("offset x: %i \n",t->offset.x);
		printf("offset y: %i \n",t->offset.y);
		printf("size x: %i \n",t->size.x);
		printf("size y: %i \n",t->size.y);
    t = t->next;
  }
}


void tetro_line_clean(t_tetro *t, t_line *ln) {
	int lock_x;
	int lock_y;

	lock_x = 0;
	lock_y = 0;
	while(ln) {
		if(!ln->empty) {
			t->size.y++;
			lock_y = 1;
		}
		if(ln->empty && !lock_y) {
			t->offset.y++;
		}
		if(t->offset.x <= ln->offset && !lock_x) {
			t->offset.x = ln->offset;
			lock_x = 1;
		} else if(ln->offset < t->offset.x) {
			t->offset.x = ln->offset;
		}
		if(ln->brick > t->size.x) {
			t->size.x = ln->brick;
		}
		ln = ln->next;
	}
}

void tetro_clean_and_format(t_tetro *t) {
  printf("CLEAN and FORMAT TETROMINOS\n");
	t_line tl;
	char name;
	int id;

	name = 'A';
	id = 0;
	checker_line_set_arguments(&tl);
  while(t) {
    printf("cleaning and formating next tetromino\n");
		tetro_line_clean(t, t->tetro_line);
		t->name = (name++);
		t->id = (id++);
    t = t->next;
  }
}