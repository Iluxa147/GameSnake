#include "Keyboard.h"

bool Keyboard::IsKeyPressed( unsigned char keycode ) const
{
	return keyStates_[keycode];
}

Keyboard::Event Keyboard::ReadKey()
{
	if( keyBuffer_.size() > 0u )
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
	if( charBuffer_.size() > 0u )
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

void Keyboard::OnKeyPressed( unsigned char keycode )
{
	keyStates_[ keycode ] = true;
	keyBuffer_.push( Keyboard::Event( Keyboard::Event::Press,keycode ) );
	TrimBuffer(keyBuffer_);
}

void Keyboard::OnKeyReleased( unsigned char keycode )
{
	keyStates_[ keycode ] = false;
	keyBuffer_.push( Keyboard::Event( Keyboard::Event::Release,keycode ) );
	TrimBuffer(keyBuffer_);
}

void Keyboard::OnChar( char character )
{
	charBuffer_.push( character );
	TrimBuffer(charBuffer_);
}

template<typename T>
void Keyboard::TrimBuffer( std::queue<T>& buffer )
{
	while( buffer.size() > bufferSize_)
	{
		buffer.pop();
	}
}

