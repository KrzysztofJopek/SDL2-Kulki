#include "ball.h"
#include "global.h"

Ball::Ball(Color::xColor c, SDL_Rect rect): color(c), rect(rect)
{
}

void Ball::render()
{
    SDL_SetRenderDrawColor(g_renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawRect(g_renderer, &rect);
}
