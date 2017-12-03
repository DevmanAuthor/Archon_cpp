#include "game.h"
#include <stdio.h>

int quit;

void game_init()
{
	quit = 0;	
	sys_init();
	world_load_content();
	world_init();
}

void game_run()
{
	while(!quit)
	{
		sys_update();
		world_draw();
		while(SDL_PollEvent(&sys.Queue) != 0){if(sys.Queue.type == SDL_QUIT){quit=1;}}
	}
}


