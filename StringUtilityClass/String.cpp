#include "String.h"
#include <iostream>



String::String()
	: m_data{ nullptr }, m_length{ 0 }
{
}

String::String(const char* _str)
	: m_data{ nullptr }, m_length{ 0 }
{
	CopyString(_str);
}

String::String(const String& _other)
	: m_data{ nullptr }, m_length{ 0 }
{
	CopyString(_other.m_data);
}

String::~String()
{
	delete[] m_data;
}





size_t String::Length() const {

	return m_length;
}

char& String::CharacterAt(size_t _index) {

	if (_index >= 0 && _index < m_length) {

		return m_data[_index];
	}
	else {

		return m_data[m_length];
	}
}

const char& String::CharacterAt(size_t _index) const {

	if (_index >= 0 && _index < m_length) {

		return m_data[_index];
	}
	else {

		return m_data[m_length];
	}
}

bool String::EqualTo(const String& _other) const {

	return strcmp(m_data, _other.m_data) == 0;
}

String& String::Append(const String& _str) {

	size_t combindLength = m_length + _str.m_length + 1;
	char* combindString = new char[combindLength];

	strcpy_s(combindString, combindLength, m_data);
	strcat_s(combindString, combindLength, _str.m_data);

	delete[] m_data;
	m_data = combindString;

	m_length += _str.m_length;

	return *this;

}

String& String::Prepend(const String& _str) {

	size_t combindLength = m_length + _str.m_length + 1;
	char* combindString = new char[combindLength];

	strcpy_s(combindString, combindLength, _str.m_data);
	strcat_s(combindString, combindLength, m_data);

	delete m_data;
	m_data = combindString;

	m_length += _str.m_length;

	return *this;

}

const char* String::CStr() const {
	return m_data;
}

String& String::ToLower() {

	for (int i = 0; i < m_length; ++i) {

		m_data[i] = std::tolower(m_data[i]);
	}

	return *this;
}

String& String::ToUpper() {

	for (int i = 0; i < m_length; ++i) {

		m_data[i] = std::toupper(m_data[i]);
	}

	return *this;
}

size_t String::Find(const String& _str) {

	char* position = strstr(m_data, _str.m_data);
	if (position == nullptr) {

		return -1;
	}

	return (position - m_data);




}

size_t String::Find(size_t _startIndex, const String& _str) {



	char* position = strstr(m_data + _startIndex, _str.m_data);
	if (position == nullptr) {

		return -1;
	}

	return (position - m_data);
}

String& String::Replace(const String& _find, const String& _replace) {

	size_t position = Find(_find);

	while (position != static_cast<size_t>(-1)) {

		size_t replaceLength = m_length + _replace.m_length - _find.m_length;

		char* replaceString = new char[replaceLength + 1];

		strncpy_s(replaceString, replaceLength + 1, m_data, position);
		replaceString[position] = '\0';

		strcat_s(replaceString, replaceLength + 1, _replace.m_data);

		strcat_s(replaceString, replaceLength + 1, m_data + position + _find.m_length);

		delete[] m_data;

		m_data = replaceString;
		m_length = replaceLength;

		position = Find(position + _replace.m_length, _find);

	}

	return *this;

}

String& String::ReadFromConsole() {

	char size[1000];
	std::cin.getline(size, 1000);
	CopyString(size);
	return *this;
}

String& String::WriteToConsole() {

	std::cout << m_data;

	return *this;
}

bool String::operator==(const String& _other) {

	return strcmp(m_data, _other.m_data) == 0;
}

bool String::operator!=(const String& _other) {

	return strcmp(m_data, _other.m_data) != 0;
}

String& String::operator=(const String& _str) {

	delete[] m_data;
	CopyString(_str.m_data);
	return *this;
}

char& String::operator[](size_t _index) {

	return m_data[_index];
}

const char& String::operator[](size_t _index) const {

	return m_data[_index];
}

bool String::operator<(const String& _other) {

	if (strcmp(m_data, _other.m_data) == 1) {

		return true;
	}

	return false;
}

char* String::operator+(const String& _other) {

	size_t combindLength = m_length + _other.m_length + 1;
	char* combindString = new char[combindLength];

	strcpy_s(combindString, combindLength, m_data);
	strcat_s(combindString, combindLength, _other.m_data);

	return combindString;
}

String& String::operator+=(const String& _other) {

	size_t combindLength = m_length + _other.m_length + 1;
	char* combindString = new char[combindLength];

	strcpy_s(combindString, combindLength, m_data);
	strcat_s(combindString, combindLength, _other.m_data);

	delete[] m_data;
	m_data = combindString;
	m_length += _other.m_length;

	return *this;
}

void String::CopyString(const char* _str) {

	m_length = strlen(_str);
	m_data = new char[m_length + 1];

	strcpy_s(m_data, m_length + 1, _str);
}


