
#include "../header/tetro.h"




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

void add_tetrominos(t_block *t_blk, t_tetro **ref_tetro, t_tetro_line **ref_tl) {
		t_tetro *temp = (*ref_tetro);
		tetro_add(&temp, *ref_tl);
		tetro_clear_line(ref_tl);
		checker_block_set_arguments(t_blk);
		(*ref_tetro) = temp;
}

void build_dict_tetrominos(t_block *t_blk , t_tetro **ref_tetro, t_tetro_line **ref_tl, int length) {
	t_tetro *temp_tetro = (*ref_tetro);
	t_tetro_line *temp_tl = (*ref_tl);

	if(t_blk->valid && length == 0) {
		t_blk->ready_to_add = 1;
	}

	if(t_blk->ready_to_add && t_blk->row == t_blk->row_max) {
		add_tetrominos(t_blk, &temp_tetro, &temp_tl);
	}
	(*ref_tetro) = temp_tetro;
	(*ref_tl) = temp_tl;
}


int checker(const int fd, t_block *t_blk, t_tetro **ref_tetro) {
	char *line;
  t_line temp_line;
	t_tetro_line *tl;
	t_tetro *temp_tetro = (*ref_tetro);

	tl = NULL;
  checker_line_init(&temp_line);
	checker_block_init(t_blk);
	while (get_next_line(fd, &line) > 0) {
		build_dict_tetrominos(t_blk, &temp_tetro, &tl, ft_strlen(line));
		checker_line_set(&temp_line, line);
		checker_block_set(t_blk, &temp_line, line);
		if(temp_line.valid) {
			// tetro_add_line(&tl, t_blk->row, &temp_line);
			tetro_add_line(&tl, t_blk->row, temp_line.content);
		} else {
			tetro_clear_line(&tl);
		}
		free(line);
	}
	get_next_line(fd, &line);
	free(line);
	close(fd);
	(*ref_tetro) = temp_tetro;
	return (1);
}



