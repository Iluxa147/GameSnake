#include "MainWindow.h"
#include "Game.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	brd_(gfx),
	rng_(std::random_device()())
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
	std::uniform_int_distribution<int> colorsDist(0, 255);
	for (size_t y = 0; y < brd_.GetBoardHeight(); ++y)
	{
		for (size_t x = 0; x < brd_.GetBoardWidth(); ++x)
		{
			Location loc = { x, y };
			Color c(colorsDist(rng_), colorsDist(rng_), colorsDist(rng_));
			brd_.DrawCell(loc, c);
		}
	}

}
