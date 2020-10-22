#ifndef __vec_h__
#define __vec_h__


// ivec2
typedef struct s_ivec2 t_ivec2;
struct  s_ivec2 {
	int x;
	int y;
	void (*set)(t_ivec2*, int, int);
  void (*copy)(t_ivec2*, t_ivec2*);
	t_ivec2 *next;
};


typedef struct s_ivec3 t_ivec3;
struct  s_ivec3 {
	int x;
	int y;
  int z;
	void (*set)(t_ivec3*, int, int, int);
  void (*copy)(t_ivec3*, t_ivec3*);
	t_ivec3 *next;
};

typedef struct s_ivec4 t_ivec4;
struct  s_ivec4 {
	int x;
	int y;
  int z;
	int w;
  void (*copy)(t_ivec4*, t_ivec4*);
	t_ivec4 *next;
};

// set function
void ivec2_init(t_ivec2 *src);
void ivec3_init(t_ivec3 *src);
void ivec4_init(t_ivec4 *src);


// function ivec2
void set_ivec2(t_ivec2 *dst, int x, int y);
void copy_ivec2(t_ivec2 *dst, t_ivec2 *src);
// functions ivec3
void set_ivec3(t_ivec3 *dst, int x, int y, int z);
void copy_ivec3(t_ivec3 *dst, t_ivec3 *src);
//function ivec4
void copy_ivec4(t_ivec4 *dst, t_ivec4 *src);



#endif