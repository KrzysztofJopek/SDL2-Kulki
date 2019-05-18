#ifndef _APP_H_
#define _APP_H_
#include <SDL2/SDL.h>

#include "global.h"
#include "controls.h"

class Controls;

class App{
    SDL_Window* window = nullptr;
    Controls* controls;

    bool running = true;
    static inline const int WIDTH = 640;
    static inline const int HEIGHT = 480;
public:
    App();
    ~App();
    void run();
    void quit();

};

#endif
