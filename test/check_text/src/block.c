#include "block.h"

void block_set(t_block *t_blk, t_line *t_ln, char *line) {
  line_check(t_ln, line);
	t_blk->brick += t_ln->brick;
	if(t_ln->valid == 1 && t_blk->row > 0 && t_blk->brick < t_blk->brick_max) {
		t_ln->valid = 0;
		if(ft_strlen(t_blk->p_line.content) == t_blk->col_max) { 
      compare_lines(t_blk, t_ln);
			free(t_blk->p_line.content);
    }
	}

	if(t_ln->valid == 1) {
		t_blk->p_line.content = ft_strdup(t_ln->content);
		t_blk->row += 1;
	}
		
	if(t_blk->row == t_blk->row_max 
      && t_blk->brick == t_blk->brick_max 
      && t_ln->state < t_ln->threshold 
      && t_ln->valid == 1) {
		printf("block_set() >>> add block\n");
		printf("block_set() >>> previous: %s\n",t_blk->p_line.content);
		printf("block_set() >>> current: %s\n",t_ln->content);
		block_set_arguments(t_blk);
	}
	
	if(t_ln->state >= t_ln->threshold) {
		block_set_arguments(t_blk);
	}
}

int checker(const int fd, t_block *t_blk) {
	char *line;
  t_line temp_line;
  line_init(&temp_line);
	block_init(t_blk);
  
	while (get_next_line(fd, &line) > 0) {
		line_set(&temp_line, line);
		block_set(t_blk, &temp_line, line);
		free(line);
	}
	get_next_line(fd, &line);
	free(line);
	close(fd);
	return (1);
}


