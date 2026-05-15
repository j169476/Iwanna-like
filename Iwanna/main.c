#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string.h>
#include "collision.h"
#include "menu.h"
#include "state.h"
#include "renderer.h"
#include "map.h"
#include "input.h"
#include "player.h"
#include "preprocess.h"

#define MAX_LEVEL 6

int main(int argc, char* argv[]){
	(void)argc;
	(void)argv;
	//加载字体
	TTF_Font* font = Game_Pre_TTF();

	// 窗口创建
	SDL_Window* window = Game_Pre_CreateWindow();

	//初始化渲染器
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if(!renderer){
		printf("%s\n", SDL_GetError());
	}

	//渲染预处理 
	Game_Pre_Render(renderer);

	//menu按钮创建
	Game_menu_Button quitButton, levelSelectButton;
	Game_Pre_CreateButtonM(&quitButton, &levelSelectButton, font);
	
	//Select按钮创建
	Game_menu_Button level_1, level_2, level_3, level_4, level_5, level_6, Back;
	Game_Pre_CreateButtonS(&level_1, &level_2, &level_3, &level_4, &level_5, &level_6, &Back, font);

	//地图通用框架创建
	Game_commonMap commonMap;
	Game_map_MapInit(&commonMap);
	
	//关卡储存 / 关卡参数 
	Game_levelMap currentLevel;
	bool levelLoaded = false;
	int currentLevelIndex;
	
	//角色创建
	Game_Player player;
	Game_player_Init(&player); 
	
	//输入初始化
	Game_Input key;
	 
/*---------------------------------------------------------------------------------------------------*/
	//主循环(游戏主架构) 
	Game_state_GameState currentState = STATE_MAIN_MENU;
	int running = 1;
	SDL_Event event;
	int mouse_x, mouse_y; 

while(running){
	//事件处理
	while(SDL_PollEvent(&event)){
		if(event.type == SDL_QUIT) running = 0;
		
		//game菜单按键检测
		if(currentState == STATE_GAME){
			if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
				currentState = STATE_MAIN_MENU;
		}
		
		//menu鼠标位置检测 
		if(currentState == STATE_MAIN_MENU){
			if(event.type == SDL_MOUSEMOTION){
				SDL_GetMouseState(&mouse_x, &mouse_y);
				
				//menu悬停检测
				levelSelectButton.isHovered = Game_menu_pointInRect(mouse_x, mouse_y, levelSelectButton.rect);
				quitButton.isHovered = Game_menu_pointInRect(mouse_x, mouse_y, quitButton.rect);
			}
			
			//menu点击检测
			if(event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT){
				if(Game_menu_pointInRect(mouse_x, mouse_y, levelSelectButton.rect)){
					Game_state_setState(&currentState, STATE_LEVEL_SELECT);
				}
				
				if(Game_menu_pointInRect(mouse_x, mouse_y, quitButton.rect)){
					Game_state_setState(&currentState, STATE_QUIT);
				}
			}	
		}
		
		else if(currentState == STATE_LEVEL_SELECT){
			//select鼠标位置检测
			 if(event.type == SDL_MOUSEMOTION){
			 	SDL_GetMouseState(&mouse_x, &mouse_y);
			 	
			 	//select悬停判断
				level_1.isHovered = Game_menu_pointInRect(mouse_x, mouse_y, level_1.rect);
                level_2.isHovered = Game_menu_pointInRect(mouse_x, mouse_y, level_2.rect);
                level_3.isHovered = Game_menu_pointInRect(mouse_x, mouse_y, level_3.rect);
                level_4.isHovered = Game_menu_pointInRect(mouse_x, mouse_y, level_4.rect);
                level_5.isHovered = Game_menu_pointInRect(mouse_x, mouse_y, level_5.rect);
                level_6.isHovered = Game_menu_pointInRect(mouse_x, mouse_y, level_6.rect);
                Back.isHovered = Game_menu_pointInRect(mouse_x, mouse_y, Back.rect);
			 }
			 
			 //select点击检测 
			 if(event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT){
			 	if(Game_menu_pointInRect(mouse_x, mouse_y, Back.rect)) Game_state_setState(&currentState, STATE_MAIN_MENU);
			 	if(Game_menu_pointInRect(mouse_x, mouse_y, level_1.rect)){
			 		//留作接口 
			 		if(Game_map_LoadFromFile(&currentLevel, "maps\\level_1.txt")){
			 			levelLoaded = true;
			 			Game_state_setState(&currentState, STATE_GAME);
			 			Game_player_Init(&player);
			 			currentLevelIndex = 1;
					 }
				 }
				 
				 if(Game_menu_pointInRect(mouse_x, mouse_y, level_2.rect)){
			 		//留作接口 
			 		if(Game_map_LoadFromFile(&currentLevel, "maps\\level_2.txt")){
			 			levelLoaded = true;
			 			Game_state_setState(&currentState, STATE_GAME);
			 			Game_player_Init(&player);
			 			currentLevelIndex = 2;
			 		}
				 }
				 
				 if(Game_menu_pointInRect(mouse_x, mouse_y, level_3.rect)){
			 		//留作接口 
			 		if(Game_map_LoadFromFile(&currentLevel, "maps\\level_3.txt")){
			 			levelLoaded = true;
			 			Game_state_setState(&currentState, STATE_GAME);
			 			Game_player_Init(&player);
			 			currentLevelIndex = 3;
			 		}
				 }
				 
				 if(Game_menu_pointInRect(mouse_x, mouse_y, level_4.rect)){
			 		//留作接口 
			 		if(Game_map_LoadFromFile(&currentLevel, "maps\\level_4.txt")){
			 			levelLoaded = true;
			 			Game_state_setState(&currentState, STATE_GAME);
			 			Game_player_Init(&player);
			 			currentLevelIndex = 4;
					}
				 }
				 
				 if(Game_menu_pointInRect(mouse_x, mouse_y, level_5.rect)){
			 		//留作接口 
			 		if(Game_map_LoadFromFile(&currentLevel, "maps\\level_5.txt")){
			 			levelLoaded = true;
			 			Game_state_setState(&currentState, STATE_GAME);
			 			Game_player_Init(&player);
			 			currentLevelIndex = 5;
			 		}
				 }
				 
				 if(Game_menu_pointInRect(mouse_x, mouse_y, level_6.rect)){
			 		//留作接口 
			 		if(Game_map_LoadFromFile(&currentLevel, "maps\\level_6.txt")){
			 			levelLoaded = true;
			 			Game_state_setState(&currentState, STATE_GAME);
			 			Game_player_Init(&player);
			 			currentLevelIndex = 6;
			 		}
				 }
			 	
			 }
		}
	}//事件结束
	
	//STATE_GAME
	if(currentState == STATE_GAME){
		//输入处理
		Game_input_In(&key); 
		//角色更新
		Game_player_Update(&player, &key);
		
		int gameCurrentState = Game_collision_ALL(&player, &commonMap, &currentLevel);
		//寄！ 
		if(gameCurrentState == -1){
			Game_player_Init(&player);
		}
	
		//过！
		if(gameCurrentState == 1){
			currentLevelIndex++;
			
			//通关
			if(currentLevelIndex > MAX_LEVEL){
				currentState = STATE_MAIN_MENU;
			//通关接口
			} else {
				char path[64];
				sprintf(path, "maps\\level_%d.txt", currentLevelIndex);
				Game_map_LoadFromFile(&currentLevel, path);
				Game_player_Init(&player);
			}
		}
	}
	
	//渲染部分
	SDL_SetRenderDrawColor(renderer, 30, 30, 30, 150);
	SDL_RenderClear(renderer);
	
	switch(currentState){
		
		case STATE_MAIN_MENU : 
			Game_menu_drawButton(renderer, &levelSelectButton);
			Game_menu_drawButton(renderer, &quitButton);
			break;
		
		case STATE_LEVEL_SELECT : 
			Game_menu_drawButton(renderer, &Back);
			Game_menu_drawButton(renderer, &level_1);
			Game_menu_drawButton(renderer, &level_2);
			Game_menu_drawButton(renderer, &level_3);
			Game_menu_drawButton(renderer, &level_4);
			Game_menu_drawButton(renderer, &level_5);
			Game_menu_drawButton(renderer, &level_6);
			break;
		
		case STATE_GAME : {
			//渲染地图 
			Game_renderer_mapRender(renderer, &commonMap);
			
			if(levelLoaded){
				//渲染关卡 
				Game_render_levelRender(renderer, &currentLevel);
				//渲染角色 
				Game_render_playerRender(renderer, &player);
			}
			
			break;
		}
		case STATE_QUIT : 
			running = 0;
			break;
	}
	//显示 
	SDL_RenderPresent(renderer);
	SDL_Delay(16);
}

/*---------------------------------------------------------------------------------------------------*/
	//退出清理
	TTF_CloseFont(font);
	TTF_Quit();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window); 
	SDL_Quit();
	return 0;
}
