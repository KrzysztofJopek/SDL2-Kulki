#include "field.h"
#include "global.h"

Field::Field(SDL_Rect rect, int x, int y): rect(rect)
{
    ball = nullptr;
    this->x = x;
    this->y = y;
}

void Field::render(bool isSelected)
{
    if(ball)
        ball->render();

    if(isSelected)
        SDL_SetRenderDrawColor(g_renderer, 0xff, 0xff, 0xff, 0xff);
    else
        SDL_SetRenderDrawColor(g_renderer, 0, 0, 0, 0xff);
    
    SDL_RenderDrawRect(g_renderer, &rect);

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

bool Field::hasBall()
{
    return ball;
}

bool Field::hasSameColor(Field* field)
{
    if(field->hasBall() && this->hasBall()){
        return field->ball->color.color == this->ball->color.color;
    }
    return false;
}

bool Field::moveBall(Field* field)
{
    if(!field || !ball)
        return false;

    field->createBall(ball->color.color);
    destroyBall();
    return true;
}

SDL_Rect Field::getRect()
{
    return rect;
}

int Field::getX()
{
    return x;
}

int Field::getY()
{
    return y;
}
