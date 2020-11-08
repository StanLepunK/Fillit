#include "../includes/tetro.h"

void set_try(t_try *try, t_puzzle *pzl, t_tetro *tetro) {
  try->name = tetro->name;
  try->index.copy(&try->index,&pzl->start_pos);
  try->offset.x = pzl->size.x - tetro->size.x + 1;
  try->offset.y = pzl->size.y - tetro->size.y;
  try->num = 0;
  try->max = (try->offset.x + 1) * (try->offset.y + 1) - 1;
  if(try->max < 1) {
    try->max = 1;
  }
}

void update_try(t_try *try) {
  try->index.x++;
  if(try->index.y > try->offset.y)
    try->index.y = 0;
  if(try->index.x > try->offset.x) {
    try->index.x = 0;
    try->index.y++;
  }
  try->num++;
}