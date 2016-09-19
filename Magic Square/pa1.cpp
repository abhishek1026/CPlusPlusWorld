#include "pa1.h"

#include <iostream>
#include <cstdlib>
#include <vector>
#include <iomanip>


using namespace std;
//This is the method through which the program begins executing.
int main(){


	int matrixSize;

	do{
		cout << "Enter the size of a magic square: ";

		cin >> matrixSize;
	}while(!((matrixSize >= 3 && matrixSize<=15) && matrixSize % 2 == 1));

	MagicSquare a(matrixSize);

	a.printArray(1);

	a.printSums(1);

	a.printArray(2);

	a.printSums(2);

	a.printArray(3);

	a.printSums(3);

	return 0;
}
/*This is the constructor for the MagicSquare class. This constructor
 * basically initializes and fills each magic square(built using 2-D vectors)
 * with the appropriate numbers by calling 3 different private methods and
 * assigning the return value for each of those methods to their respective squares.
 */
MagicSquare::MagicSquare(int size) {
	vector<int> row(size);
	for(int i = 0; i<size;i++){
		square1.push_back(row);
	}
	square1 =populateSquare(square1);
	square2 =switchRow(square1);
	square3 =switchColumn(square1);
}

/*This is the method responsible for printing out the 3 unique magic squares in a format
 * that closely resembles n x n matrices. This method is called 3 times from the main method, each
 * time with a different integer parameters to display a unique magic square in the output.
 */
void MagicSquare::printArray(int check){

cout<<"Magic Square #" << check << " is: " << endl;

switch(check){

case 1:
	for(int i =0; i<square1.size(); i++){
		for(int j=0; j<square1.size(); j++){
			if(square1.size()>=11)
				cout << setw(3) << square1[i][j] << " ";
			else if (square1.size()>=5)
				cout << setw(2) << square1[i][j] << " ";
			else
				cout << setw(1) << square1[i][j] << " ";
		}
		cout << endl;
	}
	break;
case 2:
	for(int i =0; i<square2.size(); i++){
		for(int j=0; j<square2.size(); j++){
			if(square2.size()>=11)
				cout << setw(3) << square2[i][j] << " ";
			else if (square2.size()>=5)
				cout << setw(2) << square2[i][j] << " ";
			else
				cout << setw(1) << square2[i][j] << " ";
		}
		cout << endl;
	}
	break;
case 3:
	for(int i =0; i<square3.size(); i++){
			for(int j=0; j<square3.size(); j++){
				if(square3.size()>=11)
					cout << setw(3) << square3[i][j] << " ";
				else if (square3.size()>=5)
					cout << setw(2) << square3[i][j] << " ";
				else
					cout << setw(1) << square3[i][j] << " ";
		}
		cout << endl;
	}
}
}
/*This is the method that validates the sums of each row, column, and diagonal
 * for a given magic square. The integer parameters is used to indicate which of the 3 squares to
 * analyze for these sums, which are then printed to the output. This method is also called
 * with the main method of this program.
 */
void MagicSquare::printSums(int check){

if(check == 1){
	cout << "Checking the sums of every row: ";
	for(int i =0; i<square1.size(); i++){
		int sumRow =0;
		for(int j=0; j<square1.size(); j++){
			sumRow+= square1[i][j];
		}
		cout << sumRow << " ";
	}
	cout << endl;

	cout << "Checking the sums of every column: ";
	for(int i =0; i<square1.size(); i++){
			int sumCol =0;
			for(int j=0; j<square1.size(); j++){
				sumCol+= square1[j][i];
			}
			cout << sumCol << " ";
	}
	cout << endl;

	cout<< "Checking the sums of each diagonal: ";
			int sumD =0;
	for(int i=0,j = 0;i<square1.size();i++,j++){
			sumD += square1[i][j];
	}
	cout << sumD << " ";
			sumD = 0;
	for(int i=0,j = square1.size()-1;i<square1.size(); i++,j--)
			sumD += square1[i][j];
	cout << sumD << endl;}
else if(check == 2){
	cout << "Checking the sums of every row: ";
	for(int i =0; i<square2.size(); i++){
		int sumRow =0;
		for(int j=0; j<square2.size(); j++){
			sumRow+= square2[i][j];
		}
		cout << sumRow << " ";
	}
	cout << endl;

	cout << "Checking the sums of every column: ";
	for(int i =0; i<square2.size(); i++){
			int sumCol =0;
			for(int j=0; j<square2.size(); j++){
				sumCol+= square2[j][i];
			}
			cout << sumCol << " ";
	}
	cout << endl;

	cout<< "Checking the sums of each diagonal: ";
			int sumD1=0;
	for(int i=0,j = 0;i<square2.size();i++,j++){
			sumD1 += square2[i][j];
	}
	cout << sumD1 << " ";
			sumD1 = 0;
	for(int i=0,j = square2.size()-1;i<square2.size(); i++,j--)
			sumD1 += square2[i][j];
	cout << sumD1 << endl;}
else{
	cout << "Checking the sums of every row: ";
	for(int i =0; i<square3.size(); i++){
		int sumRow =0;
		for(int j=0; j<square3.size(); j++){
			sumRow+= square3[i][j];
		}
		cout << sumRow << " ";
	}
	cout << endl;

	cout << "Checking the sums of every column: ";
	for(int i =0; i<square3.size(); i++){
			int sumCol =0;
			for(int j=0; j<square3.size(); j++){
				sumCol+= square3[j][i];
			}
			cout << sumCol << " ";
	}
	cout << endl;

	cout<< "Checking the sums of each diagonal: ";
			int sumD2=0;
	for(int i=0,j = 0;i<square3.size();i++,j++){
			sumD2 += square3[i][j];
	}
	cout << sumD2 << " ";
			sumD2 = 0;
	for(int i=0,j = square3.size()-1;i<square3.size(); i++,j--)
			sumD2 += square3[i][j];
	cout << sumD2 << endl;}
}
/*This is the method that populates the initial zeros in the 2-D vector variable named as
 * square1 in the MagicSquare class with positive integers that appropriate create and fill in
 * the first magic square. This method is invoked by the constructor, where the return value
 * is stored into the 2-D vector variable square1.
 */
vector< vector<int> > MagicSquare::populateSquare(vector< vector<int> > a){
	int count = 1;
	int row = 0;
	int col = a.size()/2;
	a[row][col] = count;


	while(++count<=(a.size()*a.size())){

		if(row == 0 && col == (a.size() -1)){
			if(a[a.size()-1][0]){
				a[row+1][col] = count;
				row++;
			}
			else{
				a[a.size()-1][0] = count;
				row = a.size()-1;
				col = 0;
			}

		}
		else if(row == 0){
			if(a[a.size()-1][col+1]){
				a[row+1][col] = count;
				row++;
			}
			else{
				a[a.size()-1][col+1] = count;
				row = a.size()-1;
				col++;
			}
		}
		else if(col == (a.size()-1)){
			if(a[row-1][0]){
				a[row+1][col] = count;
				row++;
			}
			else{
				a[row-1][0] = count;
				row--;
				col = 0;
			}
		}
		else{
			if(a[row-1][col+1]){
				a[row+1][col] = count;
				row++;
			}

			else{
				a[row-1][col+1] = count;
				row--;
				col++;
			}
		}
	}

	return a;


}
/*This is the method which essentially takes in the 2-D vector represented by
 * square1 and switches its first and last rows to obtain another unique magic square.
 * This newly formed 2-D vector/magic square is stored into square2 by the constructor,which
 * is also where the following method is invoked.
 */
vector< vector<int> > MagicSquare::switchRow(vector< vector<int> > b){
	vector< vector<int> > toReturn = b;

	for(int i =0; i<b.size(); i++){

		toReturn[0][i] = b[b.size()-1][i];
	}

	for(int i =0; i<b.size(); i++){
		toReturn[b.size()-1][i] = b[0][i];
	}

	return toReturn;


}
/*This is the method which essentially takes in the 2-D vector represented by
 * square1 and switches its first and last columns to obtain another unique magic square.
 * This newly formed 2-D vector/magic square is stored into square3 by the constructor,which
 * is also where the following method is invoked.
 */
vector< vector<int> > MagicSquare::switchColumn(vector< vector<int> > c){
	vector< vector<int> > toReturn = c;
	for(int i =0; i<c.size(); i++){
		toReturn[i][0] = c[i][c.size()-1];
	}

	for(int i =0; i<c.size(); i++){
		toReturn[i][c.size()-1] = c[i][0];
	}

	return toReturn;
}
