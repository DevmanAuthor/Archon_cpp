#ifndef SYS_HPP
#define SYS_HPP
#include <SDL2/SDL.h>

class System
{
	public:

		SDL_Window* Window;
		SDL_Surface* WindowSurface;
		void OpenNew(int w, int h);		
		System();	
	private:

};

#endif
