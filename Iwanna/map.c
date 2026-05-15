#include <stdio.h>
#include <string.h>
#include "map.h"

//创建世界 
void Game_map_MapInit(Game_commonMap* map)
{
	//创建地面 
	map -> ground = (SDL_Rect){0, 885, 1600, 15};

	//创建左墙
	map -> air[0] = (SDL_Rect){0, 0, 1, 900};

	//创建右墙
	map -> air[2] = (SDL_Rect){1599, 0 ,1 ,900};

	//创建天花板
	map -> air[1] = (SDL_Rect){0, 0, 1600, 1};

}

//读取关卡编码数据 并创建矩形 
int Game_map_LoadFromFile(Game_levelMap* level, const char* filename)
{
	FILE* file = fopen(filename, "r");
	
	level -> spikeCount = 0;
	level -> blockCount = 0;
	
	char type[64];
	
	int x, y, w, h;
	
	//fscanf返回成功读取的项数 
	while(fscanf(file, "%s %d %d %d %d", type, &x, &y, &w, &h) == 5){
		SDL_Rect rect = {x, y, w, h};
		
		//按类存入结构体 
		if(strcmp(type, "spike") == 0)
			level -> spikes[level -> spikeCount++] = rect;
		
		if(strcmp(type, "block") == 0)
			level -> blocks[level -> blockCount++] = rect;
			
		if(strcmp(type, "destination") == 0)
			level -> destination = rect;
	}
	
	fclose(file);
	return 1;
}

