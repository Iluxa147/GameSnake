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
			nextDirection_ = { 0,-1 };

			if (abs(nextDirection_.y) != abs(currDirection_.y))
			{
				deltaLoc = { 0,-1 };
			}
			else
			{
				deltaLoc = currDirection_;
			}

		}
		else if (wnd_.kbd.IsKeyPressed(VK_DOWN))
		{
			nextDirection_ = { 0,1 };
			if (abs(nextDirection_.y) != abs(currDirection_.y))
			{
				deltaLoc = { 0,1 };
			}
			else
			{
				deltaLoc = currDirection_;
			}
		}
		else if (wnd_.kbd.IsKeyPressed(VK_LEFT))
		{
			nextDirection_ = { -1,0 };

			if (abs(nextDirection_.x) != abs(currDirection_.x))
			{
				deltaLoc = { -1,0 };
			}
			else
			{
				deltaLoc = currDirection_;
			}

		}
		else if (wnd_.kbd.IsKeyPressed(VK_RIGHT))
		{
			nextDirection_ = { 1,0 };

			if (abs(nextDirection_.x) != abs(currDirection_.x))
			{
				deltaLoc = { 1,0 };
			}
			else
			{
				deltaLoc = currDirection_;
			}
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
					++growCoutn;
					if (growCoutn % 2 == 0)
					{
						if (snakeMovePeriod!=2)
						{
							--snakeMovePeriod;
						}
					}
					goal_.Spawn(rng_,brd_, snake_);
				}
				snake_.MoveBy(deltaLoc);
				currDirection_ = deltaLoc;

			}
		}
	}
}

void Game::ComposeFrame()
{
	goal_.Draw(brd_);
	snake_.Draw(brd_);
}
