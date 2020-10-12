#include "../includes/tetro.h"

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

void copy_t_line_struct(t_line *dst, const t_line *src) {
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
  copy_t_line_struct(temp_ln, src);
	temp_ln->id = rank;
	temp_ln->next = (*ref);
	(*ref) = temp_ln;
	return(1);
}