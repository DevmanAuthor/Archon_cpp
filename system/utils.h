#ifndef UTILS_H
#define UTILS_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

//Data//
typedef enum _bool{_true=1,_false=0}_bool;

//Surfaces//
SDL_Surface* loadoptgfx(char* path);//load optimized surface
void draw_gfx_line(int start, int end, int xyconst, SDL_Surface* gfx, char d);//draw a line of surfaces going either horizontal or vertical
void draw_gfx(SDL_Surface* gfx, int x, int y);//draw a surface at a particular coordinate
void draw_tex(SDL_Texture* tex, SDL_Rect clip);//draw a texture at a particular coordinate 
SDL_Texture* loadtex(char * path);//load texture
SDL_Rect surf_rect(char * path);//get a surface's rectangle
/////////

//Sprite//
typedef struct sprite{int frame; char* name; SDL_Rect clip[4]; SDL_Texture* sheet; SDL_Rect rect;} sprite; //sprite type
sprite load_sprite(char* name, char* path);//load spritesheet from file and return sprite
void debug_sprite(sprite s);//print sprite info
void animate_sprite(sprite s, SDL_Point p);
/////////

//Tiles//
typedef struct tile{SDL_Point pos; SDL_Surface* gfx;} tile; 
/////////
#endif
