#ifndef _SHAPE_H_
#define _SHAPE_H_

typedef struct shape Shape;

typedef struct box {
	int width;
	int height;

	Point apex[4];

	void (*set)    (Shape *, int, int, int, int);
	int  (*resize) (Shape *, int, int);

	void (*update_apex) (Shape *);
} Box;

typedef struct circle {
	int r;

	void (*set) (Shape *, int, int, int);

	int  (*all_border) (Shape *, int (*)(int, int));
	int  (*some_border) (Shape *, int (*)(int, int));
	void (*do_border) (Shape *, void (*)(int, int, hword));
} Circle;

struct shape {
	struct shape *next;
	struct shape *prev;

	Point p, pre_p;
	hword color;
	Velocity v;

	int type;
	int id;
	int breakable;
	int mn;

	union {
		Circle circle;
		Box box;
	} as;

	void (*move_callback)  (struct shape *, int);
	int  (*touch_callback) (struct shape *, struct shape *);

	void (*draw) (struct shape *);
	int  (*move) (struct shape *, int, int);
	void (*erase) (struct shape *);
	void (*redraw) (struct shape *);

	void (*draw_all) (struct shape *);
	void (*erase_all) (struct shape *);
	void (*redraw_all) (struct shape *);

	int (*in_screen) (struct shape *);
	int (*on_area_border) (struct shape *);
	int (*on_bottom_border) (struct shape *);

	int (*run) (struct shape *);

	int (*touch) (struct shape *);

	int  (*same_space) (struct shape *, struct shape *);
	void (*update_mn)  (struct shape *);
};

extern inline void new_Shape (Shape *);

extern void chain_shapes (int, ...);

extern inline int  move_shape (Shape *, int, int);
extern inline void erase_shape (Shape *);
extern inline void redraw_shape (Shape *);

extern inline void draw_all_shapes (Shape *);
extern inline void erase_all_shapes (Shape *);
extern inline void redraw_all_shapes (Shape *);

extern int shape_run (Shape *);
extern inline void break_shape (Shape *);
extern int touch_shapes (Shape *);

//extern inline byte separate_bit (byte);
//extern inline byte morton_number (int, int);
//extern inline int  mn_index (int, int, int, int);
//extern inline int  box_mn (Shape *);
//extern inline int  circle_mn (Shape *);
//extern inline void update_mn (Shape *);
//extern inline int  same_space (Shape *, Shape *);

#endif
