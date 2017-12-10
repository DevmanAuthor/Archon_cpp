#ifndef ENTITY_H
#define ENTITY_H
#include "utils.h"
#include "arena.h"

typedef struct entity {F_Point pos; sprite Cast;} entity; extern entity Man;

void entity_draw(entity e);
#endif
