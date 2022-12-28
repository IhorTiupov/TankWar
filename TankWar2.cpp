// TankWar2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#include <iostream>
#include "gameconsts.h"
#include "Tank.h"
#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include "MoveType.h"
#include "GameControl.h"
#include "Shot.h"


using namespace std;
using namespace gameconsts;

static std::vector<std::vector<char>> field(height, std::vector<char>(width));

void printField(vector<vector<char>>& field)
{
    for (size_t i = 0; i < height; i++)
    {
        for (size_t j = 0; j < width; j++)
        {
            cout << field[i][j];
        }
        cout << endl;
    }
}

void fullingField(char ch)
{
    for (size_t i = 0; i < height; i++)
    {
        for (size_t j = 0; j < width; j++)
        {
            field[i][j] = ch;
        }
    }
}
void setCursorPosition(int x, int y) // makes game screen
{
    static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    std::cout.flush();
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(hOut, coord);
    CONSOLE_CURSOR_INFO CCI;
    CCI.bVisible = false;
    CCI.dwSize = 1;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CCI);
}

int main()
{
    std::vector<Shot> shots;
    Tank tank{field};
    bool stop = true;
    fullingField(' ');
    int count = 0;
    while (stop)
    {
        setCursorPosition(height, width);

        tank.draw(field);
        //cout << shots.size() << std::endl;
        /*shots.erase(std::remove(shots.begin(), shots.end(), 
            [](Shot& sh) {return sh.getX() <= 0 || sh.getX() >= width || sh.getY() <= 0 || sh.getY() >= height; })
                    , shots.end());*/
        //cout << shots.size() << std::endl;
        count++;
        if (count == 100)
        {
            shots.pop_back();
            count = 0;
        }
        for (auto& shot : shots)
        {
             shot.shotTank();
        }
        printField(field);

        if(GetAsyncKeyState(VK_LEFT))
        {
            tank.move(MoveType::Left);
        }
        if (GetAsyncKeyState(VK_RIGHT))
        {
            tank.move(MoveType::Right);
        }
        if (GetAsyncKeyState(VK_UP))
        {
            tank.move(MoveType::Up);
        }
        if (GetAsyncKeyState(VK_DOWN))
        {
            tank.move(MoveType::Down);
        }
        if (GetAsyncKeyState(VK_ESCAPE))
        {
            stop = false;
        }
        if (GetAsyncKeyState(VK_SPACE))
        {
           shots.emplace_back(field, tank.getGunX(), tank.getGunY(), tank.getDirection());
           
        }
    }
}

