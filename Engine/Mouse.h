#pragma once
#include <queue>

class Mouse
{
	friend class MainWindow;

public:
	class Event
	{
	public:
		enum Type
		{
			LPress,
			LRelease,
			RPress,
			RRelease,
			WheelUp,
			WheelDown,
			Move,
			Invalid
		};

	private:
		Type type_;
		bool isLeftPressed_;
		bool isRightPressed_;
		int x_;
		int y_;

	public:
		Event():
			type_(Invalid),
			isLeftPressed_(false),
			isRightPressed_(false),
			x_(0),
			y_(0)
		{}

		Event(Type type, const Mouse& parent):
			type_(type),
			isLeftPressed_(parent.isLeftPressed_),
			isRightPressed_(parent.isRightPressed_),
			x_(parent.x_),
			y_(parent.y_)
			{}
		
		bool IsValid() const
		{
			return type_ != Invalid;
		}

		Type GetType() const
		{
			return type_;
		}

		std::pair<int, int> GetPos() const
		{
			return{ x_, y_ };
		}

		int GetPosX() const
		{
			return x_;
		}
		int GetPosY() const
		{
			return y_;
		}
		bool IsLeftPressed() const
		{
			return isLeftPressed_;
		}
		bool IsRightPressed() const
		{
			return isRightPressed_;
		}
	};

public:
	Mouse() = default;
	Mouse(const Mouse&) = delete;
	Mouse& operator=(const Mouse&) = delete;
	std::pair<int, int> GetPos() const;
	int GetPosX() const;
	int GetPosY() const;
	bool IsRightPressed() const;
	bool IsLeftPressed() const;
	bool IsInWindow() const;
	Event Read();
	bool IsEmpty() const
	{
		return buffer_.empty();
	}
	void Flush();

private:
	void OnMouseMove(int x, int y);
	void OnMouseLeave();
	void OnMouseEnter();
	void OnLeftPressed(int x, int y);
	void OnLeftReleased(int x, int y);
	void OnRightPressed(int x, int y);
	void OnRightReleased(int x, int y);
	void OnWheelUp(int x, int y);
	void OnWheelDown(int x, int y);
	void TrimBuffer();

private:
	static constexpr unsigned int bufferSize_ = 4u;
	int x_;
	int y_;
	bool isLeftPressed_ = false;
	bool isRightPressed_ = false;
	bool isInWindow_ = false;
	std::queue<Event> buffer_;
};