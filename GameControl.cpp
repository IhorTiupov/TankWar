#include<windows.h>
#include "GameControl.h"
#include "MoveType.h"

GameControl::GameControl(Tank& t, bool& stopGame) : tank(t), stop(stopGame)
{}

void GameControl::moveControl()
{
	//if (GetAsyncKeyState(VK_LEFT))
 //   {
 //       tank.move(MoveType::Left);
 //   }
 //   if (GetAsyncKeyState(VK_RIGHT))
 //   {
 //       tank.move(MoveType::Right);
 //   }
 //   if (GetAsyncKeyState(VK_UP))
 //   {
 //       tank.move(MoveType::Up);
 //   }
 //   if (GetAsyncKeyState(VK_DOWN))
 //   {
 //       tank.move(MoveType::Down);
 //   }
 //   if (GetAsyncKeyState(VK_ESCAPE))
 //   {
 //       stop = false;
 //   }
 //   if (GetAsyncKeyState(VK_SPACE))
 //   {

 //   }
}
