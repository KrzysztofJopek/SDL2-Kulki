#include "field.h"
#include "global.h"

Field::Field(SDL_Rect rect): rect(rect)
{
    ball = nullptr;
}

void Field::render()
{
    SDL_SetRenderDrawColor(g_renderer, 0, 0, 0, 0xff);
    SDL_RenderDrawRect(g_renderer, &rect);
    if(ball)
        ball->render();
}


void Field::createBall(Color::xColor c)
{
    destroyBall();
    ball = new Ball(c, rect);
}

void Field::destroyBall()
{
    if(ball){
        delete ball;
        ball = nullptr;
    }
}

SDL_Rect Field::getRect()
{
    return rect;
}
