#include "Goal.h"

Goal::Goal(std::mt19937 & rng, const Board & brd, const Snake & snake)
{
	Spawn(rng, brd, snake);
}

void Goal::Spawn(std::mt19937 & rng, const Board & brd, const Snake& snake)
{
	std::uniform_int_distribution<int> locDstX(brd.GetBoardWidthStart(), brd.GetBoardWidth()-1);
	std::uniform_int_distribution<int> locDstY(brd.GetBoardHeightStart(), brd.GetBoardHeight()-1);
	loc_ = { locDstX(rng) , locDstY(rng) };
	//brd.DrawCell(loc_, goalColor_);
}

void Goal::Draw(Board & brd)
{
	brd.DrawCell(loc_, goalColor_);
}

const Location & Goal::GetLocation() const
{
	return loc_;
}
