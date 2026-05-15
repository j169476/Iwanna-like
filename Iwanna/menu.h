#ifndef MENU_H
#define MENU_H

#include <stdbool.h>
#include <SDL2/SDL_ttf.h>

typedef struct {
	SDL_Rect rect;
	SDL_Color color;
	SDL_Color hoveredColor;
	bool isHovered;
	SDL_Color textColor;  //text support
	char* text; //text support
	TTF_Font* font; //text support
} Game_menu_Button;

//初始化按钮 
void Game_menu_initButton(Game_menu_Button* btn, int x, int y, int w, int h, TTF_Font* font);

//范围检测
bool Game_menu_pointInRect(int x, int y, SDL_Rect rect);

//按钮绘制
void Game_menu_drawButton(SDL_Renderer* button_renderer, Game_menu_Button* btn); 

//文字
void Game_menu_setButtonText(Game_menu_Button* btn, const char* text); 

#endif
