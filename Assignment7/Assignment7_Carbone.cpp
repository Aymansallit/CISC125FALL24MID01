#include <iostream>
using namespace std;

//Node structure for linked lists
struct Node {
    int d;
    Node* next;
};

//Defines stack class
class Stack{
    private:
        Node* top; //Pointer to top of stack
    public:
        Stack() : top(nullptr){} //Stack initialization constructor

        //Destructor; deallocates memory used by stack
        ~Stack(){
            while (top != nullptr) {
                Node* temp = top;
                top = top->next;
                delete temp;
            }
        }
    
    //Adds element to top of stack
    void push(int val){
        Node* newNode = new Node();
        newNode->d = val;
        newNode->next = top;
        top = newNode;
        cout << "Pushed " << val << " onto the stack." << endl;
    }

    //Remove and return top elements from stack
    void pop(){
        if (top == nullptr){
            cout << "Stack underflow! The stack is empty." << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        cout << "Popped " << temp->d << " From the stack." << endl;
        delete temp;
    }

    //Display top element without removal
    void peek(){
        if (top == nullptr){
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Top element: " << top->d << endl;
    }
    
    //Shows all elements from top to bottom
    void display(){
        if (top == nullptr) {
            cout << "Stack is empty!" << endl;
            return;
        }
        Node* current = top;
        cout << "Stack elements (top to bottom): ";
        while (current != nullptr){
            cout << current->d << " ";
            current = current->next;
        }
        cout << endl;
    }
};

//Defining Queue class
class Queue {
    private:
        Node* front; //pointer to front element of queue
        Node* rear; //pointer to rear element of queue
    public:
        Queue():front(nullptr), rear(nullptr){} //constructor that initializes an empty queue

        //Destructor to deallocate memory used by the queue
        ~Queue(){
            while (front != nullptr){
                Node* temp = front;
                front = front->next;
                delete temp;
            }
        }

    //Adds element to rear of queue
    void enqueue(int val){
        Node* newNode = new Node();
        newNode->d = val;
        newNode->next = nullptr;
        if (rear == nullptr){
            front = rear = newNode;
        }
        else{
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Enqueued " << val << " into the queue." << endl;
    }

    //Removes and returns front element from queue
    void dequeue(){
        if (front == nullptr){
            cout << "Queue underflow! The queue is empty." << endl;
            return;
        }
        Node* temp = front;
        front = front-> next;
        if(front == nullptr){
            rear = nullptr;   //if the queue becomes empty, reset rear pointer.
        }
        cout << "Dequeued " << temp->d << " from the queue." << endl;
        delete temp;
    }

    //display the front element without removal
    void peek(){
        if (front == nullptr){
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Front element: " << front->d << endl;
    }

    //show all elements from front to rear
    void display(){
        if (front == nullptr){
            cout << "Queue is empty!" << endl;
            return;
        }
        Node* current = front;
        cout << "Queue elements (front to rear): ";
        while (current != nullptr){
            cout << current->d << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main(){
    Stack stack;
    Queue queue;
    int choice, val;

    do{
        //displays menu
        cout << "\nMenu:\n";
        cout << "1. Push onto stack" << endl;
        cout << "2. Pop from stack" << endl;
        cout << "3. Peek stack" << endl;
        cout << "4. Display stack" << endl;
        cout << "5. Enqueue into queue" << endl;
        cout << "6. Dequeue from queue" << endl;
        cout << "7. Peek queue" << endl;
        cout << "8. Display queue" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: //push
                cout << "Enter value to push onto stack: ";
                cin >> val;
                stack.push(val);
                break;
            case 2: //pop
                stack.pop();
                break;
            case 3: //peek stack
                stack.peek();
                break;
            case 4: //display stack
                stack.display();
                break;
            case 5: //enqueue
                cout << "Enter value to enqueue into queue: ";
                cin >> val;
                queue.enqueue(val);
                break;
            case 6: //dequeue
                queue.dequeue();
                break;
            case 7: //peek queue
                queue.peek();
                break;
            case 8: //display queue
                queue.display();
                break;
            case 9:
                cout << "Exiting program" << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    }
    while(choice !=9);
    return 0;
};