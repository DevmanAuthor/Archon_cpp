#include "world.h"


void world_init()
{
	arena_init(Default_tile);
	debug_sprite(Cast);
}

void world_draw()
{
	arena_draw();
	outline_draw();
	animate_sprite(Cast, Arena.block[1][1]);
}

void world_load_content()
{
	Cast = load_sprite("Eliram", "content/gfx/Entity/Wizards/Eliram.png");
	arena_load();	
}


