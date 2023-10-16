#include <iostream>
#include <string>

using namespace std;
/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order,
 and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
*/




template<typename T>  
struct Node  // Declare a node
{
    T data; // Data to be stored in the node
    Node<T> *next = nullptr; // Pointer to the next node
};

template<typename T>
class SingleLinkedList
{
private:
    Node<T>* head; // Head pointer which points to the first node in the list 

public:
    SingleLinkedList()
    {
        head = nullptr; // Constructor to initialize the head as nullptr
    }

    void addList(T data)
    {
        Node<T>* node = new Node<T>; // Create a new node
        node->data = data; // Assign data to the node

        Node<T>* tmp = head; // Temporary node pointer to traverse the list

        if(head == nullptr) // Check if the list is empty
        {
            head = node; // Set the new node as the head if the list is empty
        }
        else
        {
            while (tmp->next != nullptr) // Traverse to the end of the list
            {
                tmp = tmp->next; // Move to the next node
            }
            tmp->next = node; // Add the new node at the end of the list
        }
    }

    
};





template<typename T>
class solutions
{
public: 
    SingleLinkedList<T>* addTwonumbers(SingleLinkedList<T>* input1, SingleLinkedList<T>* input2)
    {
        SingleLinkedList<T>* storage = new SingleLinkedList<T>();
        Node<T>* results = storage->head; 

        Node<T>* list1 = input1->head; 
        Node<T>* list2 = input2->head; 

        int sum; 
        int curry = 0; 

        while(list1 && list2)         
        {
            sum = list1->data + list2->data + curry;  
            curry = sum / 10;  
            results->data = sum % 10; 
            results = results->next;   
            list1 = list1->next; 
            list2 = list2->next; 
        }
        
        while(list2 != nullptr) 
        {
            sum = list2->data + curry; 
            curry = sum / 10; 
            results->data = sum % 10;  
            results = results->next;   
            list2 = list2->next; 
        }

        while(list1 != nullptr) 
        {
            sum = list1->data + curry; 
            curry = sum / 10; 
            results->data = sum % 10;
            results = results->next;  
            list1 = list1->next; 
        }
         
        return storage; 
    }
};




template<typename T>

void Display(SingleLinkedList<T> list)
    {
         // Start from the head of the list
        while(list != nullptr) // Iterate until the end of the list is reached
        {
            cout << list->data << " "; // Print the data in the current node
            node = list->next; // Move to the next node
        }
    }





int main()
{
    SingleLinkedList<int>* li = new SingleLinkedList<int>(); // Create an instance of SingleLinkedList with int data type
    li->addList(12); // Add elements to the list
    li->addList(13);
    li->addList(14);
    li->addList(15);
   // li.Display(); // Display the elements in the list
    
    SingleLinkedList<int>* li2 = new SingleLinkedList<int>(); // Create an instance of SingleLinkedList with int data type
    li2->addList(1);
    li2->addList(2);
    li2->addList(3);

    solutions<int> s; 

    
     SingleLinkedList<int>* result = s.addTwonumbers(li, li2);
    



    return 0; // Return 0 to indicate successful execution
}
