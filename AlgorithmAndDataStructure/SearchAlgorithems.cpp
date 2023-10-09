#include <iostream>
#include <vector>
using namespace std;



void linerSerach(vector<int>&array,int start, int end, vector<int>&indicate, int data)
{
    if(start>end) //base case 
    {
        return; 
    }

    if(array[start] == data )
    {
        //if we found the data in the array, it should push the data into the indicate array,  
        indicate.push_back(start);
        linerSerach(array, start+1, end, indicate, data); //call the liner function recursivly, and starteed with the next index, to check if there is a another equal data in the array
    }
    else
    {
        linerSerach(array, start+1, end, indicate, data); 
    }
}

vector<int>linerSerach(vector<int>&array, int data)
{
    vector<int>indicate; 
    linerSerach(array,0,array.size()-1, indicate, data);
    return indicate; 
}





// Recursive helper function for binary search.
void BinarySearch(vector<int>& array, int key, int left, int right, vector<int>& indicate) {
    int middle = (left + right) / 2;

    // If left crosses right, that means the data is not present in the array.
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
