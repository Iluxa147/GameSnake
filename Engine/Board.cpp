#include "Board.h"
#include <assert.h>

Board::Board(Graphics& gfx) :
	gfx_(gfx)
{}

void Board::DrawCell(const Location& loc, Color c)
{
	assert(loc.x >= 0);
	assert(loc.x < gfx_.ScreenWidth);
	assert(loc.y >= 0);
	assert(loc.y < gfx_.ScreenHeight);
	gfx_.DrawRectDim(loc.x*dimension_, loc.y*dimension_, dimension_, dimension_, c);
}

int Board::GetBoardWidth() const
{
	return width_;
}

int Board::GetBoardHeight() const
{
	return height_;
}

bool Board::isInsideBoard(const Location & loc) const
{
	return
		loc.x >= 0 && loc.x < width_ &&
		loc.y >= 0 && loc.y < height_;
}
