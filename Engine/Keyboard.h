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
		Type type_;
		unsigned char code_;

	public:
		Event() :
			type_(Invalid),
			code_(0u)
		{}

		Event(Type type, unsigned char code) :
			type_(type),
			code_(code)
		{}

		bool IsPress() const
		{
			return type_ == Press;
		}

		bool IsRelease() const
		{
			return type_ == Release;
		}

		bool IsValid() const
		{
			return type_ != Invalid;
		}
		unsigned char GetCode() const
		{
			return code_;
		}
	};

public:
	Keyboard() = default;
	Keyboard(const Keyboard&) = delete;
	Keyboard& operator = (const Keyboard&) = delete;
	Event ReadKey();
	bool IsKeyPressed(unsigned char keycode) const;
	bool IsKeyEmpty() const;
	char ReadChar();
	bool CharIsEmpty() const;
	void FlushKey();
	void FlushChar();
	void Flush();
	void EnableAutorepeat();
	void DisableAutorepeat();
	bool IsAutorepeatEnabled() const;

private:
	void OnKeyPressed(unsigned char keycode);
	void OnKeyReleased(unsigned char keycode);
	void OnChar(char character);
	template<typename T>
	void TrimBuffer(std::queue<T>& buffer);

private:
	static constexpr unsigned int nKeys_ = 256u;
	static constexpr unsigned int bufferSize_ = 4u;
	bool isAutorepeatEnabled_ = false;
	std::bitset<nKeys_> keyStates_;
	std::queue<Event> keyBuffer_;
	std::queue<char> charBuffer_;

};