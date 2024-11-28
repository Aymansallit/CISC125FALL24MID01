#include <iostream>
using namespace std;

//creates node class
class Node
{
  public:
    int data;
    Node* next;
  
  Node(int value)
  {
    data = value;
    next = nullptr;
  }
};

//creates linkedlist class to implement the functions
class LinkedList
{
  private:
    Node* head;
    
  public:
    LinkedList()
    {
      head = nullptr;
    }
    
    
  //function to insert a node at the beginning
  void insertAtBeginning(int value)
  {
    Node *newNode;
    newNode = new Node(value);
    newNode->data = value;
    newNode->next = head;
    head = newNode;
  }
  
  //function to insert a node at the end
  void insertAtEnd(int value)
  {
    Node* newNode;
    newNode = new Node(value);
    newNode->data = value;
    newNode->next = nullptr;
    
      if (head ==nullptr)
      {
        head = newNode;
      }
      
      else
      {
        Node* i = head;
        while (i->next != nullptr)
        {
          i = i->next;
        }
        i->next = newNode;
      }
  }
  
  //function to insert a node after a given value
  void insertAfter(int searchValue, int newValue)
  {
    Node* i = head;
    
    while (i != nullptr && i->data != searchValue)
    {
      i = i->next;
    }
    
    if (i != nullptr)
    {
      Node* newNode;
      newNode = new Node(newValue);
      newNode->next = i->next;
      i->next = newNode;
    }
  }
  
  //function to delete a node by its value
  void deleteByValue(int value)
  {
    if (head == nullptr)
    {
      cout << "List is empty." << endl;
    }
    
    if (head->data==value)
    {
      Node* i = head;
      head = head->next;
      delete i;
    }
    
    Node* i = head;
    while (i->next != nullptr && i->next->data != value)
    {
      i = i->next;  
    }
    
    if (i->next == nullptr)
    {
      cout << "Value not found in the list" << endl;
    }
    
    else
    {
      Node* removeNode;
      removeNode = i->next;
      i->next = removeNode->next;
      delete removeNode;
    }
  }
  
  //function to delete the first node
  void deleteFirst()
  {
    if (head == nullptr)
    {
      cout << "List is empty." << endl;
    }
    
    Node* i = head;
    head = head->next;
    delete i;
  }
  
  //function to delete the last node
  void deleteLast()
  {
    if (head == nullptr)
    {
      cout << "List is empty." << endl;
    }
    
    if (head->next == nullptr)
    {
      delete head;
      head = nullptr;
    }
    
    Node* i = head;
    while (i->next != nullptr && i->next->next != nullptr)
    {
      i = i->next;
    }
    
    delete i->next;
    i->next = nullptr;
  }
  
  //function to search for a node by its value and return its position
  int search(int value)
  {
    Node* i = head;
    
    int position = 1;
    
    while (i != nullptr)
    {
      if (i->data == value)
      {
        return position;
      }
      
      i = i->next;
      position++;
    }
    
    return -1;
  }
  
  
  //function to display all elements in order
  void display()
  {
    Node* i = head;
    
    while (i != nullptr)
    {
      cout << i->data << "->";
      i = i->next;
    }
    
    cout << "nullptr" << endl;
    
  }
  
  
  //function to reverse the List
  void reverse()
  {
    Node* i = head;
    Node* previousNode = nullptr;
    Node* nextNode = nullptr;
    
    while (i != nullptr)
    {
      nextNode = i->next;
      i->next = previousNode;
      previousNode = i;
      i = nextNode;
    }
    head = previousNode;
  }
  
};



int main() 
{
   LinkedList list;
   int choice, value, searchValue;
   
   do
   {
     cout << "\n\nSingle Linked List Operations:" << endl;
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
     
     cin >> choice;
     
     switch(choice)
     {
       case 1:
        cout << "Enter value to insert at the beginning: ";
        cin >> value;
        list.insertAtBeginning(value);
        break;
        
       case 2:
        cout << "Enter value to insert at the end: ";
        cin >> value;
        list.insertAtEnd(value);
        break;
       
       case 3:
        cout << "Enter the value to insert: ";
        cin >> value;
        cout << "Enter the value it will be inserted after: ";
        cin >> searchValue;
        list.insertAfter(value, searchValue);
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
        int position;
       
        cout << "Enter value to search: ";
        cin >> value;
        position = list.search(value);
        
         if (position == -1)
          {
            cout << "Value not found in the list." << endl;
          }
         
         else
          {
            cout << "Value is at position " << position << endl;
          }
          
          break;
          

        case 8:
         cout << "Current Linked List: ";
         list.display();
         break;
          
        case 9:
          list.reverse();
          cout << "Reversed List: ";
          list.display();
          
          list.reverse();
          break;
          
        case 10:
          cout << "Exiting program." << endl;
          break;
          
        default:
          cout << "Invalid choice. Try again." << endl;
     }
   }
   
   while (choice != 10);
   
   
   
   
   
   
   
   return 0;
   
   
};