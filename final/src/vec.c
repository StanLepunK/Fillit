#include "../includes/vec.h"

void ivec2_set_functions(ivec2 *src) {
  src->set_xy = set_xy_ivec2;
  src->set = set_ivec2;
}

void set_xy_ivec2(ivec2 *dst, int x, int y) {
  dst->x = x;
  dst->y = y;
}

void set_ivec2(ivec2 *dst, ivec2 *src) {
  dst->x = src->x;
  dst->y = src->y;
}
