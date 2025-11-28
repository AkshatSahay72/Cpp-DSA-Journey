#include <iostream>
#include <algorithm>
using namespace std;

// Structure for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Function to calculate max height of a binary tree
int maxHeight(Node* root) {
    if (!root) return 0;
    int leftSide = maxHeight(root->left);
    int rightSide = maxHeight(root->right);
    return max(leftSide, rightSide) + 1;
}

int main() {
    // Creating a sample binary tree:
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Height of the binary tree is: " << maxHeight(root) << endl;

    return 0;
}
