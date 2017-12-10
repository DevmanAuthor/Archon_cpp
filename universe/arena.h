#ifndef ARENA_H
#define ARENA_H
#include "../system/sys.h"
#include "../system/utils.h"

extern tile Default_tile;
typedef struct border {tile h; tile v; tile nw; tile ne; tile se; tile sw;} border;
typedef struct arena
	{
		SDL_Rect bounds; 
		border Border; 
		tile Basetile;
		SDL_Point grid_limit;
		SDL_Rect block[19][14];
	} arena; extern arena Arena;

void arena_init(tile B);
void arena_load_content();
void arena_draw();
void arena_grid_draw();
void arena_outline_draw();

#endif
