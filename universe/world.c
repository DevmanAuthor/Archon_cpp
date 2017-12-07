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
	SDL_Point there = Arena.block[13][13];
	tween(Man.pos, there);
}

void world_load_content()
{
	arena_load_content();
	arena_init(Default_tile);
	Man.Cast = load_sprite("Eliram", "content/gfx/Entity/Wizards/Eliram.png");
}


