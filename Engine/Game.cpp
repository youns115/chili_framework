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
	x_mobile = x_mobile + vx;
	y_mobile = y_mobile + vy;

	
	
	//screen cap limit for default shape
	if (x_mobile +5 >= gfx.ScreenWidth) {
		x_mobile = gfx.ScreenWidth -6;
		vx = 0;

	}
	if (x_mobile - 5 < 0) {
		x_mobile = 5;
		vx = 0;
	}
	if (y_mobile + 5 >= gfx.ScreenHeight) {
		y_mobile = gfx.ScreenHeight - 6;
		vy = 0;

	}
	if (y_mobile - 5 < 0) {
		y_mobile = 5;
		vy = 0;

	}

	
	//colorchange
	
	if (wnd.kbd.KeyIsPressed(VK_SPACE)) {
		//orange
		g_mobile = 165;
		b_mobile = 0;
		r_mobile = 255;
	}
	else
	{
		g_mobile = 255;
		b_mobile = 255;

	}
	
	
	

	//shift shape
	if (shapeChange) {
		
		DrawBoxTshape(x_mobile,y_mobile,r_mobile,g_mobile,b_mobile);

	}

	//default mobile shape
	else {
		DrawBox(x_mobile,y_mobile,r_mobile,g_mobile,b_mobile);
	}

	shapeChange = wnd.kbd.KeyIsPressed(VK_SHIFT);

	colliding =
		OverlapTest(x_static0, y_static0, x_mobile, y_mobile) ||
		OverlapTest(x_static1, y_static1, x_mobile, y_mobile) ||
		OverlapTest(x_static2, y_static2, x_mobile, y_mobile) ||
		OverlapTest(x_static3, y_static3, x_mobile, y_mobile) ;

	
}

void Game::ComposeFrame()
{
	
	DrawBox(x_static0, y_static0, 0, 255, 0);
	DrawBox(x_static1, y_static1, 0, 255, 0);
	DrawBox(x_static2, y_static2, 0, 255, 0);
	DrawBox(x_static3, y_static3, 0, 255, 0);

	if (colliding) {
		DrawBox(x_mobile, y_mobile, 255, 0, 0);

	}
	else
	{
		colliding = false;
	}



}

	void Game::DrawBox(int x, int y, int r, int g, int b)
	{
		//static crosshair

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

	void Game::DrawBoxTshape(int x, int y, int r, int g, int b)
	{
		gfx.PutPixel(x - 5, y, r, g, b);
		gfx.PutPixel(x - 4, y, r, g, b);
		gfx.PutPixel(x - 3, y, r, g, b);

		gfx.PutPixel(x + 3, y, r, g, b);
		gfx.PutPixel(x + 4, y, r, g, b);
		gfx.PutPixel(x + 5, y, r, g, b);

		

		gfx.PutPixel(x, y + 3, r, g, b);
		gfx.PutPixel(x, y + 4, r, g, b);
		gfx.PutPixel(x, y + 5, r, g, b);
	}

	bool Game::OverlapTest(int box0x, int box0y, int box1x, int box1y)
	{
		
		//defining box0 reticle sides
		const int left_box0 = box0x - 5;
		const int right_box0 = box0x + 5;
		const int top_box0 = box0y - 5;
		const int bottom_box0 = box0y + 5;

		//define box1 reticle sides
		const int left_box1 = box1x - 5;
		const int right_box1 = box1x + 5;
		const int top_box1 = box1y - 5;
		const int bottom_box1 = box1y + 5;



		//change color when x_box0 and x_box1 colide
		return 
			left_box0 <= right_box1 &&
			top_box0 <= bottom_box1 &&
			right_box0 >= left_box1 &&
			bottom_box0 >= top_box1;
		
	}
