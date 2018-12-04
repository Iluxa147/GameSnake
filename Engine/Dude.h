#pragma once
#include "Graphics.h"
#include "Keyboard.h"

class Dude
{
public:
	Dude() = default;
	Dude(int x, int y) :
		x_(x), y_(y)
	{}
	int GetX() const;
	int GetY() const ;
	void OnBorder();
	void DrawDude(Graphics& gfx) const; //const because readonly
	void Update(const Keyboard& kbd);

	int GetWidth() const;
	int GetHeight() const;

private:
	int x_ = Graphics::ScreenWidth / 2;
	int y_ = Graphics::ScreenHeight / 2;

	static constexpr int speed_ = 10;
	static constexpr int width_ = 5;
	static constexpr int height_ = 5;
};