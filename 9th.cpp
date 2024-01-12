#include <iostream>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    //constructor created
    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    TreeNode* root;

    // Helper function for insertion
    TreeNode* insert(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }

        if (value < node->data) {
            node->left = insert(node->left, value);
        } else if (value > node->data) {
            node->right = insert(node->right, value);
        }

        return node;
    }

    // Helper function to find the node with the minimum value in a subtree
    TreeNode* findMinNode(TreeNode* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    // Helper function for deletion
    TreeNode* remove(TreeNode* node, int value) {
        if (node == nullptr) {
            return nullptr;
        }

        if (value < node->data) {
            node->left = remove(node->left, value);
        } else if (value > node->data) {
            node->right = remove(node->right, value);
        } else {
            // Node to be deleted found

            // Case 1: Node with only one child or no child
            if (node->left == nullptr) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }

            // Case 2: Node with two children
            TreeNode* minRightSubtree = findMinNode(node->right);
            node->data = minRightSubtree->data;
            node->right = remove(node->right, minRightSubtree->data);
        }

        return node;
    }

    // Helper function to perform in-order traversal and display the elements
    void inorderTraversal(TreeNode* node) {
        if (node != nullptr) {
            inorderTraversal(node->left);
            cout << node->data << " ";
            inorderTraversal(node->right);
        }
    }

public:
    BinarySearchTree() : root(nullptr) {}

    // Function to insert a new element into the BST
    void insert(int value) {
        root = insert(root, value);
    }

    // Function to delete an element from the BST
    void remove(int value) {
        root = remove(root, value);
    }

    // Function to display the elements of the BST in sorted order
    void display() {
        cout << "In-order Traversal: ";
        inorderTraversal(root);
        cout << endl;
    }
};

int main() {
    BinarySearchTree bst;

    // Insert elements
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    // Display initial BST
    cout << "Initial Binary Search Tree: " << endl;
    bst.display();

    // Delete elements
    bst.remove(20);
    bst.remove(30);
    bst.remove(70);

    // Display BST after deletions
    cout << "Binary Search Tree after Deletions: " << endl;
    bst.display();

    return 0;
}


// output is
// Initial Binary Search Tree: 
// In-order Traversal: 20 30 40 50 60 70 80 

// Binary Search Tree after Deletions: 
// In-order Traversal: 40 50 60 80  