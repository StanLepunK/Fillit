#ifndef __vec_h__
#define __vec_h__


// ivec2
typedef struct s_ivec2 ivec2;
struct  s_ivec2 {
	int x;
	int y;
	void (*set)(ivec2*, int, int);
  void (*copy)(ivec2*, ivec2*);
	ivec2 *next;
};


typedef struct s_ivec3 ivec3;
struct  s_ivec3 {
	int x;
	int y;
  int z;
	void (*set)(ivec3*, int, int, int);
  void (*copy)(ivec3*, ivec3*);
	ivec3 *next;
};

// set function
void ivec2_init(ivec2 *src);
void ivec3_init(ivec3 *src);


// function ivec2
void set_ivec2(ivec2 *dst, int x, int y);
void copy_ivec2(ivec2 *dst, ivec2 *src);
// functions ivec3
void set_ivec3(ivec3 *dst, int x, int y, int z);
void copy_ivec3(ivec3 *dst, ivec3 *src);


#endif