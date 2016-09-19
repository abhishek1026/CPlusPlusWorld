/*
 * HelloWorld.cpp
 *
 *  Created on: Jul 27, 2016
 *      Author: abhishek
 */

#include "HelloWorld.h"
#include <iostream>
#include <cmath>

using namespace std;

int main(){

	double average;

	int size = 0;

	double total = 0.0;

	int input;

	cout << "This program will compute the average age of any given group!" << endl;

	cout << "Please enter each age on separate lines. When finished with all group members, please enter -1. " << endl;


	do{

		cin>> input;

		if(input == -1)
			continue;
		else{
			total += input;
			size++;
			average = total/size;
		}

	}while(input != -1);

	cout << "Group Size is: " << size << " and the average age is: ";

	if(size>0)
		cout << average << ". Thank you!";
	else
		cout << "N/A. Fuck you!";

}

HelloWorld::HelloWorld() {

	// TODO Auto-generated constructor stub

}

HelloWorld::~HelloWorld() {
	// TODO Auto-generated destructor stub
}


