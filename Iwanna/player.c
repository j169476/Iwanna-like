#include "player.h"
#include <SDL2/SDL.h>
#include "input.h"
#include "map.h"

void Game_player_Init(Game_Player* p)
{
    p -> rect.x = 10;
    p -> rect.y = 10;
    p -> rect.w = 32;
    p -> rect.h = 32;

    p -> vx = 0;
    p -> vy = 0;

    p -> onGround = 0;
    p -> facing = 1; //还未运用，留作后续美术优化接口 

    p -> moveSpeed = 4.0f;
    p -> jumpingForce = 11.0f;
    p -> gravity = 0.45f;
    p -> maxFallSpeed = 15.0f;
}

void Game_player_Update(Game_Player* p, Game_Input* in)
{
	//水平移动
	p -> vx = 0;
	if(in -> left) p -> vx -= p -> moveSpeed;
	if(in -> right) p -> vx += p -> moveSpeed;
	
	//跳跃
	if(in -> jump && p -> onGround){
		p -> vy = -p -> jumpingForce;
		p -> onGround = 0;
	}
	
	//下坠
	p -> vy += p -> gravity;
	if(p -> vy > p -> maxFallSpeed) p -> vy = p -> maxFallSpeed;
}
