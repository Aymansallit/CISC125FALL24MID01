#include <iostream>
using namespace std;

//Class that creates a node
class Node {
public:
    int data;
    Node *next;
    Node() {
        data = 0;
        next = NULL;
    }
};

//Class that creates a linked list
class LinkedList {
private:
    Node *head;

public:
    LinkedList() {
        head = NULL;
    }

    //function that inserts a value at the beginning of the list
    void insertAtBeginning(int value) {
        Node* N = new Node();
        N->data = value;
        N->next = head;
        head = N;
    }

    //function that inserts a value at the end of the list
    void insertAtEnd(int value) {
        Node* N = new Node();
        N->data = value;
        N->next = NULL;
        if (!head) {
            head = N;
        }
        Node* t = head;
        while (t->next != NULL) {
            t = t->next;
        }
        t->next = N;
    }

    //function that inserts a value after a specified value in the list
    void insertAfter(int searchValue, int newValue) {
        int end = 0;
        Node* t = head;
        Node* q;
        Node* N = new Node();
        if (t == NULL) {
            cout << "This list is empty." << endl;
        }
        while (end == 0) {
            if (t == NULL) {
                cout << "Value is not found" << endl;
                end = 1;
            }
            else if (t->data == searchValue) {
                q = t->next;
                N->next = q;
                t->next = N;
                N->data = newValue;
                end = 1;
            }
            else if (t->data != searchValue) {
                t = t->next;
            }
        }
    }


    //function that deletes a specified value from the list
    void deleteByValue(int searchValue) {
        int end = 0;
        Node* t = head;
        Node* q;
        if (t == NULL) {
            cout << "This list is empty." << endl;
        }
        while (end == 0) {
            if (t == NULL) {
                cout << "Value is not found" << endl;
                end = 1;
            }
            else if (t->next->data == searchValue) {
                q = t->next;
                t->next = q->next;
                delete q;
                end = 1;
            }
            else if (t->next->data != searchValue) {
                t = t->next;
            }
        }
    }

    //function that deletes the first value in a list
    void deleteFirst() {
        if (!head) {
            cout << "This list is empty." << endl;
        }
        Node* t = head;
        head = head->next;
        delete t;
    }

    //function that deletes the last value in a list
    void deleteLast() {
        if (!head) {
            cout << "This list is empty." << endl;
        }
        if (!head->next) {
            delete head;
            head = NULL;
        }
        Node* t = head;
        while (t->next->next) {
            t = t->next;
        }
        delete t->next;
        t->next = NULL;
    }

    //function that gives the position of a specified value in a list
    void search(int value) {
        int end = 0;
        int c = 1;
        if (!head) {
            cout << "This list is empty." << endl;
        }
        Node* t = head;
        while (end == 0) {
            if (t->next == NULL) {
                cout << "Value is not found" << endl;
                end = 1;
            }
            else if (t->data == value) {
                cout << "The value " << value << " is found at position " << c << "." << endl;
                end = 1;
            }
            else if (t->data != value) {
                t = t->next;
                c++;
            }
        }
    }

    //function that prints the list
    void display() {
        Node *t = head;
        if (t == NULL) {
            cout << "This list is empty." << endl;
            return;
        }
        else if (t != NULL) {
            cout << "Current linked list: ";
        }
        while (t != NULL) {
            cout << t->data << " -> ";
            t = t->next;
        }
        if (t == NULL) {
            cout << "NULL" << endl;
        }
    }

    //function that reverses the list perminately
    void reverse() {
        Node *t = head, *p = NULL, *q;
        if (t == NULL) {
            cout << "This list is empty." << endl;
        }
        while (t != NULL) {
            q = t->next;
            t->next = p;
            p = t;
            t = q;
        }
        head = p;
    }

    //function that deletes the list
    void deleteL() {
        Node* t = head;
        Node* next;
        while (t != NULL) {
            next = t->next;
            delete t;
            t = next;
        }
        head = NULL;
    }
};

//declarations
int go = 1, in1, in2, in3;

int main() {
    LinkedList list;

    //Prompt for user input
    while (go == 1 ) {
        cout << "\nSingle Linked List Operations:" << endl;
        cout << "1. Insert at Beginning" << endl;
        cout << "2. Insert at End" << endl;
        cout << "3. Insert After Value" << endl;
        cout << "4. Delete by Value" << endl;
        cout << "5. Delete First Node" << endl;
        cout << "6. Delete Last Node" << endl;
        cout << "7. Search for Value" << endl;
        cout << "8. Display List" << endl;
        cout << "9. Reverse List" << endl;
        cout << "10. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> in1;

        //Each case activates a function in LinkedList
        switch(in1) {
            case 1:
                cout << "Enter the value to insert at the beginning: ";
                cin >> in2;
                list.insertAtBeginning(in2);
                break;
            case 2:
                cout << "Enter the value to insert at the end: ";
                cin >> in2;
                list.insertAtEnd(in2);
                break;
            case 3:
                cout << "Enter the value to insert: ";
                cin >> in2;
                cout << "Enter after what value " << in2 << " should be inserted: ";
                cin >> in3;
                list.insertAfter(in3, in2);
                break;
            case 4:
                cout << "Enter the value to be deleted: ";
                cin >> in2;
                list.deleteByValue(in2);
                break;
            case 5:
                list.deleteFirst();
                break;
            case 6:
                list.deleteLast();
                break;
            case 7:
                cout << "Enter the value to search: ";
                cin >> in2;
                list.search(in2);
                break;
            case 8:
                list.display();
                break;
            case 9:
                list.reverse();
                break;
            case 10:
                cout << "Exiting Program.\n\n";
                list.deleteL();
                go = 0;
                break;
            default:
                cout << "Please enter a valid number...\n";
        }
    }
    return 0;
};
