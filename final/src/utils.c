#include "../includes/tetro.h"

int sqrt_ceil(float value) {
  int arg;
  int max;

	arg = 0;
  max = 46341; // max for the int value
  if(value < 0) {
    return(0);
  }

  while(arg * arg < value && arg * arg < max) {
    arg++;
  }
  return arg;
}


char	*strcpy_from_to(const char *src, int start, int end)
{
	char	*copy;
	int		index;
  int len;

	index = 0;
	len = end - start;
	copy = (char *)malloc(sizeof(char) * len + 1);
	if (copy == (char *)NULL)
		return (NULL);
	while (src[start + index] != '\0' && index < end)
	{
		copy[index] = src[start + index];
		index++;
	}
	copy[len] = '\0';
	return (copy);
}


void copy_t_puzzle_struct(t_puzzle *dst, t_puzzle *src) {
  dst->id = src->id;
	dst->tetro_num = src->tetro_num;
	dst->tetro_used = src->tetro_used;
	all_lines_dup(&dst->line, src->line);
	reverse_t_line(&dst->line);
	copy_ivec3(&dst->size, &src->size);
	dst->brick = src->brick;
	dst->space = src->space;
}

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
	dst->a = src->a;
	dst->b = src->b;

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