#include "entity.h"

void entity_draw(entity e)
{
	animate_sprite(e.Cast, e.pos);
	printf("Man's position={%d,%d}\n", Man.pos.x, Man.pos.y);
}

void move_lr(SDL_Point* p)
{
	p->x += 1;
	p->y += 1;
}

