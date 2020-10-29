#include "../includes/tetro.h"

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
	ivec2_init(&buffer->offset);
	ivec2_init(&buffer->size);
	ivec2_init(&buffer->canvas);
	buffer->offset.copy(&buffer->offset,&(*ref)->offset);
	buffer->canvas.copy(&buffer->canvas,&(*ref)->canvas);
	buffer->size.copy(&buffer->size,&(*ref)->size);
	buffer->start = (*ref)->start;
	buffer->end = (*ref)->end;
	tetro_line_dup(&buffer->line, (*ref)->line);
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
	ret = tetro_line_dup(&temp_tetro->line, tl);
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

int size_t_tetro(t_tetro *tetro) {
	int size;

	size = 0;
	while(tetro) {
		size++;
		tetro = tetro->next;
	}
	return (size);
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



int tetro_line_dup(t_line **ref, t_line *src) {
	int rank;
	int ret;

	rank = 0;
	ret = 0;
  while(src) {
		ret = add_t_line(ref, rank, src);
		if(!ret)
			break;
		rank++;
		src = src->next;
	}
	return(ret);
}



void tetro_line_print(t_line *ln) {
	while(ln) {
		printf("str: %s\n",ln->content);
		ln = ln->next;
  }
}

void print_tetro(t_tetro *t, int print_info_is) {
	tetro_line_print(t->line);
	if(print_info_is) {
		printf("name: %c \n",t->name);
		printf("id: %i \n",t->id);
		printf("offset x: %i \n",t->offset.x);
		printf("offset y: %i \n",t->offset.y);
		printf("size x: %i \n",t->size.x);
		printf("size y: %i \n",t->size.y);
		printf("start.x: %i\n", t->start.x);
		printf("end.x: %i\n", t->end.x);
	}
}


void print_all_tetro(t_tetro *t, int print_info_is) {
	printf("PRINT ALL TETROMINOS\n");
  while(t) {
    printf("\nprint tetromino %c\n", t->name);
		print_tetro(t, print_info_is);
    t = t->next;
  }
}

void calc_size_x(t_tetro *t, t_line *ln) {
	int index;
	char c;

	index  = 0;
	while(ln->content[index]) {
		c = ln->content[index];
		if(c == ln->a) {
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

void tetro_clean_and_format(t_tetro *t) {
	char name;
	int id;
	
	name = 'A';
	id = 0;
  while(t) {
		tetro_line_clean(t, t->line);
		t->name = (name++);
		t->id = (id++);
    t = t->next;
  }
}