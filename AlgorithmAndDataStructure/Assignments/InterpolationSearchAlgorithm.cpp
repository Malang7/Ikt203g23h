#include <iostream>
#include <vector>

using namespace std;

template<typename T>
int interpolationSearchAlgorithm(vector<T> &array, T key)
{
    int start = 0;
    int end = array.size() - 1;
 

    //this loop should continu untill the start is less then the end, and the key is greter or equl to the start and less than end element in the array 
    while (start <= end && key >= array[start] && key <= array[end])
    {

        //calculating the position 
        int position = start + (((double)(end - start) / (array[end] - array[start])) * (key - array[start]));

        if (array[position] == key)
        {
            return position;   
        
                  
        }
        if (array[position] < key)  //if the finds value is greter than the target it will incres the start by one
        {
            start = position + 1;
        }
        else                        //otherwise it will decremenet the end by one
        {
            end = position - 1;
        }
    }
    return -1;
}



int main()
{
    vector<int> array = {1, 2, 3, 4, 5, 6, 6, 8, 9};

    int result = interpolationSearchAlgorithm(array, 5);

    if(result == -1)
    {
        cout<<"target not found"; 
    }
    else 
    {
        cout<<"the target found in index: "<<result; 
    }

    return 0;
}
