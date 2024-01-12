#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
//constructor created by Node constructor
    Node(int value) : data(value), next(nullptr) {}
};

class Stack {
private:
    Node* top;

public:
    Stack() : top(nullptr) {}

    // Function to push a new element onto the stack
    void push(int value) {
        Node* newNode = new Node(value);

        if (top == nullptr) {
            top = newNode;
        } else {
            newNode->next = top;
            top = newNode;
        }

        cout << "Pushed: " << value << endl;
    }

    // Function to pop the top element from the stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop." << endl;
            return;
        }

        Node* temp = top;
        top = top->next;
        int poppedValue = temp->data;
        delete temp;

        cout << "Popped: " << poppedValue << endl;
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

        Node* current = top;
        cout << "Stack: ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Stack stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    stack.display();

    stack.pop();
    stack.display();

    return 0;
}

// output is 

// Pushed: 1
// Pushed: 2
// Pushed: 3

// Stack: 3 2 1 

// Popped: 3

// Stack: 2 1 