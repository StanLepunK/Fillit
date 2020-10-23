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
  t_line *t_line;
  
  c = t->line->b;
  while(t) {
    (*ref_pzl)->size.z +=(t->size.x + t->size.y);
    t = t->next;
  }
  (*ref_pzl)->size.x = sqrt_ceil((*ref_pzl)->size.z);
  (*ref_pzl)->size.y = (*ref_pzl)->size.x;

  fill_t_line(&t_line, c, (*ref_pzl)->size.x);
  t_line->b = c;
  t_line->empty = 1;
  t_line->offset = 0;
  t_line->brick = 0;
  t_line->space = (*ref_pzl)->size.x;

  index = 0;
  while (index < (*ref_pzl)->size.y) {
    add_t_line(&(*ref_pzl)->line, index, t_line);
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



char get_cell(t_line *src, int x, int y) {
  while(src) {
    if(src->id == y) {
      return (src->content[x]); // dangerous, because there is no out bound exception
    }
    src = src->next;
  }
  return (0);
}

void set_cell(t_line *dst, int x, int y, char c) {
  while(dst) {
    if(dst->id == y) {
      dst->content[x] = c; // dangerous, because there is no out bound exception
      break;
    }
    dst = dst->next;
  }
}

void set_try(t_try *try, t_ivec3 *size_pzl, t_ivec2 *size_tetro) {
  try->ix = 0;
  try->iy = 0;
  try->mx = size_pzl->x - size_tetro->x;
  try->my = size_pzl->y - size_tetro->y;
  try->num = 0;
  // printf("mx: %i pzl %i tetro %i\n",try->mx, size_pzl->x, size_tetro->x);
  // printf("my: %i pzl %i tetro %i\n",try->my, size_pzl->y, size_tetro->y);
}

int resolution(t_line *buf_pzl, t_tetro *tetro, t_try *try) {
  int index;

  index = 0;
  // printf("name: %c\n", tetro->name);
  // printf("id %i %s\n", tetro->line->id, tetro->line->content);
  while(index < tetro->size.x && try->ix <= try->mx) {
    if(tetro->line->content[index + tetro->offset.x] == tetro->line->a) {
      if(buf_pzl->content[index + try->ix] == tetro->line->b) {
        buf_pzl->content[index + try->ix] = tetro->name;
      } else {
        //printf("échec %c\n", buf_pzl->content[index + try->ix]);
        return (0);
      }
    }
    index++;
  }
  return (1);
}

int complete_line_try(t_line *dst_pzl_ln, t_tetro *tetro, t_try *try) {
  int index_t_ln;
  t_line *buf_pzl;

  index_t_ln = 0;
  while(tetro->line) {
    if(!tetro->line->empty) {
      while(try->iy <= try->my + index_t_ln) {
        printf("tetro name iy my %c %i %i\n", tetro->name, try->iy, try->my);
        try->ix = 0;
        buf_pzl = get_t_line(dst_pzl_ln, try->iy);
        if(buf_pzl->space >= tetro->line->brick) {
          ++try->iy;
          if(resolution(buf_pzl, tetro, try)) {
            copy_t_line_at(dst_pzl_ln,buf_pzl,try->iy);
            break;
          } else {
            return(0);
          }
        }    
      }
    }
    index_t_ln++;
    tetro->line = tetro->line->next;
  }
  return (1);
}








t_puzzle *puzzle_dup(t_puzzle **ref_pzl) {
  t_puzzle *buffer;

  buffer = NULL;
  if(!(buffer = (t_puzzle*)malloc(sizeof(t_puzzle))))
		return (0);
  puzzle_init(buffer);
  copy_t_puzzle_struct(buffer, (*ref_pzl));
  return (buffer);
}





int complete_puzzle(t_puzzle **ref_pzl, t_tetro *t, int print_info_is) {
  t_try *try;
  int max_try;
  t_puzzle *pzl;
  t_tetro *tetro;

  // reverse_t_line(&t->line);
  tetro = tetro_dup(&t);
  pzl = puzzle_dup(ref_pzl);
  set_try(try, &pzl->size, &t->size);
  max_try = (pzl->size.x * pzl->size.y) - (t->size.x * t->size.y) - 1;
  while(try->num < max_try) {
    // try->iy = 0;
    if(complete_line_try(pzl->line, tetro, try)) {
      break;
    } else {
      try->num++;
    }
    free(tetro); // sure this one is not totaly free, because there is something in sine like tetro_line has not been released
    tetro = tetro_dup(&t);
    free(pzl); // sure this one is not totaly free, because there is something in sine like tetro_line has not been released
    pzl = puzzle_dup(ref_pzl);
  }
  (*ref_pzl) = pzl;
  return (1);
}



int puzzle_build(t_puzzle **ref_pzl, t_tetro *t, int print_info_is) {
  t_puzzle *buffer;

  buffer = puzzle_dup(ref_pzl);
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
  // try to build the smallest grid for the fist time and increqe step by step
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

