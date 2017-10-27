#include <SDL2/SDL.h>
#include "sys.hpp"
#include <iostream>


int main()
{
	System Game;
	Game.OpenNew(640,480);
	
	SDL_Delay(4000);
	return 0;	
	
}


/*	SDL_Window* w = SDL_CreateWindow("o", 0,0,648,480, SDL_WINDOW_SHOWN)
	SDL_Surface* s = SDL_GetWindowSurface(w);
	SDL_FillRect(s, NULL, SDL_MapRGB(s->format, 255,50,20));
	SDL_UpdateWindowSurface(w);
	SDL_Delay(4000); */
