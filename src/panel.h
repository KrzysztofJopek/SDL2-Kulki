#ifndef _PANEL_H_
#define _PANEL_H_
#include <SDL2/SDL.h>
#include "field.h"
#include "app.h"

class Panel{
public:
    Panel(SDL_Rect rect, SDL_Color color);
    SDL_Rect getRect();
    void render();
    virtual void handleClick(int x, int y) = 0;
protected:
    SDL_Rect rect;
    SDL_Color color;
};

class GamePanel: public Panel{
public:
    GamePanel(SDL_Rect rect, SDL_Color color);
    ~GamePanel();
    void render();
    void handleClick(int x, int y);
private:
    Field* findField(int x, int y);
    void createRandomBall();
    bool canMove(int Ax, int Ay, int Bx, int By);
    bool checkNextPos(int Ax, int Ay, int Bx, int By, bool map[9][9]);

    static const int N = 9;
    int balls = 0;
    const int size = 80;
    Field* board[N][N];
    Field* selected;
};

class BarPanel: public Panel{
public:
    BarPanel(SDL_Rect rect, SDL_Color color): Panel(rect, color){};
    void handleClick(int x, int y);
};

#endif
