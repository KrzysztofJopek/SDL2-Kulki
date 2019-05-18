#ifndef _FIELD_H_
#define _FIELD_H_
#include <SDL2/SDL.h>
#include "ball.h"

class Field{
public:
    Field(SDL_Rect rect, int x, int y);
    void render(bool isSelected);

    SDL_Rect getRect();
    void createBall(Color::xColor c);
    void destroyBall();
    bool moveBall(Field* field);
    bool hasBall();
    int getX();
    int getY();
    bool hasSameColor(Field* field);

private:
    Ball* ball;
    SDL_Rect rect;
    int x;
    int y;
};

#endif
