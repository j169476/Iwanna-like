#include <SDL2/SDL.h>
#include "collision.h"
#include "player.h"
#include "map.h"

void Game_collision_X(Game_Player* p, SDL_Rect* blocks, int blockCount)
{
	for(int i = 0; i < blockCount; i++)
	{
		SDL_Rect* b = &blocks[i];
		
		if(SDL_HasIntersection(&p -> rect, b))
		{
			//ÓÒ×óÅö×²»ØÕý 
			if(p -> vx > 0){
				p -> rect.x = (b -> x) - (p -> rect.w);
			} 
			else if(p -> vx < 0){
				p -> rect.x = (b -> x) + (b -> w);
			}
			
			p -> vx = 0;
		}
	}
}

void Game_collision_Y(Game_Player* p, SDL_Rect* blocks, int blockCount)
{
	
	for(int i = 0; i < blockCount; i++)
	{
		SDL_Rect* b = &blocks[i];
		
		if(SDL_HasIntersection(&p -> rect, b))
		{
			//ÏÂÉÏÅö×²»ØÕý 
			if(p -> vy > 0){
				p -> rect.y = (b -> y) - (p -> rect.h);
				p -> onGround = 1; 
			} else if(p -> vy < 0){
				p -> rect.y = (b -> y) + (b -> h);
			}
			
			p -> vy = 0;
		}
	}
}

int Game_collision_ALL(Game_Player* p, Game_commonMap* common, Game_levelMap* level)
{
	/*------------------------------------------X--------------------------------------*/
	//Åö×²ÏäXÖáÒÆ¶¯
	p -> rect.x += (int)p -> vx;
	 
	//¿ÕÆøÇ½+·½¿é¼ì²â 
	Game_collision_X(p, level -> blocks, level -> blockCount);
	Game_collision_X(p, common -> air, 3);
	
	//¼â´Ì¼ì²â 
	for (int i = 0; i < level -> spikeCount; i++)
    {
        if (SDL_HasIntersection(&p -> rect, &level -> spikes[i]))
            return -1;
    }
    
    /*------------------------------------------Y--------------------------------------*/
    //YÖáÅö×²ÏäÍÆ½ø
	p -> rect.y += (int)p -> vy;
	//ÀëµØÖØÖÃ
	p->onGround = 0;
	
    //µØÃæ£¬Ìì»¨°å£¬·½¿é¼ì²â 
    Game_collision_Y(p, level -> blocks, level -> blockCount);
    Game_collision_Y(p, &common -> ground, 1);
    Game_collision_Y(p, common -> air, 3);

    //¼â´Ì¼ì²â
	for (int i = 0; i < level -> spikeCount; i++)
    {
        if (SDL_HasIntersection(&p -> rect, &level -> spikes[i]))
            return -1;
    }
    
    //ÖÕµã 
	if (SDL_HasIntersection(&p -> rect, &level -> destination))
        return 1;

    return 0;
}
