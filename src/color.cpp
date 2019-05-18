#include "color.h"

Color::Color(xColor c)
{
    setColor(c);
}

void Color::setColor(xColor c)
{
    switch(c){
        case Color::RED:
            r = 0xff;
            g = 0;
            b = 0;
            break;
        case Color::GREEN:
            r = 0;
            g = 0xff;
            b = 0;
            break;
        case Color::BLUE:
            r = 0;
            g = 0;
            b = 0xff;
            break;
    }
    a=0xff;
    color = c;
}

