#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    // Constructor
    LinkedList() : head(nullptr) {}

    // Destructor to prevent memory leaks
    ~LinkedList() {
        while (head != nullptr) {
            deleteFirst();
        }
    }

    // Insert at the beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Insert at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Insert after a given value
    void insertAfter(int searchValue, int newValue) {
        Node* temp = head;
        while (temp != nullptr && temp->data != searchValue) {
            temp = temp->next;
        }
        if (temp != nullptr) {
            Node* newNode = new Node(newValue);
            newNode->next = temp->next;
            temp->next = newNode;
        } else {
            cout << "Value " << searchValue << " not found in the list.\n";
        }
    }

    // Delete by value
    void deleteByValue(int value) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        if (head->data == value) {
            deleteFirst();
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != value) {
            temp = temp->next;
        }
        if (temp->next == nullptr) {
            cout << "Value " << value << " not found in the list.\n";
        } else {
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
    }

    // Delete the first node
    void deleteFirst() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Delete the last node
    void deleteLast() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    // Search for a node by value
    int search(int value) {
        Node* temp = head;
        int position = 0;
        while (temp != nullptr) {
            if (temp->data == value) {
                return position;
            }
            temp = temp->next;
            position++;
        }
        return -1; // Value not found
    }

    // Display the linked list
    void display() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr\n";
    }

    // Reverse the linked list
    void reverse() {
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;

        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }
};

// Main function to demonstrate the functionality
int main() {
    LinkedList list;
    int choice, value, searchValue;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert After Value\n";
        cout << "4. Delete by Value\n";
        cout << "5. Delete First Node\n";
        cout << "6. Delete Last Node\n";
        cout << "7. Search for a Value\n";
        cout << "8. Display List\n";
        cout << "9. Reverse List\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert at beginning: ";
            cin >> value;
            list.insertAtBeginning(value);
            break;

        case 2:
            cout << "Enter value to insert at end: ";
            cin >> value;
            list.insertAtEnd(value);
            break;

        case 3:
            cout << "Enter value to insert after: ";
            cin >> searchValue;
            cout << "Enter new value to insert: ";
            cin >> value;
            list.insertAfter(searchValue, value);
            break;

        case 4:
            cout << "Enter value to delete: ";
            cin >> value;
            list.deleteByValue(value);
            break;

        case 5:
            list.deleteFirst();
            break;

        case 6:
            list.deleteLast();
            break;

        case 7:
            cout << "Enter value to search: ";
            cin >> value;
            int position;
            position = list.search(value);
            if (position != -1) {
                cout << "Value found at position: " << position << endl;
            } else {
                cout << "Value not found in the list.\n";
            }
            break;

        case 8:
            list.display();
            break;

        case 9:
            list.reverse();
            cout << "List reversed.\n";
            break;

        case 10:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 10);

    return 0;
}
