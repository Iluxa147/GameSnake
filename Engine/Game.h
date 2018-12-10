#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Board.h"
#include <random>
#include "Snake.h"
#include "Location.h"
#include "Goal.h"

class Game
{
public:
	Game(class MainWindow& wnd);
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
private:
	MainWindow& wnd_;
	Graphics gfx_;
	Board brd_;
	std::mt19937 rng_;
	unsigned int snakeMoveCounter = 0u;
	unsigned int snakeMovePeriod = 10u;
	Location deltaLoc = { 1,0};
	Snake snake_;
	Goal goal_;
	unsigned int growCoutn = 0u;
	Location nextDirection_;
	bool isGameOver = false;
};