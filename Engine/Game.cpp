/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"


Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{

	if (wnd.kbd.KeyIsPressed(w_key)) {

	dudeY -= 1;
	}

	if (wnd.kbd.KeyIsPressed(a_key)) {

		dudeX -= 1;
	}

	if (wnd.kbd.KeyIsPressed(s_key)) {

		dudeY += 1;
	}

	if (wnd.kbd.KeyIsPressed(d_key)) {

		dudeX += 1;
	}

	dudeX = ClampScreenX(dudeX, dudeWidth);
	dudeY = ClampScreenY(dudeY, dudeHeight);
	
	

	if (IsColliding(dudeX, dudeY, dudeWidth, dudeHeight,
		poo0X, poo0Y, pooWidth, pooHeight))
	{
		poo0IsEaten = true;
	}

	if (IsColliding(dudeX, dudeY, dudeWidth, dudeHeight,
		poo1X, poo1Y, pooWidth, pooHeight))
	{
		poo1IsEaten = true;
	}

	if (IsColliding(dudeX, dudeY, dudeWidth, dudeHeight,
		poo2X, poo2Y, pooWidth, pooHeight))
	{
		poo2IsEaten = true;
	}

	
}

void Game::DrawFace(int x, int y)
{
	gfx.PutPixel(7 + x, 0 + y, 0, 0, 0);
	gfx.PutPixel(8 + x, 0 + y, 0, 0, 0);
	gfx.PutPixel(9 + x, 0 + y, 0, 0, 0);
	gfx.PutPixel(10 + x, 0 + y, 0, 0, 0);
	gfx.PutPixel(11 + x, 0 + y, 0, 0, 0);
	gfx.PutPixel(12 + x, 0 + y, 0, 0, 0);
	gfx.PutPixel(5 + x, 1 + y, 0, 0, 0);
	gfx.PutPixel(6 + x, 1 + y, 0, 0, 0);
	gfx.PutPixel(7 + x, 1 + y, 254, 221, 88);
	gfx.PutPixel(8 + x, 1 + y, 254, 221, 88);
	gfx.PutPixel(9 + x, 1 + y, 254, 221, 88);
	gfx.PutPixel(10 + x, 1 + y, 254, 221, 88);
	gfx.PutPixel(11 + x, 1 + y, 254, 221, 88);
	gfx.PutPixel(12 + x, 1 + y, 254, 221, 88);
	gfx.PutPixel(13 + x, 1 + y, 0, 0, 0);
	gfx.PutPixel(14 + x, 1 + y, 0, 0, 0);
	gfx.PutPixel(3 + x, 2 + y, 0, 0, 0);
	gfx.PutPixel(4 + x, 2 + y, 0, 0, 0);
	gfx.PutPixel(5 + x, 2 + y, 254, 221, 88);
	gfx.PutPixel(6 + x, 2 + y, 254, 221, 88);
	gfx.PutPixel(7 + x, 2 + y, 254, 221, 88);
	gfx.PutPixel(8 + x, 2 + y, 254, 221, 88);
	gfx.PutPixel(9 + x, 2 + y, 254, 221, 88);
	gfx.PutPixel(10 + x, 2 + y, 254, 221, 88);
	gfx.PutPixel(11 + x, 2 + y, 254, 221, 88);
	gfx.PutPixel(12 + x, 2 + y, 254, 221, 88);
	gfx.PutPixel(13 + x, 2 + y, 254, 221, 88);
	gfx.PutPixel(14 + x, 2 + y, 254, 221, 88);
	gfx.PutPixel(15 + x, 2 + y, 0, 0, 0);
	gfx.PutPixel(16 + x, 2 + y, 0, 0, 0);
	gfx.PutPixel(2 + x, 3 + y, 0, 0, 0);
	gfx.PutPixel(3 + x, 3 + y, 254, 221, 88);
	gfx.PutPixel(4 + x, 3 + y, 254, 221, 88);
	gfx.PutPixel(5 + x, 3 + y, 254, 221, 88);
	gfx.PutPixel(6 + x, 3 + y, 254, 221, 88);
	gfx.PutPixel(7 + x, 3 + y, 254, 221, 88);
	gfx.PutPixel(8 + x, 3 + y, 254, 221, 88);
	gfx.PutPixel(9 + x, 3 + y, 254, 221, 88);
	gfx.PutPixel(10 + x, 3 + y, 254, 221, 88);
	gfx.PutPixel(11 + x, 3 + y, 254, 221, 88);
	gfx.PutPixel(12 + x, 3 + y, 254, 221, 88);
	gfx.PutPixel(13 + x, 3 + y, 254, 221, 88);
	gfx.PutPixel(14 + x, 3 + y, 254, 221, 88);
	gfx.PutPixel(15 + x, 3 + y, 254, 221, 88);
	gfx.PutPixel(16 + x, 3 + y, 254, 221, 88);
	gfx.PutPixel(17 + x, 3 + y, 0, 0, 0);
	gfx.PutPixel(2 + x, 4 + y, 0, 0, 0);
	gfx.PutPixel(3 + x, 4 + y, 254, 221, 88);
	gfx.PutPixel(4 + x, 4 + y, 254, 221, 88);
	gfx.PutPixel(5 + x, 4 + y, 254, 221, 88);
	gfx.PutPixel(6 + x, 4 + y, 254, 221, 88);
	gfx.PutPixel(7 + x, 4 + y, 254, 221, 88);
	gfx.PutPixel(8 + x, 4 + y, 254, 221, 88);
	gfx.PutPixel(9 + x, 4 + y, 254, 221, 88);
	gfx.PutPixel(10 + x, 4 + y, 254, 221, 88);
	gfx.PutPixel(11 + x, 4 + y, 254, 221, 88);
	gfx.PutPixel(12 + x, 4 + y, 254, 221, 88);
	gfx.PutPixel(13 + x, 4 + y, 254, 221, 88);
	gfx.PutPixel(14 + x, 4 + y, 254, 221, 88);
	gfx.PutPixel(15 + x, 4 + y, 254, 221, 88);
	gfx.PutPixel(16 + x, 4 + y, 254, 221, 88);
	gfx.PutPixel(17 + x, 4 + y, 0, 0, 0);
	gfx.PutPixel(1 + x, 5 + y, 0, 0, 0);
	gfx.PutPixel(2 + x, 5 + y, 254, 221, 88);
	gfx.PutPixel(3 + x, 5 + y, 0, 0, 0);
	gfx.PutPixel(4 + x, 5 + y, 0, 0, 0);
	gfx.PutPixel(5 + x, 5 + y, 254, 221, 88);
	gfx.PutPixel(6 + x, 5 + y, 254, 221, 88);
	gfx.PutPixel(7 + x, 5 + y, 254, 221, 88);
	gfx.PutPixel(8 + x, 5 + y, 254, 221, 88);
	gfx.PutPixel(9 + x, 5 + y, 254, 221, 88);
	gfx.PutPixel(10 + x, 5 + y, 254, 221, 88);
	gfx.PutPixel(11 + x, 5 + y, 0, 0, 0);
	gfx.PutPixel(12 + x, 5 + y, 0, 0, 0);
	gfx.PutPixel(13 + x, 5 + y, 0, 0, 0);
	gfx.PutPixel(14 + x, 5 + y, 0, 0, 0);
	gfx.PutPixel(15 + x, 5 + y, 254, 221, 88);
	gfx.PutPixel(16 + x, 5 + y, 254, 221, 88);
	gfx.PutPixel(17 + x, 5 + y, 254, 221, 88);
	gfx.PutPixel(18 + x, 5 + y, 0, 0, 0);
	gfx.PutPixel(1 + x, 6 + y, 0, 0, 0);
	gfx.PutPixel(2 + x, 6 + y, 0, 0, 0);
	gfx.PutPixel(3 + x, 6 + y, 255, 255, 255);
	gfx.PutPixel(4 + x, 6 + y, 0, 0, 0);
	gfx.PutPixel(5 + x, 6 + y, 0, 0, 0);
	gfx.PutPixel(6 + x, 6 + y, 254, 221, 88);
	gfx.PutPixel(7 + x, 6 + y, 254, 221, 88);
	gfx.PutPixel(8 + x, 6 + y, 254, 221, 88);
	gfx.PutPixel(9 + x, 6 + y, 254, 221, 88);
	gfx.PutPixel(10 + x, 6 + y, 0, 0, 0);
	gfx.PutPixel(11 + x, 6 + y, 255, 255, 255);
	gfx.PutPixel(12 + x, 6 + y, 255, 255, 255);
	gfx.PutPixel(13 + x, 6 + y, 0, 0, 0);
	gfx.PutPixel(14 + x, 6 + y, 0, 0, 0);
	gfx.PutPixel(15 + x, 6 + y, 0, 0, 0);
	gfx.PutPixel(16 + x, 6 + y, 254, 221, 88);
	gfx.PutPixel(17 + x, 6 + y, 254, 221, 88);
	gfx.PutPixel(18 + x, 6 + y, 0, 0, 0);
	gfx.PutPixel(0 + x, 7 + y, 0, 0, 0);
	gfx.PutPixel(1 + x, 7 + y, 0, 0, 0);
	gfx.PutPixel(2 + x, 7 + y, 255, 255, 255);
	gfx.PutPixel(3 + x, 7 + y, 255, 255, 255);
	gfx.PutPixel(4 + x, 7 + y, 0, 0, 0);
	gfx.PutPixel(5 + x, 7 + y, 0, 0, 0);
	gfx.PutPixel(6 + x, 7 + y, 254, 221, 88);
	gfx.PutPixel(7 + x, 7 + y, 254, 221, 88);
	gfx.PutPixel(8 + x, 7 + y, 254, 221, 88);
	gfx.PutPixel(9 + x, 7 + y, 254, 221, 88);
	gfx.PutPixel(10 + x, 7 + y, 0, 0, 0);
	gfx.PutPixel(11 + x, 7 + y, 255, 255, 255);
	gfx.PutPixel(12 + x, 7 + y, 255, 255, 255);
	gfx.PutPixel(13 + x, 7 + y, 0, 0, 0);
	gfx.PutPixel(14 + x, 7 + y, 0, 0, 0);
	gfx.PutPixel(15 + x, 7 + y, 0, 0, 0);
	gfx.PutPixel(16 + x, 7 + y, 254, 221, 88);
	gfx.PutPixel(17 + x, 7 + y, 254, 221, 88);
	gfx.PutPixel(18 + x, 7 + y, 254, 221, 88);
	gfx.PutPixel(19 + x, 7 + y, 0, 0, 0);
	gfx.PutPixel(0 + x, 8 + y, 0, 0, 0);
	gfx.PutPixel(1 + x, 8 + y, 0, 0, 0);
	gfx.PutPixel(2 + x, 8 + y, 255, 255, 255);
	gfx.PutPixel(3 + x, 8 + y, 255, 255, 255);
	gfx.PutPixel(4 + x, 8 + y, 255, 255, 255);
	gfx.PutPixel(5 + x, 8 + y, 0, 0, 0);
	gfx.PutPixel(6 + x, 8 + y, 254, 221, 88);
	gfx.PutPixel(7 + x, 8 + y, 254, 221, 88);
	gfx.PutPixel(8 + x, 8 + y, 254, 221, 88);
	gfx.PutPixel(9 + x, 8 + y, 254, 221, 88);
	gfx.PutPixel(10 + x, 8 + y, 0, 0, 0);
	gfx.PutPixel(11 + x, 8 + y, 255, 255, 255);
	gfx.PutPixel(12 + x, 8 + y, 255, 255, 255);
	gfx.PutPixel(13 + x, 8 + y, 255, 255, 255);
	gfx.PutPixel(14 + x, 8 + y, 255, 255, 255);
	gfx.PutPixel(15 + x, 8 + y, 0, 0, 0);
	gfx.PutPixel(16 + x, 8 + y, 254, 221, 88);
	gfx.PutPixel(17 + x, 8 + y, 254, 221, 88);
	gfx.PutPixel(18 + x, 8 + y, 254, 221, 88);
	gfx.PutPixel(19 + x, 8 + y, 0, 0, 0);
	gfx.PutPixel(0 + x, 9 + y, 0, 0, 0);
	gfx.PutPixel(1 + x, 9 + y, 254, 221, 88);
	gfx.PutPixel(2 + x, 9 + y, 0, 0, 0);
	gfx.PutPixel(3 + x, 9 + y, 0, 0, 0);
	gfx.PutPixel(4 + x, 9 + y, 0, 0, 0);
	gfx.PutPixel(5 + x, 9 + y, 0, 0, 0);
	gfx.PutPixel(6 + x, 9 + y, 254, 221, 88);
	gfx.PutPixel(7 + x, 9 + y, 254, 221, 88);
	gfx.PutPixel(8 + x, 9 + y, 254, 221, 88);
	gfx.PutPixel(9 + x, 9 + y, 254, 221, 88);
	gfx.PutPixel(10 + x, 9 + y, 254, 221, 88);
	gfx.PutPixel(11 + x, 9 + y, 0, 0, 0);
	gfx.PutPixel(12 + x, 9 + y, 0, 0, 0);
	gfx.PutPixel(13 + x, 9 + y, 0, 0, 0);
	gfx.PutPixel(14 + x, 9 + y, 0, 0, 0);
	gfx.PutPixel(15 + x, 9 + y, 254, 221, 88);
	gfx.PutPixel(16 + x, 9 + y, 254, 221, 88);
	gfx.PutPixel(17 + x, 9 + y, 254, 221, 88);
	gfx.PutPixel(18 + x, 9 + y, 254, 221, 88);
	gfx.PutPixel(19 + x, 9 + y, 0, 0, 0);
	gfx.PutPixel(0 + x, 10 + y, 0, 0, 0);
	gfx.PutPixel(1 + x, 10 + y, 254, 221, 88);
	gfx.PutPixel(2 + x, 10 + y, 254, 221, 88);
	gfx.PutPixel(3 + x, 10 + y, 254, 221, 88);
	gfx.PutPixel(4 + x, 10 + y, 254, 221, 88);
	gfx.PutPixel(5 + x, 10 + y, 254, 221, 88);
	gfx.PutPixel(6 + x, 10 + y, 254, 221, 88);
	gfx.PutPixel(7 + x, 10 + y, 254, 221, 88);
	gfx.PutPixel(8 + x, 10 + y, 254, 221, 88);
	gfx.PutPixel(9 + x, 10 + y, 254, 221, 88);
	gfx.PutPixel(10 + x, 10 + y, 254, 221, 88);
	gfx.PutPixel(11 + x, 10 + y, 254, 221, 88);
	gfx.PutPixel(12 + x, 10 + y, 254, 221, 88);
	gfx.PutPixel(13 + x, 10 + y, 254, 221, 88);
	gfx.PutPixel(14 + x, 10 + y, 254, 221, 88);
	gfx.PutPixel(15 + x, 10 + y, 254, 221, 88);
	gfx.PutPixel(16 + x, 10 + y, 254, 221, 88);
	gfx.PutPixel(17 + x, 10 + y, 254, 221, 88);
	gfx.PutPixel(18 + x, 10 + y, 254, 221, 88);
	gfx.PutPixel(19 + x, 10 + y, 0, 0, 0);
	gfx.PutPixel(0 + x, 11 + y, 0, 0, 0);
	gfx.PutPixel(1 + x, 11 + y, 254, 221, 88);
	gfx.PutPixel(2 + x, 11 + y, 254, 221, 88);
	gfx.PutPixel(3 + x, 11 + y, 254, 221, 88);
	gfx.PutPixel(4 + x, 11 + y, 254, 221, 88);
	gfx.PutPixel(5 + x, 11 + y, 254, 221, 88);
	gfx.PutPixel(6 + x, 11 + y, 254, 221, 88);
	gfx.PutPixel(7 + x, 11 + y, 20, 14, 18);
	gfx.PutPixel(8 + x, 11 + y, 18, 11, 14);
	gfx.PutPixel(9 + x, 11 + y, 18, 12, 14);
	gfx.PutPixel(10 + x, 11 + y, 18, 12, 14);
	gfx.PutPixel(11 + x, 11 + y, 21, 13, 16);
	gfx.PutPixel(12 + x, 11 + y, 24, 11, 15);
	gfx.PutPixel(13 + x, 11 + y, 0, 0, 0);
	gfx.PutPixel(14 + x, 11 + y, 254, 221, 88);
	gfx.PutPixel(15 + x, 11 + y, 254, 221, 88);
	gfx.PutPixel(16 + x, 11 + y, 254, 221, 88);
	gfx.PutPixel(17 + x, 11 + y, 254, 221, 88);
	gfx.PutPixel(18 + x, 11 + y, 254, 221, 88);
	gfx.PutPixel(19 + x, 11 + y, 0, 0, 0);
	gfx.PutPixel(0 + x, 12 + y, 0, 0, 0);
	gfx.PutPixel(1 + x, 12 + y, 254, 221, 88);
	gfx.PutPixel(2 + x, 12 + y, 254, 221, 88);
	gfx.PutPixel(3 + x, 12 + y, 254, 221, 88);
	gfx.PutPixel(4 + x, 12 + y, 254, 221, 88);
	gfx.PutPixel(5 + x, 12 + y, 254, 221, 88);
	gfx.PutPixel(6 + x, 12 + y, 23, 9, 23);
	gfx.PutPixel(7 + x, 12 + y, 135, 26, 68);
	gfx.PutPixel(8 + x, 12 + y, 135, 26, 68);
	gfx.PutPixel(9 + x, 12 + y, 135, 26, 68);
	gfx.PutPixel(10 + x, 12 + y, 135, 26, 68);
	gfx.PutPixel(11 + x, 12 + y, 135, 26, 68);
	gfx.PutPixel(12 + x, 12 + y, 135, 26, 68);
	gfx.PutPixel(13 + x, 12 + y, 135, 26, 68);
	gfx.PutPixel(14 + x, 12 + y, 0, 0, 0);
	gfx.PutPixel(15 + x, 12 + y, 254, 221, 88);
	gfx.PutPixel(16 + x, 12 + y, 254, 221, 88);
	gfx.PutPixel(17 + x, 12 + y, 254, 221, 88);
	gfx.PutPixel(18 + x, 12 + y, 254, 221, 88);
	gfx.PutPixel(19 + x, 12 + y, 0, 0, 0);
	gfx.PutPixel(1 + x, 13 + y, 0, 0, 0);
	gfx.PutPixel(2 + x, 13 + y, 254, 221, 88);
	gfx.PutPixel(3 + x, 13 + y, 254, 221, 88);
	gfx.PutPixel(4 + x, 13 + y, 254, 221, 88);
	gfx.PutPixel(5 + x, 13 + y, 0, 0, 0);
	gfx.PutPixel(6 + x, 13 + y, 135, 26, 68);
	gfx.PutPixel(7 + x, 13 + y, 135, 26, 68);
	gfx.PutPixel(8 + x, 13 + y, 135, 26, 68);
	gfx.PutPixel(9 + x, 13 + y, 135, 26, 68);
	gfx.PutPixel(10 + x, 13 + y, 135, 26, 68);
	gfx.PutPixel(11 + x, 13 + y, 135, 26, 68);
	gfx.PutPixel(12 + x, 13 + y, 135, 26, 68);
	gfx.PutPixel(13 + x, 13 + y, 135, 26, 68);
	gfx.PutPixel(14 + x, 13 + y, 135, 26, 68);
	gfx.PutPixel(15 + x, 13 + y, 0, 0, 0);
	gfx.PutPixel(16 + x, 13 + y, 254, 221, 88);
	gfx.PutPixel(17 + x, 13 + y, 254, 221, 88);
	gfx.PutPixel(18 + x, 13 + y, 0, 0, 0);
	gfx.PutPixel(1 + x, 14 + y, 0, 0, 0);
	gfx.PutPixel(2 + x, 14 + y, 254, 221, 88);
	gfx.PutPixel(3 + x, 14 + y, 254, 221, 88);
	gfx.PutPixel(4 + x, 14 + y, 0, 0, 0);
	gfx.PutPixel(5 + x, 14 + y, 135, 26, 68);
	gfx.PutPixel(6 + x, 14 + y, 135, 26, 68);
	gfx.PutPixel(7 + x, 14 + y, 135, 26, 68);
	gfx.PutPixel(8 + x, 14 + y, 135, 26, 68);
	gfx.PutPixel(9 + x, 14 + y, 251, 192, 224);
	gfx.PutPixel(10 + x, 14 + y, 251, 192, 224);
	gfx.PutPixel(11 + x, 14 + y, 251, 192, 224);
	gfx.PutPixel(12 + x, 14 + y, 251, 192, 224);
	gfx.PutPixel(13 + x, 14 + y, 135, 26, 68);
	gfx.PutPixel(14 + x, 14 + y, 135, 26, 68);
	gfx.PutPixel(15 + x, 14 + y, 0, 0, 0);
	gfx.PutPixel(16 + x, 14 + y, 254, 221, 88);
	gfx.PutPixel(17 + x, 14 + y, 254, 221, 88);
	gfx.PutPixel(18 + x, 14 + y, 0, 0, 0);
	gfx.PutPixel(2 + x, 15 + y, 0, 0, 0);
	gfx.PutPixel(3 + x, 15 + y, 254, 221, 88);
	gfx.PutPixel(4 + x, 15 + y, 0, 0, 0);
	gfx.PutPixel(5 + x, 15 + y, 135, 26, 68);
	gfx.PutPixel(6 + x, 15 + y, 135, 26, 68);
	gfx.PutPixel(7 + x, 15 + y, 135, 26, 68);
	gfx.PutPixel(8 + x, 15 + y, 251, 192, 224);
	gfx.PutPixel(9 + x, 15 + y, 251, 192, 224);
	gfx.PutPixel(10 + x, 15 + y, 251, 192, 224);
	gfx.PutPixel(11 + x, 15 + y, 251, 192, 224);
	gfx.PutPixel(12 + x, 15 + y, 251, 192, 224);
	gfx.PutPixel(13 + x, 15 + y, 251, 192, 224);
	gfx.PutPixel(14 + x, 15 + y, 135, 26, 68);
	gfx.PutPixel(15 + x, 15 + y, 0, 0, 0);
	gfx.PutPixel(16 + x, 15 + y, 254, 221, 88);
	gfx.PutPixel(17 + x, 15 + y, 0, 0, 0);
	gfx.PutPixel(2 + x, 16 + y, 0, 0, 0);
	gfx.PutPixel(3 + x, 16 + y, 254, 221, 88);
	gfx.PutPixel(4 + x, 16 + y, 0, 0, 0);
	gfx.PutPixel(5 + x, 16 + y, 135, 26, 68);
	gfx.PutPixel(6 + x, 16 + y, 135, 26, 68);
	gfx.PutPixel(7 + x, 16 + y, 135, 26, 68);
	gfx.PutPixel(8 + x, 16 + y, 251, 192, 224);
	gfx.PutPixel(9 + x, 16 + y, 251, 192, 224);
	gfx.PutPixel(10 + x, 16 + y, 251, 192, 224);
	gfx.PutPixel(11 + x, 16 + y, 251, 192, 224);
	gfx.PutPixel(12 + x, 16 + y, 251, 192, 224);
	gfx.PutPixel(13 + x, 16 + y, 251, 192, 224);
	gfx.PutPixel(14 + x, 16 + y, 135, 26, 68);
	gfx.PutPixel(15 + x, 16 + y, 0, 0, 0);
	gfx.PutPixel(16 + x, 16 + y, 254, 221, 88);
	gfx.PutPixel(17 + x, 16 + y, 0, 0, 0);
	gfx.PutPixel(3 + x, 17 + y, 0, 0, 0);
	gfx.PutPixel(4 + x, 17 + y, 0, 0, 0);
	gfx.PutPixel(5 + x, 17 + y, 0, 0, 0);
	gfx.PutPixel(6 + x, 17 + y, 0, 0, 0);
	gfx.PutPixel(7 + x, 17 + y, 0, 0, 0);
	gfx.PutPixel(8 + x, 17 + y, 0, 0, 0);
	gfx.PutPixel(9 + x, 17 + y, 0, 0, 0);
	gfx.PutPixel(10 + x, 17 + y, 0, 0, 0);
	gfx.PutPixel(11 + x, 17 + y, 0, 0, 0);
	gfx.PutPixel(12 + x, 17 + y, 0, 0, 0);
	gfx.PutPixel(13 + x, 17 + y, 0, 0, 0);
	gfx.PutPixel(14 + x, 17 + y, 0, 0, 0);
	gfx.PutPixel(15 + x, 17 + y, 0, 0, 0);
	gfx.PutPixel(16 + x, 17 + y, 0, 0, 0);
	gfx.PutPixel(5 + x, 18 + y, 0, 0, 0);
	gfx.PutPixel(6 + x, 18 + y, 0, 0, 0);
	gfx.PutPixel(7 + x, 18 + y, 254, 221, 88);
	gfx.PutPixel(8 + x, 18 + y, 254, 221, 88);
	gfx.PutPixel(9 + x, 18 + y, 254, 221, 88);
	gfx.PutPixel(10 + x, 18 + y, 254, 221, 88);
	gfx.PutPixel(11 + x, 18 + y, 254, 221, 88);
	gfx.PutPixel(12 + x, 18 + y, 254, 221, 88);
	gfx.PutPixel(13 + x, 18 + y, 0, 0, 0);
	gfx.PutPixel(14 + x, 18 + y, 0, 0, 0);
	gfx.PutPixel(7 + x, 19 + y, 0, 0, 0);
	gfx.PutPixel(8 + x, 19 + y, 0, 0, 0);
	gfx.PutPixel(9 + x, 19 + y, 0, 0, 0);
	gfx.PutPixel(10 + x, 19 + y, 0, 0, 0);
	gfx.PutPixel(11 + x, 19 + y, 0, 0, 0);
	gfx.PutPixel(12 + x, 19 + y, 0, 0, 0);

}

void Game::DrawPoo(int x, int y)
{
	gfx.PutPixel(14 + x, 0 + y, 138, 77, 0);
	gfx.PutPixel(7 + x, 1 + y, 138, 77, 0);
	gfx.PutPixel(13 + x, 1 + y, 138, 77, 0);
	gfx.PutPixel(20 + x, 1 + y, 138, 77, 0);
	gfx.PutPixel(6 + x, 2 + y, 138, 77, 0);
	gfx.PutPixel(13 + x, 2 + y, 138, 77, 0);
	gfx.PutPixel(20 + x, 2 + y, 138, 77, 0);
	gfx.PutPixel(6 + x, 3 + y, 138, 77, 0);
	gfx.PutPixel(6 + x, 4 + y, 138, 77, 0);
	gfx.PutPixel(14 + x, 4 + y, 138, 77, 0);
	gfx.PutPixel(21 + x, 4 + y, 138, 77, 0);
	gfx.PutPixel(7 + x, 5 + y, 138, 77, 0);
	gfx.PutPixel(13 + x, 5 + y, 138, 77, 0);
	gfx.PutPixel(21 + x, 5 + y, 138, 77, 0);
	gfx.PutPixel(7 + x, 6 + y, 138, 77, 0);
	gfx.PutPixel(20 + x, 6 + y, 138, 77, 0);
	gfx.PutPixel(6 + x, 7 + y, 138, 77, 0);
	gfx.PutPixel(14 + x, 7 + y, 51, 28, 0);
	gfx.PutPixel(15 + x, 7 + y, 51, 28, 0);
	gfx.PutPixel(20 + x, 7 + y, 138, 77, 0);
	gfx.PutPixel(12 + x, 8 + y, 51, 28, 0);
	gfx.PutPixel(13 + x, 8 + y, 51, 28, 0);
	gfx.PutPixel(14 + x, 8 + y, 51, 28, 0);
	gfx.PutPixel(7 + x, 9 + y, 138, 77, 0);
	gfx.PutPixel(11 + x, 9 + y, 51, 28, 0);
	gfx.PutPixel(12 + x, 9 + y, 102, 57, 0);
	gfx.PutPixel(13 + x, 9 + y, 138, 77, 0);
	gfx.PutPixel(14 + x, 9 + y, 138, 77, 0);
	gfx.PutPixel(15 + x, 9 + y, 51, 28, 0);
	gfx.PutPixel(21 + x, 9 + y, 138, 77, 0);
	gfx.PutPixel(10 + x, 10 + y, 51, 28, 0);
	gfx.PutPixel(11 + x, 10 + y, 51, 28, 0);
	gfx.PutPixel(12 + x, 10 + y, 102, 57, 0);
	gfx.PutPixel(13 + x, 10 + y, 138, 77, 0);
	gfx.PutPixel(14 + x, 10 + y, 138, 77, 0);
	gfx.PutPixel(15 + x, 10 + y, 51, 28, 0);
	gfx.PutPixel(20 + x, 10 + y, 138, 77, 0);
	gfx.PutPixel(9 + x, 11 + y, 51, 28, 0);
	gfx.PutPixel(10 + x, 11 + y, 138, 77, 0);
	gfx.PutPixel(11 + x, 11 + y, 138, 77, 0);
	gfx.PutPixel(12 + x, 11 + y, 51, 28, 0);
	gfx.PutPixel(13 + x, 11 + y, 51, 28, 0);
	gfx.PutPixel(14 + x, 11 + y, 51, 28, 0);
	gfx.PutPixel(15 + x, 11 + y, 51, 28, 0);
	gfx.PutPixel(16 + x, 11 + y, 51, 28, 0);
	gfx.PutPixel(9 + x, 12 + y, 51, 28, 0);
	gfx.PutPixel(10 + x, 12 + y, 138, 77, 0);
	gfx.PutPixel(11 + x, 12 + y, 138, 77, 0);
	gfx.PutPixel(12 + x, 12 + y, 111, 62, 0);
	gfx.PutPixel(13 + x, 12 + y, 102, 57, 0);
	gfx.PutPixel(14 + x, 12 + y, 102, 57, 0);
	gfx.PutPixel(15 + x, 12 + y, 102, 57, 0);
	gfx.PutPixel(16 + x, 12 + y, 51, 28, 0);
	gfx.PutPixel(9 + x, 13 + y, 51, 28, 0);
	gfx.PutPixel(10 + x, 13 + y, 109, 61, 0);
	gfx.PutPixel(11 + x, 13 + y, 138, 77, 0);
	gfx.PutPixel(12 + x, 13 + y, 138, 77, 0);
	gfx.PutPixel(13 + x, 13 + y, 138, 77, 0);
	gfx.PutPixel(14 + x, 13 + y, 138, 77, 0);
	gfx.PutPixel(15 + x, 13 + y, 138, 77, 0);
	gfx.PutPixel(16 + x, 13 + y, 51, 28, 0);
	gfx.PutPixel(5 + x, 14 + y, 51, 28, 0);
	gfx.PutPixel(7 + x, 14 + y, 51, 28, 0);
	gfx.PutPixel(8 + x, 14 + y, 51, 28, 0);
	gfx.PutPixel(9 + x, 14 + y, 51, 28, 0);
	gfx.PutPixel(10 + x, 14 + y, 51, 28, 0);
	gfx.PutPixel(11 + x, 14 + y, 138, 77, 0);
	gfx.PutPixel(12 + x, 14 + y, 138, 77, 0);
	gfx.PutPixel(13 + x, 14 + y, 138, 77, 0);
	gfx.PutPixel(14 + x, 14 + y, 138, 77, 0);
	gfx.PutPixel(15 + x, 14 + y, 138, 77, 0);
	gfx.PutPixel(16 + x, 14 + y, 51, 28, 0);
	gfx.PutPixel(4 + x, 15 + y, 51, 28, 0);
	gfx.PutPixel(5 + x, 15 + y, 138, 77, 0);
	gfx.PutPixel(6 + x, 15 + y, 51, 28, 0);
	gfx.PutPixel(7 + x, 15 + y, 116, 65, 0);
	gfx.PutPixel(8 + x, 15 + y, 138, 77, 0);
	gfx.PutPixel(9 + x, 15 + y, 138, 77, 0);
	gfx.PutPixel(10 + x, 15 + y, 138, 77, 0);
	gfx.PutPixel(11 + x, 15 + y, 51, 28, 0);
	gfx.PutPixel(12 + x, 15 + y, 51, 28, 0);
	gfx.PutPixel(13 + x, 15 + y, 51, 28, 0);
	gfx.PutPixel(14 + x, 15 + y, 51, 28, 0);
	gfx.PutPixel(15 + x, 15 + y, 51, 28, 0);
	gfx.PutPixel(16 + x, 15 + y, 51, 28, 0);
	gfx.PutPixel(17 + x, 15 + y, 51, 28, 0);
	gfx.PutPixel(18 + x, 15 + y, 51, 28, 0);
	gfx.PutPixel(1 + x, 16 + y, 51, 28, 0);
	gfx.PutPixel(2 + x, 16 + y, 51, 28, 0);
	gfx.PutPixel(3 + x, 16 + y, 51, 28, 0);
	gfx.PutPixel(4 + x, 16 + y, 51, 28, 0);
	gfx.PutPixel(5 + x, 16 + y, 138, 77, 0);
	gfx.PutPixel(6 + x, 16 + y, 51, 28, 0);
	gfx.PutPixel(7 + x, 16 + y, 116, 65, 0);
	gfx.PutPixel(8 + x, 16 + y, 138, 77, 0);
	gfx.PutPixel(9 + x, 16 + y, 138, 77, 0);
	gfx.PutPixel(10 + x, 16 + y, 138, 77, 0);
	gfx.PutPixel(11 + x, 16 + y, 138, 77, 0);
	gfx.PutPixel(12 + x, 16 + y, 138, 77, 0);
	gfx.PutPixel(13 + x, 16 + y, 109, 61, 0);
	gfx.PutPixel(14 + x, 16 + y, 51, 28, 0);
	gfx.PutPixel(15 + x, 16 + y, 138, 77, 0);
	gfx.PutPixel(16 + x, 16 + y, 138, 77, 0);
	gfx.PutPixel(17 + x, 16 + y, 138, 77, 0);
	gfx.PutPixel(18 + x, 16 + y, 123, 69, 0);
	gfx.PutPixel(19 + x, 16 + y, 51, 28, 0);
	gfx.PutPixel(0 + x, 17 + y, 51, 28, 0);
	gfx.PutPixel(1 + x, 17 + y, 87, 49, 0);
	gfx.PutPixel(2 + x, 17 + y, 87, 49, 0);
	gfx.PutPixel(3 + x, 17 + y, 87, 49, 0);
	gfx.PutPixel(4 + x, 17 + y, 87, 49, 0);
	gfx.PutPixel(5 + x, 17 + y, 51, 28, 0);
	gfx.PutPixel(6 + x, 17 + y, 51, 28, 0);
	gfx.PutPixel(7 + x, 17 + y, 43, 24, 0);
	gfx.PutPixel(8 + x, 17 + y, 51, 28, 0);
	gfx.PutPixel(9 + x, 17 + y, 51, 28, 0);
	gfx.PutPixel(10 + x, 17 + y, 51, 28, 0);
	gfx.PutPixel(11 + x, 17 + y, 51, 28, 0);
	gfx.PutPixel(12 + x, 17 + y, 51, 28, 0);
	gfx.PutPixel(13 + x, 17 + y, 40, 22, 0);
	gfx.PutPixel(14 + x, 17 + y, 51, 28, 0);
	gfx.PutPixel(15 + x, 17 + y, 138, 77, 0);
	gfx.PutPixel(16 + x, 17 + y, 138, 77, 0);
	gfx.PutPixel(17 + x, 17 + y, 138, 77, 0);
	gfx.PutPixel(18 + x, 17 + y, 123, 69, 0);
	gfx.PutPixel(19 + x, 17 + y, 51, 28, 0);
	gfx.PutPixel(0 + x, 18 + y, 51, 28, 0);
	gfx.PutPixel(1 + x, 18 + y, 138, 77, 0);
	gfx.PutPixel(2 + x, 18 + y, 138, 77, 0);
	gfx.PutPixel(3 + x, 18 + y, 138, 77, 0);
	gfx.PutPixel(4 + x, 18 + y, 138, 77, 0);
	gfx.PutPixel(5 + x, 18 + y, 51, 28, 0);
	gfx.PutPixel(6 + x, 18 + y, 51, 28, 0);
	gfx.PutPixel(7 + x, 18 + y, 51, 28, 0);
	gfx.PutPixel(8 + x, 18 + y, 51, 28, 0);
	gfx.PutPixel(9 + x, 18 + y, 51, 28, 0);
	gfx.PutPixel(10 + x, 18 + y, 51, 28, 0);
	gfx.PutPixel(11 + x, 18 + y, 51, 28, 0);
	gfx.PutPixel(12 + x, 18 + y, 51, 28, 0);
	gfx.PutPixel(13 + x, 18 + y, 51, 28, 0);
	gfx.PutPixel(14 + x, 18 + y, 51, 28, 0);
	gfx.PutPixel(15 + x, 18 + y, 138, 77, 0);
	gfx.PutPixel(16 + x, 18 + y, 138, 77, 0);
	gfx.PutPixel(17 + x, 18 + y, 138, 77, 0);
	gfx.PutPixel(18 + x, 18 + y, 123, 69, 0);
	gfx.PutPixel(19 + x, 18 + y, 51, 28, 0);
	gfx.PutPixel(20 + x, 18 + y, 51, 28, 0);
	gfx.PutPixel(21 + x, 18 + y, 51, 28, 0);
	gfx.PutPixel(22 + x, 18 + y, 51, 28, 0);
	gfx.PutPixel(0 + x, 19 + y, 51, 28, 0);
	gfx.PutPixel(1 + x, 19 + y, 138, 77, 0);
	gfx.PutPixel(2 + x, 19 + y, 138, 77, 0);
	gfx.PutPixel(3 + x, 19 + y, 138, 77, 0);
	gfx.PutPixel(4 + x, 19 + y, 138, 77, 0);
	gfx.PutPixel(5 + x, 19 + y, 51, 28, 0);
	gfx.PutPixel(6 + x, 19 + y, 138, 77, 0);
	gfx.PutPixel(7 + x, 19 + y, 138, 77, 0);
	gfx.PutPixel(8 + x, 19 + y, 138, 77, 0);
	gfx.PutPixel(9 + x, 19 + y, 138, 77, 0);
	gfx.PutPixel(10 + x, 19 + y, 138, 77, 0);
	gfx.PutPixel(11 + x, 19 + y, 138, 77, 0);
	gfx.PutPixel(12 + x, 19 + y, 138, 77, 0);
	gfx.PutPixel(13 + x, 19 + y, 138, 77, 0);
	gfx.PutPixel(14 + x, 19 + y, 138, 77, 0);
	gfx.PutPixel(15 + x, 19 + y, 138, 77, 0);
	gfx.PutPixel(16 + x, 19 + y, 138, 77, 0);
	gfx.PutPixel(17 + x, 19 + y, 138, 77, 0);
	gfx.PutPixel(18 + x, 19 + y, 123, 69, 0);
	gfx.PutPixel(19 + x, 19 + y, 51, 28, 0);
	gfx.PutPixel(20 + x, 19 + y, 138, 77, 0);
	gfx.PutPixel(21 + x, 19 + y, 138, 77, 0);
	gfx.PutPixel(22 + x, 19 + y, 65, 36, 0);
	gfx.PutPixel(23 + x, 19 + y, 51, 28, 0);
	gfx.PutPixel(1 + x, 20 + y, 51, 28, 0);
	gfx.PutPixel(2 + x, 20 + y, 51, 28, 0);
	gfx.PutPixel(3 + x, 20 + y, 51, 28, 0);
	gfx.PutPixel(4 + x, 20 + y, 51, 28, 0);
	gfx.PutPixel(5 + x, 20 + y, 51, 28, 0);
	gfx.PutPixel(6 + x, 20 + y, 138, 77, 0);
	gfx.PutPixel(7 + x, 20 + y, 138, 77, 0);
	gfx.PutPixel(8 + x, 20 + y, 138, 77, 0);
	gfx.PutPixel(9 + x, 20 + y, 138, 77, 0);
	gfx.PutPixel(10 + x, 20 + y, 138, 77, 0);
	gfx.PutPixel(11 + x, 20 + y, 138, 77, 0);
	gfx.PutPixel(12 + x, 20 + y, 138, 77, 0);
	gfx.PutPixel(13 + x, 20 + y, 138, 77, 0);
	gfx.PutPixel(14 + x, 20 + y, 138, 77, 0);
	gfx.PutPixel(15 + x, 20 + y, 138, 77, 0);
	gfx.PutPixel(16 + x, 20 + y, 138, 77, 0);
	gfx.PutPixel(17 + x, 20 + y, 138, 77, 0);
	gfx.PutPixel(18 + x, 20 + y, 123, 69, 0);
	gfx.PutPixel(19 + x, 20 + y, 51, 28, 0);
	gfx.PutPixel(20 + x, 20 + y, 138, 77, 0);
	gfx.PutPixel(21 + x, 20 + y, 138, 77, 0);
	gfx.PutPixel(22 + x, 20 + y, 65, 36, 0);
	gfx.PutPixel(23 + x, 20 + y, 51, 28, 0);
	gfx.PutPixel(0 + x, 21 + y, 51, 28, 0);
	gfx.PutPixel(1 + x, 21 + y, 138, 77, 0);
	gfx.PutPixel(2 + x, 21 + y, 138, 77, 0);
	gfx.PutPixel(3 + x, 21 + y, 138, 77, 0);
	gfx.PutPixel(4 + x, 21 + y, 138, 77, 0);
	gfx.PutPixel(5 + x, 21 + y, 138, 77, 0);
	gfx.PutPixel(6 + x, 21 + y, 51, 28, 0);
	gfx.PutPixel(7 + x, 21 + y, 51, 28, 0);
	gfx.PutPixel(8 + x, 21 + y, 51, 28, 0);
	gfx.PutPixel(9 + x, 21 + y, 51, 28, 0);
	gfx.PutPixel(10 + x, 21 + y, 51, 28, 0);
	gfx.PutPixel(11 + x, 21 + y, 51, 28, 0);
	gfx.PutPixel(12 + x, 21 + y, 51, 28, 0);
	gfx.PutPixel(13 + x, 21 + y, 51, 28, 0);
	gfx.PutPixel(14 + x, 21 + y, 51, 28, 0);
	gfx.PutPixel(15 + x, 21 + y, 51, 28, 0);
	gfx.PutPixel(16 + x, 21 + y, 51, 28, 0);
	gfx.PutPixel(17 + x, 21 + y, 51, 28, 0);
	gfx.PutPixel(18 + x, 21 + y, 51, 28, 0);
	gfx.PutPixel(20 + x, 21 + y, 51, 28, 0);
	gfx.PutPixel(21 + x, 21 + y, 51, 28, 0);
	gfx.PutPixel(22 + x, 21 + y, 51, 28, 0);
	gfx.PutPixel(0 + x, 22 + y, 51, 28, 0);
	gfx.PutPixel(1 + x, 22 + y, 65, 36, 0);
	gfx.PutPixel(2 + x, 22 + y, 65, 36, 0);
	gfx.PutPixel(3 + x, 22 + y, 65, 36, 0);
	gfx.PutPixel(4 + x, 22 + y, 65, 36, 0);
	gfx.PutPixel(5 + x, 22 + y, 65, 36, 0);
	gfx.PutPixel(6 + x, 22 + y, 51, 28, 0);
	gfx.PutPixel(1 + x, 23 + y, 51, 28, 0);
	gfx.PutPixel(2 + x, 23 + y, 51, 28, 0);
	gfx.PutPixel(3 + x, 23 + y, 51, 28, 0);
	gfx.PutPixel(4 + x, 23 + y, 51, 28, 0);
	gfx.PutPixel(5 + x, 23 + y, 51, 28, 0);
	gfx.PutPixel(6 + x, 23 + y, 51, 28, 0);

}

int Game::ClampScreenX(int x, int width)
{
	const int right = +width;
	if (x < 0) {
		return 0;
	}
	else if (right >= gfx.ScreenWidth) {
		return (gfx.ScreenWidth - 1) - width;
	}
	else {

	return x;
	}
}

int Game::ClampScreenY(int y, int height)
{
	const int right = +height;
	if (y < 0) {
		return 0;
	}
	else if (right >= gfx.ScreenHeight) {
		return (gfx.ScreenHeight - 1) - height;
	}
	else {

		return y;
	}
	
}

bool Game::IsColliding(int x0, int y0, int width0, int height0,
	int x1, int y1, int width1, int height1)
{
	const int right0 = x0 + width0;
	const int bottom0 = y0 + height0;
	const int right1 = x1 + width1;
	const int bottom1 = y1 + height0;

	return
		right0 >= x1 &&
		x0 <= right1 &&
		bottom0 >= y1 &&
		y0 <= bottom1;
}


void Game::ComposeFrame()
{
	DrawFace(dudeX, dudeY);

	if (!poo0IsEaten) {
	DrawPoo(poo0X, poo0Y);

	}
	if (!poo1IsEaten) {
	DrawPoo(poo1X, poo1Y);

	}
	if (!poo2IsEaten) {

	DrawPoo(poo2X, poo2Y);
	}

}

	