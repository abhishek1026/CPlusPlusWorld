/*
 * MagicSquare.h
 *
 *  Created on: Sep 18, 2016
 *      Author: abhishek
 */
#include <vector>
#include <iostream>
#include <iomanip>
#ifndef MAGICSQUARE_H_
#define MAGICSQUARE_H_
using namespace std;

int main();

class MagicSquare {
private:
	vector<vector<int> > square1;
	vector<vector<int> > square2;
	vector<vector<int> > square3;
	vector< vector<int> > populateSquare(vector<vector<int> >);
	vector< vector<int> > switchRow(vector<vector<int> >);
	vector< vector<int> > switchColumn(vector<vector<int> >);

public:
	MagicSquare(int);
	void printArray(int);
	void printSums(int);
};

#endif /* MAGICSQUARE_H_ */
