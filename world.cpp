#include "world.hpp"
//*********WORLD***********//

World::World(System& sys)
{
	Area.w = sys.WindowSurface->clip_rect.w; 		// Set World's dimensions (width and height) according to System Object's width
        Area.h = sys.WindowSurface->clip_rect.h;		// and height dimension	
}

World::World(Point pos){Area.w = pos.x; Area.h = pos.y;} 	//Set World's dimensions from integer parameters given



void World::add(Entity* e){Entity_List.push_back(e);}
void World::Update(){ for (auto* e : Entity_List){ e->Update(); e->Draw(); } }

