#pragma once

class Location
{
public:
	void Add(const Location& val)
	{
		x += val.x;
		y += val.y;
	}
	bool operator == (const Location& rval)const
	{
		return x == rval.x && y == rval.y;
	}

public:
	int x;
	int y;
};
