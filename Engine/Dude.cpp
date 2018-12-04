#include "Dude.h"

int Dude::GetX() const
{
	return x_;
}

int Dude::GetY() const
{
	return y_;
}

int Dude::GetWidth() const
{
	return width_;
}

int Dude::GetHeight() const
{
	return height_;
}

void Dude::OnBorder()
{
	if (x_ + width_ >= Graphics::ScreenWidth)
	{
		x_ = (Graphics::ScreenWidth-1) - width_;
	}
	else if (x_ - width_ <= 0)
	{
		x_ = width_;
	}

	if (y_ + height_ >= Graphics::ScreenHeight)
	{
		y_ = (Graphics::ScreenHeight - 1) - height_;
	}
	else if (y_ - height_ <= 0)
	{
		y_ = height_;
	}

}

void Dude::DrawDude(Graphics& gfx) const
{
	gfx.PutPixel(-5 + x_, y_, 255, 255, 255);
	gfx.PutPixel(-4 + x_, y_, 255, 255, 255);
	gfx.PutPixel(-3 + x_, y_, 255, 255, 255);
	gfx.PutPixel(3 + x_, y_,  255, 255, 255);
	gfx.PutPixel(4 + x_, y_,  255, 255, 255);
	gfx.PutPixel(5 + x_, y_,  255, 255, 255);
	gfx.PutPixel(x_, -5 + y_, 255, 255, 255);
	gfx.PutPixel(x_, -4 + y_, 255, 255, 255);
	gfx.PutPixel(x_, -3 + y_, 255, 255, 255);
	gfx.PutPixel(x_, 3 + y_,  255, 255, 255);
	gfx.PutPixel(x_, 4 + y_,  255, 255, 255);
	gfx.PutPixel(x_, 5 + y_,  255, 255, 255);

}

void Dude::Update(const Keyboard& kbd)
{
	if (kbd.IsKeyPressed(VK_RIGHT))
	{
	x_ += speed_;
	}
	if (kbd.IsKeyPressed(VK_LEFT))
	{
	x_ -= speed_;
	}
	if (kbd.IsKeyPressed(VK_UP))
	{
	y_ -= speed_;
	}
	if (kbd.IsKeyPressed(VK_DOWN))
	{
	y_ += speed_;
	}
}