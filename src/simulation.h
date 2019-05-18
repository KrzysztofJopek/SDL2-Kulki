#ifndef _SIMULATION_H_
#define _SIMULATION_H_

#include "panel.h"
class GamePanel;
class BarPanel;

class Simulation{
public:
    Simulation();
    ~Simulation();
    void render();
    void handleClick(int x, int y);
    GamePanel* game;
    BarPanel* bar;
private:

};

#endif
