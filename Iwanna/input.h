#ifndef INPUT_H
#define INPUT_H

typedef struct {
    int left;
    int right;
    int jump;
    int jumpPressed;
    int jumpReleased;  
} Game_Input;

void Game_input_In(Game_Input* in);

#endif

