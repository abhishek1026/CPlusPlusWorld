#include <iostream>
#include <string>
#include <cstdlib>
#include <array>
#include <fstream>
#include <cctype>
#include "pa3.h"

using namespace std;

//Implementation of methods defined in the header file.
//Constructor of Stack class.
Stack::Stack()
{
	top=-1; // initialize the top int variable to -1 to indicate nothing is in stack.
}
void Stack::push(string value)
{
	arr[++top]=value; // store the value
}

//This method pops the top element from the stack
string Stack::pop()
{
    if(!isEmpty()){
	return arr[top--];
    }
    else
    {
        cout << "Cannot pop element! Stack is empty!!!" << endl;
    }
return NULL;
}

//This method returns the top most element in the stack
string Stack::peek(){
    if(!isEmpty()){
    cout << arr[top] << endl;
	return arr[top];
    }
    else
    {
        cout << "Cannot peek at element! Stack is empty!!!" << endl;
    }
return NULL;
}

//This method checks if the stack is empty
bool Stack::isEmpty()
{
	return ((top+1) == 0);
}

int getInd(string* x, string a){
    for(int i=0;i<100;i++){
        if(x[i] == a)
            return i;
    }

    return -1;
}

//This method check if each character in a string is lowercase
bool isSmall(string x){

    int len = x.length();

    for(int i = 0;i<len;i++){
        if(!islower(x[i]))
            return false;
    }
    return true;
}

//This method check if each character in a string is uppercase
bool isLarge(string x){

    int len = x.length();

    for(int i = 0;i<len;i++){
        if(!isupper(x[i]))
            return false;
    }
    return true;
}

int main(){

    // Program asks user for file name and checks whether given input is valid.
    cout << "What is the file name containing the test code: ";

    string name;

    cin >> name;

    ifstream test1;

    test1.open(name.c_str());
    //If the given input does not match the file name needed, the program will terminate.
    if(test1.fail()){
        cerr << "Error opening or finding file!!!" << endl;
        exit(1);
    }


    ifstream test;

    test.open(name.c_str());

    int top = -1; //used to verify, after going through while loop, whether code is balanced (BEGIN,END).


    Stack errors; //stack that holds syntax errors
    
    while(!test.eof()){
        string chk = "";
        test >> chk;
       if(chk == "BEGIN"){
               top++;
           }
        else if (chk == "END"){
            top--;
        }
       }

       if(top>-1){
           errors.push("KEYWORDS NOT BALANCED(TOO MANY BEGIN)!");
       }


       if(top<-1){
           errors.push("KEYWORDS NOT BALANCED(TOO MANY END)!");
       }

    string scanthis = ""; //string that will be populated with every non whitespace character in input file.

    ifstream look; 

    look.open(name.c_str());

    /*
    The following stacks will contain the necessary entities that are expected to be displayed in output.
    */

    Stack key;

    Stack id;

    Stack op;

    Stack delim;

    Stack constants;



    while(!look.eof()){
        string add = "";
        look >> add;

        scanthis += add + " ";

    }

    string constant = "";

    string iden  = "";

    string deli = "";

    string ops = "";

    //The following for loop iterates through the scanthis string variable to detect
    //constants, keywords, identifiers, operators, and delimeters.

    for(int i = 0; i<scanthis.length(); i++){
        //checks whether given index of string is a digit, and peforms the appropriate next steps to identify constants.
        if(isdigit(scanthis[i])){
            if(!isdigit(scanthis[i+1])){
                constant += scanthis[i];
                if(getInd(constants.getArr(),constant) == -1){
                    constants.push(constant);
           }
                constant = "";
            }
            else
                {
                    constant += scanthis[i];
                }
        }
        //checks whether given index of string is alphanumeric, and performs necessary tasks to determine and detect identifiers and keywords.
        if(isalpha(scanthis[i])){
            if(!isalpha(scanthis[i+1])){
                iden += scanthis[i];
                if(getInd(id.getArr(),iden) == -1){
                    bool keep = true;
                    while(keep){
                        if(isSmall(iden)){
                        if(getInd(id.getArr(),iden) == -1){
                            id.push(iden);
                            keep = false;
                        }
                        else
                        {
                            keep = false;
                            continue;
                        }
                    }

                    else if(isLarge(iden) && (iden == "BEGIN" || iden == "FOR" || iden == "END")){
                        if(getInd(key.getArr(),iden) == -1){
                            key.push(iden);
                            keep = false;
                        }
                         else
                        {
                            keep = false;
                            continue;
                        }
                    }
                    else{
                        if(getInd(errors.getArr(),iden) == -1){
                            errors.push(iden);
                            keep = false;
                        }
                         else
                        {
                            keep = false;
                            continue;
                        }

                    }
                    }

           }
                iden = "";
            }
            else
                {
                    iden += scanthis[i];
                }
        }
        //checks whether the given index of string constitutes a delimeters, and performs appropriate tasks to store those delimeters.
        if(scanthis[i] == ',' || scanthis[i] == ';'){
            deli = scanthis[i];
            if(getInd(delim.getArr(),deli) == -1){
                delim.push(deli);
            }
            deli = "";
        }
        //next two major if blocks check whether the given index of string contains operators, and takes necessary steps to store those operators.
        if(scanthis[i] == '=' || scanthis[i] == '/' || scanthis[i] == '*' || scanthis[i] == '-')
        {
            ops = scanthis[i];
            if(getInd(op.getArr(),ops) == -1){
                op.push(ops);
            }
            ops = "";

        }
        if(scanthis[i] == '+'){
            ops = scanthis[i];
            if(scanthis[i+1] == '+'){
                ops += scanthis[i+1];
                if(getInd(op.getArr(),ops) == -1){
                    op.push(ops);
            }
            }
            else{
                if(getInd(op.getArr(),ops) == -1){
                    op.push(ops);
            }
        }
        ops = "";

    }
    }

//Outputs the maximum depth of given nested for loops in the text file.

    

    int cr = -1; //counter variable used to help find maximum depth

    int max = 0; //if cr ever exceeds max, max is reset to cr.

    while(!test1.eof()){
        string ck = "";
        test1 >> ck;
       if(ck == "FOR")
        cr++;
        else if (ck == "END")
        cr--;
       if(cr>max){
           max = cr;
       }
       }

       cout << "The maximum depth of the nested loops is: " << max << endl;


/* The following 6 blocks of code give the output pertaining to keywords, identifiers, constants,
   operators, delimeters, and syntax errors, in that order.
*/
    
    cout << "Keywords: ";

    while(!key.isEmpty()){
        if(key.getTop()>0)
        cout << key.pop() << ", ";
        else
        cout << key.pop() << endl;
    }

    cout << "Identifiers: ";

    while(!id.isEmpty()){
        if(id.getTop()>0)
        cout << id.pop() << ", ";
        else
        cout << id.pop() << endl;
    }


    cout << "Constants: ";

    while(!constants.isEmpty()){
        if(constants.getTop()>0)
        cout << constants.pop() << ", ";
        else
        cout << constants.pop() << endl;
    }

    cout << "Operators: ";

    while(!op.isEmpty()){
        if(op.getTop()>0)
        cout << op.pop() << " ";
        else
        cout << op.pop() << endl;
    }


    cout << "Delimeters: ";

    while(!delim.isEmpty()){
        if(delim.getTop()>0)
        cout << delim.pop() << " ";
        else
        cout << delim.pop() << endl;
    }



    cout << "Syntax Error(s): ";

    while(!errors.isEmpty()){
        if(errors.getTop()>0)
        cout << errors.pop() << ", ";
        else
        cout << errors.pop() << endl;
    }


    //terminate program and return 0, indicating success.

    return 0;
}