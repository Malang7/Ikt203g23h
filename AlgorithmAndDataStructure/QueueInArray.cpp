#include <iostream>
using namespace std;

class Queue
{
private:            //declare some value to the hold the rear , front to for queue
    int front;
    int rear;
    int size;        //we have to declare the size of the array
    int *array;     //create a pointer to hold the address of the array, becuase we have dynamic memory allocation.

public:
    Queue(int n)  //declare a constructure to inilize the value for out variables and array.
    {
        front = -1;
        rear = -1;
        array = new int(n);
        size = n;
    };


    void enqueue(int data) // with help of this function we insert element into our queue
    {
        if(ISFull()) //call the full function to check if the array is ISFull
        {
            return;
        }
        if(ISEmpty()) //call the empty function to check if the array is empty, if there is ISEmpty array, it should
        {
            rear = 0,
            front = 0;
            array[rear] = data;  // insert the data from the rear, and return.
            return;
        }
        else      //otherwise
        {
            rear ++;  //it have to increment the rear, to move to the next index, and than
            array[rear] = data; //it have to insert the data to the array
        }
    };




    int dequeue()
    {
        int remove;  //create a variable to holde the number we want to remove.
        if(ISEmpty()) //check ff there is a ISEmpty queue.
        {
            cout<<"nothing to remove the array is ISEmpty.";
            return 0;
        }
        if(rear == front) //there is a senario, where we have remove alle the element from the qqueu, and we hvae there is no more element in the qeue, thats way we should set both the rear and the front to -1.
        {
            rear = -1;
            front = -1;
            return 0;
        }
        else
        {
            remove = array[front];  //store the value of the index which we want to remove it from the qeueue.
            front++; // after we removed the element from the queue we have to move the front to the next index.
        };
        cout<<"you have removed number "<< remove<<" from the queue."<<endl;
        return remove; //return the value of the index which it was delete form the qeueu.
    };


    bool ISFull() //checking if the queue is ISFull
    {
        //if the rease i equal to the size of array, which is size -1, than the qaueu is ISFull.
        if(rear == size-1)
        {
            return true;
        }
        else //if the queue is not ISFull, than return the false.
        {
            return false;
        }
    }



    bool ISEmpty() // if the rear and front is equal to -1, then the queue is empty.
    {
     if(front == - 1 && rear == -1)
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
        if(ISEmpty()) //we have to check if the qeue is ISEmpty.
        {
            cout<<"The queue is ISEmpty.";
        }
        else
        {
            for(int i = front; i<size; i++) //we looping throught the array
            {
                cout<<array[i]<<endl;
            }

        }

    };


};

//what is different between the distructure.


int main() {

    Queue p(3);
    p.enqueue(1);
    p.enqueue(2);
    p.enqueue(3);

    p.Peek();
    p.dequeue();
    p.Peek();




    return 0;
}
