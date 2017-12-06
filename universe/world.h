#ifndef WORLD_H
#define WORLD_H
#include "../system/sys.h"
#include "../system/utils.h"
#include "entity.h"
#include <SDL2/SDL.h>

typedef struct tile{SDL_Point pos; SDL_Surface* gfx;} tile; 


//Content//


tile Default_tile;



//World//
void world_init();
void world_draw();
void world_load_content();

//Arena// 
typedef struct border {tile h; tile v; tile nw; tile ne; tile se; tile sw} border;
typedef struct arena
	{
		SDL_Rect bounds; 
		border Border; 
		tile Basetile;
		SDL_Point grid_limit;
		SDL_Point block[1][1];
	} arena; arena Arena;

void arena_init(tile B);
void arena_draw();
void outline_draw();



#endif
