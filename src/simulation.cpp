#include "simulation.h"
#include "app.h"
#include <SDL2/SDL.h>

Simulation::Simulation()
{
    game = new GamePanel({0, 0, App::WIDTH-200, App::HEIGHT}, {50, 50, 50, 255});
    bar = new BarPanel({App::WIDTH-200, 0, 200, App::HEIGHT}, {90, 90, 90, 255});
}

Simulation::~Simulation()
{
    delete game;
    delete bar;
}

void Simulation::render()
{
    SDL_RenderClear(g_renderer);
    game->render();
    bar->render();
    SDL_RenderPresent(g_renderer);
}

void Simulation::handleClick(int x, int y)
{
    if(x >= 0 && x < game->getRect().w){
        game->handleClick(x,y);
    }
    else{
        bar->handleClick(x-bar->getRect().x, y);
    }
}
