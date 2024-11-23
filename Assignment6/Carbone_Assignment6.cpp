#include <iostream>

using namespace std;

//Node definition
class Node {
    public:
        int d; //stores value
        Node* next; //pointer to next node

        //Initializes code
        Node(int val){
            d = val;
            next = nullptr;
        }
};

//LinkedList definition
class LinkedList{
    private:
        Node* head; //head pointer to first node
    public:
    
    //initializes the list
    LinkedList(){ 
        head = nullptr;
    }
    
    //destuctor; deletes all nodes to prevent memory leakage.
    ~LinkedList(){ 
        Node* current = head;
        Node* nextNode;
        while(current != nullptr){
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
    
    //inserts a node at the beginning
    void insertAtBeginning(int val){
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }
    
    //inserts a node at the end
    void insertAtEnd(int val){
        Node* newNode = new Node(val);
        if (head == nullptr){
            head = newNode;
        }
        else{
            Node* temp = head;
            while (temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    
    //inserts a node after a given value
    void insertAfter(int sVal, int nVal) {
        Node* temp = head;
        while (temp != nullptr && temp ->d != sVal){
            temp = temp->next;
        }
        if (temp != nullptr){
            Node* newNode = new Node(nVal);
            newNode->next = temp->next;
            temp->next = newNode;
        }
        else{
            cout << "Value " << sVal << " not found." << endl;
        }
    }
    
    //deletes a node by value
    void deleteByValue(int val){
        if (head == nullptr){
            cout << "List is empty!" << endl;
            return;
        }
        if (head->d==val){
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr && temp -> next -> d != val){
            temp = temp -> next;
        }
        if (temp -> next == nullptr){
            cout << "Value " << val << " not found." << endl;
        }
        else {
            Node* delNode = temp -> next;
            temp -> next = temp -> next->next;
            delete delNode;
        }
    }
    
    //deletes first node
    void deleteFirst(){
        if (head == nullptr){
            cout << "List empty" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    
    //deletes last node
    void deleteLast(){
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr && temp->next->next != nullptr){
            temp = temp -> next;
        }
        delete temp->next;
        temp->next = nullptr;
    }
    
    //search for a node by its value, then returns position
    int search(int val){
        Node* temp = head;
        int pos = 1;
        while (temp != nullptr){
            if (temp->d == val){
                return pos;
            }
            temp = temp->next;
            pos++;
        }
        return -1; //not found
    }
    
    //display all elements of linked list
    void display() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        while(temp != nullptr){
            cout << temp->d << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }
    //reverses the linked list
    void reverse(){
        Node* prev = nullptr;
        Node* current = head;
        Node* nextNode = nullptr;
        while (current != nullptr){
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        head = prev;
    }
};

int main() {
    LinkedList list;
    int choice, val, pos;

    do {
        cout << "\n1.  Insert at beginning." << endl;
        cout << "2.  Insert at end." << endl;
        cout << "3.  Insert after a value." << endl;
        cout << "4.  Delete by value." << endl;
        cout << "5.  Delete the first node." << endl;
        cout << "6.  Delete the last node." << endl;
        cout << "7.  Search for a value." << endl;
        cout << "8.  Display list." << endl;
        cout << "9.  Reverse list." << endl;
        cout << "10. Exit" << endl;
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                list.insertAtBeginning(val);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> val;
                list.insertAtEnd(val);
                break;
            case 3:
                cout << "Enter a value to search after: ";
                cin >> val;
                cout << "Enter a new value: ";
                cin >> pos;
                list.insertAfter(val, pos);
                break;
            case 4:
                cout << "Enter value to delete: ";
                cin >> val;
                list.deleteByValue(val);
                break;
            case 5:
                list.deleteFirst();
                break;
            case 6:
                list.deleteLast();
                break;
            case 7:
                cout << "Enter value to search: ";
                cin >> val;
                pos = list.search(val);
                if(pos == -1){
                    cout << "Value not found." << endl;
                }
                else{
                    cout << "Value found at position " << pos << endl;
                }
                break;
            case 8:
                list.display();
                break;
            case 9:
                list.reverse();
                cout << "List reversed." << endl;
                break;
            case 10:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    }
    while (choice != 10);
    return 0;
};