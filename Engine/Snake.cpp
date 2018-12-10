#include "Snake.h"
#include <assert.h>

Snake::Snake(const Location & loc)
{
	segArr_[0].InitHead(loc);
}

void Snake::MoveBy(const Location & deltaLoc)
{
	for (size_t i = segCurrent_-1; i > 0; --i) //i = last seg
	{
		segArr_[i].Follow(segArr_[i - 1]); //follow next seg
	}
	segArr_[0].MoveBy(deltaLoc);
}

Location& Snake::GetNextHeadLocation(const Location & deltaloc) const
{
	Location l (segArr_[0].GetLocation());
	l.Add(deltaloc);
	return l;
}

void Snake::Grow(std::mt19937 & rng)
{
	if (segCurrent_ < segMaxCount_)
	{
		segArr_[segCurrent_].InitBody(rng);
		++segCurrent_;
	}
}

void Snake::Draw(Board & brd) const
{
	for (size_t i = 0; i < segCurrent_; ++i)
	{
		segArr_[i].Draw(brd);
	}
}

bool Snake::isInTileExceptEnd(const Location & loc) const
{
	for (size_t i = 0; i < segCurrent_-1; ++i)
	{
		if (segArr_[i].GetLocation() == loc)
		{
			return true;
		}
	}
	return false;
}

void Snake::Segment::InitHead(const Location & loc)
{
	loc_ = loc;
	c_ = Snake::headColor_;
}

void Snake::Segment::InitBody(std::mt19937 & rng)
{
	std::uniform_int_distribution<int> col(100u, 200u);
	c_ = Colors::MakeRGB(0, col(rng), 0);
}

void Snake::Segment::Follow(const Segment & next)
{
	loc_ = next.loc_;
}

void Snake::Segment::MoveBy(const Location & deltaLoc)
{
	assert(abs(deltaLoc.x) + abs(deltaLoc.y) == 1);
	loc_.Add(deltaLoc);
}

void Snake::Segment::Draw(Board & brd) const
{
	brd.DrawCell(loc_, c_);
}

const Location& Snake::Segment::GetLocation() const
{
	return loc_;
}
