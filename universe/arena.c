#include "arena.h"

//Arena//
void arena_init(tile B)
{
	Arena.Basetile = B;
	Arena.bounds.x=32;
	Arena.bounds.y=32;
	Arena.bounds.w=sys.WIDTH-32;
	Arena.bounds.h=sys.HEIGHT-32;
 	Arena.grid_limit=(SDL_Point){Arena.bounds.w / Arena.bounds.x, Arena.bounds.h / Arena.bounds.y};
	for (int i = 1; i < Arena.grid_limit.x; i++)
	{
		for(int j = 1; j < Arena.grid_limit.y; j++)
			{
				Arena.block[i][j].x += i * 32;
				Arena.block[i][j].y += j * 32;
				printf("Arena.pos[%d][%d}= {%d,%d}\n",i,j, Arena.block[i][j].x, Arena.block[i][j].y);	
			}
	}
}

void arena_load()
{
	Arena.Border.nw.gfx = loadoptgfx("content/gfx/Viewport/border-corner-nw.png");
	Arena.Border.ne.gfx = loadoptgfx("content/gfx/Viewport/border-corner-ne.png");
	Arena.Border.se.gfx = loadoptgfx("content/gfx/Viewport/border-corner-se.png");
	Arena.Border.sw.gfx = loadoptgfx("content/gfx/Viewport/border-corner-sw.png");
	Arena.Border.v.gfx = loadoptgfx("content/gfx/Viewport/border-vertical.png");
	Arena.Border.h.gfx = loadoptgfx("content/gfx/Viewport/border-horizontal.png");
	Default_tile.gfx = loadoptgfx("content/gfx/Viewport/tilesz.png");

}
void arena_draw()
{
		for (int x = Arena.bounds.x; x < Arena.bounds.w; x += Arena.Basetile.gfx->clip_rect.w)
		{
			for (int y = Arena.bounds.y; y < Arena.bounds.h; y += Arena.Basetile.gfx->clip_rect.h)
			{
				draw_gfx(Arena.Basetile.gfx, x,y);				
			}
		}
}


//Outline//
void outline_draw()
{
	//horizontal outlines
	draw_gfx_line(Arena.bounds.x, Arena.bounds.w, Arena.bounds.y - Arena.Border.h.gfx->clip_rect.h, Arena.Border.h.gfx, 'h');
	draw_gfx_line(Arena.bounds.x, Arena.bounds.w, Arena.bounds.h, Arena.Border.h.gfx, 'h');
	//vertical outlies
	draw_gfx_line(Arena.bounds.y, Arena.bounds.h, Arena.bounds.x - Arena.Border.h.gfx->clip_rect.w, Arena.Border.v.gfx, 'v');
	draw_gfx_line(Arena.bounds.y, Arena.bounds.h, Arena.bounds.w, Arena.Border.v.gfx, 'v');
	//draw corners in the order of [North West, North East, South East, South West]
	draw_gfx(Arena.Border.nw.gfx, Arena.bounds.x-Arena.Border.nw.gfx->w, Arena.bounds.y-Arena.Border.nw.gfx->w);
	draw_gfx(Arena.Border.ne.gfx, Arena.bounds.w, Arena.bounds.y-Arena.Border.ne.gfx->w);
	draw_gfx(Arena.Border.se.gfx, Arena.bounds.w, Arena.bounds.h);
	draw_gfx(Arena.Border.sw.gfx, Arena.bounds.x-Arena.Border.sw.gfx->w, Arena.bounds.h);
}	


