#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>
#include "input.h"

typedef struct
{
	float x, y;
	float vx, vy;
	
	int width, height;
	SDL_Rect rect;
	
	int onGround;
	int facing;
	
	float moveSpeed;
	float jumpingForce;
	float gravity;
	float maxFallSpeed;
	
} Game_Player;

void Game_player_Init(Game_Player* p);

void Game_player_Update(Game_Player* p, Game_Input* in);

#endif
