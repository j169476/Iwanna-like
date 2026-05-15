#include "renderer.h"
#include "menu.h"
#include "SDL2/SDL.h"
#include <stdio.h>
#include "SDL2/SDL_ttf.h"
#include "menu.h"

// 字体读取
TTF_Font* Game_Pre_TTF()
{
	if(TTF_Init() < 0){
		printf("%s\n", TTF_GetError());
	}
	
	TTF_Font* font = TTF_OpenFont("assets\\Font\\arial.ttf", 24);
	if(!font){
		printf("%s\n", TTF_GetError());
	}
	return font;
} 

// 创建窗口 
SDL_Window* Game_Pre_CreateWindow()
{
	if(SDL_Init(SDL_INIT_VIDEO) < 0){
		printf("%s\n", SDL_GetError());
	}

	SDL_Window* window = SDL_CreateWindow(
	"IWanna",
	SDL_WINDOWPOS_CENTERED,
	SDL_WINDOWPOS_CENTERED,
	1600,
	900,
	SDL_WINDOW_SHOWN
	);
	return window;
}

// 渲染预处理
void Game_Pre_Render(SDL_Renderer* renderer)
{
	// 背景
	SDL_SetRenderDrawColor(renderer, 30, 30, 30, 150);
	SDL_RenderClear(renderer);
}

// 菜单按钮创建 
void Game_Pre_CreateButtonM(Game_menu_Button* quitButton, Game_menu_Button* levelSelectButton, TTF_Font* font)
{
	Game_menu_initButton(quitButton, 700, 400, 200, 80, font);
	Game_menu_initButton(levelSelectButton, 700, 300, 200, 80, font);
	Game_menu_setButtonText(quitButton, "Quit");
	Game_menu_setButtonText(levelSelectButton, "Level Select");
}

// 选择按钮创建 
void Game_Pre_CreateButtonS(Game_menu_Button* level_1, Game_menu_Button* level_2, Game_menu_Button* level_3, 
						  Game_menu_Button* level_4, Game_menu_Button* level_5, Game_menu_Button* level_6, 
						  Game_menu_Button* Back, TTF_Font* font)
{
	SDL_Rect levelButtonRects[6];

	int btnW = 350, btnH = 120;
	int spacing = 50;
	int startX = 225, startY = 305;

	for (int row = 0; row < 2; row++) {
    	for (int col = 0; col < 3; col++) {
        	int index = row * 3 + col;
        	levelButtonRects[index].x = startX + col * (btnW + spacing);
        	levelButtonRects[index].y = startY + row * (btnH + spacing);
        	levelButtonRects[index].w = btnW;
        	levelButtonRects[index].h = btnH;
    	}
	}
	
	//按钮创建
	const char* buttonTexts[6] = {
    	"Level.1", "Level.2", "Level.3",
    	"Level.4", "Level.5", "Level.6"
	};

	Game_menu_initButton(Back, 700, 645, 200, 80, font);
	Game_menu_setButtonText(Back, "Back");
	
	Game_menu_initButton(level_1, levelButtonRects[0].x, levelButtonRects[0].y, btnW, btnH, font);
	Game_menu_setButtonText(level_1, buttonTexts[0]);
			
	Game_menu_initButton(level_1, levelButtonRects[0].x, levelButtonRects[0].y, btnW, btnH, font);
	Game_menu_setButtonText(level_1, buttonTexts[0]);

	Game_menu_initButton(level_2, levelButtonRects[1].x, levelButtonRects[1].y, btnW, btnH, font);
	Game_menu_setButtonText(level_2, buttonTexts[1]);

	Game_menu_initButton(level_3, levelButtonRects[2].x, levelButtonRects[2].y, btnW, btnH, font);
	Game_menu_setButtonText(level_3, buttonTexts[2]);

	Game_menu_initButton(level_4, levelButtonRects[3].x, levelButtonRects[3].y, btnW, btnH, font);
	Game_menu_setButtonText(level_4, buttonTexts[3]);

	Game_menu_initButton(level_5, levelButtonRects[4].x, levelButtonRects[4].y, btnW, btnH, font);
	Game_menu_setButtonText(level_5, buttonTexts[4]);

	Game_menu_initButton(level_6, levelButtonRects[5].x, levelButtonRects[5].y, btnW, btnH, font);
	Game_menu_setButtonText(level_6, buttonTexts[5]);
}
