#include "../includes/vec.h"

void ivec2_init(ivec2 *src) {
  src->x = 0;
  src->y = 0;
  src->set = set_ivec2;
  src->copy = copy_ivec2;
}

void ivec3_init(ivec3 *src) {
  src->x = 0;
  src->y = 0;
  src->z = 0;
  src->set = set_ivec3;
  src->copy = copy_ivec3;
}


void set_ivec2(ivec2 *dst, int x, int y) {
  dst->x = x;
  dst->y = y;
}

void copy_ivec2(ivec2 *dst, ivec2 *src) {
  dst->x = src->x;
  dst->y = src->y;
}

void set_ivec3(ivec3 *dst, int x, int y, int z) {
  dst->x = x;
  dst->y = y;
  dst->z = z;
}

void copy_ivec3(ivec3 *dst, ivec3 *src) {
  dst->x = src->x;
  dst->y = src->y;
  dst->z = src->z;
}
