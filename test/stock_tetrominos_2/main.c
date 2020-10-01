#include "tetro.h"

void print_tetro(t_tetro *t) {
	while(t) {
		printf("tetrominos\n");
		while(t->tetro_line) {
			printf("str: %s\n",t->tetro_line->str);
			t->tetro_line = t->tetro_line->next;
		}
		t = t->next;
	}
}

void clear_tetro_line(t_tetro_line **ref) {
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

t_tetro *func_level_0(t_tetro *t) {
	char *str = "truc";
	t_tetro_line *tl;
	tl = NULL;

	for(int i = 0 ; i < 4 ; i++) {
		add_tetro_line(&tl, i, str);
	}
	add_tetro(&t, tl);
	clear_tetro_line(&tl);

	str = "machin";
	for(int i = 0 ; i < 4 ; i++) {
		add_tetro_line(&tl, i, str);
	}
	add_tetro(&t, tl);
	clear_tetro_line(&tl);
	// return the pointer passing
	return (t);
}


int main() {
	t_tetro *t;
	t = NULL;
	t = func_level_0(t);
	print_tetro(t);
	return(0);
}