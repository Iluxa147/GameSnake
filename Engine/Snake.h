#pragma once
#include "Location.h"
#include "Colors.h"
#include "Board.h"
#include <random>

class Snake
{
private:
	class Segment
	{
	public:
		void InitHead(const Location& loc);
		void InitBody(std::mt19937 & rng);
		void Follow(const Segment& next);
		void MoveBy(const Location & deltaLoc);
		void Draw(Board& brd) const;
		const Location& GetLocation() const;

	private:
		Location loc_;
		Color c_;
	};

public:
	Snake(const Location& loc);
	void MoveBy(const Location& deltaLoc);
	Location& GetNextHeadLocation(const Location& deltaLocation)const;
	void Grow(std::mt19937 & rng);
	void Draw(Board& brd) const;
	bool isInTile(const Location& loc) const;
	bool isInTileExceptEnd(const Location& loc) const;

private:
	static constexpr unsigned int segMaxCount_ = 100u;
	static constexpr Color headColor_ = Colors::Yellow;
	Segment segArr_[segMaxCount_];
	unsigned int segCurrent_ = 1u;
};