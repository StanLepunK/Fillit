#include "../includes/tetro.h"

void copy_t_line(t_line *dst, const t_line *src) {
  dst->id = src->id;
  
  dst->content = ft_strdup(src->content);
  dst->length = src->length;
	dst->pair.a = src->pair.a;
	dst->pair.b = src->pair.b;

	dst->empty = src->empty;
	dst->offset = src->offset;

  dst->valid = src->valid;
	dst->state = src->state;
	dst->threshold = src->threshold;

	dst->brick = src->brick;
	dst->space = src->space;
  dst->col = src->col;
  dst->col_max = src->col_max;
}

void reverse_t_line(t_line **ref) {
	t_line *prev;
	t_line *current;
	t_line *next;

	prev = NULL;
	current = *ref;
	next = NULL;
	while(current) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	(*ref) = prev;
}

int add_t_line(t_line **ref, int rank, t_line *src) {
	t_line *temp_ln;

	temp_ln = NULL;
	if(!(temp_ln = (t_line*)malloc(sizeof(t_line))))
		return (0);
  copy_t_line(temp_ln, src);
	temp_ln->id = rank;
	temp_ln->next = (*ref);
	(*ref) = temp_ln;
	return(1);
}


int all_lines_dup(t_line **ref, t_line *src) {
	int rank;
	int ret;

	rank = 0;
	ret = 0;
  while(src) {
		ret = add_t_line(ref, rank, src);
		if(!ret)
			break;
		rank++;
		src = src->next;
	}
	return(ret);
}


t_line *get_t_line(t_line *ln, int index) {
	while(ln) {
		if(ln->id == index) {
			return ln;
		}
		ln = ln->next;
	}
	return (0);
}


int fill_line(char **ref_string, char c, size_t len) {
  int index;

  index = 0;
  while (index < len) {
    (*ref_string)[index] = c;
    index++;
  }
  (*ref_string)[index] = '\0';
  return (1);
}

