#include <iostream>
using namespace std;

template <typename T>


T* SelectionSort(T array[], T sizeOFarray)
{
    //staring with the first element in the array
    int i  = 0;
    //placeholder for the second element int the array
    while (i<sizeOFarray) //this loops through each element
    {
        int minIndex  = i;
        int j = i+1;


        //this loop search for the smallest element
        while (j<sizeOFarray)
        {
            if (array[i]>array[j]) //if the first element in the array is greater than the second elemenet in the array
            {
                minIndex  = j;  // the minimum variable become to the second element in the array
            }
            j++;
        }


        T temp = array[i]; //store the current element into the temp variable
         array[i] = array[minIndex]; //overwrite the value of the index i buy the value of the index min
         array[minIndex] = temp; //overwrite the value of the index mini with te temp


        i++;

    }

    return array;
}





int main()
{
    int myNumbers[5] = {15, 2, 30, 0, 25};
    int *array;

    array= SelectionSort(myNumbers, 5);

    for(int i= 0; i<sizeof(myNumbers)/ sizeof(int); i++)
    {
        cout<<array[i]<<endl;
    }





    return 0;
}




