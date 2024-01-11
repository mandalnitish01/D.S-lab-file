#include <iostream>

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
    
    // Constructor to initialize a new node
    Node(int value) : data(value), next(nullptr) {}
};

// LinkedList class
class LinkedList {
private:
    Node* head; // Pointer to the head of the linked list

public:
    // Constructor to initialize an empty linked list
    LinkedList() : head(nullptr) {}

    // Function to insert a new node at the beginning of the list
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        std::cout << "Inserted " << value << " at the beginning." << std::endl;
    }

    // Function to insert a new node at the end of the list
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);

        // If the list is empty, set the new node as the head
        if (head == nullptr) {
            head = newNode;
        } else {
            // Traverse the list to find the last node
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            // Insert the new node at the end
            current->next = newNode;
        }

        std::cout << "Inserted " << value << " at the end." << std::endl;
    }

    // Function to delete a node with a specific value from the list
    void deleteNode(int value) {
        Node* current = head;
        Node* prev = nullptr;

        // Traverse the list to find the node with the specified value
        while (current != nullptr && current->data != value) {
            prev = current;
            current = current->next;
        }

        // If the node with the specified value is found, delete it
        if (current != nullptr) {
            // If the node to be deleted is the head, update the head
            if (prev == nullptr) {
                head = current->next;
            } else {
                // Otherwise, update the previous node's next pointer
                prev->next = current->next;
            }
            
            delete current; // Free the memory occupied by the deleted node
            std::cout << "Deleted node with value " << value << "." << std::endl;
        } else {
            std::cout << "Node with value " << value << " not found." << std::endl;
        }
    }

    // Function to display the elements of the linked list
    void display() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    LinkedList myList;

    myList.insertAtBeginning(10);
    myList.insertAtEnd(20);
    myList.insertAtEnd(30);
    myList.display();

    myList.deleteNode(20);
    myList.display();

return 0;
}

// Output is 

// Inserted 10 at the beginning.
// Inserted 20 at the end.
// Inserted 30 at the end.
// 10 20 30 
// Deleted node with value 20.
// 10 30 