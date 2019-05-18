#ifndef _APP_H_
#define _APP_H_
#include <SDL2/SDL.h>

#include "global.h"
#include "controls.h"

class Controls;

class App{
public:
    App();
    ~App();
    void run();
    void quit();
    static inline const int WIDTH = 720+200;
    static inline const int HEIGHT = 720;
private:
    SDL_Window* window = nullptr;
    Controls* controls;

    bool running = true;

};

#endif
