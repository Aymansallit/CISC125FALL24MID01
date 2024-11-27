#include <iostream>
using namespace std;

// First we add a node for the class.
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Second is now the LinkedList class.
class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // InsertAtBeginning inserted for the node.
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Insert a node at the end.
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Insert a node after a given value is provided.
    void insertAfter(int searchValue, int newValue) {
        Node* temp = head;
        while (temp && temp->data != searchValue) {
            temp = temp->next;
        }
        if (temp) {
            Node* newNode = new Node(newValue);
            newNode->next = temp->next;
            temp->next = newNode;
        } else {
            cout << "Value " << searchValue << " not found in the list.\n";
        }
    }

    // DeleteByValue is added for the option.
    void deleteByValue(int value) {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->data != value) {
            temp = temp->next;
        }
        if (temp->next) {
            Node* nodeToDelete = temp->next;
            temp->next = nodeToDelete->next;
            delete nodeToDelete;
        } else {
            cout << "Value " << value << " not found in the list.\n";
        }
    }

    // Delete the first node with that.
    void deleteFirst() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteLast() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    // Search node option is then added.
    int search(int value) {
        Node* temp = head;
        int position = 1;
        while (temp) {
            if (temp->data == value) {
                return position;
            }
            temp = temp->next;
            position++;
        }
        return -1; // Value not found
    }

    // All elements are displayed for the linked list, then reversed.
    void display() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;

        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
};

// Now we can code the main menu for this program, as the user can enter a value to ask which one they need.
int main() {
    LinkedList list;
    int choice, value, searchValue;

    do {
        cout << "\nMenu:\n"
             << "1. Insert at Beginning\n"
             << "2. Insert at End\n"
             << "3. Insert After a Value\n"
             << "4. Delete by Value\n"
             << "5. Delete First Node\n"
             << "6. Delete Last Node\n"
             << "7. Search for a Value\n"
             << "8. Display List\n"
             << "9. Reverse List\n"
             << "0. Exit\n"
             << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            list.insertAtBeginning(value);
            break;
        case 2:
            cout << "Enter value to insert: ";
            cin >> value;
            list.insertAtEnd(value);
            break;
        case 3:
            cout << "Enter value to insert after: ";
            cin >> searchValue;
            cout << "Enter value to insert: ";
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
            if (position == -1) {
                cout << "Value not found in the list.\n";
            } else {
                cout << "Value found at position: " << position << "\n";
            }
            break;
        case 8:
            list.display();
            break;
        case 9:
            list.reverse();
            cout << "List reversed.\n";
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
