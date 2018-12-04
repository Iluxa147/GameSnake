#pragma once
#include "Graphics.h"
#include "Dude.h"

class Carpet
{
public:
	/*Carpet(int x, int y, int vx, int vy) :
		x_(x), y_(y), vx_(vx), vy_(vy)
	{}*/
	void CarpetInit(int x, int y, int vx, int vy);
	void UpdateCarpet();
	void isCollided(const Dude& dude);
	void DrawCarpet(Graphics& gfx) const; //const because readonly
	bool isCollided() const // no object change
	{
		return isCollected_;
	}

private:
	int x_;
	int y_;
	int vx_;
	int vy_;
	bool isCollected_ = false;
	static constexpr int width = 5;
	static constexpr int height = 5;
};