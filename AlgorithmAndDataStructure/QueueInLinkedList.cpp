#include <iostream>
using namespace std;


struct Node
{
    int data;
    Node *next;
};

class Queue
{
private:
    Node *front; //point to the front of the linklist, we removing should happen from the front
    Node *rear;
public:
    Queue()
    {
        front = nullptr;
        rear = nullptr;
    }

    void EnQueue(int data)
    {
        //the insertion happen from the rear.

        Node *node = new Node; //allocate memory for the linklist
        node->data = data; // Initialize value into our node

        if(IsEmpty())  //check if there is empty node
        {
            node ->next = nullptr;
            rear = node; //both the front and rear point to the node, because there is no other node.
            front = node;
            return ;
        }
        else
        {
            // this was wrong,
             node->next = nullptr; //the new node become the rear, and it should to store the address of node of the front of him
             rear->next = node;
            rear = node; //update the rear to the new node.
        }
    };

    int DeQueue()  //to remove the node from the Dequeue, it should be remove from the front of the queue, first in first out.
    {
        Node *node ;  //allocate memory
        node = front;  // Assigning the address of the front node.

        int data = node->data; // create a variable and store the data

        if(IsEmpty()) //Check if the Queue is empty.
        {
            cout<<"The queue is empty nothing to remove.";
            return 0;
        }
        else if(rear == front) // if there is one element in the queue
        {
            rear = nullptr;      //both the rear and front become to nullptr
            front = nullptr;

            delete node; //remove the node and than, return the data
            return data;
        }
        else
        {
            front = front->next;
            delete node;
            return data;
        }

    };

    bool IsEmpty()
    {
      if(rear == nullptr)
      {
          return true;
      }
      else
      {
          return false;
      }
    };

    void Peek()
    {
        Node *node = front;

        if(IsEmpty()) //if the list is empty then return.
        {
            cout<<"The Queue is empty."<<endl;
            return;
        };

        while (node) {
            cout << node->data << endl;
            node = node->next;
        }//can not understand the logic behind  of this, i should think more about this.
    };


};

int main()
{
    Queue q;
    q.EnQueue(1);
    q.EnQueue(2);
    q.EnQueue(3);
    q.EnQueue(4);
    q.EnQueue(5);
    q.EnQueue(6);

    q.Peek();
    cout<<"the number is: "<<q.DeQueue()<<" delete"<<endl;
    q.Peek();



    return 0;
}