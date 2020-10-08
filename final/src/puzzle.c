#include "../includes/tetro.h"

char	*r_copy_from_to(const char *src, int start, int end)
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



void puzzle_line_solve(t_puzzle **ref_pzl, t_tetro *t) {
  t_puzzle *temp = (*ref_pzl);
  printf("piece of puzzle\n");
  int iter_x = 0;
  int iter_y = 0;
	while(iter_y < t->size.y + t->offset.y) {
    if(iter_y >= t->offset.y) {
      char *res;
      int end = t->size.x + t->offset.x;
      res = r_copy_from_to(t->tetro_line->content, t->offset.x, end);
      printf("str format: %s\n",res);
    }
		t->tetro_line = t->tetro_line->next;
    iter_y++;
  }
  (*ref_pzl) = temp;
}

int puzzle(t_tetro *t, int print_info_is) {
  if(print_info_is)
    printf("PRINT PUZZLE\n");
  t_puzzle *pzl;
  pzl = NULL;
  if(!(pzl = (t_puzzle*)malloc(sizeof(t_puzzle))))
		return (0);

  while(t) {
    if(print_info_is)
      printf("\nnext piece to solve puzzle\n");
    puzzle_line_solve(&pzl, t);

    t = t->next;
  }
  return (1);
}