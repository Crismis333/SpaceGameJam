#ifndef OBJECT_H_
	#define OBJECT_H_

#include "Sprite.h"
#include "Event.h"
#include "FPS.h"
#include "CAnimation.h"

#include <vector>

class Room;

enum {
    OBJECT_FLAG_NONE		= 0,

    OBJECT_FLAG_GRAVITY		= 0x00000001,
    OBJECT_FLAG_GHOST		= 0x00000002,
    OBJECT_FLAG_MAPONLY		= 0x00000004
};

enum objectType {
    OBJECT_TYPE_UNDEFINED, OBJECT_TYPE_ALIEN, OBJECT_TYPE_SOLDIER
};

class Object : public Event {
	public:
		//Vars
		static int	IDcount;

		objectType  ObjectType;

		int			ID;

		int			Flags;

		float		X;
		float		Y;

		int			Width;
		int			Height;

		float		SpeedX;
		float		SpeedY;

		float		MaxSpeedX;
		float		MaxSpeedY;

		float		AccelX;
		float		AccelY;

		bool		Dead;

		CAnimation* Animation;

		Sprite*		Spr;

		//Methods
		Object();

		virtual ~Object();

		virtual bool OnInit();

		virtual void OnLoop();

		virtual void OnRender(SDL_Surface* display);

		virtual void OnCleanup();

		static void Instantiate(Object* obj,const char* file);

		static void Instantiate(Object* obj,const char* file, float X, float Y);

		static void Instantiate(Object* obj,const char* file, float X, float Y, int FrameCount, float SpriteX, float SpriteY, int FrameRate);

		static void Instantiate(Object* obj,const char* file, float X, float Y, Rect* BBox);
		
		static void Instantiate(Object* obj,const char* file, float X, float Y, Rect* BBox, int FrameCount, float SpriteX, float SpriteY, int FrameRate);

		static void Instantiate(Object* obj,const char* file, float X, float Y, Rect* BBox, SpriteAnchor SA);

		static void Instantiate(Object* obj,const char* file, float X, float Y, Rect* BBox, int FrameCount, float SpriteX, float SpriteY, int FrameRate, SpriteAnchor SA);

		void Destroy();

		//Collision
		virtual bool OnCollision(Object* Obj);

		void OnMove(float MoveX, float MoveY);

        void StopMove();

        bool Collides(int oX, int oY, int oW, int oH);

		//Events
		void OnEvent(SDL_Event* Ev);

	protected:
        int			Col_X;
        int			Col_Y;
        int			Col_Width;
        int			Col_Height;

    private:
		//Collision
        bool PosValid(int NewX, int NewY);

        bool PosValidEntity(Object* Obj, int NewX, int NewY); // Might not be necessary with Mask test
};

class ObjectCol {
	public:
        static std::vector<ObjectCol>    ObjectColList;

    public:
        Object* ObjA;
        Object* ObjB;

    public:
        ObjectCol();
};

#endif
