#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
//constructor created
    Queue() : front(nullptr), rear(nullptr) {}

    // Function to enqueue (insert) a new element into the queue
    void enqueue(int value) {
        Node* newNode = new Node(value);

        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        cout << "Enqueued: " << value << endl;
    }

    // Function to dequeue (remove) the front element from the queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }

        Node* temp = front;
        front = front->next;
        int dequeuedValue = temp->data;
        delete temp;

        cout << "Dequeued: " << dequeuedValue << endl;

        if (front == nullptr) {
            rear = nullptr; // If the last element is dequeued, update rear as well
        }
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Function to display the elements of the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        Node* current = front;
        cout << "Queue: ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Queue queue;

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    queue.display();

    queue.dequeue();
    queue.display();

    return 0;
}

// output is 
// Enqueued: 1
// Enqueued: 2
// Enqueued: 3

// Queue: 1 2 3 

// Dequeued: 1

// Queue: 2 3
