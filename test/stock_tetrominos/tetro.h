#ifndef __tetro_h__
#define __tetro_h__

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_tetro_line t_tetro_line;
struct s_tetro_line {
  char *str;
  t_tetro_line *next;
};

typedef struct s_tetro t_tetro;
struct s_tetro {
  t_tetro_line tetro_line;
  t_tetro *next;
};


int add_tetro(t_tetro **ref, t_tetro_line *tetro_line);
int add_tetro_line(t_tetro_line **ref, char *str);

void print_tetro(t_tetro *tetro);
void print_tetro_line(t_tetro_line *tetro_line);

#endif