#ifndef SYS_HPP
#define SYS_HPP
#include <SDL2/SDL.h>
#include "utils.hpp"


class Object
{
	public:
		virtual void Init()=0;	
		virtual	void Update()=0;
		virtual void Draw()=0;
		virtual void Kill()=0;	
};


class Control:Object
{
	SDL_Surface* img; 		 	//GUI control img
	void (*callback); 	                //GUI control callback
	Control(Rect r);
	Rect Region; 				//Region for interaction, on mouse/keyboard/etc.. operation
};



class System
{
	public:
		SDL_Window* Window;
		SDL_Surface* WindowSurface;
		void OpenNew(int x, int y);				
		System();	

	private:

};

#endif
