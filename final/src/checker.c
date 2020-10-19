
#include "../includes/tetro.h"




void checker_block_set(t_block *t_blk, t_line *t_ln, char *line) {
  checker_line(t_ln, line);
	t_blk->brick += t_ln->brick;
	if(t_ln->valid == 1 && t_blk->row > 0 && t_blk->brick < t_blk->brick_max) {
		t_ln->valid = 0;
		if(ft_strlen(t_blk->p_line.content) == t_blk->col_max) { 
      checker_compare_lines(t_blk, t_ln);
			free(t_blk->p_line.content);
    }
	}

	if(t_ln->valid == 1) {
		t_blk->p_line.content = ft_strdup(t_ln->content);
		t_blk->p_line.empty = t_ln->empty;
		t_blk->row += 1;
	}
	
	if(t_blk->row == t_blk->row_max 
      && t_blk->brick == t_blk->brick_max 
      && t_ln->state < t_ln->threshold 
      && t_ln->valid == 1) {
		t_blk->valid = 1;
	}
	
	if(t_ln->state >= t_ln->threshold) {
		checker_block_set_arguments(t_blk);
	}
}

void info_line(char elem, char previous, t_line *t_ln) {
	if(elem == t_ln->a) {
		t_ln->empty = 0;
		t_ln->brick++;
	}
	if(previous != 0 && previous != elem) {
		t_ln->state++;
	}
	if(elem == t_ln->b && t_ln->state < 1) {
		t_ln->offset++;
	}
}

void checker_line(t_line *t_ln, char *line) {
	char	c;
	char previous;

  t_ln->state = t_ln->threshold;
	if(t_ln->length == t_ln->col_max) {
		t_ln->state = 0;
		previous = 0;
    while((c = *line++) !=  '\0') {
			if(c == t_ln->b || c == t_ln->a) {
				info_line(c, previous, t_ln);
				previous = c;
			} else {
        t_ln->state = t_ln->threshold;
				break;
			}
		}
		t_ln->space = t_ln->length - t_ln->brick;
	}

  t_ln->valid = 0;
  if(t_ln->state < t_ln->threshold) {
		t_ln->valid = 1;
	}
}

void checker_line_set(t_line *t_ln, char *line) {
	t_ln->brick = 0;
	t_ln->state = 0;
	t_ln->valid = 0;
	t_ln->empty = 1;
	t_ln->offset = 0;
	t_ln->content = ft_strcpy(t_ln->content, line);
  t_ln->length = ft_strlen(t_ln->content);
}


void checker_compare_lines(t_block *t_blk, t_line *t_ln) {
	int index;

	index = 0;
	if(t_blk->p_line.empty == 0) {
		while(index < t_ln->col_max) {
			if(t_ln->content[index] == t_ln->a && t_ln->content[index] == t_blk->p_line.content[index]) {
				t_ln->valid = 1;
				break;
			}
			index++;
		}
	} else {
		t_ln->valid = 1;
	}
}



