#include "String.h"
#include <iostream>


String::String()
	: m_data{new char[1]}
{
}

String::String(const char* _str)
	: m_data{ new char[strlen(_str) + 1]}
{
	strcpy_s(m_data, strlen(_str) + 1, _str);
}

String::String(const String& _other)
	: String(_other.m_data)
{
}

//String::String(String&& _other) noexept
	//: m_data(_other.m_data)
//{
	//_other
//}

String::~String()
{
}

size_t String::Length() const
{
	return size_t();
}

char& String::CharacterAt(size_t _index)
{
	// TODO: insert return statement here
}

const char& String::CharacterAt(size_t _index) const
{
	// TODO: insert return statement here
}

bool String::EqualTo(const String& _other) const
{
	return false;
}

String& String::Append(const String& _str)
{
	// TODO: insert return statement here
}

String& String::Prepend(const String& _str)
{
	// TODO: insert return statement here
}

const char* String::CStr() const
{
	return nullptr;
}

String& String::ToLower()
{
	// TODO: insert return statement here
}

String& String::ToUpper()
{
	// TODO: insert return statement here
}

size_t String::Find(const String& _str)
{
	return size_t();
}

size_t String::Find(size_t _startIndex, const String& _str)
{
	return size_t();
}

String& String::Replace(const String& _find, const String& _replace)
{
	// TODO: insert return statement here
}

String& String::ReadFromConsole()
{
	// TODO: insert return statement here
}

String& String::WriteToConsole()
{
	// TODO: insert return statement here
}

bool String::operator==(const String& _other)
{
	return false;
}

bool String::operator!=(const String& _other)
{
	return false;
}

String& String::operator=(const String& _str)
{
	m_data = new char[strlen(_str.m_data) + 1];
	strcpy_s(m_data, strlen(_str.m_data) + 1, _str.m_data);
}

char& String::operator[](size_t _index)
{
	// TODO: insert return statement here
}

const char& String::operator[](size_t _index) const
{
	// TODO: insert return statement here
}
