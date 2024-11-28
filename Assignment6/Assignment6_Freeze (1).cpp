#include <iostream>

class Node{
    public: 
        int Data;
        Node* Next;
     // Node(int Data_Point, Node* Pointer): Data(Data_Point), Next(Pointer){}
};

class Linked_List{
    private:
        Node* Head_Node = new Node();
        Node* Tail_Node = new Node();
    public:
        Linked_List(){
            Head_Node->Next = Tail_Node;
            Head_Node->Data = 1234567;
            Tail_Node->Data = 1234567;
        };
        //insert new value at beginning of list
        void Insert_At_Beginning(int Value){
            if(Head_Node->Data == 1234567){
                Head_Node->Data = Value;
            }
            else{
            Node* New_Node = new Node();
            New_Node->Data = Value;
            New_Node->Next = Head_Node;
            Head_Node = New_Node;
            }
        };

        //insert new value at end of list
        void Insert_At_End(int Value){
            if (Tail_Node->Data == 1234567){
                Tail_Node->Data = Value;
            }
            else{
//while pointer isnt pointing to null, access the next node and check its address and keep proceeding
            Node* New_Node = new Node();
            New_Node->Data = Value;
            Tail_Node->Next = New_Node;
            New_Node->Next = NULL;
            Tail_Node = New_Node;
            }
            
        };

        //Allows to insert new value after search value
        void Insert_After(int Search_Value, int New_Value){
//call search func based on search value,
            Node* Temp_Node = Head_Node;
            int Position = 0;
            while (Temp_Node->Data!=Search_Value){
                if (Temp_Node == Tail_Node){
                    std::cout << "Value not found!" << std::endl; 
                    return;
                }
                Temp_Node = Temp_Node->Next;
                Position++;
              
            }
            //Temp_Node->Data == Search_Value;
            Node* New_Node = new Node();
            //Reassigning the address of Temp_Node->Next to New Node Next :)
            New_Node->Next = Temp_Node->Next;
            //Temp_Node->Next is now pointing to the new node :) :)
            Temp_Node->Next = New_Node;
            //New_Node->Data is now set to the new value :):):)
            New_Node->Data = New_Value;
        };             
            
        // Delete a node by the value entered
        void Delete_By_Value(int Value){
            int Position = Search(Value);
            if (Position = -1){
                return;
            }
            Node* Temp_Node = Head_Node;
            int Current_Position = 0;
            while (Current_Position!= Position-1){
                    Temp_Node = Temp_Node->Next;
                    Position++;
            }
            //delete from existence
            Temp_Node->Next = Temp_Node->Next->Next;
            Temp_Node = Temp_Node->Next;
            delete Temp_Node;
        }

       //Deletes first item in LL
        void Delete_First(){
           // same as insert first, head pointing to second element
            Node* New_Node = Head_Node;
            Head_Node = Head_Node->Next;
            delete New_Node;
        }

        //Deletes last item in LL
        void Delete_Last(){
            //same as insert last but with tail
             Node* New_Node = new Node();
             Node* Prev_Node = new Node();
             New_Node = Head_Node;
                while(New_Node!= Tail_Node){
                    Prev_Node = New_Node;
                    New_Node = New_Node->Next;
                }
            Prev_Node->Next = NULL;
            delete New_Node; //byeeeeeeeeee
            Tail_Node = Prev_Node;
        }

        //pull a value by search
         int Search(int Value){
            Node* Temp_Node = Head_Node;
            int Position = 0;
            while (Temp_Node!=Tail_Node){
                if (Temp_Node->Data ==Value){
                    return Position;
                }
                    Temp_Node = Temp_Node->Next;
                    Position++;
            }
            if (Temp_Node->Data ==Value){
                    return Position;
            }
            else{
                return -1;
            }
        };

        //Displays the LL
        void Display(){
        Node* Temp_Node = Head_Node;
            if(Head_Node->Data == 1234567 && Tail_Node->Data == 1234567){
                    std::cout << "Current Linked List: List is empty." << std::endl;
                    return;
            }
            std::cout << "Current Linked List: " ;
            while (Temp_Node!=Tail_Node){
                std::cout << Temp_Node->Data << "->";
                Temp_Node = Temp_Node->Next;
            }
            std::cout << Temp_Node->Data << "-> NULL" << std::endl;
        }

        //reverses the LL
        void Reverse(){
           Node* Temp_Tail = new Node();
           Node* Head_Holder = new Node();
           Node* Deleter_Node = new Node();
           Head_Holder = Head_Node;
           Head_Node = Temp_Tail;
           while(Head_Holder != Tail_Node){
            Insert_At_Beginning(Head_Holder->Data);
            Deleter_Node = Head_Holder;
            Head_Holder = Head_Holder->Next;
            delete Deleter_Node;
           }
           Insert_At_Beginning(Tail_Node->Data);
           Tail_Node = Temp_Tail;
           Delete_Last();

        };
                //snake, tail is pointing to temp node _> next
};



int main(){
    Linked_List* Link_List = new Linked_List();
    int Choice, Value, Search_Value;
    do {
        std::cout << "Single Linked List Operations: " << std::endl;
        std::cout << "1. Insert at Beginning" << std::endl;
        std::cout << "2. Insert at End" << std::endl;
        std::cout << "3. Insert After a Value" << std::endl;
        std::cout << "4. Delete by Value" << std::endl;
        std::cout << "5. Delete First Node" << std::endl;
        std::cout << "6. Delete Last Node" << std::endl;
        std::cout << "7. Search for Value" << std::endl;
        std::cout << "8. Display List" << std::endl;
        std::cout << "9. Reverse List" << std::endl;
        std::cout << "10. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> Choice;

        switch (Choice) {
        case 1:
            std::cout << "Enter value to insert at the beginning: ";
            std::cin >> Value;
            Link_List->Insert_At_Beginning(Value);
            break;
        case 2:
            std::cout << "Enter value to insert at the end: ";
            std::cin >> Value;
            Link_List->Insert_At_End(Value);
            break;
        case 3:
            std::cout << "Enter value to search and value to insert after it: ";
            std::cin >> Search_Value >> Value;
            Link_List->Insert_After(Search_Value, Value);
            break;
        case 4:
            std::cout << "Enter value to delete: ";
            std::cin >> Value;
            Link_List->Delete_By_Value(Value);
            break;
        case 5:
            Link_List->Delete_First();
            break;
        case 6:
            Link_List->Delete_Last();
            break;
        case 7:
            std::cout << "Enter value to search: ";
            std::cin >> Value;
            int pos;
            pos = Link_List->Search(Value);
            if (pos == -1)
                std::cout << "Value not found!" << std::endl;
            else
                std::cout << "Value found at position: " << pos << std::endl;
            break;
        case 8:
            Link_List->Display();
            break;
        case 9:
            Link_List->Reverse();
            std::cout << "List reversed!" << std::endl;
            Link_List->Display();
            break;
        case 10:
            std::cout << "Exiting" << std::endl;
            break;
        default:
            std::cout << "Invalid choice! Please try again." << std::endl;
    }

} while (Choice != (10));

return 0;
}
