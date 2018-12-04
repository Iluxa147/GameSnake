# pragma once

class Color
{
public:
	unsigned int dword; // 32 bit

public:
	constexpr Color() :
		dword() //initialize 0 with a default constructor
	{}
	constexpr Color(const Color& src) :
		dword(src.dword)
	{}
	constexpr Color(unsigned int src_dword) :
		dword(src_dword)
	{}
	constexpr Color(unsigned char x, unsigned char r, unsigned char g, unsigned char b) : //make color with four 8-bit values
		dword((x << 24u) | (r << 16u) | (g << 8u) | b)
	{}
	constexpr Color(unsigned char r, unsigned char g, unsigned char b) :
		dword((r << 16u) | (g << 8u) | b)
	{}
	constexpr Color(Color col, unsigned char x) :
		Color((x << 24u) | col.dword)
	{}

	Color& operator = (const Color& col)
	{
		dword = col.dword;
		return *this;
	}

	constexpr unsigned int GetX() const //TODO WTF divided X and A
	{
		return dword >> 24; //move x to low bit part
	}
	constexpr unsigned int GetA() const
	{
		return GetX();
	}
	constexpr unsigned int GetR() const
	{
		return (dword >> 16u) & 0xFFu; //mask R color value
	}
	constexpr unsigned int GetG() const
	{
		return (dword >> 8u) & 0xFFu; //mask G color value
	}
	constexpr unsigned int GetB() const
	{
		return dword & 0xFFu; //mask B color value
	}

	void SetX(unsigned char x)
	{
		dword = ((dword & 0xFFFFFFu) | x << 24u); // make 0 at high bits to write x
	}
	void SetA(unsigned char a)
	{
		SetX(a);
	}
	void SetR(unsigned char r)
	{
		dword = ((dword & 0xFF00FFFFu) | r << 16u);
	}
	void SetG(unsigned char g)
	{
		dword = ((dword & 0xFFFF00FFu) | g << 8u);
	}
	void SetB(unsigned char b)
	{
		dword = (dword & 0xFFFFFF00u) | b;
	}
};

namespace Colors
{
	static constexpr Color MakeRGB(unsigned char r, unsigned char g, unsigned char b)
	{
		return (r << 16u) | (g << 8) | b;
	}
	static constexpr Color White = MakeRGB(255u, 255u, 255u);
	static constexpr Color Black = MakeRGB(0u, 0u, 0u);
	static constexpr Color Gray = MakeRGB(0x80u, 0x80u, 0x80u);
	static constexpr Color LightGray = MakeRGB(0xD3u, 0xD3u, 0xD3u);
	static constexpr Color Red = MakeRGB(255u, 0u, 0u);
	static constexpr Color Green = MakeRGB(0u, 255u, 0u);
	static constexpr Color Blue = MakeRGB(0u, 0u, 255u);
	static constexpr Color Yellow = MakeRGB(255u, 255u, 0u);
	static constexpr Color Cyan = MakeRGB(0u, 255u, 255u);
	static constexpr Color Magenta = MakeRGB(255u, 0u, 255u);
}