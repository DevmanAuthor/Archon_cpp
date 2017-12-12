#include "world.h"

void world_init()
{
	world_load_content();
}

void world_draw()
{

}

void world_load_content()
{
	arena_load_content();
	arena_init(Default_tile);
}

