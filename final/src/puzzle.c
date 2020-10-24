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

void set_grid_size(t_puzzle *pzl, t_tetro *tetro) {
  if(size_t_tetro(tetro) > 1) {
    while(tetro) {
      pzl->size.z +=(tetro->size.x + tetro->size.y);
      tetro = tetro->next;
    }
    pzl->size.x = sqrt_ceil(pzl->size.z);
    pzl->size.y = pzl->size.x;
  } else {
    pzl->size.x = tetro->size.x;
    pzl->size.y = tetro->size.y;
  }
}

int build_grid_puzzle(t_puzzle **ref_pzl, t_tetro *t) {
  char c;
  int index;
  t_line *t_line;
  
  set_grid_size(*ref_pzl, t);

  c = t->line->b;
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
  try->pzl_ix = 0;
  try->pzl_iy = 0;
  try->mox = size_pzl->x - size_tetro->x;
  try->moy = size_pzl->y - size_tetro->y;
  try->num = 0;
  try->max = (size_pzl->x * size_pzl->y) - (size_tetro->x * size_tetro->y) - 1;
  if(try->max < 1)
    try->max = 1;
}

int resolution(t_line *buf_pzl, t_tetro *tetro, t_try *try) {
  int index;

  index = 0;
  while(index < tetro->size.x && try->pzl_ix <= try->mox) {
    if(tetro->line->content[index + tetro->offset.x] == tetro->line->a) {
      if(buf_pzl->content[index + try->pzl_ix] == tetro->line->b) {
        buf_pzl->content[index + try->pzl_ix] = tetro->name;
      } else {
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
    if(index_t_ln > tetro->size.y) {
      return (0);
    }
    printf("1 %s\n",tetro->line->content);
    if(!tetro->line->empty) {
      // printf("tetro name %c iy: %i moy: %i index_t_ln: %i\n", tetro->name, try->iy, try->moy, index_t_ln);
      while(try->pzl_iy <= try->moy + index_t_ln) {
        try->pzl_ix = 0;
        buf_pzl = get_t_line(dst_pzl_ln, try->pzl_iy);
        if(buf_pzl->space >= tetro->line->brick) {
          try->pzl_iy++;
          if(resolution(buf_pzl, tetro, try)) {
            break;
          } else {
            return(0);
          }
        }
      }
      index_t_ln++;
    }
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





int complete_puzzle(t_puzzle **ref_pzl, t_tetro *tetro, int print_info_is) {
  t_try *try;
  t_puzzle *pzl;
  t_tetro *buf_tetro;

  buf_tetro = tetro_dup(&tetro);
  pzl = puzzle_dup(ref_pzl);
  set_try(try, &pzl->size, &tetro->size);
  while(try->num < try->max) {
    if(complete_line_try(pzl->line, buf_tetro, try)) {
      break;
    } else {
      try->num++;
    }
    free(buf_tetro); // sure this one is not totaly free, because there is something in sine like tetro_line has not been released
    buf_tetro = tetro_dup(&tetro);
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

