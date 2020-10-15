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
  t_puzzle *temp_pzl; // can be remove, replace after temp_pzl by (*ref_pzl)
  t_line *piece;
  
  temp_pzl = (*ref_pzl); // can be remove
  while(t->tetro_line) {
    if(!t->tetro_line->empty) {
      init_temp_puzzle_line(&piece, t->tetro_line->col_max * 26);
      add_t_line(&piece,0,t->tetro_line);
      end = t->size.x + t->offset.x;
      piece->content = strcpy_from_to(t->tetro_line->content, t->offset.x, end);
      piece->length = ft_strlen(piece->content);
      piece->space = (piece->length - piece->brick);
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

void complete_line_try(t_line *dst, t_line *src_list) {
  int index;
  t_line *buffer;

  
  
  while(src_list) {
    if(dst->space >= src_list->brick) {
      add_t_line(&buffer,0,dst);
      printf("before buffer->content: %s\n", buffer->content);
      printf("before src_list->content: %s\n", src_list->content);
      index = 0;
      while(index < dst->length) {
        if(buffer->content[index] == buffer->b) {
          // printf("before src_list->content: %s\n", src_list->content);
          buffer->content[index] = src_list->content[index + src_list->offset];
        }
        index++;
      }
      printf("after buffer: %s\n\n", buffer->content);
      // printf("try to add piece %s in the existing line %s\n", src_list->content, dst->content);
    }
    if(!src_list->empty) {
      printf("je suis plein aux as %s\n", src_list->content);
      break;

    }
      
    src_list = src_list->next;
  }
}

int complete_puzzle(t_puzzle **ref_pzl, t_tetro *t, int print_info_is) {
  int res;
  t_puzzle *pzl;

  pzl = (*ref_pzl);
  while(pzl->tetro_line) {
    
    // printf("brick: %i\n", pzl->tetro_line->brick);
    // printf("length: %i\n", pzl->tetro_line->length);
    // printf("space: %i\n", pzl->tetro_line->space);
    if(pzl->tetro_line->space) {
    // if(pzl->tetro_line->brick < pzl->tetro_line->length) {
      complete_line_try(pzl->tetro_line, t->tetro_line);
      // while(t->tetro_line) {
      //   printf("try to add piece %s in the existing line %s\n", t->tetro_line->content, pzl->tetro_line->content);
      //   t->tetro_line = t->tetro_line->next;
      // }

    }
    pzl->tetro_line = pzl->tetro_line->next;
  }

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
    printf("\npiece of puzzle: %c", t->name);
  
  reverse_t_line(&t->tetro_line);
  if(!complete_puzzle(&buffer, t, print_info_is)) {
    add_new_line_puzzle(ref_pzl, t);
  }
  printf("puzzle size: %i, %i\n", (*ref_pzl)->size.x, (*ref_pzl)->size.y);
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
  // 
  // while(t) {
  //   if(print_info_is)
  //     printf("\nnext piece to solve puzzle\n");
  //   puzzle_build(&pzl, t, print_info_is);
  //   t = t->next;
  // }
  puzzle_print(pzl);
  return (1);
}

