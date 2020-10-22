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

void dup_tetro_line_list(t_line **ref_dst, t_line *src) {
	int rank;

	rank = 0;
	while(src) {
		add_t_line(ref_dst, rank, src);
		rank++;
		src = src->next;
	}
}

void copy_t_puzzle_struct(t_puzzle *dst, t_puzzle *src) {
  dst->id = src->id;
  
	dup_tetro_line_list(&dst->line, src->line);
  dst->size.x = src->size.x;
	dst->size.y = src->size.y;

	dst->brick = src->brick;
	dst->space = src->space;
}

int copy_t_line_at(t_line *dst, const t_line *src, int index) {
	// printf("copy at %i\n",index);
	while(src) {
		// printf("copy src->id %i\n",src->id);
		if(src->id == index) {
			// printf("copy\n");
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

t_line *get_t_line(t_line *ln, int index) {
	while(ln) {
		// printf("get src->id %i\n",ln->id);
		if(ln->id == index) {
			return ln;
		}
		ln = ln->next;
	}
	return (0);
}


int fill_line(char **ref, char c, size_t len) {
  int index;

  index = 0;
  if(!((*ref) = (char*)malloc(sizeof(char) * (len + 1))))
    return (0);
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
  fill_line(&(*ref)->content, c, len);
  return(1);
}