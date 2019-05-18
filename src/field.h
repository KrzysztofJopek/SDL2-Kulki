#ifndef _FIELD_H_
#define _FIELD_H_
#include <SDL2/SDL.h>
#include "ball.h"

class Field{
public:
    Field(SDL_Rect rect);
    void render();

    SDL_Rect getRect();
    void createBall(Color::xColor c);
    void destroyBall();

private:
    Ball* ball;
    SDL_Rect rect;
};

#endif
