#include "entity.h"

void entity_draw(entity e)
{
	animate_sprite(e.Cast, e.pos);

}

void move_lr(SDL_Point* p)
{
	p->x += 1;
	p->y += 1;
}

