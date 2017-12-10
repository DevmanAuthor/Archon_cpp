#include "world.h"

entity Man;
F_Point there;
int kex, key;
void world_init()
{
	
	world_load_content();
	Man.pos=(F_Point){Arena.block[1][1].x, Arena.block[1][1].y};
	there = (F_Point){Arena.block[9][7].x, Arena.block[9][7].y};
}

void world_draw()
{
	srand(time(NULL));
	arena_draw();
	//entity_draw(Man);
	static F_Point* p = &Man.pos; F_Point* t= &there; SDL_Rect q = {there.x, there.y, 32,32};
	tween_straight(p, t);
	SDL_Point pos = (SDL_Point){p->x, p->y};
	SDL_RenderDrawLine(sys.Renderer, Man.pos.x, Man.pos.y, there.x, there.y);
	animate_sprite(Man.Cast, pos);
	SDL_SetRenderDrawColor(sys.Renderer, 225,0,0,0);

	SDL_RenderDrawRect(sys.Renderer, (SDL_Rect*)&q);
	move();		
}

void world_load_content()
{
	arena_load_content();
	arena_init(Default_tile);
	Man.Cast = load_sprite("Eliram", "content/gfx/Entity/Wizards/Eliram.png");
}

void move()
{
	if (sys.keyb[SDL_SCANCODE_RIGHT]){
		kex++;
		Man.pos = (F_Point) {kex, key};
	} else if (sys.keyb[SDL_SCANCODE_LEFT]){
		kex--;
		Man.pos = (F_Point) {kex, key};
	}
	
	if (sys.keyb[SDL_SCANCODE_UP]){
		key--;
		Man.pos = (F_Point) {kex, key};
	} else if (sys.keyb[SDL_SCANCODE_DOWN]){
		key++;
		Man.pos = (F_Point) {kex, key};
	}
	if(sys.keyb[SDL_SCANCODE_RETURN]){
		Man.pos= (F_Point){Arena.block[(rand()%18)+1][(rand()%13)+1].x, Arena.block[(rand()%18)+1][(rand()%13)+1].y};
		there= (F_Point){Arena.block[(rand()%18)+1][(rand()%13)+1].x, Arena.block[(rand()%18)+1][(rand()%13)+1].y};
	}
}