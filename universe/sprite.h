#ifndef SPRITE_H
#define SPRITE_H
#include "world.h"

typedef struct sprite{int frame; char* name; SDL_Rect clip[4]; SDL_Texture* sheet; SDL_Rect rect;} sprite; 
sprite load_sprite(char* name, char* sheetpath);
void debug_sprite(sprite s);
void animate_sprite(sprite s, int x, int y);


//Sample Sprites

#endif


