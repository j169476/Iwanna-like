#include <SDL2/SDL.h>
#include "menu.h"
#include "map.h"
#include "player.h"

//≤Àµ•∞¥≈•‰÷»æ 
void Game_renderer_drawMenuButton(SDL_Renderer* renderer,
									 Game_menu_Button* levelBtn,
									 Game_menu_Button* quitBtn){
	SDL_RenderClear(renderer);
	Game_menu_drawButton(renderer, levelBtn);
	Game_menu_drawButton(renderer, quitBtn);
	SDL_RenderPresent(renderer);
}

//—°πÿ∞¥≈•‰÷»æ 
void Game_renderer_drawLevelButton(SDL_Renderer* renderer, Game_menu_Button* Back,
					 Game_menu_Button* level_1, Game_menu_Button* level_2, Game_menu_Button* level_3,
					 Game_menu_Button* level_4, Game_menu_Button* level_5, Game_menu_Button* level_6){
	SDL_RenderClear(renderer);
	Game_menu_drawButton(renderer, Back);
	Game_menu_drawButton(renderer, level_1);
	Game_menu_drawButton(renderer, level_2);
	Game_menu_drawButton(renderer, level_3);
	Game_menu_drawButton(renderer, level_4);
	Game_menu_drawButton(renderer, level_5);
	Game_menu_drawButton(renderer, level_6);
	SDL_RenderPresent(renderer);
}

//µÿÕº‰÷»æ 
void Game_renderer_mapRender(SDL_Renderer* renderer, Game_commonMap* map)
{
	//µÿ√Ê‰÷»æ
	SDL_SetRenderDrawColor(renderer, 0, 81, 51, 255);
	SDL_RenderFillRect(renderer, &map -> ground);
}

//πÿø®‰÷»æ
void Game_render_levelRender(SDL_Renderer* renderer, Game_levelMap* level)
{
	//¥Ã‰÷»æ
	SDL_SetRenderDrawColor(renderer, 148, 149, 147, 255);
	for(int i = 0; i < level -> spikeCount; i++){
		SDL_RenderFillRect(renderer, &level -> spikes[i]);
	}
	
	//∆ΩÃ®‰÷»æ 
	SDL_SetRenderDrawColor(renderer, 132, 51, 31, 255);
	for(int i = 0; i < level -> blockCount; i++){
		SDL_RenderFillRect(renderer, &level -> blocks[i]);
	}
	
	//÷’µ„‰÷»æ
	SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
	SDL_RenderFillRect(renderer, &level -> destination);
} 

//ÕÊº“‰÷»æ
void Game_render_playerRender(SDL_Renderer* renderer, Game_Player* p)
{
	SDL_SetRenderDrawColor(renderer, 50, 200, 50, 255);
    SDL_RenderFillRect(renderer, &p -> rect);
}
 
