
#include "../includes/tetro.h"

void block_dup(t_block *t_blk, t_line *t_ln) {
	char *temp_str;

	temp_str = ft_strdup(t_ln->content);
	// ft_memmove(t_blk->p_line->content,temp_str,ft_strlen(temp_str));
	ft_strncpy(t_blk->p_line->content,temp_str,ft_strlen(temp_str));
	t_blk->p_line->empty = t_ln->empty;
	t_blk->row += 1;
	free(temp_str);
}

void checker_block_set(t_block *t_blk, t_line *t_ln, char *line) {
  checker_line(t_ln, line);
	t_blk->brick += t_ln->brick;
	if(t_ln->valid == 1 && t_blk->row > 0 && t_blk->brick < t_blk->brick_max) {
		t_ln->valid = 0;
		if(ft_strlen(t_blk->p_line->content) == t_blk->col_max) { 
      checker_compare_lines(t_blk, t_ln);
			// free(t_blk->p_line->content); // remove with new function block_dup();
    }
	}

	if(t_ln->valid == 1) {
		block_dup(t_blk, t_ln);
	}
	
	if(t_blk->row == t_blk->row_max 
      && t_blk->brick == t_blk->brick_max 
      && t_ln->state < t_ln->threshold 
      && t_ln->valid == 1) {
		t_blk->valid = 1;
	}
	
	if(t_ln->state >= t_ln->threshold) {
		block_set_arguments(t_blk);
	}
}

void info_line(char elem, char previous, t_line *t_ln) {
	if(elem == t_ln->pair.a) {
		t_ln->empty = 0;
		t_ln->brick++;
	}
	if(previous != 0 && previous != elem) {
		t_ln->state++;
	}
	if(elem == t_ln->pair.b && t_ln->state < 1) {
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
			if(c == t_ln->pair.b || c == t_ln->pair.a) {
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
	if(t_blk->p_line->empty == 0) {
		while(index < t_ln->col_max) {
			if(t_ln->content[index] == t_ln->pair.a && t_ln->content[index] == t_blk->p_line->content[index]) {
				t_ln->valid = 1;
				break;
			}
			index++;
		}
	} else {
		t_ln->valid = 1;
	}
}


int build(const int fd, t_block **ref_blk, t_tetro **ref_tetro, t_pair *pair) {
	char *line;
  t_line *buffer;
	t_line *tl;
	t_tetro *temp_tetro;

	temp_tetro = (*ref_tetro);
	tl = NULL;
  new_t_line(&buffer, pair);
	new_t_block(ref_blk);
	while (get_next_line(fd, &line) > 0) {
		build_dict_tetrominos((*ref_blk), &temp_tetro, &tl, ft_strlen(line));
		checker_line_set(buffer, line);
		checker_block_set((*ref_blk), buffer, line);
		if(buffer->valid) {
			add_t_line(&tl, (*ref_blk)->row, buffer);
		} else {
			free_line_list(&tl);
		}
		free(line);
	}
	get_next_line(fd, &line);
	free_line(buffer);
	free(line);
	close(fd);
	(*ref_tetro) = temp_tetro;
	return (1);
}



