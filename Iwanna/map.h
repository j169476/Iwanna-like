#ifndef MAP_H
#define MAP_H

#include <SDL2/SDL.h>

#define MAX_TITLE 2000

typedef struct {
	SDL_Rect ground;
	SDL_Rect air[3];
} Game_commonMap;

typedef struct {
	SDL_Rect destination;

	SDL_Rect spikes[MAX_TITLE];
	int spikeCount;

	SDL_Rect blocks[MAX_TITLE];
	int blockCount;
} Game_levelMap;

void Game_map_MapInit(Game_commonMap* map);

int Game_map_LoadFromFile(Game_levelMap* level, const char* filename);

#endif
