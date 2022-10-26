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
}

void Game::ComposeFrame()
{
	int x = 400, y = 300;
	int r = 255, g = 255, b = 255;
	const int w_key = 0x57, a_key= 0x41, s_key = 0x53, d_key= 0x44;

	//color
	if (wnd.kbd.KeyIsPressed(VK_SPACE)) {
		g = 165;
		b = 0;
		
	}
	
	//postiion
	if (wnd.kbd.KeyIsPressed(w_key)) {
		y = y - 100;
	}
	if (wnd.kbd.KeyIsPressed(a_key)) {
		x = x - 100;
	}
	if (wnd.kbd.KeyIsPressed(s_key)) {
		y = y + 100;
	}
	if (wnd.kbd.KeyIsPressed(d_key)) {
		x = x + 100;
	}
	
	//shape
	if (wnd.kbd.KeyIsPressed(VK_SHIFT)) {
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
