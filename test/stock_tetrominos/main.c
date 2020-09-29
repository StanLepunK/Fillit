

#include "tetro.h"




void clear_tetro_line(t_tetro_line **ref) {
  t_tetro_line *current = *ref;
  t_tetro_line *next;
  while(current) {
    next = current->next;
    free(current->str);
    free(current);
    current = next;
  }
  *ref = NULL;
}

int main() {
  // line
  char *str = "####";
  t_tetro_line *line;
  line = NULL;

  t_tetro *tetro;
  tetro = NULL;

  int line_length = strlen(str);



  for(int i = 0 ; i < line_length ; i++) {
    add_tetro_line(&line, str);
  }
  add_tetro(&tetro, line);
  clear_tetro_line(&line);
  
  // str = "....";
  // for(int i = 0 ; i < line_length ; i++) {
  //   add_tetro_line(&line, str);
  // }
  // add_tetro(&tetro, line);
  // clear_tetro_line(&line);


  // str = "****";
  // for(int i = 0 ; i < line_length ; i++) {
  //   add_tetro_line(&line, str);
  // }
  // add_tetro(&tetro, line);
  // clear_tetro_line(&line);
  
  print_tetro(tetro);

  return (0);
}