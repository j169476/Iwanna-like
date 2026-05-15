#ifndef COLLISION_H
#define COLLISION_H

#include "player.h"
#include "map.h"

void Game_collision_X(Game_Player* p, SDL_Rect* blocks, int blockCount);

void Game_collision_Y(Game_Player* p, SDL_Rect* blocks, int blockCount);

int Game_collision_ALL(Game_Player* p, Game_commonMap* common, Game_levelMap* level);

#endif

