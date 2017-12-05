#ifndef WORLD_H
#define WORLD_H
#include "../system/sys.h"
#include <SDL2/SDL.h>

typedef struct tile{SDL_Point pos; SDL_Surface* gfx;} tile; 
typedef struct arena{SDL_Rect bounds; tile Basetile;} arena; arena Arena;

//Content//
tile Default_tile;
tile border_horz;
tile border_vert;
tile border_corn_nw;
tile border_corn_ne;
tile border_corn_se;
tile border_corn_sw;

//World//
void world_init();
void world_draw();
void world_load_content();

//Arena//
void arena_init(tile B);
void arena_draw();
void outline_draw();



#endif
