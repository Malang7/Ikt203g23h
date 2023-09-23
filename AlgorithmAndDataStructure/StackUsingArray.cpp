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
        array = new int(n);
    };
    void addRlement(int data)
    {
        if(IsFull())
        {
            cout<<"The stack is full, not enogh space to a new element.";
        }
        else if(IsEmpty())
        {
            top ++;
            array[top] = data;
        }
        else
        {
         top ++;
         array[top] = data;
        };
    };

    int removeElement()
    {
        int data = top;

        return 0;
    };

    bool IsFull()
    {
        if(top == length)
        {
            return true;
        }
    };


    bool IsEmpty()
    {
        if(top == -1)
        {
            return true;
        }
    };


    void Display()
    {
        if(IsEmpty())
        {
            return;
        }
        int data = top;
        while (data != -1)
        {
            cout<<array[data]<<endl;
            data --;
        }
    }
};



