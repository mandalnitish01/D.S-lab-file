#include <iostream>
using namespace std;
// Function to perform linear search in an array
int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == key) {
            return i; // Return the index if the element is found
        }
    }
    return -1; // Return -1 if the element is not found
}

int main() {
    const int size = 5;
    int arr[size] = {10, 20, 30, 40, 50};
    int key;

    cout << "Enter the element to search: ";
    cin >> key;

    int result = linearSearch(arr, size, key);

    if (result != -1) {
        cout << "Element " << key << " found at index " << result << endl;
    } else {
        cout << "Element " << key << " not found in the array." << endl;
    }

    return 0;
}

// output is  
// (1).
// Enter the element to search: 30
// Element 30 found at index 2

// (2).
// Enter the element to search: 6
// Element 6 not found in the array.
