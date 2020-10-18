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



int complete_line_try(t_line *dst_pzl_ln, t_line *src_tetro_ln, t_tetro *t, int offset_try) {
  int ix; // index
  int ox; // offset
  int ot; // offset try
  int succes;

  succes = -1;
  ox = t->offset.x;
  ot = offset_try;
  while(src_tetro_ln && dst_pzl_ln) {
    // reverse_t_line(&src_tetro_ln);
    printf("pzl line id %i\n",dst_pzl_ln->id);
    if(!src_tetro_ln->empty) {
      ix = 0;
      if(dst_pzl_ln->space >= src_tetro_ln->brick) {
        // printf("pzl content ln %s\n",dst_pzl_ln->content);
        printf("tetro content ln %s\n",src_tetro_ln->content);
        // printf("pzl line id %i\n",dst_pzl_ln->id);
        while(ix + ox < src_tetro_ln->length) {
          if(src_tetro_ln->content[ix + ox] == src_tetro_ln->a) {
            if(dst_pzl_ln->content[ix + ot] == src_tetro_ln->b) {
              // printf("pzl line id %i\n",dst_pzl_ln->id);
              dst_pzl_ln->content[ix + ot] = src_tetro_ln->a;
              succes = 1;
            } else {
              succes = 0;
            }
          }
          ix++;
        }
      }
      dst_pzl_ln = dst_pzl_ln->next;
    }
    src_tetro_ln = src_tetro_ln->next;
  }
  return (succes);
}






int complete_puzzle(t_puzzle **ref_pzl, t_tetro *t, int print_info_is) {
  int res;
  t_puzzle *pzl;
  int succes = 0;

  pzl = (*ref_pzl);
  int offset_try = 0;
  // print_all_tetro(t,0);
  succes = complete_line_try(pzl->tetro_line, t->tetro_line, t, offset_try);
  //printf("succes: %i\n", succes);

  // for the future
  // int offset_try = 0;
  // int max_try = pzl->size.x - t->size.x;
  // while(offset_try < max_try) {
  //   complete_line_try(pzl->tetro_line, t->tetro_line, t->offset.x, offset_try);
  //   offset_try++;
  // }
  (*ref_pzl) = pzl;
  res = 0;
  return (res);
}



int puzzle_build(t_puzzle **ref_pzl, t_tetro *t, int print_info_is) {
  t_puzzle *buffer;

  buffer = NULL;
  if(!(buffer = (t_puzzle*)malloc(sizeof(t_puzzle))))
		return (0);
  puzzle_init(buffer);
  copy_t_puzzle_struct(buffer, (*ref_pzl));

  if(print_info_is)
    printf("\npiece of puzzle: %c\n", t->name);
  
  complete_puzzle(&buffer, t, print_info_is);
  (*ref_pzl) = buffer;
  // printf("puzzle size: %i, %i\n", (*ref_pzl)->size.x, (*ref_pzl)->size.y);
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






