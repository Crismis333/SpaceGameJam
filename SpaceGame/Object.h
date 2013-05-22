#ifndef OBJECT_H_
	#define OBJECT_H_

#include <vector>

#include "Sprite.h"
#include "Event.h"

class Object : public Event {
	public:
		//Vars
		static std::vector<Object*>	ObjectList;

		float X;
		float Y;

		Sprite* Spr;

		//Methods
		Object();

		virtual ~Object();

		virtual bool OnInit();

		virtual void OnLoop();

		virtual void OnRender(SDL_Surface* display);

		virtual void OnCleanup();

		void SetSprite(const char* file);

		//Events
		void OnEvent(SDL_Event* Ev);

		void OnMouseMove(int mX, int mY, int relX, int relY, bool Left, bool Right, bool Middle);
};

#endif