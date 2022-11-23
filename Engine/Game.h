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
#include "Sound.h"

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
	/*  User Functions  */
	void DrawFace(int x, int y);
	void Drawfood(int x, int y);
	void DrawGameOver(int x, int y);
	void DrawTitleScreen(int x, int y);
	int ClampScreenX(int x, int width);
	int ClampScreenY(int y, int height);
	bool IsColliding(int x0, int y0, int width0, int height0,
		int x1, int y1, int width1, int height1);
	
	

private:
	MainWindow& wnd;
	Graphics gfx;
	Sound eatSound;
	Sound Music;
	Sound GameOver;
	/*  User Variables   */
	int dudeX =400;
	int dudeY = 300;
	int dudeWidth = 20;
	int dudeHeight = 20;

	int food0X = 300;
	int food0Y = 150;
	int food0vx = 1;
	int food0vy = 1;
	bool food0IsEaten = false;

	int food1X = 100;
	int food1Y = 500;
	int food1vx = -1;
	int food1vy = 1;
	bool food1IsEaten = false;

	int food2X = 600;
	int food2Y = 400;
	int food2vx = 1;
	int food2vy = -1;
	bool food2IsEaten = false;

	int food3X = 450;
	int food3Y = 200;
	int food3vx = -1;
	int food3vy = -1;
	bool food3IsEaten = false;

	int foodWidth = 24;
	int foodHeight = 24;
	const int w_key = 0x57, a_key = 0x41, s_key = 0x53, d_key = 0x44;
	
	bool isStarted = false;

	bool food0EatenMusic = true;
	bool food1EatenMusic = true;
	bool food2EatenMusic = true;
	bool food3EatenMusic = true;
	bool gameStartsMusic = true;
	bool GameOverMusic = true;
};