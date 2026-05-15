#include "state.h"
#include <stddef.h>

void Game_state_setState(Game_state_GameState* current, Game_state_GameState next){
	if(current == NULL) return;
	*current = next;
}

Game_state_GameState Game_state_getState(Game_state_GameState* current){
	if(current == NULL)
		return STATE_QUIT;
	return *current;
}
