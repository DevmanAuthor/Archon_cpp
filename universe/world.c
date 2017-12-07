#include "world.h"

entity Man;
SDL_Point max = {480,480};

void world_init()
{
	world_load_content();
}

void world_draw()
{
	arena_draw();
	entity_draw(Man);
	SDL_Point* p = &Man.pos;
	move_lr(p);
	printf("Man's position={%d,%d}\n", Man.pos.x, Man.pos.y);
		if(p->x == max.x && p->y == max.y)
			{
				*p =(SDL_Point){0,0};
			}

}

void world_load_content()
{
	arena_load_content();
	arena_init(Default_tile);
	Man.Cast = load_sprite("Eliram", "content/gfx/Entity/Wizards/Eliram.png");
}


