#ifndef DRAWER_H_
	#define DRAWER_H_

#include "Sprite.h"

class Drawer {
	public:
		static Uint32 color;

		static void SetColor(int r, int g, int b);
		static void SetColor(int r, int g, int b, int a);

		static void Point(int x, int y);
		static void Line(int x1, int y1, int x2, int y2);
		static void Rectangle(Rect rec, bool fill);
};

#endif