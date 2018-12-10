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
	gfx_.DrawRectDim(loc.x*dimension_, loc.y*dimension_, dimension_, dimension_, colorOutline_);
	gfx_.DrawRectDim(loc.x*dimension_+1, loc.y*dimension_+1, dimension_-2, dimension_-2, c);
}

int Board::GetBoardWidth() const
{
	return width_;
}

int Board::GetBoardHeight() const
{
	return height_;
}

int Board::GetBoardWidthStart() const
{
	return widthStart_;
}

int Board::GetBoardHeightStart() const
{
	return heightStart_;
}

bool Board::isInsideBoard(const Location & loc) const
{
	bool tmp = loc.x >= widthStart_ && loc.x < width_ &&
		loc.y >= heightStart_ && loc.y < height_;

	return
		loc.x >= widthStart_ && loc.x < width_ &&
		loc.y >= heightStart_ && loc.y < height_;
}

void Board::DrawLimit()
{
	gfx_.DrawRect(widthStart_*dimension_, heightStart_*dimension_, (width_)*dimension_, (height_)*dimension_, colorLimit_);

	/*for (int y = 0; y < height_; ++y)
	{
		Location loc = { 0,y };
		DrawCell(loc, colorLimit_);
		loc = { 0,y };
		DrawCell(loc, colorLimit_);
	}*/

	/*for (size_t y = 0; y < height_; ++y)
	{
		for (size_t x = 0; x < width_; ++x)
		{
			Location loc = { x,y };
			DrawCell(loc, colorLimit_);
		}
	}*/
}