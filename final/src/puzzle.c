#include "../includes/tetro.h"

int init_temp_puzzle_line(t_line **ref_ln, int len) {
  t_line *ln = (*ref_ln);
  if (!(ln = (t_line*)malloc(sizeof(t_line))))
    return(0);
  ln->col_max = len;
  if (!(ln->content = (char*)malloc(sizeof(char) *ln->col_max)))
    return (0);
  (*ref_ln) = ln;
  return (1);
}

void brick_switch(char *line, char target_char, char new_char) {
  int index;

  index = 0;
  while(index < ft_strlen(line)) {
    if(line[index] == target_char) {
      line[index] = new_char;
    }
    index++;
  }
}

int add_line_puzzle(t_line **ref, char name, t_line *src) {
	t_line *temp_ln;
	temp_ln = NULL;
	if(!(temp_ln = (t_line*)malloc(sizeof(t_line))))
		return (0);
  copy_t_line_struct(temp_ln, src);
	temp_ln->next = (*ref);
	(*ref) = temp_ln;
	return(1);
}




int puzzle_add(t_puzzle **ref_pzl, t_tetro *t) {
  t_puzzle *temp_pzl = (*ref_pzl);

  printf("\npiece of puzzle: %c\n", t->name);
  int iter_x = 0;
  int iter_y = 0;
	while(iter_y < t->size.y + t->offset.y) {
    if(iter_y >= t->offset.y) {
      t_line *res;
      init_temp_puzzle_line(&res, t->tetro_line->col_max * 26);
      int end = t->size.x + t->offset.x;
      res->content = strcpy_from_to(t->tetro_line->content, t->offset.x, end);
      printf("str format: %s\n",res->content);
      add_line_puzzle(&temp_pzl->tetro_line, t->name, res);
      brick_switch(temp_pzl->tetro_line->content, t->tetro_line->a, t->name);
    }
		t->tetro_line = t->tetro_line->next;
    iter_y++;
  }
  (*ref_pzl) = temp_pzl;
  return (1);
}


void puzzle_print(t_puzzle *pzl) {
  printf("\nPUZZLE\n");
  while(pzl->tetro_line) {
    printf("%s\n",pzl->tetro_line->content);
    pzl->tetro_line = pzl->tetro_line->next;
  }
}


int puzzle(t_tetro *t, int print_info_is) {
  if(print_info_is)
    printf("PRINT PUZZLE\n");
  t_puzzle *pzl;
  pzl = NULL;
  if(!(pzl = (t_puzzle*)malloc(sizeof(t_puzzle))))
		return (0);
  pzl->id = 0;
  pzl->tetro_line = NULL;
  pzl->size.x = 0;
  pzl->size.y = 0;
  
  while(t) {
    if(print_info_is)
      printf("\nnext piece to solve puzzle\n");
    // if(t->size.y > 1 && t->size.y != t->size.x)
    //   reverse_t_line(&t->tetro_line);
    puzzle_add(&pzl, t);
    t = t->next;
  }
  puzzle_print(pzl);
  return (1);
}