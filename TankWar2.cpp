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
#include "Walls.h"

using namespace std;
using namespace gameconsts;

static vector<vector<char>> field(height, vector<char>(width));

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
    Walls wall{ field, 0, 0 };
    bool stop = true;

    fullingField(' ');
    int count = 0;
    int size = shots.empty();
    wall.draw(field);
    while (stop)
    {
        setCursorPosition(0, 0);
        tank.draw(field);

        if (count > 10 && !size)
        {
            shots.pop_back();
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

