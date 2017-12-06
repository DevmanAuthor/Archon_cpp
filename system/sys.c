#include "sys.h"

int sys_init()
{
	sys.WIDTH=640;
	sys.HEIGHT=480;	

	if(SDL_Init(SDL_INIT_EVERYTHING) != 0)	{printf("SDL Could not Start Everthing! %s", SDL_GetError()); }
	else {sys.Window = SDL_CreateWindow("-",0,0, sys.WIDTH, sys.HEIGHT, SDL_WINDOW_SHOWN);}
	if(sys.Window == NULL) 	{printf("SDL Could not make Window! %s", SDL_GetError());}
	else {sys.Viewport = SDL_GetWindowSurface(sys.Window); sys.Renderer = SDL_CreateRenderer(sys.Window, -1, SDL_RENDERER_SOFTWARE);}	
	if (sys.Renderer == NULL) {printf("SDL Could not make Renderer! %s", SDL_GetError());}
	else{SDL_FillRect(sys.Viewport, NULL, SDL_MapRGB(sys.Viewport->format, 0,0,0));} 
	int imgflags = IMG_INIT_PNG;
	if(!(IMG_Init(imgflags) & imgflags)) {printf("SDL_Image could not start imgflags! %s", SDL_GetError());}

}

void sys_update()
{
	SDL_UpdateWindowSurface(sys.Window); 
}



