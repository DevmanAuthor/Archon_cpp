#ifndef  SYS_H
#define SYS_H
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

System sys;
int sys_init();
void sys_update();


//////////Utils://////////


//Surfaces//
SDL_Surface* loadoptgfx(char* path);
void draw_gfx_line(int start, int end, int xyconst, SDL_Surface* gfx, char d);
void draw_gfx(SDL_Surface* gfx, int x, int y);
void draw_tex(SDL_Texture* tex, SDL_Rect clip);
SDL_Texture* loadtex(char * path);
SDL_Rect surf_rect(char * path);
/////////

//Sprite//
typedef struct sprite{int frame; char* name; SDL_Rect clip[4]; SDL_Texture* sheet; SDL_Rect rect;} sprite; 
sprite load_sprite(char* name, char* sheetpath);
void debug_sprite(sprite s);
void animate_sprite(sprite s, int x, int y);
/////////

#endif
