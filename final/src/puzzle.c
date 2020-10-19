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

int build_grid_puzzle(t_puzzle **ref_pzl, t_tetro *t) {
  char c;
  int index;
  
  c = t->tetro_line->b;
  while(t) {
    (*ref_pzl)->size.x += t->size.x;
    (*ref_pzl)->size.y += t->size.y;
    t = t->next;
  }

  t_line *t_line;
  fill_t_line(&t_line, c, (*ref_pzl)->size.x);
  t_line->b = c;
  t_line->empty = 1;
  t_line->offset = 0;
  t_line->brick = 0;
  t_line->space = (*ref_pzl)->size.x;

  index = 0;
  while (index < (*ref_pzl)->size.y) {
    add_t_line(&(*ref_pzl)->tetro_line, index, t_line);
    index++;
  }
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




int complete_line_try(t_line *dst_pzl_ln, t_tetro *t, int offset_try) {
  int ix; // index
  int ox; // offset
  int ot; // offset try

  ox = t->offset.x;
  ot = offset_try;
  while(t->tetro_line && dst_pzl_ln) {
    // printf("pzl line id %i\n",dst_pzl_ln->id);
    if(!t->tetro_line->empty) {
      ix = 0;
      if(dst_pzl_ln->space >= t->tetro_line->brick) {
        while(ix + ox < t->tetro_line->length) {
          if(t->tetro_line->content[ix + ox] == t->tetro_line->a) {
            if(dst_pzl_ln->content[ix + ot] == t->tetro_line->b) {
              // printf("SUCCES\n");
              dst_pzl_ln->content[ix + ot] = t->name;
            } else {
              // printf("FAIL\n");
              // printf("ix + ox %i\n",ix + ox);
              // printf("t->tetro_line->content[ix + ox] %c\n",t->tetro_line->content[ix + ox]);
              // printf("t->tetro_line->content %s\n",t->tetro_line->content);
              // printf("ix + ot %i\n",ix + ot);
              // printf("dst_pzl_ln->content[ix + ot] %c\n",dst_pzl_ln->content[ix + ot]);
              // printf("dst_pzl_ln->content %s\n",dst_pzl_ln->content);
              return (0);
            }
          }
          ix++;
        }
      }
      dst_pzl_ln = dst_pzl_ln->next;
    }
    t->tetro_line = t->tetro_line->next;
  }
  return (1);
}










t_puzzle *dup_puzzle(t_puzzle **ref_pzl) {
  t_puzzle *buffer;

  buffer = NULL;
  if(!(buffer = (t_puzzle*)malloc(sizeof(t_puzzle))))
		return (0);
  puzzle_init(buffer);
  copy_t_puzzle_struct(buffer, (*ref_pzl));
  return (buffer);
}



int complete_puzzle(t_puzzle **ref_pzl, t_tetro *t, int print_info_is) {
  int try;
  int max_try;
  t_puzzle *pzl;
  t_tetro *tetro;

  reverse_t_line(&t->tetro_line);
  tetro = tetro_dup(&t);
  pzl = dup_puzzle(ref_pzl);
  try = 0;
  max_try = (pzl->size.x * pzl->size.y) - (t->size.x * t->size.y);
  while(try <= max_try) {
    if(complete_line_try(pzl->tetro_line, tetro, try)) {
      break;
    }
    
    free(tetro); // sure this one is not totaly free, because there is something in sine like tetro_line has not been released
    tetro = tetro_dup(&t);
    free(pzl); // sure this one is not totaly free, because there is something in sine like tetro_line has not been released
    pzl = dup_puzzle(ref_pzl);
    try++;
  }
  (*ref_pzl) = pzl;
  return (1);
}



int puzzle_build(t_puzzle **ref_pzl, t_tetro *t, int print_info_is) {
  t_puzzle *buffer;

  buffer = dup_puzzle(ref_pzl);
  if(print_info_is)
    printf("\npiece of puzzle: %c\n", t->name);
  
  complete_puzzle(&buffer, t, print_info_is);
  (*ref_pzl) = buffer;
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
  build_grid_puzzle(&pzl, t);
  
  while(t) {
    if(print_info_is)
      printf("\nnext piece to solve puzzle\n");
    puzzle_build(&pzl, t, print_info_is);
    t = t->next;
  }
  puzzle_print(pzl);
  return (1);
}

