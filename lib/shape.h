#ifndef _SHAPE_H_
#define _SHAPE_H_

typedef struct shape Shape;

typedef struct box {
	//int type;
	int width;
	int height;

	Point apex[4];

	void (*update_apex) (Shape *);
} Box;

typedef struct circle {
	//int type;
	int r;

	int  (*all_border) (Shape *, int (*)(int, int));
	int  (*some_border)(Shape *, int (*)(int, int));
	void (*do_border) (Shape *, void (*)(int, int, hword));
} Circle;

struct shape {
	struct shape *next;

	Point p;
	hword color;
	Velocity v;
	int type;

	union {
		Circle circle;
		Box box;
	} as;

	void (*draw)(struct shape *);
	int  (*move)(struct shape *, int, int);
	void (*erase)(struct shape *);

	int (*in_screen)(struct shape *);
	int (*on_area_border)(struct shape *);

	void (*run)(struct shape *);

	int (*touch)(struct shape *);
};

extern void new_Shape (Shape *);

extern int move_shape (Shape *, int, int);

extern void shape_run (Shape *);
extern int touch_shapes (Shape *);
#endif
