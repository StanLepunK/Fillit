#include "../includes/vec.h"

void ivec2_init(t_ivec2 *src) {
  src->x = 0;
  src->y = 0;
  src->set = set_ivec2;
  src->copy = copy_ivec2;
}

void set_ivec2(t_ivec2 *dst, int x, int y) {
  dst->x = x;
  dst->y = y;
}

void copy_ivec2(t_ivec2 *dst, t_ivec2 *src) {
  dst->x = src->x;
  dst->y = src->y;
}


void ivec3_init(t_ivec3 *src) {
  src->x = 0;
  src->y = 0;
  src->z = 0;
  src->set = set_ivec3;
  src->copy = copy_ivec3;
}

void set_ivec3(t_ivec3 *dst, int x, int y, int z) {
  dst->x = x;
  dst->y = y;
  dst->z = z;
}

void copy_ivec3(t_ivec3 *dst, t_ivec3 *src) {
  dst->x = src->x;
  dst->y = src->y;
  dst->z = src->z;
}

void ivec4_init(t_ivec4 *src) {
  src->x = 0;
  src->y = 0;
  src->z = 0;
  src->w = 0;
  src->copy = copy_ivec4;
}


void copy_ivec4(t_ivec4 *dst, t_ivec4 *src) {
  dst->x = src->x;
  dst->y = src->y;
  dst->z = src->z;
  dst->w = src->w;
}







