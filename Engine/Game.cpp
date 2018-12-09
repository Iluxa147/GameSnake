#include "MainWindow.h"
#include "Game.h"

Game::Game(MainWindow& wnd)
	:
	wnd_(wnd),
	gfx_(wnd),
	brd_(gfx_),
	rng_(std::random_device()()),
	snake_({2,2})
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
				if (wnd_.kbd.IsKeyPressed(VK_CONTROL))
				{
					snake_.Grow();
				}
				snake_.MoveBy(deltaLoc);
			}
		}
	}
}

void Game::ComposeFrame()
{
	snake_.Draw(brd_);
}
