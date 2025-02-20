#pragma once
#include <iostream>
#include <cctype>


// File: string.hpp
// Author: Hamish McDonald
// Date 2025-02-14

// This header file defines a basic string utility class that will make working with character arrays easier to manage.
// Specifics about the usage of members functions can be found in string.cpp

class String {
public:

	//Function protoyping

	String(); 

	String(const char* _cstr);
	
	String(const String& _str);

	const size_t Length() const;

	String& Append(const String& _str);

	String& ToLower();

	String& ToUpper();

	int FindCharacter(const char& _chr) const;

	int Replace(const char _findcharacter, const char _replacecharacter);

	String& ReadFromConsole(); 

	const String& WriteToConsole() const;

	String& WriteToConsole(); 

	bool friend operator==(const String& lhs, const String& rhs); 

	friend std::ostream& operator<<(std::ostream& os, const String& _str);

	friend std::istream& operator>>(std::istream& is, String& _str);

	char& operator[] (size_t index);

	const char& operator[] (size_t index) const;

	friend String& operator+=(String& _str, const char _chr); 

	bool operator< (const String& _str) const;

	String& operator= (const String& _str); 

	String& Clear(); 

	~String();

private:
	// Private members variables of string class
	char* start; 
	size_t length; 

};