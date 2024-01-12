#include<iostream>
using namespace std;

class heap {
public:
    int arr[100];
    int size;

    heap() {
        size = 0;
    }

    void insert(int val) {
        size += 1;
        int index = size;
        arr[index] = val;

        while (index > 1) {
            int parent = index / 2;
            if (arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            } else {
                return;
            }
        }
    }

    // Function to perform heap sort
    void heapSort() {
        int n = size;

        // Build max heap
        for (int i = n / 2; i >= 1; i--) {
            heapify(i, n);
        }

        // Extract elements from the heap in non-decreasing order
        for (int i = n; i >= 2; i--) {
            swap(arr[1], arr[i]);
            heapify(1, i - 1);
        }
    }

    void heapify(int i, int n) {
        int largest = i;
        int left = 2 * i;
        int right = 2 * i + 1;

        if (left <= n && arr[left] > arr[largest]) {
            largest = left;
        }

        if (right <= n && arr[right] > arr[largest]) {
            largest = right;
        }

        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(largest, n);
        }
    }

    void print() {
        for (int i = 1; i <= size; i++) {
            cout << arr[i] << "  ";
        }
        cout << endl;
    }
};

int main() {
    heap h;
    h.insert(42);
    h.insert(32);
    h.insert(52);
    h.insert(22);
    h.insert(77);
    h.insert(66);
    h.insert(88);

    cout << "Elements before sorting: ";
    h.print();

    h.heapSort();

    cout << "Elements after sorting: ";
    h.print();

    return 0;
}


// output is 
//  Elements before sorting: 88  52  77  22  32  42  66  
// Elements after sorting: 22  32  42  52  66  77  88  