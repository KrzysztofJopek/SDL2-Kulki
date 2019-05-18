#ifndef _GLOBAL_H_
#define _GLOBAL_H_

#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

#define ERROR() do{fprintf(stderr, "ERROR: %s", SDL_GetError()); exit(1);}while(0)

extern SDL_Renderer* g_renderer;

#endif
