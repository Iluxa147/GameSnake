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
#include "Carpet.h"
#include "Dude.h"
#include <random>  
#include <ctime>

class Game
{
public:
	Game(class MainWindow& wnd);
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;
	void Go(); //Game loop prototype

private:
	void ComposeFrame(); //visual
	void UpdateModel(); //logic
	void DrawCross(int x, int y, int r, int g, int b);
	void DrawHello(int x, int y, int r, int g, int b);
	//bool isCollided(int box0x, int box0y, int box1x, int box1y);
	//int OnBorderX(int boxX);
	//int OnBorderY(int boxY);


private:
	MainWindow& wnd_;
	Graphics gfx_;

	std::random_device rd;
	std::mt19937 rng;
	std::uniform_int_distribution<int> xDst_;
	std::uniform_int_distribution<int> yDst_;


	static constexpr int carpetsSize_ = 5;
	Carpet Carpets_[carpetsSize_];

	/*Carpet Carpet0_;
	Carpet Carpet1_;
	Carpet Carpet2_;*/

	Dude Dude0_;

	Point point0_;

	unsigned int x0 = 50;
	unsigned int y0 = 50;

	unsigned int x1 = 100;
	unsigned int y1 = 100;

	bool isGameStarted_ = false;
	/*int carpet1X_ = 200;
	int carpet1Y_ = 200;
	int carpet1VX_ = 5;
	int carpet1VY_ = 5;
	bool isCarpet1Collected_ = false;

	int carpet2X_ = 300;
	int carpet2Y_ = 300;
	bool isCarpet2Collected_ = false;

	int carpet3X_ = 400;
	int carpet3Y_ = 400;
	bool isCarpet3Collected_ = false;*/


	//bool isCollided_ = false;
	//bool isOnBorder_ = false;


	/*int vX_ = 0;
	int vY_ = 0;
	int xMovable_ = gfx_.ScreenWidth / 2;
	int yMovable_ = gfx_.ScreenHeight / 2;
	bool isRight = false;
	bool isLeft = false;
	bool isTop = false;
	bool isBottom = false;*/
};