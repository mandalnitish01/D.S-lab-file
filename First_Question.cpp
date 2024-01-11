#include <iostream>
#include <vector>
using namespace std;

void insertElement(vector<int> &arr, int k, int newElement)
{
    // Check if the position is valid
    if (k < 0 || k > arr.size())
    {
        cout << "Invalid position for insertion." << endl;
        return;
    }

    // Insert the new element at the specified position
    arr.insert(arr.begin() + k, newElement);
}

int main()
{
    // Example Usage
    vector<int> Unsorted_Array = {3, 1, 4, 1, 5, 9, 2, 6, 5};
    int Kth = 3;
    int newElementToInsert = 8;

    // Insert the new element into the array
    insertElement(Unsorted_Array, Kth, newElementToInsert);

    // Display the modified array
    cout << "Original Array: ";
    for (int num : Unsorted_Array)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

// Output is

// Original Array: 3 1 4 8 1 5 9 2 6 5 
