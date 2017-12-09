#include "world.h"

entity Man;

void world_init()
{
	world_load_content();
	Man.pos=Arena.block[1][1];
}

void world_draw()
{
	arena_draw();
	entity_draw(Man);
	SDL_Point there = Arena.block[9][13];
//	tween((SDL_Point*)&Man.pos,(SDL_Point*)&there);
	tween_straight((SDL_Point*)&Man.pos,(SDL_Point*)&there);
	
	SDL_SetRenderDrawColor(sys.Renderer, 225,0,0,0);
	SDL_RenderDrawLine(sys.Renderer, Arena.block[1][1].x, Arena.block[1][1].y, Arena.block[9][13].x, Arena.block[9][13].y);
//	printf("Man's position={%d,%d} \t Arena.block position = {%d,%d} \n", Man.pos.x, Man.pos.y, Arena.block[10][13].x ,Arena.block[10][13].y);
}

void world_load_content()
{
	arena_load_content();
	arena_init(Default_tile);
	Man.Cast = load_sprite("Eliram", "content/gfx/Entity/Wizards/Eliram.png");
}


