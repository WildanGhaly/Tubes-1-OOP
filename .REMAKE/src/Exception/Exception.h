#ifndef EXCEPTION_H
#define EXCEPTION_H

#include<exception>
using namespace std;

class CardNumberException : public exception  {
	public:
    const char* what() const throw() {
		return "Exception: Invalid number\n";
	}
};

class CardColorException : public exception  {
	public:
    const char* what() const throw() {
		return "Exception: Invalid color\n";
	}
};

class InvalidInputException : public exception  {
	public:
    const char* what() const throw() {
		return "Exception: Invalid input, Please try again!\n";
	}
};

class NameCharOutOfBounds : public exception  {
	public:
    const char* what() const throw() {
		return "Exception: Name Length Out of Bounds\n";
	}
};

class RuntimeError : public exception  {
	public:
    const char* what() const throw() {
		return "Runtime Error\n";
	}
};

#endif