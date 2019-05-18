#include "panel.h"
#include "global.h"

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
            board[x][y] = new Field({x*size, y*size, size, size});
        }
    }
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
            board[x][y]->render();
        }
    }
}

void GamePanel::handleClick(int x, int y)
{
    Field* field = findField(x, y);
    if(field);
        field->createBall(Color::RED);
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


void BarPanel::handleClick(int x, int y)
{
    printf("Clicked: BarPanel - %d %d\n", x, y);
}


