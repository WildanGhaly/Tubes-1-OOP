#ifndef EXCEPTION_H
#define EXCEPTION_H

#include<exception>
using namespace std;

class CardNumberException : public exception  {
	public:
    const char* what() const throw() {
		return "\033[1;31mException: Invalid number\033[0m\n";
	}
};

class CardColorException : public exception  {
	public:
    const char* what() const throw() {
		return "\033[1;31mException: Invalid Color\033[0m\n";
	}
};

class InvalidInputException : public exception  {
	public:
    const char* what() const throw() {
		return "\033[1;31mException: Invalid input, Please try again!\033[0m\n";
	}
};

class NameCharOutOfBounds : public exception  {
	public:
    const char* what() const throw() {
		return "\033[1;31mException: Length Out of Bounds\033[0m\n";
        
	}
};

class RuntimeError : public runtime_error  {
	public:
    const char* what() const throw() {
		return "\033[1;31mRuntime Error\033[0m\n";
	}
};

class IndexOutOfBoundException : public exception  {
	public:
    const char* what() const throw() {
		return "\033[1;31mException: Index out of bounds\033[0m\n";
	}
};

class FileNotExistException : public exception  {
	public:
    const char* what() const throw() {
		return "\033[1;31mException: No such filename\033[0m\n";
	}
};

#endif