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
	delete m_data;
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
	
	delete m_data;
	
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
	
	if (strstr(m_data, _str.m_data)) {
		std::cout << "found" << std::endl;
	}
	else {
		std::cout << "not found" << std::endl;
	}
	
	return size_t();
}

size_t String::Find(size_t _startIndex, const String& _str) {



	return size_t();
}
/*
String& String::Replace(const String& _find, const String& _replace) {
	// TODO: insert return statement here
}

String& String::ReadFromConsole() {
	// TODO: insert return statement here
}
*/
void String::WriteToConsole() const {
	std::cout << m_data;
}
/*
bool String::operator==(const String& _other) {
	return false;
}

bool String::operator!=(const String& _other)
{
	return false;
}

String& String::operator=(const String& _str)
{
	// TODO: insert return statement here
}

char& String::operator[](size_t _index)
{
	// TODO: insert return statement here
}

const char& String::operator[](size_t _index) const
{
	// TODO: insert return statement here
}
*/
void String::CopyString(const char* _str)
{

	m_length = strlen(_str);
	m_data = new char[m_length + 1];
	strcpy_s(m_data, m_length + 1, _str);



}


