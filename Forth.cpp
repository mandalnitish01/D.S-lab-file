#include <iostream>
using namespace std;

// Node structure to represent elements in the linked list
struct Node {
    int data;
    Node* next;
};

// Stack class
class Stack {
private:
    Node* top;

public:
    // Constructor
    Stack() : top(nullptr) {}

    // Function to push an element onto the stack
    void push(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        cout << "Pushed: " << value <<  endl;
    }

    // Function to pop an element from the stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow. Cannot pop element." << endl;
            return;
        }

        Node* temp = top;
        top = top->next;
        cout << "Popped " << temp->data << " from the stack." << endl;
        delete temp;
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Function to display the elements of the stack
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }

        cout << "Stack elements: ";
        Node* current = top;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    // Example Usage
    Stack myStack;

    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.display();

    myStack.pop();
    myStack.display();
return 0;
}

// Output is 

// Pushed: 1
// Pushed: 2
// Pushed: 3
// Stack elements: 3 2 1 
// Popped 3 from the stack.
// Stack elements: 2 1 
