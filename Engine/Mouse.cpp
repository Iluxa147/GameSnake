#include "Mouse.h"

std::pair<int, int> Mouse::GetPos() const
{
	return{ x_, y_ };
}

int Mouse::GetPosX() const
{
	return x_;
}

int Mouse::GetPosY() const
{
	return y_;
}

bool Mouse::IsLeftPressed() const
{
	return isLeftPressed_;
}

bool Mouse::IsRightPressed() const
{
	return isRightPressed_;
}

bool Mouse::IsInWindow() const
{
	return isInWindow_;
}

Mouse::Event Mouse::Read()
{
	if (buffer_.size() > 0)
	{
		Mouse::Event e = buffer_.front();
		buffer_.pop();
		return e;
	}
	else
	{
		return Mouse::Event();
	}
}

void Mouse::Flush()
{
	buffer_ = std::queue<Event>();
}

void Mouse::OnMouseLeave()
{
	isInWindow_ = false;
}

void Mouse::OnMouseEnter()
{
	isInWindow_ = true;
}

void Mouse::OnMouseMove(int newx, int newy)
{
	x_ = newx;
	y_ = newy;
	
	buffer_.push(Mouse::Event(Mouse::Event::Move, *this));
	TrimBuffer();
}

void Mouse::OnLeftPressed(int x, int y)
{
	isLeftPressed_ = true;

	buffer_.push(Mouse::Event(Mouse::Event::LPress, *this));
	TrimBuffer();
}

void Mouse::OnLeftReleased(int x, int y)
{
	isLeftPressed_ = false;

	buffer_.push(Mouse::Event(Mouse::Event::LRelease, *this));
	TrimBuffer();
}

void Mouse::OnRightPressed(int x, int y)
{
	isRightPressed_ = true;

	buffer_.push(Mouse::Event(Mouse::Event::RPress, *this));
	TrimBuffer();
}

void Mouse::OnRightReleased(int x, int y)
{
	isRightPressed_ = false;

	buffer_.push(Mouse::Event(Mouse::Event::RRelease, *this));
	TrimBuffer();
}

void Mouse::OnWheelUp(int x, int y)
{
	buffer_.push(Mouse::Event(Mouse::Event::WheelUp, *this));
	TrimBuffer();
}

void Mouse::OnWheelDown(int x, int y)
{
	buffer_.push(Mouse::Event(Mouse::Event::WheelDown, *this));
	TrimBuffer();
}

void Mouse::TrimBuffer()
{
	while (buffer_.size() > bufferSize_)
	{
		buffer_.pop();
	}
}