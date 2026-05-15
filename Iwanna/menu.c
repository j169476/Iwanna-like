#include <SDL2/SDL.h>
#include <stdbool.h>
#include <string.h>
#include <SDL2/SDL_ttf.h>
#include <stdlib.h>
#include "renderer.h"
#include "menu.h"
#include "state.h"

//初始化按钮 
void Game_menu_initButton(Game_menu_Button* btn, int x, int y, int w, int h, TTF_Font* font){
	btn -> rect.x = x;
	btn -> rect.y = y;
	btn -> rect.w = w;
	btn -> rect.h = h;

	btn -> color = (SDL_Color){225, 182, 193, 255};
	btn -> hoveredColor = (SDL_Color){125,170,180, 255};
	btn -> textColor = (SDL_Color){0, 0, 0, 255};  //text support
	btn -> isHovered = false;
	btn -> text = NULL;  //text support
	btn -> font = font; // text support
}

//设置文字
void Game_menu_setButtonText(Game_menu_Button* btn, const char* text){
	if(btn -> text != NULL){
		free(btn -> text);
	}
	btn -> text = strdup(text);
} 

//范围检测 
bool Game_menu_pointInRect(int x, int y, SDL_Rect rect){
	return (x >= rect.x && x <= rect.x + rect.w &&
			y >= rect.y && y <= rect.y + rect.h);
}

//绘制按钮
 void Game_menu_drawButton(SDL_Renderer* buttonRenderer, Game_menu_Button* btn){
 	SDL_Color color = btn -> isHovered ? btn -> hoveredColor : btn -> color;
 	
 	SDL_SetRenderDrawColor(buttonRenderer, color.r, color.g, color.b, color.a);
 	SDL_RenderFillRect(buttonRenderer, &btn -> rect);
 	SDL_SetRenderDrawColor(buttonRenderer, 255, 255, 255, 255);
 	SDL_RenderDrawRect(buttonRenderer, &btn -> rect);
 	
 	/*------------------------------------------text rendering--------------------------------------*/
 	//安全检查 
 	if(btn -> text != NULL && btn -> font != NULL){
 		//将ttf转换为像素图像
	 	SDL_Surface* textSurface = TTF_RenderUTF8_Blended(btn -> font, btn -> text, btn -> textColor);
	 	//将CPU像素数据转为GPU纹理 
		SDL_Texture* textTexture = SDL_CreateTextureFromSurface(buttonRenderer, textSurface);
		
		//获取长宽 
		int textWidth = textSurface -> w;
		int textHeight = textSurface -> h;
		
		//居中计算 
		SDL_Rect textRect = {
			btn -> rect.x + (btn -> rect.w - textWidth) / 2,
			btn -> rect.y + (btn -> rect.h - textHeight) / 2,
			textWidth,
			textHeight
		};
		
		//渲染文字
		SDL_RenderCopy(buttonRenderer, textTexture, NULL, &textRect); //null为不剪裁，使用整个纹理
		
		//清理 
		SDL_DestroyTexture(textTexture);
		SDL_FreeSurface(textSurface);
	}
}
