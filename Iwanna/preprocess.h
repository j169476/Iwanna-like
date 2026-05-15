#ifndef PREPROCESS_H
#define PREPROCESS_H

TTF_Font* Game_Pre_TTF();

SDL_Window* Game_Pre_CreateWindow();

void Game_Pre_Render(SDL_Renderer* renderer);

void Game_Pre_CreateButtonM(Game_menu_Button* quitButton, Game_menu_Button* levelSelectButton, TTF_Font* font);

void Game_Pre_CreateButtonS(Game_menu_Button* level_1, Game_menu_Button* level_2, Game_menu_Button* level_3, 
						  Game_menu_Button* level_4, Game_menu_Button* level_5, Game_menu_Button* level_6, 
						  Game_menu_Button* Back, TTF_Font* font);
#endif
