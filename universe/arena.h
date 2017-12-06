#ifndef ARENA_H
#define ARENA_H
#include "../system/sys.h"
#include "../system/utils.h"

tile Default_tile;
typedef struct border {tile h; tile v; tile nw; tile ne; tile se; tile sw} border;
const SDL_Point gru;
typedef struct arena
	{
		SDL_Rect bounds; 
		border Border; 
		tile Basetile;
		SDL_Point grid_limit;
		SDL_Point block[19][14];
	} arena; arena Arena;

void arena_init(tile B);
void arena_draw();
void outline_draw();

#endif
