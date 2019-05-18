#include "panel.h"
#include "global.h"
#include <stdlib.h>
#include <time.h>

Panel::Panel(SDL_Rect rect, SDL_Color color)
{
    this->rect = rect;
    this->color = color;
}

SDL_Rect Panel::getRect()
{
    return rect;
}


void Panel::render()
{
    SDL_SetRenderDrawColor(g_renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(g_renderer, &rect);
}

GamePanel::GamePanel(SDL_Rect rect, SDL_Color color): Panel(rect, color)
{
    for(int x=0; x<N; x++){
        for(int y=0; y<N; y++){
            board[x][y] = new Field({x*size, y*size, size, size}, x, y);
        }
    }
    selected = nullptr;
    srand (time(NULL));
    for(int i=0; i<3; i++){
        createRandomBall();
    }
}

bool GamePanel::canMove(int Ax, int Ay, int Bx, int By)
{
    bool map[9][9] = {0,};
    for(int x=0; x<N; x++){
        for(int y=0; y<N; y++){
            if(board[x][y]->hasBall())
                map[x][y] = true;
        }
    }
    return checkNextPos(Ax, Ay, Bx, By, map);
}

bool GamePanel::checkNextPos(int Ax, int Ay, int Bx, int By, bool map[9][9])
{
    if(Ax == Bx && Ay == By) 
        return true;
    map[Ax][Ay] = true;

    if((Ax-1 >= 0) && (map[Ax-1][Ay] == false)){
        if(checkNextPos(Ax-1, Ay, Bx, By, map))
            return true;
    }
    if((Ax+1 < 9) && (map[Ax+1][Ay] == false)){
        if(checkNextPos(Ax+1, Ay, Bx, By, map))
            return true;
    }
    if((Ay-1 >= 0) && (map[Ax][Ay-1] == false)){
        if(checkNextPos(Ax, Ay-1, Bx, By, map))
            return true;
    }
    if((Ay+1 < 9) && (map[Ax][Ay+1] == false)){
        if(checkNextPos(Ax, Ay+1, Bx, By, map))
            return true;
    }
    return false;
}

GamePanel::~GamePanel()
{
    for(int x=0; x<N; x++){
        for(int y=0; y<N; y++){
            delete board[x][y];
        }
    }

}

void GamePanel::render()
{
    Panel::render();
    for(int x=0; x<N; x++){
        for(int y=0; y<N; y++){
            board[x][y]->render(false);
        }
    }
    if(selected)
        selected->render(true);
}

//TODO this method is too compliacted
void GamePanel::handleClick(int x, int y)
{
    Field* field = findField(x, y);
    if(field){
        if(field == selected){
            selected = nullptr;
        }
        else if(field->hasBall()){
            selected = field;
        }
        else{
            if(selected){
                bool moved = false;
                if(canMove(selected->getX(), selected->getY(),
                            field->getX(), field->getY())){
                    moved = selected->moveBall(field);
                }
                if(moved){
                    selected = nullptr;
                    for(int i=0; i<3; i++){
                        createRandomBall();
                    }
                }
            }
        }
    }
}

Field* GamePanel::findField(int x, int y)
{
    SDL_Rect temp;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            temp = board[i][j]->getRect();
            if(x < temp.x || x >= temp.x+temp.w ||
                    y < temp.y || y >= temp.y+temp.h)
                continue;
            return board[i][j];
        }
    }
    return nullptr;
}

void GamePanel::createRandomBall()
{
    if(balls == N*N)
        return;

    int freeFields = N*N - balls;
    int randField = rand() % freeFields;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(board[i][j]->hasBall())
                continue;
            //TODO don't use hardcoded number of colors
            if(randField-- <= 0){
                board[i][j]->createBall(static_cast<Color::xColor>(rand() % 3));
                balls++;
                return;
            }
        }
    }


}

void BarPanel::handleClick(int x, int y)
{
    printf("Clicked: BarPanel - %d %d\n", x, y);
}


