#include "Sprite.h"

Sprite::Sprite() {
	Image = NULL;

	OffsetX = OffsetY = 0;
}

Sprite::Sprite(const char* file) {
	Image = LoadImage(file);
	SetTransparencyColor(255,0,255);
}

SDL_Surface* Sprite::LoadImage(const char* file) {
	SDL_Surface* Surf_Temp = NULL;
	SDL_Surface* Surf_Return = NULL;

	if ((Surf_Temp = IMG_Load(file)) == NULL) {
		#ifdef PRINTDEBUG
			printf("Failed to load img: %s\n", file);
		#endif
		return NULL;
	}

	Surf_Return = SDL_DisplayFormatAlpha(Surf_Temp);
	SDL_FreeSurface(Surf_Temp);

	return Surf_Return;
}

bool Sprite::OnDraw(SDL_Surface* Display, int X, int Y) {
	if (Display == NULL || Image == NULL) {
		#ifdef PRINTDEBUG
			printf("Can not Draw when Image or Display is NULL!\n");
		#endif
		return false;
	}

	SDL_Rect DestR;

	DestR.x = X-OffsetX;
	DestR.y = Y-OffsetY;

	SDL_BlitSurface(Image, NULL, Display, &DestR);

	return true;
}

bool Sprite::OnDraw(SDL_Surface* Display, int X, int Y, int X2, int Y2, int W, int H) {
	if (Display == NULL || Image == NULL) {
		#ifdef PRINTDEBUG
			printf("Can not Draw when Image or Display is NULL!\n");
		#endif
		return false;
	}

	SDL_Rect DestR;

	DestR.x = X-OffsetX;
	DestR.y = Y-OffsetY;

	SDL_Rect SrcR;

	SrcR.x = X2;
	SrcR.y = Y2;
	SrcR.w = W;
	SrcR.h = H;

	SDL_BlitSurface(Image, &SrcR, Display, &DestR);

	return true;
}

bool Sprite::SetTransparencyColor(int R, int G, int B) {
	if (Image == NULL) {
		#ifdef PRINTDEBUG
			printf("Can not set transparency when Image is NULL!\n");
		#endif
		return false;
	}

	SDL_SetColorKey(Image, SDL_SRCCOLORKEY | SDL_RLEACCEL, SDL_MapRGB(Image->format, R, G, B));

	return true;
}

void Sprite::OnCleanup() {
	SDL_FreeSurface(Image);
}
