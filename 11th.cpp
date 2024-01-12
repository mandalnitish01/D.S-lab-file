#include <iostream>
using namespace std;

// Function to perform binary search in a sorted array
int binarySearch(int arr[], int s, int e, int key) {
    while (s <= e) {
        int mid = s + (e - s) / 2;

        if (arr[mid] == key) {
            return mid; // Return the index if the element is found
        } else if (arr[mid] < key) {
            s = mid + 1;
        } else {
            e = mid - 1;
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

    int result = binarySearch(arr, 0, size - 1, key);

    if (result != -1) {
        cout << "Element " << key << " found at index " << result << endl;
    } else {
        cout << "Element " << key << " not found in the array." << endl;
    }

    return 0;
}


// output is 

// Enter the element to search: 10
// Element 10 found at index 0

// Enter the element to search: 5
// Element 5 not found in the array.