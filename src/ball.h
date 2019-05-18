#ifndef _BALL_H_
#define _BALL_H_
#include "color.h"
#include <SDL2/SDL.h>

class Ball{
public:
    Ball(Color::xColor color, SDL_Rect rect);
    Color color;
    void render();
    SDL_Rect rect; 
};

#endif
