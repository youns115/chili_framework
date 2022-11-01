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

	//postiion
	if (wnd.kbd.KeyIsPressed(w_key)) {
		if (inhibitUp) {
			
		}
		else
		{
			vy = vy - 1;
			inhibitUp = true;
		}
		
	}
	else
	{
		inhibitUp = false;
	}

	if (wnd.kbd.KeyIsPressed(a_key)) {
		if (inhibitLeft) {

		}
		else
		{
		vx = vx - 1;
		inhibitLeft = true;
		}
	}
	else
	{
		inhibitLeft = false;
	}


	if (wnd.kbd.KeyIsPressed(s_key)) {
		if (inhibitDown) {

		}
		else
		{
		vy = vy + 1;
		inhibitDown = true;
		}
	}
	else
	{
		inhibitDown = false;
	}


	if (wnd.kbd.KeyIsPressed(d_key)) {
		if (inhibitRight) {

		}
		else
		{
		vx = vx + 1;
		inhibitRight = true;
		}

	
	}
	else
	{
		inhibitRight = false;
	}

	//moving the crosshair
	x = x + vx;
	y = y + vy;

	//color
	if (wnd.kbd.KeyIsPressed(VK_SPACE)) {
		//orange
		g = 165;
		b = 0;
	}


	shapeChange = wnd.kbd.KeyIsPressed(VK_SHIFT);
}

void Game::ComposeFrame()
{
	//shift shape
	if (shapeChange) {
		gfx.PutPixel(x-105, y, r, g, b);
		
		
		gfx.PutPixel(x-104, y, r, g, b);
		gfx.PutPixel(x-103, y, r, g, b);
					   
		gfx.PutPixel(x+103, y, r, g, b);
		gfx.PutPixel(x+104, y, r, g, b);
		gfx.PutPixel(x+105, y, r, g, b);

		gfx.PutPixel(x, y-105, r, g, b);
		gfx.PutPixel(x, y-104, r, g, b);
		gfx.PutPixel(x, y-103, r, g, b);
		gfx.PutPixel(x, y, r, g, b);
					
		gfx.PutPixel(x, y+103, r, g, b);
		gfx.PutPixel(x, y+104, r, g, b);
		gfx.PutPixel(x, y+105, r, g, b);

	}
	//default shape
	else {
		gfx.PutPixel(x - 5, y, r, g, b);
		gfx.PutPixel(x - 4, y, r, g, b);
		gfx.PutPixel(x - 3, y, r, g, b);

		gfx.PutPixel(x + 3, y, r, g, b);
		gfx.PutPixel(x + 4, y, r, g, b);
		gfx.PutPixel(x + 5, y, r, g, b);

		gfx.PutPixel(x, y - 5, r, g, b);
		gfx.PutPixel(x, y - 4, r, g, b);
		gfx.PutPixel(x, y - 3, r, g, b);
		

		gfx.PutPixel(x, y + 3, r, g, b);
		gfx.PutPixel(x, y + 4, r, g, b);
		gfx.PutPixel(x, y + 5, r, g, b);
	}

}
