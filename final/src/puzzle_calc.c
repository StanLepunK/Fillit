#include "../includes/tetro.h"



int line_resolution(t_line *buf_pzl, t_tetro *tetro, t_try *try_piece, int index) {
  int i_x;
  int succes;
  t_line *buf_tetro_ln;

  i_x = 0;
  succes = 0;
  buf_tetro_ln = get_t_line(tetro->line, index);
  while(i_x < tetro->size.x && try_piece->index.x < try_piece->offset.x) {
    if(buf_tetro_ln->content[i_x + tetro->offset.x] == buf_tetro_ln->pair.a) {
      if(buf_pzl->content[i_x + try_piece->index.x] == buf_tetro_ln->pair.b) {
        buf_pzl->content[i_x + try_piece->index.x] = tetro->name;
        succes = 1;
      } else {
        return (0);
      }
    }
    i_x++;
  }
  return (succes);
}


int complete_line_try(t_line *dst_pzl_ln, t_tetro *tetro, t_try *try_piece) {
  int index_real;
  int index;
  int i_y;
  t_line *buf_pzl;
  t_line *buf_tetro_ln;

  index = tetro->offset.y;
  index_real = 0;
  i_y = 0;
  while(index < tetro->canvas.y) {
    if(index_real > tetro->size.y) {
      return (0);
    }
    buf_tetro_ln = get_t_line(tetro->line, index);
    if(!buf_tetro_ln->empty) {
      if(try_piece->index.y + i_y > try_piece->offset.y + index_real)
        return(0);
      while(try_piece->index.y + i_y <= try_piece->offset.y + index_real) {
        buf_pzl = get_t_line(dst_pzl_ln, try_piece->index.y + i_y);
        if(buf_pzl->space >= buf_tetro_ln->brick) {
          i_y++;
          if(line_resolution(buf_pzl, tetro, try_piece, index)) {
            break;
          } else {
            return(0);
          }
        }
      }
      index_real++;
    }
    index++;
  }
  tetro->pos.copy(&tetro->pos,&try_piece->index);
  return (1);
}





void update_puzzle(t_puzzle **pzl, t_tetro *tetro) {
  (*pzl)->last_pos.copy(&(*pzl)->last_pos,&tetro->pos);
  if(tetro->id == 0) {
    (*pzl)->start_pos.copy(&(*pzl)->start_pos,&tetro->pos);
  } else {
    if((*pzl)->last_pos.x < (*pzl)->start_pos.x) {
      (*pzl)->start_pos.x = (*pzl)->last_pos.x;
    }
    if((*pzl)->last_pos.y < (*pzl)->start_pos.y) {
      (*pzl)->start_pos.y = (*pzl)->last_pos.y;
    }
  }
  (*pzl)->tetro_used++;
}



int complete_puzzle(t_puzzle **ref_pzl, t_tetro *tetro, t_try *try_piece) {
  t_puzzle *pzl;
  t_tetro *buf_tetro;

  buf_tetro = tetro_dup(&tetro);
  pzl = puzzle_dup(ref_pzl);
  while(try_piece->num < try_piece->max) {
    if(complete_line_try(pzl->line, buf_tetro, try_piece)) {
      update_puzzle(&pzl, buf_tetro);
      update_try(try_piece);
      // printf("BINGO try piece: %i < %i\n", try_piece->num,try_piece->max);
      // puzzle_print(pzl);
      break;
    }
    update_try(try_piece);
    free_tetro(buf_tetro);
    buf_tetro = tetro_dup(&tetro);
    free_puzzle(pzl);
    pzl = puzzle_dup(ref_pzl);   
  }
  (*ref_pzl) = pzl;
  return (1);
}


int buffering_calc(t_puzzle **ref_pzl, t_tetro *tetro, t_try *try_piece) {
  t_puzzle *buffer;

  buffer = (*ref_pzl);
  complete_puzzle(&buffer, tetro, try_piece);
  (*ref_pzl) = buffer;
  return (1);
}

int puzzle_resolution(t_puzzle **ref_pzl, t_puzzle **ref_pzl_list, t_tetro *tetro, t_try *try_pzl) {
  int res;
  t_try *try_piece;

  try_piece = new_try();
  res = 1;
  while(try_pzl->tetro_start < size_t_tetro(tetro)) {
    set_try(try_piece, (*ref_pzl), get_t_tetro(tetro, try_pzl->tetro_start));
    if(try_pzl->tetro_start == 0) {
      try_piece->index.copy(&try_piece->index, &try_pzl->index); // why ?
    }
    buffering_calc(ref_pzl, get_t_tetro(tetro, try_pzl->tetro_start), try_piece);
    printf("NEXT PIECE %i\n", try_pzl->tetro_start);
    try_pzl->tetro_start++;
  }
  if(try_pzl->num < try_pzl->max) {
    if((*ref_pzl)->tetro_used == (*ref_pzl)->tetro_num) {
      printf("ADD PUZZLE\n");
      add_t_puzzle(ref_pzl_list, (*ref_pzl));
    }
    res = 0;
  }
  if(!res) {
    update_try(try_pzl);
    try_pzl->tetro_start  = 0;
    (*ref_pzl)->tetro_used = 0;
    clear_puzzle(ref_pzl, tetro);
    puzzle_resolution(ref_pzl, ref_pzl_list, tetro, try_pzl);
  }
  free(try_piece);
  return(res);
}

int puzzle(t_puzzle **ref_list, t_tetro *tetro, t_pair *pair, int *inc) {
  t_puzzle *pzl;
  t_try *try_pzl;
  int index;

  if(!(pzl = (t_puzzle*)malloc(sizeof(t_puzzle))))
		return (0);
  puzzle_init(pzl, pair->b);
  build_grid_puzzle(&pzl, tetro, inc);
  try_pzl = new_try();

  index = 0;
  // while(index < pzl->tetro_num) {
    set_try(try_pzl, pzl, tetro);
    puzzle_resolution(&pzl, ref_list, tetro, try_pzl);
    puzzle_analyze(pzl);
    index++;
    // try_pzl->tetro_start++;
 // }

  // puzzle_print_info(pzl);

  free_puzzle(pzl);
  free(try_pzl);

  // if no solution found increase the canvas size of the puzzle
  if(!size_t_puzzle((*ref_list))) {
    printf("\033[1;31mLA LOOSE J'INCREMENTE\033[0m\n");
    inc[0]++;
    puzzle(ref_list, tetro, pair, inc);
  }
  return (size_t_puzzle((*ref_list)));
}



