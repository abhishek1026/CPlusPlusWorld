#include <iostream>
#include <cmath>

using namespace std;

int factorialFinder(int x){

	int result = x;

	while(x>1){

		result*=(x-1);

		x--;

	}
	return result;
}

int main(){

int parameter;

cout<<"Enter a positive integer greater than one: ";

cin>>parameter;

cout<<factorialFinder(parameter)<< endl;

return 0;
}
