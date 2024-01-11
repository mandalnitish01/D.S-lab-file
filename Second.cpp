#include <iostream>
using namespace std;
#define MAX_SIZE 100

class Stack {
private:
    int arr[MAX_SIZE];
    int top;

public:
    // Constructor
    Stack() {
        top = -1;
    }

    // Function to push an element onto the stack
    void push(int value) {
        if (top == MAX_SIZE - 1) {
            cout << "Stack Overflow. Cannot push element." << endl;
            return;
        }
        arr[++top] = value;
        cout << "Pushed " << value << endl;
    }

    // Function to pop an element from the stack
    void pop() {
        if (top == -1) {
            cout << "Stack Underflow. Cannot pop element." << endl;
            return;
        }
        cout << "Popped " << arr[top--] << " from the stack." << endl;
    }

    // Function to display the elements of the stack
    void display() {
        if (top == -1) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Our Stack elements: ";
        for (int i = 0; i <= top; ++i) {
            cout << arr[i] << " ";
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

//Output is

// Pushed 1
// Pushed 2
// Pushed 3
// Our Stack elements: 1 2 3 
// Popped 3 from the stack.
// Our Stack elements: 1 2 
