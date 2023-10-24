#include <iostream>
#include <vector>

using namespace std;

template<typename T>
vector<T> interpolationSearchAlgorithm(vector<T> &array, T key)
{


    int start = 0;
    int end = array.size() - 1;
    vector<int> result; 
    //this loop should continu untill the start is less then the end, and the key is greter or equl to the start and less than end element in the array 
    while (start <= end && key >= array[start] && key <= array[end])
    {
        //calculating the position 
        int position = start + (((double)(end - start) / (array[end] - array[start])) * (key - array[start]));

        if (array[position] == key)
        {
            result.push_back(position);
            end = position -1; 

            // Check if in the remaining part of the array, there are again some values which are equal to the key.
           
            while(end>= 0 && array[end] == key)
            {
                result.push_back(end);
                end --; 
            }

            start = position+1;
            while(start<array.size() && array[start]==key)
            {
                result.push_back(start); 
                start ++; 
            }
         //going out of the loop, when all numbers is found 
        }
        if (array[position] < key)  //if the finds value is greter than the target it will incres the start by one
        {
            start = position + 1;
        }
        else   //otherwise it will decremenet the end by one
        {
            end = position - 1;
        }
    }
    return result;


}

template<typename T>
void display(vector<T>& result)
{
    if(result.empty())
    {
        cout<<"target not found"; 
    }
    else 
    {
        for(auto &index : result)
        cout<<"the target found in index: "<<index<<endl; 
    }
}




int main()
{
    vector<int> array = {1, 2, 3, 4, 5, 6, 6, 8, 9};

    vector<int> result = interpolationSearchAlgorithm(array, 6);

    display(result); 

    vector<string> ar = {"a", "b", "c", "d"};
    vector<int> e = interpolationSearchAlgorithm(ar, "b");





    return 0;
}
