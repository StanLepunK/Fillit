#include "block.h"

void line_check(t_line *t_ln, char *line) {
	char	c;
	char previous;

  t_ln->state = t_ln->threshold;
	if(t_ln->length == t_ln->col_max) {
		t_ln->state = 0;
		previous = 0;
    // need to pass line, to use to read it, without use an index argument... to keep line under 25 norminette suck
    while((c = *line++) !=  '\0') {
			if(c == t_ln->b || c == t_ln->a) {
				if(c == t_ln->a) {
					t_ln->brick += 1;
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

  t_ln->valid = 0;
  if(t_ln->state < t_ln->threshold) {
		t_ln->valid = 1;
	}
}

void line_set(t_line *t_ln, char *line) {
	t_ln->brick = 0;
	t_ln->state = 0;
	t_ln->valid = 0;
	t_ln->content = ft_strcpy(t_ln->content, line);
  t_ln->length = ft_strlen(t_ln->content);
}


void compare_lines(t_block *t_blk, t_line *t_ln) {
	int index;

	index = 0;
	while(index < t_ln->col_max) {
    printf("compare_lines() by char >>> curent <> previous >>> %c <> %c\n",t_ln->content[index], t_blk->p_line.content[index]);
    if(t_ln->content[index] == t_ln->a && t_ln->content[index] == t_blk->p_line.content[index]) {
			t_ln->valid = 1;
      break;
		}
		index++;
	}
}