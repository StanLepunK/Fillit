#include "block.h"

void block_set(t_block *t_blk, t_line *t_ln, char *line) {
	// printf("0 block_set() t_ln->content: %s\n", t_ln->content);
  line_check(t_ln, line);
	// printf("1 block_set() t_ln->content: %s\n", t_ln->content);
	t_blk->brick += t_ln->brick;
	// printf("t_ln->valid: %i\n", t_ln->valid);
  if(t_ln->valid == 1) {
		// printf("ft_strlen(t_blk->previous_line): %lu\n", ft_strlen(t_blk->previous_line));
		// printf("ft_strlen(t_ln->content): %lu\n", ft_strlen(t_ln->content));
		// printf("t_ln->content: %s\n", t_ln->content);

		// if(t_blk->p_line->length == t_blk->col_max) {
		if(ft_strlen(t_blk->previous_line) == t_blk->col_max) {
      compare_lines(t_blk, t_ln);
    }
		t_blk->previous_line = ft_strcpy(t_blk->previous_line, t_ln->content);
		// t_blk->p_line->content = ft_strcpy(t_blk->p_line->content, t_ln->content);
		// t_blk->p_line->length = t_ln->length;
	}
	t_blk->row += 1;
	if(t_blk->row == t_blk->row_max 
      && t_blk->brick == t_blk->brick_max 
      && t_ln->state < t_ln->threshold 
      && t_ln->valid == 1) {
		printf("add block\n");
		block_init(t_blk);
	}	
	if(t_ln->state >= t_ln->threshold) {
		block_init(t_blk);
	}
}

void checker(const int fd, t_block *temp_block) {
	char *line;
  t_line temp_line;

  line_init(&temp_line);
	block_init(temp_block);
  
	while (get_next_line(fd, &line) > 0) {
		line_set(&temp_line, line);
		block_set(temp_block, &temp_line, line);
		// free(temp_line.content);
		free(line);
	}
	get_next_line(fd, &line);
	free(line);
	close(fd);
}


