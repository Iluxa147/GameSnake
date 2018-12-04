#include "Carpet.h"

void Carpet::CarpetInit(int x, int y, int vx, int vy)
{
	x_ = x;
	y_ = y;
	vx_ = vx;
	vy_ = vy;
}

void Carpet::UpdateCarpet()
{
	x_ += vx_;
	y_ += vy_;

	if (x_ + width >= Graphics::ScreenWidth)
	{
		x_ = (Graphics::ScreenWidth-1) - width;
		vx_ = -vx_;
	}
	else if (x_ - width <= 0)
	{
		x_ = width;
		vx_ = -vx_;
	}

	if (y_ + height >= Graphics::ScreenHeight)
	{
		y_ = (Graphics::ScreenHeight - 1) - height;
		vy_ = -vy_;
	}
	else if (y_ - height <= 0)
	{
		y_ = height;
		vy_ = -vy_;
	}
}

void Carpet::isCollided(const Dude& dude)
{
	if(
		// return isCollected_=
		x_ - width <= dude.GetX() + dude.GetWidth() &&
		x_ + width >= dude.GetX() - dude.GetWidth() &&
		y_ - height <= dude.GetY() + dude.GetHeight() &&
		y_ + height >= dude.GetY() - dude.GetHeight()
	){
		isCollected_ = true;
	}
	/*else
	{
		isCollected_ = false;
	}*/
}

void Carpet::DrawCarpet(Graphics& gfx) const
{
	if (!isCollected_)
	{
		gfx.PutPixel(-5 + x_, y_, 0, 255, 0);
		gfx.PutPixel(-4 + x_, y_, 0, 255, 0);
		gfx.PutPixel(-3 + x_, y_, 0, 255, 0);
		gfx.PutPixel(3 + x_, y_, 0, 255, 0);
		gfx.PutPixel(4 + x_, y_, 0, 255, 0);
		gfx.PutPixel(5 + x_, y_, 0, 255, 0);
		gfx.PutPixel(x_, -5 + y_, 0, 255, 0);
		gfx.PutPixel(x_, -4 + y_, 0, 255, 0);
		gfx.PutPixel(x_, -3 + y_, 0, 255, 0);
		gfx.PutPixel(x_, 3 + y_, 0, 255, 0);
		gfx.PutPixel(x_, 4 + y_, 0, 255, 0);
		gfx.PutPixel(x_, 5 + y_, 0, 255, 0);
	}
}
