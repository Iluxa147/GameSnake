#include "Goal.h"

Goal::Goal(std::mt19937 & rng, const Board & brd, const Snake & snake)
{
	Spawn(rng, brd, snake);
}

void Goal::Spawn(std::mt19937 & rng, const Board & brd, const Snake& snake)
{
	std::uniform_int_distribution<int> locDstX(brd.GetBoardWidthStart(), brd.GetBoardWidth()-1);
	std::uniform_int_distribution<int> locDstY(brd.GetBoardHeightStart(), brd.GetBoardHeight()-1);
	do
	{
		loc_ = { locDstX(rng) , locDstY(rng) };
	} while (snake.isInTile(loc_));
}

void Goal::Draw(Board & brd)
{
	brd.DrawCell(loc_, goalColor_);
}

const Location & Goal::GetLocation() const
{
	return loc_;
}
