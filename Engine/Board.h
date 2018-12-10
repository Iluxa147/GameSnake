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
	int GetBoardWidthStart() const;
	int GetBoardHeightStart() const;
	bool isInsideBoard(const Location& loc)const;
	void DrawLimit();

private:
	static constexpr int dimension_ = 10; //one seg size
	//static constexpr int width_ = Graphics::ScreenWidth/ 10*dimension_;
	//static constexpr int height_ = Graphics::ScreenHeight/ 10*dimension_;
	static constexpr int widthStart_ = 2;
	static constexpr int heightStart_ = 2;
	static constexpr int width_ = (Graphics::ScreenWidth /dimension_) - widthStart_;
	static constexpr int height_ = (Graphics::ScreenHeight / dimension_) - heightStart_;
	static constexpr Color colorLimit_ = Colors::Gray;
	static constexpr Color colorOutline_ = Colors::Black;

	Graphics& gfx_;
};
