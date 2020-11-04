#include "../includes/tetro.h"

void set_try(t_try *try, t_ivec3 size_pzl, t_tetro *t) {
  try->name = t->name;
  try->index.set(&try->index,0,0);
  try->offset.x = size_pzl.x - t->size.x + 1;
  try->offset.y = size_pzl.y - t->size.y;
  try->num = 0;
  try->put = 0;
  try->max = (size_pzl.x * size_pzl.y) - (t->size.x * t->size.y) - 1;
  if(try->max < 1) {
    try->max = 1;
  }
}

void update_try(t_try *try) {
  try->index.x++;
  if(try->index.x > try->offset.x) {
    try->index.x = 0;
    try->index.y++;
  }
  try->num++;
}