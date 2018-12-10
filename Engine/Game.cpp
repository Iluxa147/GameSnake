#include "MainWindow.h"
#include "Game.h"

Game::Game(MainWindow& wnd)
	:
	wnd_(wnd),
	gfx_(wnd),
	brd_(gfx_),
	rng_(std::random_device()()),
	snake_({10,10}),
	goal_(rng_, brd_, snake_)
{
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
	brd_.DrawLimit();

	if (!isGameOver)
	{
		if (wnd_.kbd.IsKeyPressed(VK_UP))
		{
			deltaLoc = { 0,-1 };
			;
		}
		if (wnd_.kbd.IsKeyPressed(VK_DOWN))
		{
			deltaLoc = { 0,1 };
		}
		if (wnd_.kbd.IsKeyPressed(VK_LEFT))
		{
			deltaLoc = { -1,0 };
		}
		if (wnd_.kbd.IsKeyPressed(VK_RIGHT))
		{
			deltaLoc = { 1,0 };
		}

		++snakeMoveCounter;
		if (snakeMoveCounter >= snakeMovePeriod)
		{
			snakeMoveCounter = 0u;
			const Location segNextLoc = snake_.GetNextHeadLocation(deltaLoc);
			if (!brd_.isInsideBoard(segNextLoc) || snake_.isInTileExceptEnd(segNextLoc))
			{
				isGameOver = true;
			}
			else
			{
				const bool isEaten = segNextLoc == goal_.GetLocation();
				if (wnd_.kbd.IsKeyPressed(VK_CONTROL) || isEaten)
				{
					snake_.Grow(rng_);
					goal_.Spawn(rng_,brd_, snake_);
				}
				snake_.MoveBy(deltaLoc);
			}
		}
	}
}

void Game::ComposeFrame()
{
	goal_.Draw(brd_);
	snake_.Draw(brd_);
}
