#include "game.h"
#include <stdio.h>

_bool quit;

void game_init()
{
	quit = _false;	
	sys_init();
	world_init();
}

void game_run()
{
	while(!quit)
	{
		sys_update();
		world_draw();
		while(SDL_PollEvent(&sys.Queue) != 0){if(sys.Queue.type == SDL_QUIT){quit=_true;}}
	}
}


