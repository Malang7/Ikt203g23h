#include <iostream>
using namespace std;


struct Node
{
    int data;
    Node *next;
};

class Stack
{
private:
    Node *top;  //declare a pointer which it will point to first node in the singel linked list

public:
    Stack()
    {
        top = nullptr;
    }

    bool IsEmpty()   //check if the stack is empty
    {
        if(top == nullptr)
        {
            return true;
        }
        return false;
    }

    void push(int data)                 //pushData data into the stack
    {
        Node *node = new Node;          //allocate memory for the node
        node-> data = data;         //assigning data into the linked list

        if(IsEmpty())           //check if the stack is empty
        {
            node->next = nullptr;       //update the pointer of the node
            top = node;             //assigning the address of the node into the top pointer
        }
        else
        {
            node->next = top;    //update the pointer of the node, which it will point to the front node
            top = node;          //update the top, with assigning the  node to the top
        }
    }

    int  popData()   //removing data from the stack
    {
        Node *remove = top;             //create a node which it will point top
        int data;
        if(IsEmpty())       //check if the stack is empty
        {
            throw runtime_error("Stack underflow");  //Or another suitable exception
        }
        else if(top->next == nullptr)    //if there is just one node
        {
            data = remove->data;
            top = nullptr;              //update the top
            delete remove;                  //removing the data and node from the stack
            return data;
        }
        else
        {
            data =  remove->data;
            top  = top->next;
            delete remove;
            return data;
        }
    }

    void displayData()
    {
        Node *stack = top;
        if(IsEmpty())
        {
            return;
        }
        else
        {
            while(stack != nullptr)
            {
                cout<<stack->data;
                stack = stack->next;
            }
        }
    }
};


int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    s.displayData();
    cout<<endl;

    s.popData();
    s.displayData();
    cout<<endl;

    s.popData();
    s.displayData();
    cout<<endl;

    s.popData();
    s.displayData();
    cout<<endl;

    s.popData();
    s.displayData();
    cout<<endl;

    s.popData();
    s.displayData();
    cout<<endl;

    s.popData();
    s.displayData();

    s.popData();
    s.displayData();




}