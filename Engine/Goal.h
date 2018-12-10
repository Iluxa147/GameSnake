#pragma once
#include "Location.h"
#include <random>
#include "Board.h"
#include "Snake.h"

class Goal
{
public:
	Goal(std::mt19937 & rng, const Board & brd, const Snake& snake);
	void Spawn(std::mt19937 & rng, const Board & brd, const Snake& snake);
	void Draw(Board& brd);
	const Location& GetLocation() const;
	//Spawn();
private:
	static constexpr Color goalColor_ = Colors::Green;
	Location loc_;
};
