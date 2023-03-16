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

// class RuntimeError : public runtime_error  {
// 	public:
//     const char* what() const throw() {
// 		return "\033[1;31mRuntime Error\033[0m\n";
// 	}
// };

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

class CardInsufficientException : public exception  {
	public:
    const char* what() const throw() {
		return "\033[1;31mException: Number of card in deck insufficient for this game\n"
		"Please insert proper deck\033[0m\n";
	}
};

class CardRedundancyException : public exception  {
	public:
    const char* what() const throw() {
		return "\033[1;31mException: Some cards in deck is redundant\n"
		"Please insert proper deck\033[0m\n";
	}
};

class NotFoundException : public exception  {
	public:
    const char* what() const throw() {
		return "\033[1;31mException: Not found\n"
		"Please insert proper deck\033[0m\n";
	}
};

template <typename T>
void Input(T& input){
	cin.exceptions(ios_base::failbit);
	while(true){
        try{
            cin >> input;
            if(!cin.fail()){
                break;
            }
        }catch (const ios_base::failure &) {
            cout  << "\033[1;31mException: Sorry, input type doesn't match variables :(\n"
			"Please enter again\033[0m\n>> ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

template<char*&>
void Input(char*& input){
	char* temp=new char[1000];
	cin >> temp;
	while(true){
		if(strlen(temp)<=100){
			input=new char[100];
			input=temp;
			break;
		} else {
			throw NameCharOutOfBounds();
		}
	}

}

#endif