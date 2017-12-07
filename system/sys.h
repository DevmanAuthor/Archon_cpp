#ifndef  SYS_H
#define SYS_H
#include "utils.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

/////////System://////////
typedef struct System
{
	int WIDTH;
	int HEIGHT;
	SDL_Window* Window;
	SDL_Surface* Viewport;
	SDL_Renderer* Renderer;
	SDL_Event Queue;
} System;

extern System sys;
int sys_init();
void sys_update();


#endif
