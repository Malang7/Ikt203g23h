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
    Node *top;

public:
    Stack()
    {
        top = nullptr;
    }

    bool IsEmpty()
    {
        if(top == nullptr)
        {
            return true;
        }
        return false;
    }

    void push(int data)
    {
        Node *node = new Node;
        node-> data = data;

        if(IsEmpty())
        {
            node->next = nullptr;
            top = node;
        }
        else
        {
            node->next = top;
            top = node;
        }
    }

    int  pop()
    {
        Node *remove = top;
        int data;
        if(IsEmpty())
        {
            throw runtime_error("Stack underflow");  // Or another suitable exception
        }
        else if(top->next == nullptr)
        {
            data = remove->data;
            top = nullptr;
            delete remove;
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

    void display()
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

    s.display();
    cout<<endl;

    s.pop();
    s.display();
    cout<<endl;

    s.pop();
    s.display();
    cout<<endl;

    s.pop();
    s.display();
    cout<<endl;

    s.pop();
    s.display();
    cout<<endl;

    s.pop();
    s.display();
    cout<<endl;

    s.pop();
    s.display();

    s.pop();
    s.display();




}