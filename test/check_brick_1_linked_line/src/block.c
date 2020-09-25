#include "block.h"


void line_check(t_block *t_blk, t_line *t_ln) {
	char	c;
	char previous;

  t_ln->state = t_ln->threshold;
	if(ft_strlen(t_ln->content) == t_blk->row_max) { // why row_max it's weird ?
		t_ln->state = 0;
		previous = 0;
		while((c = *t_ln->content++) !=  '\0') {
			if(c == t_ln->b || c == t_ln->a) {
				if(c == t_ln->a) {
					t_blk->brick += 1;
				}
				if(previous != 0 && previous != c) {
					t_ln->state++;
				}
				previous = c;
			} else {
        t_ln->state = t_ln->threshold;
				break;
			}
		}
	}

	// printf("temp->valid %i, temp->state %i, temp->threshold %i\n",temp->valid, temp->state, temp->threshold);
  t_ln->valid = 0;
  if(t_ln->state < t_ln->threshold) {
		t_ln->valid = 1;
	}
}


void compare_lines(t_block *t_blk, t_line *t_ln) {
	int index;

	index = 0;
	while(index < t_blk->col_max && t_blk->brick <= t_blk->brick_max) {
		if(t_ln->content[index] == t_ln->a && t_ln->content[index] == t_blk->previous_line[index]) {
			t_ln->valid = 1;
      // break;
		} else {
      t_ln->valid = 0;
    }
		if(t_ln->content[index] == t_ln->b) {
      t_ln->valid = 1;  
    }
		index++;
	}
}


void block_set(t_block *t_blk, t_line *t_ln) {
  line_check(t_blk, t_ln);
  if(t_ln->valid == 1) {
		if(ft_strlen(t_blk->previous_line) == t_blk->col_max) {
      compare_lines(t_blk, t_ln);
    }

		t_blk->previous_line = ft_strcpy(t_blk->previous_line, t_ln->content);
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
    temp_line.content = ft_strcpy(temp_line.content, line);
		block_set(temp_block, &temp_line);
		// free(temp_line.content);
		free(line);
	}
	get_next_line(fd, &line);
	free(line);
	close(fd);
}


