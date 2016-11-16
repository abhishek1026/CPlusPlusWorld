#include <iostream>
#include <string>
#include <cstdlib>
#include <array>
#include <fstream>
#include <cctype>

using namespace std;

#ifndef PA3_H
#define PA3_H

//This is the header file that contains the definition for the Stack class.

class Stack{
private:
	//encapsulated member variables
	int top;
	string arr[1000];

public:
	//public methods that are implemented in the .cpp file.

	Stack(); //constructor defined in .cpp file.

	void push(string);
	string pop();
    string peek();

	bool isEmpty();
	
	int getTop(){
		return top;
	}
	string* getArr(){
		return arr;
	}
};



#endif