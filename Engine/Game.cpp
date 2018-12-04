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

Game::Game(MainWindow& wnd) :
	wnd_(wnd),
	gfx_(wnd),
	rng(rd()),
	xDst_(0,770),
	yDst_(0, 570),

	/*Carpet0_(xDst_(rng), yDst_(rng), 0, 0),
	Carpet1_(xDst_(rng), yDst_(rng), -5, -5),
	Carpet2_(400, 400, -5, -5),*/
	Dude0_(200, 200)
{
	point0_.x = 100;
	point0_.y = 100;
	point0_.color = Colors::Yellow;

	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> xDst_(0, 700);
	std::uniform_int_distribution<int> yDst_(0, 200);
	std::uniform_int_distribution<int> vel(-2, 2);


	for (size_t i = 0; i < carpetsSize_; i++)
	{
		Carpets_[i].CarpetInit(xDst_(rng), yDst_(rng), vel(rng), vel(rng));
	}

}

void Game::Go()
{
	gfx_.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx_.EndFrame();

}

void Game::UpdateModel()
{
	if (wnd_.kbd.IsKeyPressed(VK_RETURN))
	{
		isGameStarted_ = true;
	}

	if (isGameStarted_)
	{
		Dude0_.Update(wnd_.kbd);

		if (wnd_.kbd.IsKeyPressed(VK_RIGHT))
		{
			point0_.x += 3;

			x0 += 3;

			//Dude0_.x_ += 3;
		}
		if (wnd_.kbd.IsKeyPressed(VK_LEFT))
		{
			point0_.x -= 3;

			x0 -= 3;

			//Dude0_.x_ -= 3;
		}
		if (wnd_.kbd.IsKeyPressed(VK_UP))
		{
			point0_.y -= 3;

			y0 -= 3;

			//Dude0_.y_ -= 3;
		}
		if (wnd_.kbd.IsKeyPressed(VK_DOWN))
		{
			point0_.y += 3;

			y0 += 3;

			//Dude0_.y_ += 3;
		}

		if (wnd_.mouse.IsLeftPressed())
		{
			x1 = wnd_.mouse.GetPosX();
			y1 = wnd_.mouse.GetPosY();
		}

		/*if (wnd_.kbd.IsKeyPressed('D'))
		{
			squareLengthX+=3;
		}

		if (wnd_.kbd.IsKeyPressed('A'))
		{
			squareLengthX -= 3;
		}

		if (wnd_.kbd.IsKeyPressed('W'))
		{
			squareHeightY -= 3;
		}

		if (wnd_.kbd.IsKeyPressed('S'))
		{
			squareHeightY += 3;
		}*/

		Dude0_.OnBorder();
		//Dude0_.x_ = OnBorderX(Dude0_.x_);
		//Dude0_.y_ = OnBorderY(Dude0_.y_);

		for (size_t i = 0; i < carpetsSize_; i++)
		{
			Carpets_[i].UpdateCarpet();
		}


		/*carpet1X_ += carpet1VX_;
		carpet1Y_ += carpet1VY_;

		{
			const int carpet1XHold = carpet1X_;
			const int carpet1YHold = carpet1Y_;

			carpet1X_ = OnBorderX(carpet1X_);
			if (carpet1X_ != carpet1XHold)
			{
				carpet1VX_ = -carpet1VX_;
			}

			carpet1Y_ = OnBorderY(carpet1Y_);
			if (carpet1Y_ != carpet1YHold)
			{
				carpet1VY_ = -carpet1VY_;
			}
		}*/

		bool allCollided = true;
		for (size_t i = 0; i < carpetsSize_; i++)
		{
			Carpets_[i].isCollided(Dude0_);
			allCollided = allCollided && Carpets_[i].isCollided();
		}

		if (allCollided)
		{
			gfx_.DrawRect(200, 200, 50, 50);
		}

		//isCollided_ = isCollided(Dude0_.x_, Dude0_.y_, Carpet0_.x_, Carpet0_.y_);
	}
}

void Game::ComposeFrame()
{
	if (isGameStarted_)
	{

		if (wnd_.kbd.IsKeyPressed(VK_CONTROL))
		{
			gfx_.DrawRect(point0_, x1, y1);

		}



		int rMovable, gMovable, bMovable;
		int rStatic = 0, gStatic = 255, bStatic = 0;
		/*if (Carpet0_.isCollided() || Carpet1_.isCollided() || Carpet2_.isCollided())
		{
			rMovable = 255;
			gMovable = bMovable = 0;
		}
		else
		{
			rMovable = gMovable = bMovable = 255;
		}*/
		Dude0_.DrawDude(gfx_);



		for (size_t i = 0; i < carpetsSize_; i++)
		{
			Carpets_[i].DrawCarpet(gfx_);
		}
		//DrawCross(Dude0_.x_, Dude0_.y_, rMovable, gMovable, bMovable);
		//DrawCross(Carpet0_.x_, Carpet0_.y_, rStatic, gStatic, bStatic);
		//DrawCross(Carpet1_.x_, Carpet1_.y_, rStatic, gStatic, bStatic);
		//DrawCross(Carpet2_.x_, Carpet2_.y_, rStatic, gStatic, bStatic);
	}
	else
	{
		Game::DrawHello(200, 200, 100, 100, 100);
	}
}

void Game::DrawCross(int x, int y, int r, int g, int b) // TODO hardcode time!
{
	gfx_.PutPixel(-5 + x, y, r, g, b);
	gfx_.PutPixel(-4 + x, y, r, g, b);
	gfx_.PutPixel(-3 + x, y, r, g, b);
	gfx_.PutPixel(3 + x, y, r, g, b);
	gfx_.PutPixel(4 + x, y, r, g, b);
	gfx_.PutPixel(5 + x, y, r, g, b);
	gfx_.PutPixel(x, -5 + y, r, g, b);
	gfx_.PutPixel(x, -4 + y, r, g, b);
	gfx_.PutPixel(x, -3 + y, r, g, b);
	gfx_.PutPixel(x, 3 + y, r, g, b);
	gfx_.PutPixel(x, 4 + y, r, g, b);
	gfx_.PutPixel(x, 5 + y, r, g, b);
}

void Game::DrawHello(int x, int y, int r, int g, int b) // TODO hardcode time!
{
	for (size_t yy = 0; yy < 200; ++yy)
	{
		for (size_t xx = 0; xx < 300; ++xx)
		{
			gfx_.PutPixel(x+xx, y+yy, r, g, b);
		}
	}

	/*for (size_t i = 0; i < 10; i++)
	{
		gfx_.PutPixel(i + x, y+2, r, g, b);

	}*/


}
