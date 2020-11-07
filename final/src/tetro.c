#include "../includes/tetro.h"

t_tetro *get_t_tetro(t_tetro *t, int index) {
	while(t) {
		if(t->id == index) {
			return t;
		}
		t = t->next;
	}
	return (0);
}

int size_t_tetro(t_tetro *tetro) {
	int size;

	size = 0;
	while(tetro) {
		size++;
		tetro = tetro->next;
	}
	return (size);
}



void tetro_lines_dup(t_line **ref, t_tetro *tetro) {
	int index;

	index = 0;
  while(index < tetro->canvas.y) {
		if(!add_t_line(ref, index, get_t_line(tetro->line, index)))
			break;
		index++;	
	}
}

t_tetro *tetro_dup(t_tetro **ref) {
	t_tetro *buffer;

	buffer = NULL;
	if(!(buffer = (t_tetro*)malloc(sizeof(t_tetro))))
		return (0);
	tetro_init(buffer);
	buffer->id = (*ref)->id;
	buffer->name = (*ref)->name;
	// printf("tetro_dup() buffer->name: %c\n",buffer->name);
	// printf("tetro_dup() (*ref)->name: %c\n",(*ref)->name);
	ivec2_init(&buffer->pos);
	ivec2_init(&buffer->offset);
	ivec2_init(&buffer->size);
	ivec2_init(&buffer->canvas);
	buffer->offset.copy(&buffer->offset,&(*ref)->offset);
	buffer->canvas.copy(&buffer->canvas,&(*ref)->canvas);
	buffer->size.copy(&buffer->size,&(*ref)->size);
	buffer->start = (*ref)->start;
	buffer->end = (*ref)->end;
	// tetro_lines_dup(&buffer->line, (*ref)); // copy in the same order
	all_lines_dup(&buffer->line, (*ref)->line);
	return (buffer);
}

int tetro_add(t_tetro **ref, t_line *tl, int id) {
	t_tetro *temp_tetro;
	int ret;

	ret = 0;
	temp_tetro = NULL;
	if(!(temp_tetro = (t_tetro*)malloc(sizeof(t_tetro))))
		return (0);
	tetro_init(temp_tetro);
	temp_tetro->id = (++id);
	ret = all_lines_dup(&temp_tetro->line, tl);
	temp_tetro->next = (*ref);
  (*ref) = temp_tetro;
	return(ret);
}

void add_tetrominos(t_block *t_blk, t_tetro **ref_tetro, t_line **ref_tl) {
	t_tetro *temp;

	temp = (*ref_tetro);
	if(temp) {
		tetro_add(&temp, *ref_tl, temp->id);
	} else {
		tetro_add(&temp, *ref_tl, -1);
	}
	temp->canvas.x = t_blk->row_max;
	temp->canvas.y = t_blk->col_max;
	free_line_list(ref_tl);
	block_set_arguments(t_blk);
	(*ref_tetro) = temp;
}

void build_dict_tetrominos(t_block *t_blk , t_tetro **ref_tetro, t_line **ref_tl, int length) {
	t_tetro *temp_tetro;
	t_line *temp_tl;

	temp_tetro = (*ref_tetro);
	temp_tl = (*ref_tl);
	if(t_blk->valid && length == 0) {
		t_blk->ready_to_add = 1;
	}

	if(t_blk->ready_to_add && t_blk->row == t_blk->row_max) {
		add_tetrominos(t_blk, &temp_tetro, &temp_tl);
	}
	(*ref_tetro) = temp_tetro;
	(*ref_tl) = temp_tl;
}

void print_all_tetro(t_tetro *t, int print_info_is) {
	printf("PRINT ALL TETROMINOS\n");
  while(t) {
    printf("\nprint tetromino %c\n", t->name);
		tetro_print(t, print_info_is);
    t = t->next;
  }
}

void calc_size_x(t_tetro *t, t_line *ln) {
	int index;
	char c;

	index  = 0;
	while(ln->content[index]) {
		c = ln->content[index];
		if(c == ln->pair.a) {
			if(t->start.x < 0 || t->start.x > index)
				t->start.x = index;
			if(t->end.x < index)
				t->end.x = index;
		}
		index++;
	}
}


void tetro_line_clean(t_tetro *t, t_line *ln) {
	int lock_x;
	int lock_y;

	lock_x = 0;
	lock_y = 0;
	while(ln) {
		if(!ln->empty) {
			t->size.y++;
			lock_y = 1;
		}
		if(ln->empty && !lock_y) {
			t->offset.y++;
		}

		if(t->offset.x <= ln->offset && !lock_x) {
			t->offset.x = ln->offset;
			lock_x = 1;
		} else if(ln->offset < t->offset.x) {
			t->offset.x = ln->offset;
		}

		calc_size_x(t, ln);
		ln = ln->next;
	}
	t->size.x = t->end.x - t->start.x + 1;

}

void reverse_t_tetro(t_tetro **ref_tetro) {
	t_tetro *prev;
	t_tetro *current;
	t_tetro *next;

	prev = NULL;
	current = *ref_tetro;
	next = NULL;
	while(current) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	(*ref_tetro) = prev;
}

void tetro_clean_and_format(t_tetro **ref_tetro) {
	char name;
	int index;
	int length;
	t_tetro *buffer;
	
	name = 'A';
	length = size_t_tetro((*ref_tetro));
	index = 0;
	while(index < length) {
		buffer = get_t_tetro((*ref_tetro), index);
		tetro_line_clean(buffer, buffer->line);
		buffer->name = name++;
		buffer->id = index;
		index++;
	}
}