#include <iostream>
#include "sys.hpp"
#define _SGR "[ Source-Generater Error] "

System::System()
{
	SDL_Init(SDL_INIT_EVERYTHING);
}

void System::OpenNew(int w, int h)
{
	Window = SDL_CreateWindow("GameWindow",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN);
	
	if (Window == NULL)
		{
			std::cout << _SGR << "Error in making SDL_Window()"<< SDL_GetError();
		}
	else
		{
			WindowSurface = SDL_GetWindowSurface(Window);
			if (WindowSurface == NULL)
				{
					std::cout << _SGR << "Error in making SDL_Surface(Window)" << SDL_GetError();
				}	
			else
				{
					SDL_FillRect(WindowSurface, NULL, SDL_MapRGB(WindowSurface->format, 100, 200, 255));
					SDL_UpdateWindowSurface(Window);
				}
		}
}
