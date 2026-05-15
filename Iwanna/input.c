#include "input.h"
#include <SDL2/SDL.h>

void Game_input_In(Game_Input* in)
{
    const Uint8* keys = SDL_GetKeyboardState(NULL);

    in -> left  = keys[SDL_SCANCODE_A];
    in -> right = keys[SDL_SCANCODE_D];
    in -> jump  = keys[SDL_SCANCODE_SPACE];
}

