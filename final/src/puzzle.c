#include "../includes/tetro.h"

void copy_t_puzzle(t_puzzle *dst, t_puzzle *src) {
  dst->id = src->id;
	dst->tetro_num = src->tetro_num;
	dst->tetro_used = src->tetro_used;
	all_lines_dup(&dst->line, src->line);
	reverse_t_line(&dst->line);
	copy_ivec3(&dst->size, &src->size);
	copy_ivec2(&dst->start_pos, &src->start_pos);
	copy_ivec2(&dst->last_pos, &src->last_pos);
  copy_ivec2(&dst->offset, &src->offset);
	dst->brick = src->brick;
	dst->space = src->space;
  dst->score = src->score;
}


t_puzzle *puzzle_dup(t_puzzle **ref_pzl) {
  t_puzzle *buffer;

  if(!new_t_puzzle(&buffer, (*ref_pzl)->blank))
    return (NULL);
  copy_t_puzzle(buffer, (*ref_pzl));
  return (buffer);
}

int add_t_puzzle(t_puzzle **dst, t_puzzle *src) {
  t_puzzle *temp_pzl;

  if(!new_t_puzzle(&temp_pzl, src->blank))
    return (0);
  copy_t_puzzle(temp_pzl, src);
  temp_pzl->id = src->id++;
	temp_pzl->next = (*dst);
	(*dst) = temp_pzl;

  return (1);
}

int size_t_puzzle(t_puzzle *pzl) {
	int size;

	size = 0;
	while(pzl) {
		size++;
		pzl = pzl->next;
	}
	return (size);
}



void clear_puzzle(t_puzzle **ref_pzl, t_tetro *t) {
  int index;
  char c;
  t_line *ln;

  index = 0;
  while(index < (*ref_pzl)->size.y) {
    c = t->line->pair.b;
    ln = get_t_line((*ref_pzl)->line,index);
    fill_line(&ln->content, c, (*ref_pzl)->size.x);
    index++;
  }
  (*ref_pzl)->brick = 0;
  (*ref_pzl)->space = 0;
}


void puzzle_analyze(t_puzzle *pzl) {
  int index_x;
  int index_y;
  char c;

  index_y = 0;
  while(index_y < pzl->size.y) {
    index_x = 0;
    while(index_x < pzl->size.x) {
      c = get_t_line(pzl->line,index_y)->content[index_x];
      if(c == pzl->blank) {
         pzl->space++;
      } else {
        pzl->brick++;
      }
      index_x++;
    }
    index_y++;
  }
}



void set_grid_size(t_puzzle *pzl, t_tetro *tetro, int *inc) {
  t_ivec2 min_size;

  min_size.x = tetro->canvas.x;
  min_size.y = tetro->canvas.y;
  if(size_t_tetro(tetro) > 1) {
    while(tetro) {
      pzl->tetro_num++;
      pzl->size.z +=(tetro->size.x + tetro->size.y);
      tetro = tetro->next;
    }
    pzl->size.z += inc[0];
    pzl->size.x = sqrt_ceil(pzl->size.z) -1;
    if(pzl->size.x < min_size.x) {
      pzl->size.x = min_size.x;
    }
    pzl->size.y = pzl->size.x;
    if(pzl->size.y < min_size.y) {
      pzl->size.y = min_size.y;
    }
  } else {
    pzl->tetro_num = 1;
    pzl->size.x = tetro->size.x;
    pzl->size.y = tetro->size.y;
  }
}

int build_grid_puzzle(t_puzzle **ref_pzl, t_tetro *tetro, int *inc) {
  char c;
  int index;
  t_line *t_line;
  
  set_grid_size(*ref_pzl, tetro, inc);
  c = tetro->line->pair.b;
  new_t_line_puzzle(&t_line, c, (*ref_pzl)->size.x);
  t_line->pair.b = c;
  t_line->empty = 1;
  t_line->offset = 0;
  t_line->brick = 0;
  t_line->space = (*ref_pzl)->size.x;

  index = 0;
  while (index < (*ref_pzl)->size.y) {
    add_t_line(&(*ref_pzl)->line, index, t_line);
    index++;
  }
  free_line(t_line);
  return (1);
}







void calc_offset_puzzle(t_puzzle **ref_pzl) {
  t_ivec2 pos;
  char c;

  pos.y = 0; 
  while(pos.y < (*ref_pzl)->size.y) {
    pos.x = 0;
    while(pos.x < (*ref_pzl)->size.x) {
      c = get_t_line((*ref_pzl)->line, pos.y)->content[pos.x];
      if(c == (*ref_pzl)->blank && (*ref_pzl)->offset.x <= pos.x && pos.y == 0) {
        (*ref_pzl)->offset.x++;
      }
      if(c != (*ref_pzl)->blank) {
        if((*ref_pzl)->offset.x > 0 && pos.x < (*ref_pzl)->offset.x) {
          (*ref_pzl)->offset.x = pos.x;
        }  
        break;
      }
      pos.x++;
    }
    if((*ref_pzl)->offset.x == (*ref_pzl)->size.x) {
      (*ref_pzl)->offset.y++;
    }  
    pos.y++;
  }
}


void translate_x_puzzle(t_puzzle **ref_pzl) {
  t_ivec2 pos;
  char c;
  int ix;

  pos.y = 0;
  while(pos.y < (*ref_pzl)->size.y) {
    pos.x = (*ref_pzl)->offset.x;
    while(pos.x < (*ref_pzl)->size.x + (*ref_pzl)->offset.x) {
      ix = pos.x - (*ref_pzl)->offset.x;
      if(pos.x < (*ref_pzl)->size.x) {
        c = get_t_line((*ref_pzl)->line, pos.y)->content[pos.x];
        get_t_line((*ref_pzl)->line, pos.y)->content[ix] = c;
      } else {
        get_t_line((*ref_pzl)->line, pos.y)->content[ix] = (*ref_pzl)->blank;
      }
      pos.x++;
    }
    pos.y++;
  }
}

void translate_y_puzzle(t_puzzle **ref_pzl) {
  t_ivec2 pos;
  char c;
  int iy;

  pos.y = (*ref_pzl)->offset.y;
  while(pos.y < (*ref_pzl)->size.y + (*ref_pzl)->offset.y) {
    pos.x = 0;
    iy = pos.y - (*ref_pzl)->offset.y;
    if(pos.y < (*ref_pzl)->size.y) {
      while(pos.x < (*ref_pzl)->size.x) {
        c = get_t_line((*ref_pzl)->line, pos.y)->content[pos.x];
        get_t_line((*ref_pzl)->line, iy)->content[pos.x] = c;
        pos.x++;
      }
    } else {
      c = (*ref_pzl)->blank;
      fill_line(&get_t_line((*ref_pzl)->line, iy)->content, c, (*ref_pzl)->size.x);
    }
    pos.y++;
  }
}


void calc_score_puzzle(t_puzzle **ref_pzl) {
  t_ivec2 pos;
  t_ivec2 val;
  char c;

  pos.y = 0; 
  while(pos.y < (*ref_pzl)->size.y) {
    pos.x = 0;
    while(pos.x < (*ref_pzl)->size.x) {
      c = get_t_line((*ref_pzl)->line, pos.y)->content[pos.x];
      if(c == (*ref_pzl)->blank) {
         val.x = (*ref_pzl)->size.x - pos.x;
         val.y = (*ref_pzl)->size.y - pos.y;
        (*ref_pzl)->score += (val.x + val.y);
      }
      pos.x++;
    }  
    pos.y++;
  }
}

void finalize_puzzle(t_puzzle **ref_pzl) {
  calc_offset_puzzle(ref_pzl);
  if((*ref_pzl)->offset.x > 0) {
    translate_x_puzzle(ref_pzl);
  }
  if((*ref_pzl)->offset.y > 0) {
    translate_y_puzzle(ref_pzl);
  }
  calc_score_puzzle(ref_pzl);
}