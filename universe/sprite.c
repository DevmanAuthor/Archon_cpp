#include "sprite.h"

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

void animate_sprite(sprite s, int x, int y)
{
	int frame = (int)((SDL_GetTicks()/200)%4);
	SDL_Rect renderloc ={x, y,32,32};
	SDL_SetRenderDrawBlendMode(sys.Renderer, SDL_BLENDMODE_BLEND);
	SDL_RenderCopy(sys.Renderer, s.sheet, &s.clip[frame],&renderloc);
}

void debug_sprite(sprite s) 
{ 
		
	for (int i = 0; i < 4; i++)
	{printf("%s.clip[%d]:\n\tx:%d \t\ty: %d \n\tw: %d \t\th: %d \n", s.name,i, s.clip[i].x, s.clip[i].y, s.clip[i].w, s.clip[i].h);}
}

