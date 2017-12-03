#include "sys.h"

/////////System://///////////
int sys_init()
{
	sys.WIDTH=640;
	sys.HEIGHT=480;	

	if(SDL_Init(SDL_INIT_EVERYTHING) != 0)	{printf("SDL Could not Start Everthing! %s", SDL_GetError()); }
	else {sys.Window = SDL_CreateWindow("-",0,0, sys.WIDTH, sys.HEIGHT, SDL_WINDOW_SHOWN);}
	if(sys.Window == NULL) 	{printf("SDL Could not make Window! %s", SDL_GetError());}
	else {sys.Viewport = SDL_GetWindowSurface(sys.Window); sys.Renderer = SDL_CreateRenderer(sys.Window, -1, SDL_RENDERER_SOFTWARE);}	
	if (sys.Renderer == NULL) {printf("SDL Could not make Renderer! %s", SDL_GetError());}
	else{SDL_FillRect(sys.Viewport, NULL, SDL_MapRGB(sys.Viewport->format, 0,0,0));} 
	int imgflags = IMG_INIT_PNG;
	if(!(IMG_Init(imgflags) & imgflags)) {printf("SDL_Image could not start imgflags! %s", SDL_GetError());}
	glEnable(GL_BLEND);
}

void sys_update()
{
	SDL_UpdateWindowSurface(sys.Window); 
}







//////////Utils://////////
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

void draw_gfx_line(int start, int end, int xyconst, SDL_Surface* gfx, char d)
{
	switch(d)
	{
		case 'h':
			for (int x = start; x < end; x+= gfx->clip_rect.w){draw_gfx(gfx, x, xyconst);}
	       		break;		
	 	case 'v':
			for (int y = start; y < end; y+= gfx->clip_rect.h){draw_gfx(gfx, xyconst, y);}
			break;
	}
}

void draw_gfx(SDL_Surface* gfx, int x, int y)
{
	SDL_Rect r={x, y, gfx->clip_rect.w, r.h=gfx->clip_rect.h};SDL_BlitSurface(gfx, NULL, sys.Viewport,&r);	
}

void draw_tex(SDL_Texture* tex, SDL_Rect* clip)
{
	SDL_RenderCopy(sys.Renderer, tex, &clip, &sys.Viewport->clip_rect); 
}
SDL_Texture* loadtex(char * path)
{
	SDL_Texture* pass;
	SDL_Surface* surf = loadoptgfx(path);
	SDL_SetColorKey(surf, SDL_TRUE, SDL_MapRGB(surf->format, 0,0,0));
	if (surf == NULL){printf("Sorry, SDL failed to load surface %s \n due to Error: ", path, SDL_GetError());}
	else { pass = SDL_CreateTextureFromSurface(sys.Renderer, surf);}
	if (pass == NULL) {printf("sorry, SDL failed to load *TEXTURE* %s \n due to Error: ", path, SDL_GetError());}
	SDL_FreeSurface(surf);
	return pass;	
}
