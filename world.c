#include "world.h"
#include "sprite.h"
//World//
void world_init()
{
	arena_init(Default_tile);
}
void world_draw()
{
	arena_draw();
	outline_draw();
//	SDL_RenderCopy(sys.Renderer, Eliram.sheet, &Eliram.clip[0], &sys.Viewport->clip_rect);
	animate_sprite(Eliram);
}

void world_load_content()
{	
	border_corn_nw.gfx = loadoptgfx("gfx/Viewport/border-corner-nw.png");
	border_corn_ne.gfx = loadoptgfx("gfx/Viewport/border-corner-ne.png");
	border_corn_se.gfx = loadoptgfx("gfx/Viewport/border-corner-se.png");
	border_corn_sw.gfx = loadoptgfx("gfx/Viewport/border-corner-sw.png");
	border_vert.gfx = loadoptgfx("gfx/Viewport/border-vertical.png");
	border_horz.gfx = loadoptgfx("gfx/Viewport/border-horizontal.png");
	Default_tile.gfx = loadoptgfx("gfx/Viewport/tilesz.png");
	Eliram = load_sprite("Eliram", "gfx/Entity/Wizards/Eliram.png");
	debug_sprite(Eliram);
}

//Arena//
void arena_init(tile B)
{
	Arena.Basetile = B;
	Arena.bounds.x=32;
	Arena.bounds.y=32;
	Arena.bounds.w=sys.WIDTH-32;
	Arena.bounds.h=sys.HEIGHT-32;
}

void arena_draw()
{
	int i=0;int j=0;
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
	draw_gfx_line(Arena.bounds.x, Arena.bounds.w, Arena.bounds.y - border_horz.gfx->clip_rect.h, border_horz.gfx, 'h');
	draw_gfx_line(Arena.bounds.x, Arena.bounds.w, Arena.bounds.h, border_horz.gfx, 'h');
	//vertical outlies
	draw_gfx_line(Arena.bounds.y, Arena.bounds.h, Arena.bounds.x - border_horz.gfx->clip_rect.w, border_vert.gfx, 'v');
	draw_gfx_line(Arena.bounds.y, Arena.bounds.h, Arena.bounds.w, border_vert.gfx, 'v');
	//draw corners in the order of [North West, North East, South East, South West]
	draw_gfx(border_corn_nw.gfx, Arena.bounds.x-border_corn_nw.gfx->w, Arena.bounds.y-border_corn_nw.gfx->w);
	draw_gfx(border_corn_ne.gfx, Arena.bounds.w, Arena.bounds.y-border_corn_ne.gfx->w);
	draw_gfx(border_corn_se.gfx, Arena.bounds.w, Arena.bounds.h);
	draw_gfx(border_corn_sw.gfx, Arena.bounds.x-border_corn_sw.gfx->w, Arena.bounds.h);
}	


