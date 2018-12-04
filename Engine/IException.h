#pragma once
#include <string>

class IException
{
public:
	IException(const wchar_t* file, unsigned int line, const std::wstring& note = L"") :
		note_(note),
		file_(file),
		line_(line)
	{}

	const std::wstring& GetNote() const
	{
		return note_;
	}
	const std::wstring& GetFile() const
	{
		return file_;
	}
	const unsigned int& GetLine() const
	{
		return line_;
	}

	std::wstring GetLocation() const
	{
		return std::wstring(L"Line [") + std::to_wstring(line_) + L"] in " + file_;
	}

	virtual std::wstring GetFullMessage() const = 0;
	virtual std::wstring GetExceptionType() const = 0;

private:
	std::wstring note_;
	std::wstring file_;
	unsigned int line_;
};