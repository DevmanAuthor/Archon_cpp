#include "sys.h"
#include "utils.h"
#include <stdlib.h>

void check_accuracy(int x, int y, int w, int h, SDL_Rect Arenablock)
{
	SDL_RenderDrawLine(sys.Renderer, x, y, w, h);
	SDL_SetRenderDrawColor(sys.Renderer, 225,0,0,0);

	SDL_RenderDrawRect(sys.Renderer, (SDL_Rect*)& Arenablock);
}

void tween(F_Point* st, F_Point* en){
	if (st->x == en->x){
	} else if(st->x < en->x){
		st->x++;
	} else if(st->x > en->x){
		st->x--;
	}

	
	if (st->y == en->y){
	} else if(st->y < en->y){
		st->y++;
	} else if(st->y > en->y){
		st->y--;
	}
}
void speedtween_accruate(F_Point* st, F_Point* en){
	int dx = en->x - st->x;
	int dy = en->y - st->y;
	//int rx = (dx/dy);
	//int ry = (dy/dx);


	if (st->x == en->x){
		printf("same x of start.x! start.x=%d ",st->x);
	} else if(st->x < en->x){
		st->x+=  (int)(dx / 2);
	} else if(st->x > en->x){
		st->x+= (int)(dx / 2);
	}

	
	if (st->y == en->y){
		printf("same y of start.y! start.y=%d ",st->y);
	} else if(st->y < en->y){
		st->y+= (int)(dy / 2);
	} else if(st->y > en->y){
		st->y+= (int)(dy / 2) - 2;
	}
	
	printf("dx:%d  dy:%d\t manpos={%f,%f}\t  rx:%f   ry:%f: \n",dx,dy, st->x,st->y);// rx,ry);
}

//----------------------------------------Surfaces & Textures-----------------------------------------//
SDL_Rect surf_rect(char* path){
	SDL_Surface* s = loadoptgfx(path);
	SDL_Rect pass = s->clip_rect;
	SDL_FreeSurface(s); 
	return pass;
}//returns a rectangle structure from surface generated from path



SDL_Surface* loadoptgfx(char* path){
	SDL_Surface* loadedsurface = IMG_Load(path);
	SDL_Surface* optsurface = SDL_ConvertSurface( loadedsurface, sys.Viewport->format, NULL);
	SDL_FreeSurface(loadedsurface);
	return optsurface;
}//returns display-optimized surface generated from path




void draw_gfx_line(int xystart, int xyend, int xyconst, SDL_Surface* gfx, char d){
	switch(d){
			case 'h':
				for (int x = xystart; x < xyend; x+= gfx->clip_rect.w){draw_gfx(gfx, x, xyconst);}
	       			break;		
	 		case 'v':
				for (int y = xystart; y < xyend; y+= gfx->clip_rect.h){draw_gfx(gfx, xyconst, y);}
				break;
		}	
}//draws a vertical or horizontal line of surfaces based on the pair of distance coordinates "xystart" and  "xyend" from the
 //constant axis distance "xyconst". The character "d" from values 'h' or 'v' determines whether it is horizontal or vertical  




void draw_gfx(SDL_Surface* gfx, int x, int y){	
	SDL_Rect r={x, y, gfx->clip_rect.w, r.h=gfx->clip_rect.h};SDL_BlitSurface(gfx, NULL, sys.Viewport,&r);
}//draws a surface at given location "x" and "y"



void draw_tex(SDL_Texture* tex, SDL_Rect clip){	
	SDL_RenderCopy(sys.Renderer, tex, NULL, &clip);
}//draws a Texture at given location "x" and "y"


SDL_Texture* loadtex(char * path){
	return (SDL_Texture*)IMG_LoadTexture(sys.Renderer, path);
}//loads a Texture from a given path
//----------------------------------------------------------------------------------------------------------------------//







//----------------------------------Sprites-----------------------------------------------------------------------------//
sprite load_sprite(char* name, char* path){	
	sprite s;
	s.name=name;
	s.rect = surf_rect(path);
	s.sheet = loadtex(path);
	s.clip[0]=(SDL_Rect){0,0,32,32};
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
}//loads a sprite from given "path" and assigns a "name" to it


void animate_sprite(sprite s, int x, int y){	
	int frame = (int)((SDL_GetTicks()/200)%4);
	SDL_Rect renderloc ={x, y, 32,32};
	SDL_RenderCopy(sys.Renderer, s.sheet, &s.clip[frame],&renderloc);
	SDL_RenderPresent(sys.Renderer);
}//animates a sprite at given point "p"


void debug_sprite(sprite s){ 
	for (int i = 0; i < 4; i++)
	{printf("%s.clip[%d]:\n\tx:%d \t\ty: %d \n\tw: %d \t\th: %d \n", s.name,i, s.clip[i].x, s.clip[i].y, s.clip[i].w, s.clip[i].h);}
}//displays a sprite's retangle data to the terminal
//------------------------------------------------------------------------------------------------------------------------//
