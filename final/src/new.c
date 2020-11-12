#include "../includes/tetro.h"
int COUNT_NEW;

int new_t_tetro(t_tetro **ref_tetro) {
  (*ref_tetro) = NULL;
	if(!((*ref_tetro) = (t_tetro*)malloc(sizeof(t_tetro))))
		return (0);
  tetro_init((*ref_tetro));

  COUNT_NEW++;
  return (1);
}

int new_t_line_puzzle(t_line **ref_line, char c, size_t len) {
  if(!((*ref_line) = (t_line*)malloc(sizeof(t_line))))
    return (0);
	(*ref_line)->length = len;
	(*ref_line)->col_max = len;
	if(!new_string(&(*ref_line)->content, len))
		return(0);
  fill_line(&(*ref_line)->content, c, len);

  COUNT_NEW++;
  return(1);
}


int new_t_line(t_line **ref_line, t_pair *pair) {
  (*ref_line) = NULL;
  if (!((*ref_line) = (t_line*)malloc(sizeof(t_line))))
    return(0);
  line_set_arguments((*ref_line), pair);
  if (!new_string(&(*ref_line)->content, (*ref_line)->col_max))
		return (0);

  COUNT_NEW++;
  return(1);
}

int new_string(char **ref, size_t len) {
	if(!((*ref) = (char*)malloc(sizeof(char) * (len + 1))))
    return (0);

  COUNT_NEW++;
	return(1);
}



int new_t_try(t_try **ref_try) {
  (*ref_try) = NULL;
  if(!((*ref_try) = (t_try*)malloc(sizeof(t_try))))
    return (0);
  ivec2_init(&(*ref_try)->index);
  ivec2_init(&(*ref_try)->offset);
  (*ref_try)->tetro_start = 0;
  (*ref_try)->num = 0;
	(*ref_try)->max = 0;

  COUNT_NEW++;
  return (1);
}


int new_t_puzzle(t_puzzle **ref_pzl, char blank) {
  (*ref_pzl) = NULL;
  if(!((*ref_pzl) = (t_puzzle*)malloc(sizeof(t_puzzle))))
		return (0);
  (*ref_pzl)->id = 0;
  (*ref_pzl)->line = NULL;
  ivec3_init(&(*ref_pzl)->size);
  ivec2_init(&(*ref_pzl)->start_pos);
  ivec2_init(&(*ref_pzl)->last_pos);
  ivec2_init(&(*ref_pzl)->offset);
  (*ref_pzl)->blank = blank;
  (*ref_pzl)->brick = 0;
  (*ref_pzl)->space = 0;
  (*ref_pzl)->tetro_num = 0;
  (*ref_pzl)->tetro_used = 0;
  (*ref_pzl)->score = 0;

  COUNT_NEW++;
  return(1);
}



int new_t_block(t_block **ref_blk) {
  (*ref_blk) = NULL;
  if (!((*ref_blk) = (t_block*)malloc(sizeof(t_block))))
    return(0);
  block_set_arguments((*ref_blk));
  if (!((*ref_blk)->p_line = (t_line*)malloc(sizeof(t_line))))
		return (0);
  if (!((*ref_blk)->p_line->content = (char*)malloc(sizeof(char) *(*ref_blk)->col_max)))
		return (0);

  COUNT_NEW++;
  return(1);
}