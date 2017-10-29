#ifndef WORLD_HPP
#define WORLD_HPP
#include <list>
#include "sys.hpp"

class Entity:public Object
{

};


class World:public Object
{
	public:
		Rect Area;
		int _z; 					//Dimensions
		std::list<Entity*> Entity_List; 		//all entities in world
		void add(Entity* e);				//add entities to stage
		void Update(); 					//update & render entity properties

		World(System& sys);
		World(Point size); 				//load world?
};



#endif
