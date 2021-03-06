#ifndef SPRITE_H_
	#define SPRITE_H_
	#define PRINTDEBUG //comment out or remove to disable debug log

#ifdef _WIN32
	#include <SDL.h>
	#include <SDL_image.h>
#else
    #include <SDL/SDL.h>
	#include <SDL/SDL_image.h>
#endif

enum SpriteAnchor {
	UPPERLEFT, UPPERCENTER, UPPERRIGHT,
	MIDDLELEFT, MIDDLECENTER, MIDDLERIGHT,
	LOWERLEFT, LOWERCENTER, LOWERRIGHT
};

class Sprite {
	private:
		//Vars
		SDL_Surface* Image;

		//Methods
		SDL_Surface* LoadImage(const char* file);

		bool SetTransparencyColor(int R, int G, int B);

	public:
		//Vars
		bool Visible;

		int OffsetX;
		int OffsetY;
		int SpriteW;
		int SpriteH;

		//Methods
		Sprite();

		Sprite(const char* file, SpriteAnchor SA);

		bool OnDraw(SDL_Surface* Display, int X, int Y);

		bool OnDraw(SDL_Surface* Display, int X, int Y, int X2, int Y2, int W, int H);

		void OnCleanup();
};

struct Rect {
	public:
		int X;
		int Y;
		int Width;
		int Height;

		Rect();
		Rect(int X, int Y, int Width, int Height);
};

#endif
