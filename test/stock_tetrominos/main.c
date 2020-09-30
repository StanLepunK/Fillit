

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
  t_tetro_line *tetro_line;
  tetro_line = NULL;

  t_tetro *tetro;
  tetro = NULL;

  int num_row = 4;

  for(int i = 0 ; i < num_row ; i++) {
    add_tetro_line(&tetro_line, str, i);
  }
  add_tetro(&tetro, tetro_line);
  print_tetro_line(tetro->tetro_line);
  // clear_tetro_line(&tetro_line);
  
  // str = "....";
  // for(int i = 0 ; i < num_row ; i++) {
  //   add_tetro_line(&tetro_line, str, i);
  // }
  // add_tetro(&tetro, tetro_line);
  // clear_tetro_line(&tetro_line);


  // str = "****";
  // for(int i = 0 ; i < num_row ; i++) {
  //   add_tetro_line(&tetro_line, str, i);
  // }
  // add_tetro(&tetro, tetro_line);
  //clear_tetro_line(&tetro_line);
  
  // print_tetro(tetro);

  return (0);
}