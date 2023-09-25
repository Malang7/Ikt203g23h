#include <iostream>
using namespace std;


class Stack
{
private:
    int *array;
    int top;
    int length;
public:
    Stack(int n)
    {
        top = -1;
        length = n;
        array = new int[n];
    };
    void push(int data)
    {
        if(IsFull())        //check if the stack is full
        {
            cout<<"The stack is full, not enogh space to a new element."<<endl;
        }
        else   //otherwise
        {
            top ++;             //increment the top with one
            array[top] = data;          //assigning the data to index [top]
        };
    };

    int pop()
    {
        int data;        //a placeholder for the element we want to remove

        if(IsEmpty())       //check if there is empty stack.
        {
            cout<<"The stack is empty, nothing to remove";
            return 0;
        }
        else
        {
            data = array[top];          //assigning the data which is stored in the array [top].
            top --;                     //decrease the top buy one.
            return data;              //return the data
        }
    };


    bool IsFull()
    {
        if(top == length-1)   //check the condition, to check if the top is equal to the lengths of the array
        {
            return true;
        }
        return false;
    };


    bool IsEmpty()
    {
        if(top == -1) //check if the top i equal to the -1
        {
            return true;
        }
        return false;
    };


    void Display()
    {
        if(IsEmpty())   // check if stack is empty
        {
            return;
        }
        int i = top;        // make a variable and assigning to the top
        while (i != -1)        // check the condition
        {
            cout<<array[i]<<endl; // printing out value of each index in the array
            i --;       // decrease the i
        }
    }
};

int main()
{
    Stack s(4);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(44);
    s.Display();
    s.pop();
    cout<<endl;
    s.Display();

    s.pop();
    cout<<endl;
    s.Display();

    s.pop();
    cout<<endl;
    s.Display();

    s.pop();
    cout<<endl;
    s.Display();


    s.pop();
    cout<<endl;
    s.Display();



    return 0;
}
