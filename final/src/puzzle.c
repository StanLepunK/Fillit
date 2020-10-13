#include "../includes/tetro.h"

int init_temp_puzzle_line(t_line **ref_ln, int len) {
  t_line *ln;

  ln = (*ref_ln);
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
  int length;

  length = 0;
	t_line *temp_ln;
	temp_ln = NULL;
	if(!(temp_ln = (t_line*)malloc(sizeof(t_line))))
		return (0);
  copy_t_line_struct(temp_ln, src);
	temp_ln->next = (*ref);
  length = (ft_strlen(temp_ln->content));
	(*ref) = temp_ln;
	return(length);
}

int add_new_line_puzzle(t_puzzle **ref_pzl, t_tetro *t) {
  int length;
  int end;
  t_puzzle *temp_pzl; // can be remove
  t_line *piece;
  
  temp_pzl = (*ref_pzl); // can be remove
  reverse_t_line(&t->tetro_line);
  while(t->tetro_line) {
    if(!t->tetro_line->empty) {
      init_temp_puzzle_line(&piece, t->tetro_line->col_max * 26);
      end = t->size.x + t->offset.x;
      piece->content = strcpy_from_to(t->tetro_line->content, t->offset.x, end);
      length = add_line_puzzle(&temp_pzl->tetro_line, t->name, piece);
      if(length > temp_pzl->size.x) {
        temp_pzl->size.x = length;
      }
      temp_pzl->size.y++;
      brick_switch(temp_pzl->tetro_line->content, t->tetro_line->a, t->name);
    }
		t->tetro_line = t->tetro_line->next;
  }
  (*ref_pzl) = temp_pzl; // can be remove
  return (1);
}

int complete_puzzle(t_puzzle **ref_pzl, t_tetro *t, int print_info_is) {
  int res;
  t_puzzle *temp_pzl;

  temp_pzl = (*ref_pzl);
  printf("je suis là pour compléter le puzzle\n");
  while(temp_pzl->tetro_line) {
    printf("brick: %i\n",temp_pzl->tetro_line->brick);
    temp_pzl->tetro_line = temp_pzl->tetro_line->next;
  }
  // while((*ref_pzl)->tetro_line) {
  //   printf("brick: %i\n",(*ref_pzl)->tetro_line->brick);
  //   (*ref_pzl)->tetro_line = (*ref_pzl)->tetro_line->next;
  // }

  res = 0;
  return (res);
}



int puzzle_build(t_puzzle **ref_pzl, t_tetro *t, int print_info_is) {
  t_puzzle *buffer;

  buffer = NULL;
  if(!(buffer = (t_puzzle*)malloc(sizeof(t_puzzle))))
		return (0);
  puzzle_init(buffer);
  copy_t_puzzle_struct(buffer, (*ref_pzl)); // problem in the navigation of linked list.

  if(print_info_is)
    printf("\npiece of puzzle: %c", t->name);
  
  if(!complete_puzzle(&buffer, t, print_info_is)) {
    add_new_line_puzzle(ref_pzl, t);
  }
  printf("puzzle size: %i, %i\n", (*ref_pzl)->size.x, (*ref_pzl)->size.y);
  return (1);
}








int puzzle(t_tetro *t, int print_info_is) {
  t_puzzle *pzl;

  pzl = NULL;
  if(print_info_is)
    printf("PRINT PUZZLE\n");
  if(!(pzl = (t_puzzle*)malloc(sizeof(t_puzzle))))
		return (0);
  puzzle_init(pzl);
  while(t) {
    if(print_info_is)
      printf("\nnext piece to solve puzzle\n");
    puzzle_build(&pzl, t, print_info_is);
    t = t->next;
  }
  puzzle_print(pzl);
  return (1);
}











// int puzzle_build(t_puzzle **ref_pzl, t_tetro *t, int print_info_is) {
//   int count;
//   int end;
//   t_puzzle *temp_pzl;
//   t_line *piece;
  
//   if(print_info_is)
//     printf("\npiece of puzzle: %c", t->name);
//   temp_pzl = (*ref_pzl);
//   reverse_t_line(&t->tetro_line);
//   count = 0;
//   while(count < t->canvas.y) {
//     if(!t->tetro_line->empty) {
//       init_temp_puzzle_line(&piece, t->tetro_line->col_max * 26);
//       end = t->size.x + t->offset.x;
//       piece->content = strcpy_from_to(t->tetro_line->content, t->offset.x, end);
//       if(print_info_is)
//         printf("str format: %s\n",piece->content);
//       add_line_puzzle(&temp_pzl->tetro_line, t->name, piece);
//       brick_switch(temp_pzl->tetro_line->content, t->tetro_line->a, t->name);
//     }
// 		t->tetro_line = t->tetro_line->next;
//     count++;
//   }
//   (*ref_pzl) = temp_pzl;
//   return (1);
// }