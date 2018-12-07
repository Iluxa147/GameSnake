#pragma once
#include "Location.h"
#include "Graphics.h"

class Board
{
public:
	Board(Graphics& gfx);
	void DrawCell(Location& loc, Color c);
	int GetBoardWidth() const;
	int GetBoardHeight() const;

private:
	static constexpr int dimension_ = 50;
	static constexpr int width_ = 5;
	static constexpr int height_ = 5;
	Graphics& gfx_;
};
