#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_tetro_line t_tetro_line;
struct s_tetro_line {
  char *str;
  int length;
  t_tetro_line *next;
};


typedef struct s_tetro t_tetro;
struct s_tettro {


};


typedef struct s_dict t_dict;
struct s_dict {


};


int main() {
  char *str = "####";
  t_tetro_line line;
  line.length = strlen(str);

  for(int i = 0 ; i < line.length ; i++) {
    line.str = strdup(str);
    printf("%s\n",line.str);
    free(line.str);

  }

  return (0);
}