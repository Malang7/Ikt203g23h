#include "iostream"
#include "vector"


using namespace std;




class solution
{

public:
    void swap(int &a, int& b)
    {
        int tmp = a;
        a = b;
        b = tmp;
    }
    void InsertionOperation(vector<int>& array, int data)
    {
     array.push_back(data);
     linkeTheNode(array, array.size()-1);
    }

    void linkeTheNode(vector<int>& array, int i)
    {
        int parrent = (i-1)/2;
        if(parrent>0)
        {
            if(array[parrent]<array[i])
            {
                swap(array[parrent], array[i]);
                linkeTheNode(array, parrent);
            }
        }
    }



    void hypefy(vector<int>& array, int i)
    {
        int largest = i;  //consider the largest is the i, or the parrrent node
        int left = 2*i+1;
        int right = 2*i+2;

        if(left<array.size() && array[largest]<array[left])
        {
            largest = left;
        }
        if(right<array.size() && array[largest]<array[right])
        {
            largest = right;
        }


        if(largest != i)
        {

            swap(array[largest], array[i]);
            hypefy(array, largest);  //call the function recursivly for the largest number after swaping, to continue the process for the swaped element too

        }
    }

    void buildTheMaHeap(vector<int>&array)
    {
        int arrayLengh = array.size();

        for(int i = (arrayLengh-1)/2; i>= 0; i--)
        {
            hypefy(array, i);
        }

    }


    vector<int> sorting(vector<int>& array)
    {
        vector<int> result;
        int i = array.size();
        while(i>=0)
        {
            if(!array.empty())
            {
               // cout<<array.front();
                result.push_back(array.front());
                swap(array.front(), array.back());
                array.pop_back();
                hypefy(array, 0);
                i--;
            } else
            {
                break;
            }
        }
        return result;
    }




    void Display(vector<int>& array)
    {
        if(array.empty())
        {
            cout<<"nothing in the tree to print";
        }
        else
        {
            for(auto &element : array)
            {
                cout<<" "<<element<<", ";
            }
        };
    }





};




int main()
{

    vector<int> array = {1,2,3,4};

    solution s1;
    s1.hypefy(array,1);
    cout<< 3/2<<endl;
    s1.InsertionOperation(array, 50);
    s1.InsertionOperation(array, 52);
    s1.InsertionOperation(array, 32);
    s1.InsertionOperation(array, 90);
    s1.InsertionOperation(array, 60);
    s1.InsertionOperation(array, 1);


    s1.buildTheMaHeap(array);
   // s1.Display(array);

    vector<int> result;

    result  = s1.sorting(array);

    s1.Display(result);


    return 0;
}