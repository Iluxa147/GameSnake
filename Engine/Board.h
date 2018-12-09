#pragma once
#include "Location.h"
#include "Graphics.h"

class Board
{
public:
	Board(Graphics& gfx);
	void DrawCell(const Location& loc, Color c);
	int GetBoardWidth() const;
	int GetBoardHeight() const;
	bool isInsideBoard(const Location& loc)const;

private:
	static constexpr int dimension_ = 20; //one seg size
	static constexpr int width_ = 25;
	static constexpr int height_ = 25;
	Graphics& gfx_;
};
