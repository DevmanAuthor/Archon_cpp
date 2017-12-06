#include "sys.h"
#include "utils.h"
#include <stdlib.h>

//////Surfaces & Textures//////
SDL_Rect surf_rect(char* path)
{
	SDL_Surface* s = loadoptgfx(path);
	SDL_Rect pass = s->clip_rect;
	SDL_FreeSurface(s); 
	return pass;
}
SDL_Surface* loadoptgfx(char* path)
{
	SDL_Surface* optsurface = NULL;
	SDL_Surface* loadedsurface = IMG_Load(path);

	optsurface = SDL_ConvertSurface( loadedsurface, sys.Viewport->format, NULL);
	SDL_FreeSurface(loadedsurface);
	return optsurface;
}

void draw_gfx_line(int xystart, int xyend, int xyconst, SDL_Surface* gfx, char d)
{
	switch(d)
	{
		case 'h':
			for (int x = xystart; x < xyend; x+= gfx->clip_rect.w){draw_gfx(gfx, x, xyconst);}
	       		break;		
	 	case 'v':
			for (int y = xystart; y < xyend; y+= gfx->clip_rect.h){draw_gfx(gfx, xyconst, y);}
			break;
	}
}

void draw_gfx(SDL_Surface* gfx, int x, int y)
{SDL_Rect r={x, y, gfx->clip_rect.w, r.h=gfx->clip_rect.h};SDL_BlitSurface(gfx, NULL, sys.Viewport,&r);}

void draw_tex(SDL_Texture* tex, SDL_Rect clip){SDL_RenderCopy(sys.Renderer, tex, NULL, &clip);}

SDL_Texture* loadtex(char * path){return (SDL_Texture*)IMG_LoadTexture(sys.Renderer, path);}
////////////////////////////





///////////Sprites//////////

sprite load_sprite(char* name, char* sheetpath)
{
	sprite s;
	s.name=name;
	s.rect = surf_rect(sheetpath);
	s.sheet = loadtex(sheetpath);
	SDL_Rect r = {0,0,32,32};
	s.clip[0]=r;	
	if (s.sheet == NULL){printf("spritesheet could not be found!%s", SDL_GetError());}
	else{
		for (int i = 1; i < 4; i++)
		{
			s.clip[i].x = 32 * i;
			s.clip[i].y = 0;
			s.clip[i].w = 32; 
			s.clip[i].h = 32;
		}
	    }
	return s;
}

void animate_sprite(sprite s, SDL_Point p)
{
	int frame = (int)((SDL_GetTicks()/200)%4);
	SDL_Rect renderloc ={p.x, p.y,32,32};
	SDL_SetRenderDrawBlendMode(sys.Renderer, SDL_BLENDMODE_BLEND);
	SDL_RenderCopy(sys.Renderer, s.sheet, &s.clip[frame],&renderloc);
}

void debug_sprite(sprite s) 
{ 
		
	for (int i = 0; i < 4; i++)
	{printf("%s.clip[%d]:\n\tx:%d \t\ty: %d \n\tw: %d \t\th: %d \n", s.name,i, s.clip[i].x, s.clip[i].y, s.clip[i].w, s.clip[i].h);}
}
///////////////////////
