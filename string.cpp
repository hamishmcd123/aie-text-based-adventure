#include "string.hpp"
#include <iostream>

// Default constructor
String::String() {
	start = new char[1];
	start[0] = '\0';
	std::cout << start[0];
	length = 0;
}


// Constructor for using c-style strings
// Example usage: String _str("This is a test string");
String::String(const char* _cstr) {
	int templength = 0;
	for (int i = 0; *(_cstr + i) != '\0'; i++) {
		templength++;
	}

	length = templength;

	start = new char[length + 1];
	start[length] = '\0';

	for (int i = 0; *(_cstr + i) != '\0'; i++) {
		*(start + i) = *(_cstr + i);
	}

}

// Returns the length of the string (excluding the null terminator character)
// Example usage: 
// String _str("hello");
// std::cout << _str.Length();
// Output : 5

const size_t String::Length() const {
	return length;
}


// Subscript operator. Returns character at index [n].
// Example usage: 
// String _str("hello"); 
// std::cout << _str[0]; 
// Output : h

char& String::operator[] (size_t index) {
	if (index < length) {
		return *(start + index);
	}
	else {
		return (start)[length];
	}
}


// Definition for stream insertion operator. 
// Example usage: 
// String _str("hello");
// std::cout << _str;
// Output: hello

std::ostream& operator<<(std::ostream& os, const String& _str) {
	for (int i = 0; i < (_str.Length()); i++) {
		os << _str[i];
	}
	return os;
}

// Writes string to console. 
// Example usage:
// String _str("hello"); 
// _str.WriteToConsole(); 
// Output: hello

const String& String::WriteToConsole() const {
	std::cout << *(this) << '\n';
	return *this;
}

String& String::WriteToConsole() {
	std::cout << *(this) << '\n';
	return *this;
}


// String destructor function.
String::~String() {
	if (start != nullptr) {
		delete[] start;
	}
}

// Converts string to lowercase. 
// Example usage:
// String _str("HELLO"); 
// std::cout << _str.ToLower(); 
// Output: hello

String& String::ToLower() {
	for (int i = 0; i < length; i++) {

		(*this)[i] = (char)(std::tolower((*this)[i]));
	}
	return *this;
}

// Converts string to uppercase.
// Example usage:
// String _str("hello"); 
// std::cout << _str.ToUpper(); 
// Output: HELLO

String& String::ToUpper() {
	for (int i = 0; i < length; i++) {
		(*this)[i] = (char)(std::toupper((*this)[i]));
	}
	return *this;
}

// Copy constructor
String::String(const String& _str) {
	length = _str.length;
	start = new char[length + 1];
	for (int i = 0; i < length; i++) {
		start[i] = _str[i];
	}
	start[length] = '\0';
}

// Const subscript operator. See subscript operator. 
const char& String::operator[] (size_t index) const {
	if (index < length) {
		return *(start + index);
	}
	else {
		return (start)[length];
	}
}

// Equality operator. Returns TRUE is two strings have the same contents. 
// Example usage:
// String _str1("hello");
// String _str2("hello");
// std::cout << (_str1 == _srt2); 
// Output: 1

bool operator==(const String& lhs, const String& rhs) {
	// First check to see if lengths are even equal...
	if (lhs.length != rhs.length) {
		return false;
	}

	for (int i = 0; i < lhs.length; i++) {
		if (lhs[i] != rhs[i]) {
			return false;
		}
	}

	return true;
}

// Appends one string to another. 
// Example usage:
// String _str1("hello"); 
// String _str2("bello"); 
// std::cout << _str1.Append(_str2); 
// Output: hellobello

String& String::Append(const String& _str) {

	size_t templength = this->length + _str.length;

	char* newstart = new char[templength + 1];

	for (int i = 0; i < (this->length); i++) {
		newstart[i] = (*this)[i];
	}

	int j = 0;

	for (int i = this->length; i < templength; i++) {
		newstart[i] = _str[j];
		j++;
	}

	newstart[templength] = '\0';

	delete[] this->start;

	this->start = newstart;
	this->length = templength;
	return *this;
}


// Returns int corresponding to the index of first appearance of character. Returns -1 if character is not found. 
// Example usage:
// String _str("hello");
// std::cout << _str.FindCharacter('e');
// Output: 1

int String::FindCharacter(const char& _chr) const {
	int index = 0;
	for (int i = 0; i < this->length; i++) {
		if (_chr == (*this)[i]) {
			return index;
		}
		index++;
	}
	return -1;
}

// Replaces _findcharacter with _replacecharacter in a string. Returns int corresponding to the number of replacements. 
// Example usage:
// String _str("hello"); 
// std::cout << _str.Replace('h','b') << '\n';
// std::cout << _str; 
// Output: 1
// Output: bello

int String::Replace(const char _findcharacter, const char _replacecharacter) {
	int replacecount = 0;
	for (int i = 0; i < this->length; i++) {
		if ((*this)[i] == _findcharacter) {
			(*this)[i] = _replacecharacter;
			replacecount++;
		}
	}
	return replacecount;
}



// Assignment operator. Replaces lhs with rhs. 
// Example usage:
// String _str1("hello");
// String _str2("bello");
// _str1 = _str2; 
// std::cout << _str1; 
// Output: bello

String& String::operator=(const String& _str) {
	if (!(*this == _str)) {
		delete[] this->start;
		this->length = _str.length;
		this->start = new char[_str.length + 1];
		for (int i = 0; i < this->length; i++) {
			start[i] = _str[i];
		}
		start[length] = '\0';
	}
	return *this;
}



// Less than operator. Returns true if the lhs String comes before the rhs String alphabetically.
// Example usage: 
// String _str1("abc"); 
// String _str2("efg");
// std::cout << (_str1 < _str2); 
// Output: 1

bool String::operator<(const String& _str) const {
	if (length > 0 && _str.length > 0) {
		int comparison = 0;
		comparison = strcmp(start, _str.start);
		if (comparison < 0) {
			return true;
		}
		else {
			return false;
		}
	}

	// If either length is zero...
		else if (length == 0 && _str.length != 0) {
		return true;
		}
		// This encompasses both the case where 
		// length != 0 && _str.length == 0
		// length == 0 && _str.length == 0
		else {
		return false;
		}
}

// Plus-equals operator; appends a single char onto the end of string. 
// Example usage:
// String _str1("mee"); 
// _str1 += 'p'; 
// std::cout << _str1; 
// Output: meep

String& operator+=(String& _str, const char _chr) {
	size_t templength = _str.length + 1;
	char* newstart = new char[templength + 1];
	for (int i = 0; i < _str.length; i++) {
		newstart[i] = _str[i];
	}
	newstart[templength - 1] = _chr;
	newstart[templength] = '\0';

	delete[] _str.start;

	_str.start = newstart;
	_str.length = templength;

	return _str;
}



// Stream extraction operator. 
std::istream& operator>>(std::istream& is, String& _str) {
	std::istream::sentry s(is);

	if (s) {
		while (is) {
			char c = is.get();
			if (is.eof() || !(std::isprint(c))) break;
			if (std::isprint(c)) {
				_str += c;
			}
		}
	}


	return is;
}


// Requests input from console and stores it in the String. 
// Example usage: 
// String bello; 
// bello = bello.ReadFromConsole(); 
// User input: bello
// std::cout << bello; 
// output bello

String& String::ReadFromConsole() {
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	std::cin >> *this;
	return *this;
}


// Clears string and sets contents to a null-terminator character.
String& String::Clear() {
	delete[] start;
	length = 0;
	start = new char[1];
	start[0] = '\0';
	return *this;
}






