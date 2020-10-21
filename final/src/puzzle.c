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
  
  c = t->tetro_line->b;
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
      // printf("set cell x: %i, y %i >>>  %c <> %c \n",x, y, src->content[x], c);
      dst->content[x] = c; // dangerous, because there is no out bound exception
      // printf("xy %i, %i\n",x, y);
      // printf("name %c\n",dst->content[x]);
      break;
    }
    dst = dst->next;
  }
}



int complete_line_try(t_line *dst_pzl_ln, t_tetro *t, ivec3 *try) {
  int ix; // index
  int ox; // offset

  ox = t->offset.x;
  while(t->tetro_line) {
    if(!t->tetro_line->empty) {
      ix = 0;
      if(get_t_line(dst_pzl_ln, try->y)->space >= t->tetro_line->brick) {
        // printf("je suis passé\n");
      // if(dst_pzl_ln->space >= t->tetro_line->brick) {
        while(ix + ox < t->tetro_line->length) {
          if(t->tetro_line->content[ix + ox] == t->tetro_line->a) {
            if(get_cell(dst_pzl_ln, try->x, try->y) == t->tetro_line->b) {
              set_cell(dst_pzl_ln, try->x, try->y, t->name);
              printf("get_cell(): %c\n",get_cell(dst_pzl_ln, try->x, try->y));
            } else {
              return (0);
            }
          }
          ix++;
        }
      }
      // printf("je suis out\n");
    }
    t->tetro_line = t->tetro_line->next;
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

void set_try(ivec3 *try, ivec3 *size_pzl, ivec2 *size_tetro) {
  int len;
  int sx;
  int sy;

  len = try->z;
  sx = size_pzl->x - size_tetro->x;
  sy = size_pzl->y - size_tetro->y;
  try->x = len % sx;
  try->y = len / sx;
  printf("len %i\n", len);
  printf("sx: %i\n", sx);
  printf("try->y: %i\n", try->y);
}



int complete_puzzle(t_puzzle **ref_pzl, t_tetro *t, int print_info_is) {
  ivec3 *try;
  int max_try;
  t_puzzle *pzl;
  t_tetro *tetro;

  reverse_t_line(&t->tetro_line);
  tetro = tetro_dup(&t);
  pzl = puzzle_dup(ref_pzl);
  ivec3_init(try);
  max_try = (pzl->size.x * pzl->size.y) - (t->size.x * t->size.y) - 1;
  printf("max try %i\n", max_try);
  while(try->z < max_try) {
    set_try(try, &pzl->size, &t->size);
    if(complete_line_try(pzl->tetro_line, tetro, try)) {
      break;
    }
    
    free(tetro); // sure this one is not totaly free, because there is something in sine like tetro_line has not been released
    tetro = tetro_dup(&t);
    free(pzl); // sure this one is not totaly free, because there is something in sine like tetro_line has not been released
    pzl = puzzle_dup(ref_pzl);
    try->z++;
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











// int complete_line_try(t_line *dst_pzl_ln, t_tetro *t, ivec3 *try) {
//   int ix; // index
//   int ox; // offset
//   int ot; // offset try

//   ox = t->offset.x;
//   ot = try->z;
//   while(t->tetro_line && dst_pzl_ln) {
//     // printf("pzl line id %i\n",dst_pzl_ln->id);
//     if(!t->tetro_line->empty) {
//       ix = 0;
//       if(dst_pzl_ln->space >= t->tetro_line->brick) {
//         while(ix + ox < t->tetro_line->length) {
//           if(t->tetro_line->content[ix + ox] == t->tetro_line->a) {
//             if(dst_pzl_ln->content[ix + ot] == t->tetro_line->b) {
//               // printf("SUCCES\n");
//               dst_pzl_ln->content[ix + ot] = t->name;
//             } else {
//               // printf("FAIL\n");
//               // printf("ix + ox %i\n",ix + ox);
//               // printf("t->tetro_line->content[ix + ox] %c\n",t->tetro_line->content[ix + ox]);
//               // printf("t->tetro_line->content %s\n",t->tetro_line->content);
//               // printf("ix + ot %i\n",ix + ot);
//               // printf("dst_pzl_ln->content[ix + ot] %c\n",dst_pzl_ln->content[ix + ot]);
//               // printf("dst_pzl_ln->content %s\n",dst_pzl_ln->content);
//               return (0);
//             }
//           }
//           ix++;
//         }
//       }
//       dst_pzl_ln = dst_pzl_ln->next;
//     }
//     t->tetro_line = t->tetro_line->next;
//   }
//   return (1);
// }