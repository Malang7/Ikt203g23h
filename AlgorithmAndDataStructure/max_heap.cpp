#include <vector>
#include <iostream>

using namespace std;

void swpe(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void maxHeapfy(vector<int>& array, int root, int size) {



    int largest = root;
    int leftChild = 2 * root + 1;
    int rightChild = 2 * root + 2;

    if (leftChild < size && array[leftChild] > array[largest]) {
        largest = leftChild;
    }

    if (rightChild < size && array[rightChild] > array[largest]) {
        largest = rightChild;
    }

    if (largest != root) {
        swpe(array[root], array[largest]);
        maxHeapfy(array, largest, size);
    }
}

vector<int> sortedetHeap(vector<int> array) {
    vector<int> result;
    int size = array.size();

    for (int i = size / 2 - 1; i >= 0; i--) {
        maxHeapfy(array, i, size);
    }

    for (int i = size - 1; i > 0; i--) {
        swpe(array[0], array[i]);
        result.push_back(array[i]);
        maxHeapfy(array, 0, i);
    }

    result.push_back(array[0]); // Push the last remaining element

    return result;
}

int main() {
    vector<int> array = {4, 10, 3, 5, 1};
    vector<int> sortedArray = sortedetHeap(array);

    cout << "Sorted Array: ";
    for (int num : sortedArray) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
