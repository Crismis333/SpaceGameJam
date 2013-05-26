#include "Drawer.h"
#include "App.h"

Uint32 Drawer::color = 0;

void Drawer::SetColor(int R, int G, int B) {
	color = SDL_MapRGB( App::Application.GetDisplay()->format, R, G, B );
}

void Drawer::Point(int X, int Y)
{
	if (X >= SCREEN_WIDTH || X < 0)
		return;
	if (Y >= SCREEN_HEIGHT || Y < 0)
		return;

	Uint32 *pixmem32;
  
	pixmem32 = (Uint32*) App::Application.GetDisplay()->pixels  + Y*SCREEN_WIDTH + X;
	*pixmem32 = color;
}

//A Method that draws a line on screen, it uses Bresenhams Line Algorithm
//Found on http://en.wikipedia.org/wiki/Bresenham's_line_algorithm
void Drawer::Line(int X1, int Y1, int X2, int Y2)
{
	bool RunLoop = true;
	int sX = 0, sY = 0, err = 0, e2 = 0;
	int dX = abs(X2-X1);
	int dY = abs(Y2-Y1);

	if (X1 < X2)
		sX = 1;
	else
		sX = -1;

	if (Y1 < Y2)
		sY = 1;
	else
		sY = -1;

	err = dX - dY;
	
	while(RunLoop)
	{
		Point(X1, Y1);
		if (X1 == X2 && Y1 == Y2)
			RunLoop = false;
		e2 = 2*err;
		if (e2 > -dY)
		{
			err = err - dY;
			X1 = X1 + sX;
		}
		if (e2 < dX)
		{
			err = err + dX;
			Y1 = Y1 + sY;
		}
	}
}

void Drawer::Rectangle(Rect rec, bool fill) {
	if (fill) {
		for (int x = rec.X; x < rec.X+rec.Width; x++) {
			for (int y = rec.Y; y < rec.Y + rec.Height; y++) {
				Point(x,y);
			}
		}
	}
	else {
		Line(rec.X,rec.Y,rec.X+rec.Width,rec.Y);
		Line(rec.X,rec.Y,rec.X,rec.Y+rec.Height);

		Line(rec.X+rec.Width, rec.Y, rec.X+rec.Height, rec.Y+rec.Width);
		Line(rec.X, rec.Y+rec.Width, rec.X+rec.Height, rec.Y+rec.Width);
	}
}