#include <iostream>
#include <vector>
using namespace std;



template <typename T>

//sort the array based on the selection sort, find the minmum elemnet, and place it into the sorted array 
T* SelectionSort(T array[], T sizeOFarray)
{
    //staring with the first element in the array
    int i  = 0;
    //placeholder for the second element int the array
    while (i<sizeOFarray-1) //this loops through each element
    {
        int minIndex  = i; //consier the first element as minimum value 
        int j = i+1;    //starting from the second element 
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
         
         if(minIndex != i)
         {
            array[i] = array[minIndex]; //overwrite the value of the index i buy the value of the index min
            array[minIndex] = temp; //overwrite the value of the index mini with te temp
         }    
        i++;
    }

    // The worst-case time complexity of insertion sort is O(n^2).
    // The best-case time complexity is O(n), if the array is already sorted. 


    return array;
};



template <typename I>
I* InsertionSort(I array[], I sizeOfTheArray) //sorting the array by the insertion method, assuming the first elemenet is sorted 
{
    for (int current = 1; current<sizeOfTheArray; current++) //we assum that the first elenet is sorted, and we start with the second element.
    { 
        I temp = array[current]; //The current elemenet, this variable will holde the value of the current index
       int previous  = current - 1 ; //get the previous index 

    // Check if the the previous in grater or equl to zero and if the previous elemnet is 
    // greater than the current elemnet 
       while(previous>= 0 && array[previous]> temp) 
       {
            array[previous+1] = array[previous]; //ransfer the value from the previous index to the next index
            previous--; //Decrement the privious to get the element before the previous
       }
        array[previous+1] = temp; //update the current index with the value key a

       // The worst-case time complexity of insertion sort is O(n^2).
        // The best-case time complexity is O(n), if the array is already sorted.


    }
    return array;
};


template <typename B> 
// Sort an array using the Bubble Sort algorithm.
B* BubbleSortAlgorithm(B array[], int size)
{
    for(int i = 0; i < size-1; i++)    
    {
        bool flag = false; // Use bool for a more descriptive type 

        // inner loop goes up to size-1-i
        for (int j = 0; j < size-1-i; j++) 
        {
            // Compare current element with the next element
            if(array[j] > array[j+1]) 
            {
                // Swapping the elements
                B temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp; 
                flag = true; 
            }
        }

        // If no elements were swapped by the inner loop, then the array is already sorted.
        // The worst-case time complexity of Bubble Sort is O(n^2). The best-case time complexity is O(n) when the array is already sorted.
        if(!flag)
            break; 
    }

    return array; 
}



template<typename M>
M* mergeSortAlgorithm(vector<M>& array)
{
    int length = array.size();

    // Base condition for recursion.
    if(length <= 1)
        return 0; 

    int middle = length / 2;

    vector<M> lowerBound;  

    // Using upperBound at the 'middle' index may give incorrect results if the length of the array is odd.
    // For instance, when the length is 5, "middle" will be 2. In this scenario, the lowerBound vector should have a size of 2,
    // while the upperBound vector should store the remaining 3 elements. 
    // This "middle" calculation works when the array size is even. But, to handle both even and odd lengths,
    // the size of upperBound must be 'length - middle'. For instance, '5 - 2 = 3', making the size of the upperBound vector 3.

    vector<M> upperBound;

    // This loop goes through each element and splits the vector into two vectors.
    for(int i = 0; i < length; i++)
    {
        if(i < middle)
        {
            lowerBound.push_back(array.at(i)); // Assigns values to the lowerBound vector. 
        }
        else
        {
            upperBound.push_back(array.at(i)); // Assigns values to the right side of the vector. 
        }
    }

    // Display
    cout << "The lowerBound vector: " << endl << endl;

    // I prefer using the range-based for loop to print elements stored in the vector because 
    // the vector size might not always be known.
    // By using 'const auto& element', we access each element directly without copying them.
    // While this doesn't matter much for small data sets, it's efficient for large ones to avoid unnecessary copies.
    // Moreover, the 'const' ensures that the elements of the container won't be modified within the loop.
    for(const auto& element : lowerBound)
    {
        cout << element << endl;
    }

    cout << "The upperBound vector: " << endl << endl;

    for(const auto& element : upperBound)
    {
        cout << element << endl; 
    }

    // Recursively call the merge sort algorithm to continue dividing.
    mergeSortAlgorithm(lowerBound);            
    mergeSortAlgorithm(upperBound);

    return 0;
}

void merge(vector<int>& array, vector<int>& lowerBound, vector<int>& upperBound)
{
    int i = 0; 
    int j = 0; 
    int k = 0; 

    // Check if the element in the lowerBound is greater than the element in the upperBound.
    // The smaller element will be appended to the new array.
    while(i < lowerBound.size() && j < upperBound.size())
    {
        if(lowerBound[i] > upperBound[j])  // Find the smaller element between the two arrays.
        {   
            // Append the smaller element to the new array.
            array[k] = upperBound[j];
            j++;  // Move to the next index in the upperBound.
            k++;  // Move to the next empty index in the array.
        }
        else
        {
            array[k] = lowerBound[i];  // If the element in lowerBound is smaller, append it to the array.
            i++; // Move to the next index in the lowerBound.
            k++; 
        }
    }

    // Copy the remaining elements from lowerBound to the array.
    while(i < lowerBound.size())
    {
        array[k] = lowerBound[i]; 
        i++;
        k++;  
    }

    // Copy the remaining elements from upperBound to the array.
    while(j < upperBound.size())
    {
        array[k] = upperBound[j];
        j++;
        k++;
    }
}



void Display(int *array, int size)   //display the elemenet within of the array 
{
    cout<<"sorted list: "<<endl;
    for (int i = 0; i <size; i++)
    {
        cout<<array[i]<<endl;

    }
}

int main()
{
    int myNumbers[5] = {15, 2, 30, 0, 25};
    int *array;

    //array= SelectionSort(myNumbers, 5);

    vector<int> v = {15,2,30,0,25}; 


    array = mergeSortAlgorithm(v);
    int divide = 5/2;
    cout<<"divide "<<divide;

   // Display(array, 5);



    return 0;
}




