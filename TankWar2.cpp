// TankWar2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.


#include <iostream>
#include "gameconsts.h"
#include "Tank.h"
#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include<windows.h>
#include "MoveType.h"


using namespace std;
using namespace gameconsts;


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
            gameconsts::field[i][j] = ch;
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
//void moveControl()
//{
//    if (GetAsyncKeyState(VK_LEFT))
//    {
//        tank.move(MoveType::Left);
//    }
//    if (GetAsyncKeyState(VK_RIGHT))
//    {
//        tank.move(MoveType::Right);
//    }
//    if (GetAsyncKeyState(VK_UP))
//    {
//        tank.move(MoveType::Up);
//    }
//    if (GetAsyncKeyState(VK_DOWN))
//    {
//        tank.move(MoveType::Down);
//    }
//    if (GetAsyncKeyState(VK_ESCAPE))
//    {
//        s = false;
//    }
//    if (GetAsyncKeyState(VK_SPACE))
//    {
//
//    }
//}

int main()
{
    Tank tank;
    bool s = true;

    while (s)
    {
        setCursorPosition(height, width);
        fullingField(' ');
        tank.draw(gameconsts::field);
        printField(gameconsts::field);

        if (GetAsyncKeyState(VK_LEFT))
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
            s = false;
        }
        if (GetAsyncKeyState(VK_SPACE))
        {

        }
    }
}

