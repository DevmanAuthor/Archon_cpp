#include "entity.h"

void entity_draw(entity e)
{
	animate_sprite(e.Cast, (SDL_Point){(int)e.pos.x, (int)e.pos.y});

}

