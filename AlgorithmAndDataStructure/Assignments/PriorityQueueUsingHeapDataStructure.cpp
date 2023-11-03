#include "iostream"
#include "vector"
#include <queue>

/*
    Assignment Description:

    In this assignment, you will explore the concept of task scheduling and implement a task scheduling system using a priority queue based on a heap data structure. The goal is to create a program that allows users to insert tasks along with their priorities and efficiently schedule and execute those tasks based on their priorities.

    Tasks:

    Task 1:  (4 points)

    Design a priority queue data structure based on a max-heap to support task scheduling. Define the data structure's attributes and methods. Implement the priority queue data structure along with methods for insertion and task execution. Create a task structure that includes the task's name and priority.

    Task 2: (1.5 point)

    Develop a mechanism that allows users to insert tasks along with their priorities. The user will insert tasks without considering the orders. Include comments in your code for clarity.

    Implement a user-friendly interface that accepts user input for task insertion.

        Display the task with the highest priority.
        Display n tasks with the highest priority.
        Tasks should have a unique name
        Show a message if the user inserts duplicate names

 */





using namespace std;


struct task
{
    string taskName;
    int priority;
};

class PriorityQueue
{
private:
    vector<task> array;



public:
    void swap(task &a, task& b)
    {
        task tmp = a;
        a = b;
        b = tmp;
    }

    void linkeTheNode(vector<task>& array, int i)
    {
        int parrent = (i-1)/2;
        if(parrent>0)
        {
            if(array[parrent].priority<array[i].priority)
            {
                swap(array[parrent], array[i]);
                linkeTheNode(array, parrent);
            }
        }
    }




    void InsertionOperation(vector<task>& array, task data)
    {
        array.push_back(data);
        linkeTheNode(array, array.size()-1);
    }




    void hypefy(vector<task>& array, int i)
    {
        int largest = i;  //consider the largest is the i, or the parrrent node
        int left = 2*i+1;
        int right = 2*i+2;

        if(left<array.size() && array[largest].priority<array[left].priority)
        {
            largest = left;
        }
        if(right<array.size() && array[largest].priority<array[right].priority)
        {
            largest = right;
        }


        if(largest != i)
        {

            swap(array[largest], array[i]);
            hypefy(array, largest);  //call the function recursivly for the largest number after swaping, to continue the process for the swaped element too

        }
    }

    void buildTheMaHeap(vector<task>&array)
    {
        int arrayLengh = array.size();

        for(int i = (arrayLengh-1)/2; i>= 0; i--)
        {
            hypefy(array, i);
        }

    }


    vector<task> sorting(vector<task>&array)
    {
        vector<task> result;
        int i = array.size();
        while(i>=0)
        {
            if(!array.empty())
            {
                hypefy(array, 0);
                result.push_back(array.front());
                swap(array.front(), array.back());
                array.pop_back();
                i--;
            } else
            {
                break;
            }
        }
        return result;
    }




    void Display(vector<task>& array, int n)
    {
        int i = 0;

        if(array.empty())
        {
            cout<<"Empty, nothing to print.";
            return;
        }

        if(n>array.size() || n<=0)
        {
            cout<<"input is out of the range. number of elements is"<<array.size();
            return;
        }


        while(i<n)
        {
            cout<<"Task with name "<<array[i].taskName<<", and with priority "<< array[i].priority<<endl;
            i++;
        }



    }

    void GethighestPriority(vector<task> &array) {
        if (!array.empty()) {
            cout<<"the element with the name: "<<array[0].taskName<<"and priority: "<<array[0].priority;
            array.erase(array.begin());
            //array.pop_back();
        } else {
            {
                cout<<"nothing to remove.";
            }
        }
    }



};



void App(vector<task>& result)
{
    int input;
    PriorityQueue p;



    p.InsertionOperation(result, {"task 1", 2});
    p.InsertionOperation(result, {"task 2", 3});
    p.InsertionOperation(result, {"task 3", 4});
    p.InsertionOperation(result, {"task 4", 5});
    p.InsertionOperation(result, {"task 5", 6});
    p.InsertionOperation(result, {"task 6", 7});
    p.InsertionOperation(result, {"task 7", 8});




    while(input != 0)
    {
        /*if(result.empty())
        {
            cout<<"there is no task to execute, please enter 1 to enter some tasks or 0 to exit the program.";
        }*/

        cout
                <<endl
                <<"---------------Task Scheduling with Priority Queue Using Heap Data Structure----------------"
                <<endl
                <<endl
                <<endl
                <<" 1 to enter the task "
                <<endl
                <<" 2 to execute a task with the highest priority "
                <<endl
                <<" 3 to display n tasks with the highest priority "
                <<endl
                <<" 0 to exit the programm"
                <<endl
                <<" Enter your option: "
                <<endl;
        cin>>input;

        if(input == 0)
        {
            break;
        }
        else if(input == 1)
        {
            task data;
            cout<<"Enter the task name: "<<endl;
            cin.ignore();
            getline(cin,data.taskName) ;
            cout<<"Enter the priority of the task: ";
            cin>>data.priority;
            p.InsertionOperation(result, data);
        }
        else if (input == 2)
        {
            vector<task> sortResult = p.sorting(result);
            p.GethighestPriority(sortResult);


        } else if (input == 4)
        {
            int n;
            cout<<"please enter 'n' tasks to display tasks: ";
            cin>>n;
            vector<task> sortResult = p.sorting(result);
            p.Display(sortResult,n);

        }




    }


}






int main()
{

    vector<task> result;



    App(result);

    /*
     * vector<int> array = {1,2,3,4};

    PriorityQueue s1;
    vector<task> test;

    s1.InsertionOperation(test, {"task 1", 2});
    s1.InsertionOperation(test, {"task 2", 3});
    s1.InsertionOperation(test, {"task 3", 4});
    s1.InsertionOperation(test, {"task 4", 5});
    s1.InsertionOperation(test, {"task 5", 6});
    s1.InsertionOperation(test, {"task 6", 7});
    s1.InsertionOperation(test, {"task 7", 8});




    s1.Display(test);
    cout<<endl;
    //s1.buildTheMaHeap(array);
   // s1.Display(array);

    vector<task> result;

    result  = s1.sorting(test);

    s1.Display(result);
*/


    return 0;
}