#pragma once
#include <queue>
#include <bitset>

class Keyboard
{
	friend class MainWindow;
public:
	class Event
	{
	public:
		enum Type
		{
			Press,
			Release,
			Invalid
		};
	private:
		Type type;
		unsigned char code;
	public:
		Event()
			:
			type(Invalid),
			code(0u)
		{}
		Event(Type type, unsigned char code)
			:
			type(type),
			code(code)
		{}
		bool IsPress() const
		{
			return type == Press;
		}
		bool IsRelease() const
		{
			return type == Release;
		}
		bool IsValid() const
		{
			return type != Invalid;
		}
		unsigned char GetCode() const
		{
			return code;
		}
	};
public:
	Keyboard() = default;
	Keyboard(const Keyboard&) = delete;
	Keyboard& operator=(const Keyboard&) = delete;
	bool KeyIsPressed(unsigned char keycode) const;
	Event ReadKey();
	bool KeyIsEmpty() const;
	char ReadChar();
	bool CharIsEmpty() const;
	void FlushKey();
	void FlushChar();
	void Flush();
	void EnableAutorepeat();
	void DisableAutorepeat();
	bool AutorepeatIsEnabled() const;
private:
	void OnKeyPressed(unsigned char keycode);
	void OnKeyReleased(unsigned char keycode);
	void OnChar(char character);
	template<typename T>
	void TrimBuffer(std::queue<T>& buffer);
private:
	static constexpr unsigned int nKeys = 256u;
	static constexpr unsigned int bufferSize = 4u;
	bool autorepeatEnabled = false;
	std::bitset<nKeys> keystates;
	std::queue<Event> keybuffer;
	std::queue<char> charbuffer;
};









#include "Keyboard.h"

bool Keyboard::IsKeyPressed(unsigned char keycode) const
{
	return keyStates_[keycode];
}

Keyboard::Event Keyboard::ReadKey()
{
	if (keyBuffer_.size() > 0u)
	{
		Keyboard::Event e = keyBuffer_.front();
		keyBuffer_.pop();
		return e;
	}
	else
	{
		return Keyboard::Event();
	}
}

bool Keyboard::IsKeyEmpty() const
{
	return keyBuffer_.empty();
}

char Keyboard::ReadChar()
{
	if (charBuffer_.size() > 0u)
	{
		unsigned char charcode = charBuffer_.front();
		charBuffer_.pop();
		return charcode;
	}
	else
	{
		return 0;
	}
}

bool Keyboard::CharIsEmpty() const
{
	return charBuffer_.empty();
}

void Keyboard::FlushKey()
{
	keyBuffer_ = std::queue<Event>();
}

void Keyboard::FlushChar()
{
	charBuffer_ = std::queue<char>();
}

void Keyboard::Flush()
{
	FlushKey();
	FlushChar();
}

void Keyboard::EnableAutorepeat()
{
	isAutorepeatEnabled_ = true;
}

void Keyboard::DisableAutorepeat()
{
	isAutorepeatEnabled_ = false;
}

bool Keyboard::IsAutorepeatEnabled() const
{
	return isAutorepeatEnabled_;
}

void Keyboard::OnKeyPressed(unsigned char keycode)
{
	keyStates_[keycode] = true;
	keyBuffer_.push(Keyboard::Event(Keyboard::Event::Press, keycode));
	TrimBuffer(keyBuffer_);
}

void Keyboard::OnKeyReleased(unsigned char keycode)
{
	keyStates_[keycode] = false;
	keyBuffer_.push(Keyboard::Event(Keyboard::Event::Release, keycode));
	TrimBuffer(keyBuffer_);
}

void Keyboard::OnChar(char character)
{
	charBuffer_.push(character);
	TrimBuffer(charBuffer_);
}

template<typename T>
void Keyboard::TrimBuffer(std::queue<T>& buffer)
{
	while (buffer.size() > bufferSize_)
	{
		buffer.pop();
	}
}
