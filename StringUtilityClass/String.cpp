#include "String.h" 
#include <iostream> 


String::String()
    : m_data{ nullptr }, m_length{ 0 }
{
}


String::String(const char* _str)
    : m_data{ nullptr }, m_length{ 0 }
{
    CopyString(_str); // Copy the input string
}


String::String(const String& _other)
    : m_data{ nullptr }, m_length{ 0 }
{
    CopyString(_other.m_data); // Copy the data from the other string
}

String::~String()
{
    delete[] m_data; 
}

// Get the length of the string
size_t String::Length() const 
{
    return m_length;
}

// Access a character in the string by index
char& String::CharacterAt(size_t _index) 
{
    // Check if index is valid
    if (_index >= 0 && _index < m_length) 
    {
        return m_data[_index];
    }
    else 
    {
        // Return the null character
        return m_data[m_length];
    }
}

// Access a character in the string by index (const version)
const char& String::CharacterAt(size_t _index) const 
{
    // Check if index is valid
    if (_index >= 0 && _index < m_length) 
    {
        return m_data[_index];
    }
    else 
    {
        // Return the null character
        return m_data[m_length];
    }
}

// Check if two strings are equal
bool String::EqualTo(const String& _other) const 
{
    // Use strcmp to compare the strings
    return strcmp(m_data, _other.m_data) == 0;
}

// Append another string to this string
String& String::Append(const String& _str) 
{
    // Calculate the combined length of the strings
    size_t combinedLength = m_length + _str.m_length + 1;
    char* combinedString = new char[combinedLength];

    // Copy the current string to the combined string
    strcpy_s(combinedString, combinedLength, m_data);

    // Append the other string to the combined string
    strcat_s(combinedString, combinedLength, _str.m_data);

    // Update the current string to the combined string
    delete[] m_data;
    m_data = combinedString;

    // Update the length of the current string
    m_length += _str.m_length;
    
    return *this;
}

// Prepend another string to this string
String& String::Prepend(const String& _str) 
{
    // Calculate the combined length of the strings
    size_t combinedLength = m_length + _str.m_length + 1;
    char* combinedString = new char[combinedLength];

    // Copy the other string to the beginning of the combined string
    strcpy_s(combinedString, combinedLength, _str.m_data);

    // Append the current string to the combined string
    strcat_s(combinedString, combinedLength, m_data);
    
    // Update the current string to the combined string
    delete[] m_data;
    m_data = combinedString;
    
    // Update the length of the current string
    m_length += _str.m_length;
    
    return *this;
}

// Get a C-style string (null-terminated)
const char* String::CStr() const 
{
    return m_data;
}

// Convert all characters to lowercase
String& String::ToLower() 
{
    for (int i = 0; i < m_length; ++i) 
    {
        m_data[i] = std::tolower(m_data[i]);
    }

    return *this;
}

// Convert all characters to uppercase
String& String::ToUpper() 
{
    for (int i = 0; i < m_length; ++i) 
    {
        m_data[i] = std::toupper(m_data[i]);
    }

    return *this;
}

// Find the first occurrence of a substring
size_t String::Find(const String& _str) 
{
    // Use strstr to find the substring in the string
    char* position = strstr(m_data, _str.m_data);
    
    // Return the index of the substring if found
    if (position != nullptr) 
    {
        return (position - m_data);
    }
    
    // Return -1 if the substring is not found
    return -1;
}

// Find the first occurrence of a substring starting from a specific index
size_t String::Find(size_t _startIndex, const String& _str) 
{
    // Use strstr to find the substring in the string starting from _startIndex
    char* position = strstr(m_data + _startIndex, _str.m_data);

    // Return the index of the substring if found
    if (position != nullptr) 
    {
        return (position - m_data);
    }

    // Return -1 if the substring is not found
    return -1;
}

// Replace all occurrences of a substring with another substring
String& String::Replace(const String& _find, const String& _replace) 
{
    // Find the position of the first occurrence of _find
    size_t position = Find(_find);

    // Repeat the replacement process until no more occurrences are found
    while (position != static_cast<size_t>(-1)) 
    {
        // Calculate the length of the replaced string
        size_t replaceLength = m_length + _replace.m_length - _find.m_length;
        char* replaceString = new char[replaceLength + 1];

        // Copy the substring before the found position
        strncpy_s(replaceString, replaceLength + 1, m_data, position);
        
        // Null-terminate the replaced string
        replaceString[position] = '\0';

        // Append the replacement string
        strcat_s(replaceString, replaceLength + 1, _replace.m_data);
        
        // Append the substring after the found position
        strcat_s(replaceString, replaceLength + 1, m_data + position + _find.m_length);
        
        // Update the current string to the replaced string
        delete[] m_data;
        m_data = replaceString;

        // Update the length of the current string
        m_length = replaceLength;

        // Find the position of the next occurrence
        position = Find(position + _replace.m_length, _find);
    }

    return *this;
}

// Read a string from the console
String& String::ReadFromConsole() 
{
    char buffer[1000]; // Buffer to store input
    std::cin.getline(buffer, 1000); // Read a line of input
    CopyString(buffer); // Copy the input string

    return *this; 
}

// Write the string to the console
String& String::WriteToConsole() 
{
    std::cout << m_data; 
    return *this; 
}

// Overloaded equality operator
bool String::operator==(const String& _other) 
{
    return strcmp(m_data, _other.m_data) == 0; // Compare strings
}

// Overloaded inequality operator
bool String::operator!=(const String& _other) 
{
    return strcmp(m_data, _other.m_data) != 0; // Compare strings
}

// Overloaded assignment operator
String& String::operator=(const String& _str) 
{
    delete[] m_data; // Free memory of current string
    CopyString(_str.m_data); // Copy the data from the other string
    
    return *this; 
}

// Overloaded subscript operator
char& String::operator[](size_t _index) 
{
    return m_data[_index]; 
}

// Overloaded subscript operator for const strings
const char& String::operator[](size_t _index) const 
{
    return m_data[_index]; 
}

// Overloaded less than operator
bool String::operator<(const String& _other) 
{
    return strcmp(m_data, _other.m_data) < 0; 
}

// Overloaded addition operator for concatenating strings
char* String::operator+(const String& _other) 
{
    // Calculate the length of the combined string
    size_t combinedLength = m_length + _other.m_length + 1; 
    char* combinedString = new char[combinedLength]; 

    // Copy the data from the first string
    strcpy_s(combinedString, combinedLength, m_data); 

    // Concatenate the data from the second string
    strcat_s(combinedString, combinedLength, _other.m_data); 
    
    return combinedString;
}

// Overloaded compound assignment operator for concatenating strings
String& String::operator+=(const String& _other) 
{
    // Calculate the length of the combined string
    size_t combinedLength = m_length + _other.m_length + 1; 
    char* combinedString = new char[combinedLength]; 

    // Copy the data from the first string
    strcpy_s(combinedString, combinedLength, m_data);

   // Concatenate the data from the second string
    strcat_s(combinedString, combinedLength, _other.m_data);

    // Update the current string to the combined string
    delete[] m_data; 
    m_data = combinedString; 

    // Update the length of the current string
    m_length += _other.m_length; 
    
    return *this; 
}

// Private function to copy a string
void String::CopyString(const char* _str) 
{
    m_length = strlen(_str); // Calculate the length of the string
    m_data = new char[m_length + 1]; // Allocate memory for the string
    strcpy_s(m_data, m_length + 1, _str); // Copy the data from the input string
}
