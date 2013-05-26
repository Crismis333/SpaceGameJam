#include "TileSelector.h"
#include "Drawer.h"
#include "App.h"
#include <string>
#define CROOM App::Application.CurrentRoom

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
	Drawer::SetColor(0,145,0);
	Drawer::Rectangle(Rect((int)X,(int)Y,Width,Height), false);
	Drawer::SetColor(0,255,0);
	Drawer::Rectangle(Rect((int)X+1,(int)Y+1,Width-2,Height-2), false);
}

void TileSelector::OnMouseMove(int mX, int mY, int relX, int relY, bool Left, bool Right, bool Middle) {
	X = (float)CalcX(mX);
	Y = (float)CalcY(mY);
}

void TileSelector::OnLButtonDown(int mX, int mY) {
	int x = CROOM->GetXTile((float)mX);
	int y = CROOM->GetYTile((float)mY);

    switch (App::Application.GameMode) {
        case GAME_MODE_PLAN:
            {
                Soldier* o = App::Application.SelectedSoldier;
                if (CROOM->TileIsFree(o, y, x)) {
                    if (!o->IsPlaced) {
                        const char * img = (std::string("./gfx/Soldier/SoldierStill") + o->bmSuffix + ".png").c_str();
                        Object::Instantiate(o, img, (float)CalcX(mX)+Width/2, (float)CalcY(mY)+Height/2, NULL, MIDDLECENTER);
                        CROOM->OccupyTile(o, y, x);
                    }
                    else {
                        CROOM->LeaveTile(o, CROOM->GetYTile(o->Y), CROOM->GetXTile(o->X));

                        o->Y = (float)CalcY(mY)+Height/2;
                        o->X = (float)CalcX(mX)+Width/2;
                        o->DestX = o->X;
                        CROOM->OccupyTile(o, y, x);
                    }
                    o->IsPlaced = true;

                    // Select next soldier
                    App::Application.AutoSelectSoldier();

                    #ifdef PRINTDEBUG
                        printf("No soldier to select\n");
                    #endif
                }
                else {
                    #ifdef PRINTDEBUG
                        printf("Tile is already occupied\n");
                    #endif
                }
            }
        break;
        case GAME_MODE_PLAY:
            // Do nothing yet
            return;
        break;
    }
}

void TileSelector::OnRButtonDown(int mX, int mY) {
    int x = CROOM->GetXTile(mX);
	int y = CROOM->GetYTile(mY);

    switch (App::Application.GameMode) {
        case GAME_MODE_PLAN:
            for (unsigned int i = 0; i < CROOM->ObjectGrid[y][x].size(); i++) {
                if (CROOM->ObjectGrid[y][x][i]->ObjectType == OBJECT_TYPE_SOLDIER) {
                    Soldier* o = (Soldier*) CROOM->ObjectGrid[y][x][i];
                    CROOM->RemoveObject(o);
                    CROOM->LeaveTile(o, y, x);
                    o->IsPlaced = false;

                    // Select next soldier
                    App::Application.AutoSelectSoldier();
                }
            }
        break;
        case GAME_MODE_PLAY:
            // Do nothing yet
        break;
    }
}

int TileSelector::CalcX(int x) {
	if (x <= padLeft)
		x = padLeft;
	if (x > SCREEN_WIDTH - padRight - 1)
		x = SCREEN_WIDTH - padRight - 1;

	return ((x / Width) * Width) + 1;
}
int TileSelector::CalcY(int y) {
	if (y <= padTop)
		y = padTop;
	if (y > SCREEN_HEIGHT - padBot - 1)
		y = SCREEN_HEIGHT - padBot - 1;

	return ((y / (Height + padBetween)) * (Height + padBetween)) + padTop + 1;
}
