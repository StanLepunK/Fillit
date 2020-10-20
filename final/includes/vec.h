#ifndef __vec_h__
#define __vec_h__

typedef struct s_ivec2 ivec2;
struct  s_ivec2 {
	int x;
	int y;
	void (*set_xy)(ivec2*, int, int);
  void (*set)(ivec2*, ivec2*);
	ivec2 *next;
};

void ivec2_set_functions(ivec2 *src);
// functions
void set_xy_ivec2(ivec2 *dst, int x, int y);
void set_ivec2(ivec2 *dst, ivec2 *src);

#endif