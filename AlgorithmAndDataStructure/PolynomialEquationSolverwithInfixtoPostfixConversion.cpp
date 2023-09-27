#include <iostream>
using namespace std;



//We element the stack using single linked list, we have to declare a struct which is consist of a pointer
//which it will store the address of the next node, and a variable data, which it will store the data from the user
struct Node
{
    char data;
    Node *next;
};

class Stack
{
private:
    Node *top;  //declare a pointer, which it will point to the top of the stack

public:
    Stack()
    {
        top = nullptr;
    }
    //This function will check if the stack is empty, if the top is null than will return true, otherwise the function return false
    bool IsEmpty()
    {
        if(top == nullptr)
        {
            return true;
        }
        return false;
    }


    //This function will push element into the stack, if the stack is empty we push element on to the stack
    //If there is an element in stack than we push the element on to the top the previous element
    void pushData(char data)
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


    //This function will remove elements from the stack, if there is no element on the stack, the function will execute an error
    //Otherwise it will remove the element from the stack
    char  popData()
    {
        Node *remove = top;             //Create a node which it will point top
        char data;
        if(IsEmpty())       //Check if the stack is empty
        {
            throw runtime_error("Stack is empty");  //Or another suitable exception
        }
        else if(top->next == nullptr)    //If there is just one node
        {
            data = remove->data;
            top = nullptr;              //Update the pointer
            delete remove;               //Removing the node, and return the data
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



    //This function will print out the from the stack
    void displayData()
    {
        Node *stack = top;
        if(IsEmpty()) //Checking if its empty
        {
            throw runtime_error("stack is empty");
        }
        else
        {
            while(stack != nullptr) //Otherwise the loop begin and it will continue until the stack is empty
            {
                cout<<stack->data<<endl;  //print out data
                stack = stack->next; //Update the pointer
            }
        }
    }


    //This function will return the last element in the stack
    char topOfTheStack()
    {
        //Check if the top is null, if its true, it will execute an error
      if (top == nullptr)
      {
          throw runtime_error("stack underflow!");
      }
      else
      {
          return top->data; //Otherwise it will return the element
      }

    }
};





int priority(char c) //This function determine the priority of each character and returns its value
{
    if (c == '(' )   //( have the lowest priority
        return 1;
    else if (c == '+' || c == '-')
        return 2;
    else if (c == '/' || c == '*')
        return 3;
    else if (c == '^')  //^have the highest priority
        return 4;
    else
        return 0 ;   //As default the function will return  0
}

void  handleOperands(char operands, string& postfix) //handling the operands
{
    postfix += operands; //add each operand into the postfix
}


//This function will handle the operator, which it will take there argument, the operator, the reference of the string which it will make able to work directly with the original data
//and not the the copy of it, and the last argument is reference of the postfix
void handelOperator(char Operator, Stack &s, string &postfix)
{
    //we looping through the list and check if the list is not empty. and  if the  priority  of the operator is  grater and  equal to the priority of the
    //of the stack than it will add the element which is stored on top of the stack, ann than it will remove it from the stack.
    while(s.IsEmpty() == false && priority(Operator) <= priority(s.topOfTheStack()))
    {
        postfix += s.topOfTheStack();
        s.popData();
    };
    s.pushData(Operator); //add the element into the stack

}






//this function will convert infix expression  to postfix, this function take string as argument and it will return the postfix expression.
string  InfixInToThePostfix(string infix)
{
    Stack s;  //declare an instance of the Stack class named 's'
    int length = infix.length();   //calculate the length of  prefix

    int i = 0;
    char c;  //placeholder for  each character, it will be updated each time i increases
    string postfix; //it will store the postfix elements

    while (i<length) //this loop will continue until the i is less than length of infix
    {
        c = infix[i];
        if (isalnum(c) || c=='x')
        {
            handleOperands(c,postfix);
        }
        else if(c == '+' || c == '-' || c == '^' || c == '/' || c == '*')
        {
            handelOperator(c, s, postfix);
        }
        i++;
    }
    while(s.IsEmpty() == false)  //this while loop have to run until the stack is empty
    {
        postfix += s.topOfTheStack();   //adding the reminder into the postfix
        s.popData();        //remove the element from the stack
    }

    s.displayData();

    return postfix;

}




int main ()
{
    cout << InfixInToThePostfix("a+b-");


    Stack s;


    cout<<endl;

    s.pushData('m');
    s.pushData('c');
    s.pushData('f');
    s.pushData('a');
    s.pushData('t');
    s.pushData('y');
    s.pushData('l');
    s.pushData('p');
    s.displayData();

    s.popData();
    cout<<endl;
    s.displayData();

    s.popData();
    cout<<endl;
    s.displayData();

    s.popData();
    cout<<endl;
    s.displayData();


    s.popData();
    cout<<endl;
    s.displayData();

    s.popData();
    cout<<endl;
    s.displayData();








    return 0;
}

