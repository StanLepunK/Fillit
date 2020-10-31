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
      pzl->tetro_num++;
      pzl->size.z +=(tetro->size.x + tetro->size.y);
      tetro = tetro->next;
    }
    pzl->size.x = sqrt_ceil(pzl->size.z);
    pzl->size.y = pzl->size.x;
  } else {
    pzl->tetro_num = 1;
    pzl->size.x = tetro->size.x;
    pzl->size.y = tetro->size.y;
  }
}

int build_grid_puzzle(t_puzzle **ref_pzl, t_tetro *tetro) {
  char c;
  int index;
  t_line *t_line;
  
  set_grid_size(*ref_pzl, tetro);
  c = tetro->line->b;
  fill_t_line(&t_line, c, (*ref_pzl)->size.x);
  t_line->b = c;
  t_line->empty = 1;
  t_line->offset = 0;
  t_line->brick = 0;
  t_line->space = (*ref_pzl)->size.x;

  index = 0;
  while (index < (*ref_pzl)->size.y) {
    add_t_line(&(*ref_pzl)->line, index, t_line);
    // free(t_line);
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

void set_try(t_try *try, t_ivec3 size_pzl, t_ivec2 size_tetro) {
  try->pzl_ix = 0;
  try->pzl_iy = 0;
  try->pzl_mox = (size_pzl.x - size_tetro.x) + 1;
  try->pzl_moy = size_pzl.y - size_tetro.y;
  try->num = 0;
  try->put = 0;
  try->max = (size_pzl.x * size_pzl.y) - (size_tetro.x * size_tetro.y) - 1;
  if(try->max < 1)
    try->max = 1;
}





int line_resolution(t_line *buf_pzl, t_tetro *tetro, t_try *try) {
  int i_x;
  int succes;

  i_x = 0;
  succes = 0;
  while(i_x < tetro->size.x && try->pzl_ix < try->pzl_mox) {
    if(tetro->line->content[i_x + tetro->offset.x] == tetro->line->a) {
      if(buf_pzl->content[i_x + try->pzl_ix] == tetro->line->b) {
        buf_pzl->content[i_x + try->pzl_ix] = tetro->name;
        succes = 1;
        try->put++;
      } else {
        return (0);
      }
    }
    i_x++;
  }
  return (succes);
}


int complete_line_try(t_line *dst_pzl_ln, t_tetro *tetro, t_try *try) {
  int index_t_ln;
  int i_y;
  t_line *buf_pzl;

  index_t_ln = 0;
  i_y = 0;
  while(tetro->line) {
    if(index_t_ln > tetro->size.y) {
      return (0);
    }
    if(!tetro->line->empty) {
      if(try->pzl_iy + i_y > try->pzl_moy + index_t_ln)
        return(0);
      while(try->pzl_iy + i_y <= try->pzl_moy + index_t_ln) {
        buf_pzl = get_t_line(dst_pzl_ln, try->pzl_iy + i_y);
        if(buf_pzl->space >= tetro->line->brick) {
          i_y++;
          if(line_resolution(buf_pzl, tetro, try)) {
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






t_line *header_t_line(t_line *ptr) {
	t_line *header = ptr;
	return (header);
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


void inc_index_pzl(t_try *try) {
  try->pzl_ix++;
  if(try->num%try->pzl_mox == 0) {
    try->pzl_ix = 0;
    try->pzl_iy++;
  }
  try->num++;
}


int complete_puzzle(t_puzzle **ref_pzl, t_tetro *tetro, t_try *try) {
  t_puzzle *pzl;
  t_tetro *buf_tetro;

  buf_tetro = tetro_dup(&tetro);
  pzl = puzzle_dup(ref_pzl);
  while(try->num < try->max) {
    if(complete_line_try(pzl->line, buf_tetro, try)) {
      pzl->tetro_used++;
      break;
    } else {
      inc_index_pzl(try);
    }
    free_tetro(buf_tetro);
    buf_tetro = tetro_dup(&tetro);
    free_puzzle(pzl);
    pzl = puzzle_dup(ref_pzl);
    
  }
  (*ref_pzl) = pzl;
  return (1);
}


int buffer_pzl(t_puzzle **ref_pzl, t_tetro *t, t_try *try) {
  t_puzzle *buffer;
  
  buffer = (*ref_pzl);
  complete_puzzle(&buffer, t, try);
  (*ref_pzl) = buffer;
  return (1);
}










int puzzle_resolution(t_puzzle **ref_pzl, t_tetro *t, t_try *try_pzl) {
  int index_t;
  int res;
  t_try *try_piece;

  try_piece = new_try();
  index_t = 0;
  res = 1;
  
  while(index_t < (*ref_pzl)->tetro_num) {
    printf("tetro: %c try piece: %i\n",get_t_tetro(t, index_t)->name,try_piece->num);
    set_try(try_piece, (*ref_pzl)->size, t->size);
    if(index_t == 0) {
      try_piece->pzl_ix = try_pzl->pzl_ix;
      try_piece->pzl_iy = try_pzl->pzl_iy;
    }
    printf("1 puzzle_resolution\n");
    printf("1 puzzle_resolution (*ref_pzl)->line: %p \n",(*ref_pzl)->line);
    buffer_pzl(ref_pzl, get_t_tetro(t, index_t), try_piece);
    printf("2 puzzle_resolution\n");
    index_t++;
  }

  if((*ref_pzl)->tetro_used < (*ref_pzl)->tetro_num) {
    puzzle_print((*ref_pzl), 1);
    res = 0;
  }
  if(!res) {
    inc_index_pzl(try_pzl);
    (*ref_pzl)->tetro_used = 0;
    puzzle_resolution(ref_pzl, t, try_piece);
  }
  free(try_piece);
  return(res);
}

















int puzzle(t_tetro *t, int print_info_is) {
  t_puzzle *pzl;
  t_try *try_pzl;

  if(!(pzl = (t_puzzle*)malloc(sizeof(t_puzzle))))
		return (0);
  puzzle_init(pzl);
  try_pzl = new_try();
  set_try(try_pzl, pzl->size, t->size);
  build_grid_puzzle(&pzl, t);
  puzzle_resolution(&pzl, t, try_pzl);
  puzzle_print(pzl, print_info_is);
  free_puzzle(pzl);
  free(try_pzl);
  return (1);
}












