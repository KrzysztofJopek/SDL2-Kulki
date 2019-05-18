#ifndef _COLOR_H_
#define _COLOR_H_
#include <SDL2/SDL.h>
class Color: public SDL_Color{
public:
    enum xColor{
        RED=0,
        GREEN,
        BLUE
    };

    Color(xColor c);
    xColor color;
    void setColor(xColor c);
};

#endif
