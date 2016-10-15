#include <iostream>
using namespace std;

// Node class
class Node {
    int data;
    Node *next;

  public:
    Node() {};
    void SetData(int aData) { data = aData; };
    void SetNext(Node* aNext) { next = aNext; };
    int Data() { return data; };
    Node* Next() { return next; };
};

// List class
class List {
    Node *head;
  public:
    List() { head = NULL; };
    void Print();
    bool Append(int data);
    bool Delete(int data);
};

/**
 * Print the contents of the list
 */
void List::Print() {

    // Temp pointer
    Node *tmp = head;

    // No nodes
    if ( tmp == NULL ) {
    cout << "EMPTY" << endl;
    return;
    }

    // One node in the list
    if ( tmp->Next() == NULL ) {
    cout << tmp->Data();
    cout << " --> ";
    cout << "NULL" << endl;
    }
    else {
    // Parse and print the list
    do {
        cout << tmp->Data();
        cout << " --> ";
        tmp = tmp->Next();
    }
    while ( tmp != NULL );

    cout << "NULL" << endl;
    }
}

/**
 * Append a node to the linked list
 */
bool List::Append(int data) {

    // Create a new node
    Node* newNode = new Node();
    newNode->SetData(data);
    newNode->SetNext(NULL);

    // Create a temp pointer
    Node *tmp = head;

    if ( tmp != NULL ) {
    // Nodes already present in the list
    // Parse to end of list
    while ( tmp->Next() != NULL ) {
        tmp = tmp->Next();
    }

    // Point the last node to the new node
    tmp->SetNext(newNode);
    }
    else {
    // First node in the list
    head = newNode;
    }
    return true;
}

/**
 * Delete a node from the list
 */
bool List::Delete(int data) {

    // Create a temp pointer
    Node *tmp = head;

    // No nodes
    if ( tmp == NULL )
    return false;

    bool isMatch = false;

    // only one node present in the list
    if ( tmp->Next() == NULL ) {
        if(tmp->Data() == data){
        head = NULL;
        delete tmp;
        return true;
        }
        return false;
    }
    else {
    // Parse thru the nodes
    Node *prev;
    int count = 0;
    do {
        if ( tmp->Data() == data ) {
            if(count == 0)
                prev = head;
            isMatch = true;
            break;
        }
        prev = tmp;
        tmp = tmp->Next();
        count++;
    } while ( tmp != NULL );

    // Adjust the pointers
    if(isMatch){
        if(count == 0)
        head = tmp->Next();
    else    
        prev->SetNext(tmp->Next());
    // Delete the current node
    delete tmp;
    
    }
    return isMatch;
    }
}

int main()
{
    // New list
    List list;

    cout << "Welcome to the Linked List Demo!" << endl;

    int choice;

    do{
        
        cout << "Please type an int from 1-4 for the following choices: " << endl;

        cout << "(1) Add to list\n(2) Delete from list\n(3) View Linked List\n(4) Exit\n";

        cin >> choice;

        switch(choice){
            int subchoice;
            case 1: cout << "Number to add?: ";
                    cin >> subchoice;
                    if(list.Append(subchoice))
                        cout << "Success! " << subchoice << " added to LL!" << endl;
                        break;
            case 2: cout << "Number to delete?: ";
                    cin >> subchoice;
                    if(list.Delete(subchoice))
                        cout << "Success! First instance of " << subchoice << " removed from LL!" << endl;
                        else
                            cout << "Please try again! Either list is empty or entered value has no matches in LL!" << endl;
                        break;
            case 3: list.Print();
  
        }

    }while(choice != 4);

    cout << "Thanks for playing!" << endl;
    /*
    list.Print();

    // Append nodes to the list
    list.Append(-2);
    list.Print();
    list.Append(-1);
    list.Print();
    list.Append(0);
    list.Print();
    list.Append(1);
    list.Print();
    list.Append(2);
    list.Print();
    list.Append(3);
    list.Print();

    // Delete nodes from the list
    list.Delete(0);
    list.Print();
    list.Delete(-1);
    list.Print();
    list.Delete(1);
    list.Print();
    list.Delete(-2);
    list.Print();
    list.Delete(-2);
    list.Print();
    list.Delete(2);
    list.Print();
    list.Delete(3);
    list.Print();

    list.Append(26);
    list.Print();
    list.Delete(26);
    list.Print();
    */
}