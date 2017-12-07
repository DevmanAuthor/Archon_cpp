#ifndef WORLD_H
#define WORLD_H
#include "../system/sys.h"
#include "../system/utils.h"
#include "entity.h"
#include "arena.h"
#include <SDL2/SDL.h>

//World//
void world_init();
void world_draw();
void world_load_content();

#endif
