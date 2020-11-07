#include "../includes/tetro.h"

int copy_t_line_at(t_line *dst, const t_line *src, int index) {
	while(src) {	
		if(src->id == index) {
			copy_t_line(dst, src);
			return (1);
		}
		src = src->next;
	}
	return (0);
}

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

int malloc_line(char **ref, size_t len) {
	if(!((*ref) = (char*)malloc(sizeof(char) * (len + 1))))
    return (0);
	return(1);
}

int fill_line(char **ref, char c, size_t len) {
  int index;

  index = 0;
  while (index < len) {
    (*ref)[index] = c;
    index++;
  }
  (*ref)[index] = '\0';
  return (1);
}

int fill_t_line(t_line **ref, char c, size_t len) {
  if(!((*ref) = (t_line*)malloc(sizeof(t_line))))
    return (0);
	(*ref)->length = len;
	(*ref)->col_max = len;
	malloc_line(&(*ref)->content, len);
  fill_line(&(*ref)->content, c, len);
  return(1);
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