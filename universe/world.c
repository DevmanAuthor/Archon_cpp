#include "world.h"


void world_init()
{
	arena_init(Default_tile);
}

void world_draw()
{
	arena_draw();
	outline_draw();
	animate_sprite(Cast, Arena.block[18][12]);
}

void world_load_content()
{
	Cast = load_sprite("Eliram", "gfx/Entity/Wizards/Eliram.png");
	arena_load();	
}


