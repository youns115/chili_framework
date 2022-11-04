/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
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
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();

private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */

	void DrawBox(int x, int y, int r, int g, int b);
	bool OverlapTest(int box0x, int box0y, int box1x, int box1y);
	void DrawBoxTshape(int x, int y, int r, int g, int b);
	
	/********************************/

private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables   */
	int x_mobile = 400;
	int y_mobile = 300;

	//vilocity of the crosshair
	float vx = 0;
	float vy = 0;
	
	//input keys
	const int w_key = 0x57, a_key = 0x41, s_key = 0x53, d_key = 0x44;

	//colors
	int r_mobile = 255, g_mobile = 255, b_mobile = 255;
	

	//static crosshairs
	int x_static0 = 200;
	int y_static0 = 100;

	int x_static1 = 300;
	int y_static1 = 200;

	int x_static2 = 400;
	int y_static2 = 500;

	int x_static3 = 700;
	int y_static3 = 500;

	
	//initial shape change and colliding value
	bool shapeChange = false;

	bool colliding = false;
	//prevent from increasing vilocity per frame(and change it to per press)
	bool inhibitUp = false;
	bool inhibitLeft = false;
	bool inhibitDown = false;
	bool inhibitRight = false;

	
	/********************************/
};