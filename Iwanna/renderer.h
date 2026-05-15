#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>
#include "menu.h"
#include "map.h"
#include "player.h"

void Game_renderer_drawMenuButton(SDL_Renderer* renderer, Game_menu_Button* levelBtn, Game_menu_Button* quitBtn);

void Game_renderer_drawLevelButton(SDL_Renderer* renderer, Game_menu_Button* Back,
					 Game_menu_Button* level_1, Game_menu_Button* level_2, Game_menu_Button* level_3,
					 Game_menu_Button* level_4, Game_menu_Button* level_5, Game_menu_Button* level_6);

void Game_renderer_mapRender(SDL_Renderer* renderer, Game_commonMap* map);

void Game_render_levelRender(SDL_Renderer* renderer, Game_levelMap* level);

void Game_render_playerRender(SDL_Renderer* renderer, Game_Player* p);
#endif

