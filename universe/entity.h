#ifndef ENTITY_H
#define ENTITY_H
#include "utils.h"
#include "arena.h"

typedef struct entity {F_Point pos; sprite Cast;} entity;
typedef struct wizard {F_Point pos; int HP; int DMG; int ENERGY; sprite Breathe; sprite Cast; sprite Death} wizard;

//minions

typedef struct rat{F_Point pos; int HP; int DMG; sprite Breathe; sprite Attack; sprite Death} rat;

#endif
