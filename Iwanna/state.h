#ifndef STATE_H
#define STATE_H

typedef enum{
	STATE_MAIN_MENU,
	STATE_LEVEL_SELECT,
	STATE_QUIT,
	STATE_GAME
} Game_state_GameState;

void Game_state_setState(Game_state_GameState* current, Game_state_GameState next);
Game_state_GameState Game_state_getState(Game_state_GameState* current);

#endif
