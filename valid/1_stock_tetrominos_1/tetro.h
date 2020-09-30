#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_tetro_line t_tetro_line;
struct s_tetro_line {
	char *str;
	int id;
	t_tetro_line *next;
};

typedef struct s_tetro t_tetro;
struct s_tetro {
	t_tetro_line *tetro_line;
	t_tetro *next;
};


int add_tetro_line(t_tetro_line **ref, int rank, char *str);
int dup(t_tetro_line **ref, t_tetro_line *src);
int add_tetro(t_tetro **ref, t_tetro_line *src);