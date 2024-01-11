#include <iostream>
using namespace std;
#define MAX_SIZE 100

class Queue {
private:
    int arr[MAX_SIZE];
    int front, rear;

public:
    // Constructor
    Queue() {
        front = rear = -1;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    // Function to check if the queue is full
    bool isFull() {
        return (rear == MAX_SIZE - 1);
    }

    // Function to insert an element into the queue (enqueue)
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow. Cannot enqueue element." << endl;
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear++;
        }

        arr[rear] = value;
        cout << "Enqueued: " << value  << endl;
    }

    // Function to remove an element from the queue (dequeue)
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow. Cannot dequeue element." << endl;
            return;
        }

        cout << "Dequeued " << arr[front] << " from the queue." << endl;

        if (front == rear) {
            // If the queue becomes empty after dequeue
            front = rear = -1;
        } else {
            front++;
        }
    }

    // Function to display the elements of the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Queue elements: ";
        for (int i = front; i <= rear; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    // Example Usage
    Queue myQueue;

    myQueue.enqueue(1);
    myQueue.enqueue(2);
    myQueue.enqueue(3);
    myQueue.display();

    myQueue.dequeue();
    myQueue.display();

    return 0;
}


//Output is 

// Enqueued: 1
// Enqueued: 2
// Enqueued: 3
// Queue elements: 1 2 3 
// Dequeued 1 from the queue.
// Queue elements: 2 3 
