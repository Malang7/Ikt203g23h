#include <iostream>
#include <vector>
using namespace std;



// Recursive function to search for a given data in the vector and store its indices where found.
void linerSerach(vector<int>& array, int start, int end, vector<int>& indicate, int data)
{
    // Base case: If the starting index is greater than the ending index, 
    // then the search in the current sub-array is over.
    if(start > end) 
    {
        return; 
    }

    // If the current element matches the desired data
    if(array[start] == data )
    {
        // Push the current index into the indicate vector 
        // to keep track of where the data was found.
        indicate.push_back(start);

        // Move to the next index and continue the search 
        // to find any other occurrences of the data.
        linerSerach(array, start+1, end, indicate, data);
    }
    else
    {
        // If the current element doesn't match the data, 
        // move to the next index and continue the search.
        linerSerach(array, start+1, end, indicate, data); 
    }
}

// Function that initializes and triggers the recursive search.
// It returns a vector containing indices where the data is found.
vector<int> linerSerach(vector<int>& array, int data)
{
    // Vector to store the indices where the data is found.
    vector<int> indicate; 

    // Start the search from the beginning (0) to the end (array.size() - 1).
    linerSerach(array, 0, array.size()-1, indicate, data);

    // Return the vector with the indices.
    return indicate; 
}




void BinarySearch(vector<int>& array, int key, int left, int right, vector<int>& indicate) {
    int middle = (left + right) / 2;

    // base case: If left crosses right, that means the data is not present in the array.
    if(left > right) {
        return;
    }

    if(array[middle] == key) {
        indicate.push_back(middle);

        // Check if the data is present on the right side.
        BinarySearch(array, key, middle + 1, right, indicate);

        // Check if the data is present on the left side.
        BinarySearch(array, key, left, middle - 1, indicate);

    } else if (key > array[middle]) {
        // If the data is present on the right side of the array.
        BinarySearch(array, key, middle + 1, right, indicate);
    } else {
        // If the data is present on the left side of the array.
        BinarySearch(array, key, left, middle - 1, indicate);
    }
}

// Function overloading in C++ allows one to have one or more functions 
// with the same name in the same scope, but with different parameters.
vector<int> BinarySearch(vector<int>& array, int key) {
    vector<int> indicate;
    BinarySearch(array, key, 0, array.size() - 1, indicate);
    return indicate;
}

int main() {
    vector<int> array = {1, 2, 3, 4, 5, 6, 6, 7, 8};
    vector<int> indicate = linerSerach(array, 6);


    if(indicate.empty())
    {
        cout<<"no data in array"; 
    }

    for(auto index: indicate) {
        cout << index << " ";
    }

    return 0;
}
