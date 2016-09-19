#include <iostream>
#include <cmath>

using namespace std;

bool continueRunning = true;

int doubleUntil1000(int x){
	int power = 1;
	while(true){

		int check = pow(2,power)*x;

		if(check>1000)
			return pow(2,power-1)*x;
		else if(check == 1000)
			return check;
		else
			power++;
	}
}
int main(){
	do{
		int chosenOne;

			cout << "Enter a positive integer less than 1000 to begin doubling: ";

			cin >> chosenOne;

			bool continueRunning = true;

			if(chosenOne>=1000 || chosenOne<=0){
				do{
					cout << "Please enter an integer from the expected range(1-999): ";
					cin >> chosenOne;

					if(chosenOne>=1 && chosenOne<=999){
						continueRunning = false;
					}
				}while(continueRunning);
			}

			int result = doubleUntil1000(chosenOne);

			cout << "The final number before crossing 1000 is: " << result << endl;
			bool keep = true;
			do{
			cout <<"Play again?(y/n) ";

			char response;

			cin>>response;

			if(response!= 'y' && response != 'n')
				continue;
			else if (response == 'n'){
				keep = false;
				::continueRunning = false;
			}
			else
			{
				keep = false;
			}
			}while(keep);
	}while(::continueRunning);

	cout << "Thanks for your time!" << endl;

	return 0;
}
