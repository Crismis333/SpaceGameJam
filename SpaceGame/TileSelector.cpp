#include "TileSelector.h"
#include "Drawer.h"
#include "App.h"

TileSelector::TileSelector() {
	padLeft = 32;
	padRight = 32;
	padTop = 64;
	padBot = 96;

	padBetween = 96;
}

TileSelector::TileSelector(int W, int H) {
	padLeft = 32;
	padRight = 32;
	padTop = 72;
	padBot = 128;

	padBetween = 96;

	this->Width = W;
	this->Height = H;
}

void TileSelector::OnRender(SDL_Surface* display) {
	Drawer::SetColor(0,0,0);
	Drawer::Rectangle(Rect(X,Y,Width,Height), false);
}

void TileSelector::OnMouseMove(int mX, int mY, int relX, int relY, bool Left, bool Right, bool Middle) {
	int mouseX = mX;
	int mouseY = mY;

	if (mouseX <= padLeft)
		mouseX = padLeft;
	if (mouseX > SCREEN_WIDTH - padRight - 1)
		mouseX = SCREEN_WIDTH - padRight - 1;

	if (mouseY <= padTop)
		mouseY = padTop;
	if (mouseY > SCREEN_HEIGHT - padBot - 1)
		mouseY = SCREEN_HEIGHT - padBot - 1;

	float newX = 0;
	float newY = 0;

	newX = (float)(mouseX / Width) * Width;
	newY = (float)(mouseY / (Height + padBetween)) * (Height + padBetween);

	X = newX + 1;
	Y = newY + padTop + 1;
}