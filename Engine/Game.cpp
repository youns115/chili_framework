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
	shapeChange = wnd.kbd.KeyIsPressed(VK_SHIFT);

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

	//color
	if (wnd.kbd.KeyIsPressed(VK_SPACE)) {
		//orange
		g_mobile = 165;
		b_mobile = 0;

	}
	else
	{
		g_mobile = 255;
		b_mobile = 255;
	}
	
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


	//defining mobile reticle sides
	const int left_mobile = x_mobile - 5;
	const int right_mobile = x_mobile + 5;
	const int top_mobile = y_mobile - 5;
	const int bottom_mobile = y_mobile + 5;

	//define static reticle sides
	const int left_static = x_static - 5;
	const int right_static = x_static + 5;
	const int top_static = y_static - 5;
	const int bottom_static = y_static + 5;
	
	
	//change shape when x_mobile and x_static colide
	if (left_mobile<right_static&&
		top_mobile<bottom_static&&
		right_mobile>left_static &&
		bottom_mobile>top_static) 
	{
		shapeChange = true;
	}
	else
	{
		shapeChange = false;
	}
	
}

void Game::ComposeFrame()
{
	//static crosshair
	gfx.PutPixel(x_static - 5, y_static, r, g, b);
	gfx.PutPixel(x_static - 4, y_static, r, g, b);
	gfx.PutPixel(x_static - 3, y_static, r, g, b);
				   
	gfx.PutPixel(x_static + 3, y_static, r, g, b);
	gfx.PutPixel(x_static + 4, y_static, r, g, b);
	gfx.PutPixel(x_static + 5, y_static, r, g, b);
				   
	gfx.PutPixel(x_static, y_static - 5, r, g, b);
	gfx.PutPixel(x_static, y_static - 4, r, g, b);
	gfx.PutPixel(x_static, y_static - 3, r, g, b);
				   			
	gfx.PutPixel(x_static, y_static + 3, r, g, b);
	gfx.PutPixel(x_static, y_static + 4, r, g, b);
	gfx.PutPixel(x_static, y_static + 5, r, g, b);


	//shift shape
	if (shapeChange) {
		gfx.PutPixel(x_mobile-5, y_mobile, r_mobile, g_mobile, b_mobile);
		gfx.PutPixel(x_mobile-4, y_mobile, r_mobile, g_mobile, b_mobile);
		gfx.PutPixel(x_mobile-3, y_mobile, r_mobile, g_mobile, b_mobile);
					  			  					  			
		gfx.PutPixel(x_mobile+3, y_mobile, r_mobile, g_mobile, b_mobile);
		gfx.PutPixel(x_mobile+4, y_mobile, r_mobile, g_mobile, b_mobile);
		gfx.PutPixel(x_mobile+5, y_mobile, r_mobile, g_mobile, b_mobile);
					  								 			
		gfx.PutPixel(x_mobile, y_mobile+3, r_mobile, g_mobile, b_mobile);
		gfx.PutPixel(x_mobile, y_mobile+4, r_mobile, g_mobile, b_mobile);
		gfx.PutPixel(x_mobile, y_mobile+5, r_mobile, g_mobile, b_mobile);
					  			
	}
	//default shape
	else {
		gfx.PutPixel(x_mobile - 5, y_mobile, r_mobile, g_mobile, b_mobile);
		gfx.PutPixel(x_mobile - 4, y_mobile, r_mobile, g_mobile, b_mobile);
		gfx.PutPixel(x_mobile - 3, y_mobile, r_mobile, g_mobile, b_mobile);
					  						  					  
		gfx.PutPixel(x_mobile + 3, y_mobile, r_mobile, g_mobile, b_mobile);
		gfx.PutPixel(x_mobile + 4, y_mobile, r_mobile, g_mobile, b_mobile);
		gfx.PutPixel(x_mobile + 5, y_mobile, r_mobile, g_mobile, b_mobile);
					  						  					  
		gfx.PutPixel(x_mobile, y_mobile - 5, r_mobile, g_mobile, b_mobile);
		gfx.PutPixel(x_mobile, y_mobile - 4, r_mobile, g_mobile, b_mobile);
		gfx.PutPixel(x_mobile, y_mobile - 3, r_mobile, g_mobile, b_mobile);
					  						  					
		gfx.PutPixel(x_mobile, y_mobile + 3, r_mobile, g_mobile, b_mobile);
		gfx.PutPixel(x_mobile, y_mobile + 4, r_mobile, g_mobile, b_mobile);
		gfx.PutPixel(x_mobile, y_mobile + 5, r_mobile, g_mobile, b_mobile);
	}				  

}
