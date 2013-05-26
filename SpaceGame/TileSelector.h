#ifndef TILESELECTOR_H_
#define TILESELECTOR_H_

#include "Object.h"

class TileSelector : public Object {
	private:
		int padLeft;
		int padRight;
		int padTop;
		int padBot;

		int padBetween;

	public:
		TileSelector();

		TileSelector(int W, int H);

		void OnRender(SDL_Surface* display);

		//Events
		void OnMouseMove(int mX, int mY, int relX, int relY, bool Left, bool Right, bool Middle);

		void OnLButtonDown(int mX, int mY);

		void OnRButtonDown(int mX, int mY);

	private:
		int CalcX(int x);

		int CalcY(int y);
};

#endif