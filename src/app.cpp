#include "app.h"
#include <SDL2/SDL_image.h>

SDL_Renderer* g_renderer;

App::App()
{
    if(SDL_Init(SDL_INIT_VIDEO) == -1)
        ERROR();
    int imgFlags = IMG_INIT_PNG;
    if(!(IMG_Init(imgFlags) & imgFlags))
        ERROR();

    controls = new Controls(this);

    window = SDL_CreateWindow(
            "SDL2 Pong Game",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            App::WIDTH,
            App::HEIGHT,
            SDL_WINDOW_SHOWN);
    if(!window)
        ERROR();

    g_renderer = SDL_CreateRenderer(
            window,
            -1,
            SDL_RENDERER_ACCELERATED);
    if(!g_renderer)
        ERROR();
}

App::~App()
{
    SDL_DestroyRenderer(g_renderer);
    SDL_DestroyWindow(window);
    delete controls;
}

void App::run()
{
    unsigned int tick1, tick2, delta;
    tick1 = SDL_GetTicks();
    while(running){
        tick2 = SDL_GetTicks();
        delta = tick2 - tick1;
        tick1 = tick2;

        controls->handleEvents();
    }
}

void App::quit()
{
    running = false;
}
