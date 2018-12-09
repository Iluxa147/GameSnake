#pragma once
#include "Location.h"
#include "Colors.h"
#include "Board.h"

class Snake
{
private:
	class Segment
	{
	public:
		void InitHead(const Location& loc);
		void InitBody();
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
	void Grow();
	void Draw(Board& brd) const;
	bool isInTile(const Location& loc) const;

private:
	static constexpr unsigned int segMaxCount_ = 100u;
	static constexpr Color headColor_ = Colors::Red;
	static constexpr Color bodyColor_ = Colors::Green;
	Segment segArr_[segMaxCount_];
	unsigned int segCurrent_ = 1u;
};