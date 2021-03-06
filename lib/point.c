#include "gba.h"
#include "screen.h"
#include "point.h"

inline void
new_Point (Point *p)
{
	p->move = move_point;
	p->draw = point_draw_point;
	
	p->distance = point_distance;

	p->set = set_point;
}

static inline int
point_distance (Point *p1, Point *p2)
{
	return (p2->x - p1->x) * (p2->x - p1->x) + (p2->y - p1->y) * (p2->y - p1->y);
}

static inline void
point_draw_point (Point *p, hword c)
{
	draw_point(p->x, p->y, c);
}

inline void
draw_point (int x, int y, hword c)
{
	hword *base;

	base = (hword *)VRAM;
	*(base + x + LCD_WIDTH * y) = c;
}

static inline void
int_draw_line(int x1, int x2, int y, hword c)
{
	hword *base;
	int i;

	base = (hword*)VRAM;

	for (i = 0; i<(x2-x1); i++) {
		*(base + x1 + LCD_WIDTH * y + i) = c;
	}
}

static inline int
move_point (Point *p, int x, int y)
{
	if ( in_screen( p->x + x, p->y + y ) ) {
		p->x += x;
		p->y += y;

		return 1;
	} else {
		return 0;
	}
}

static inline void
set_point (Point *p, int x, int y)
{
	p->x = x;
	p->y = y;
}
