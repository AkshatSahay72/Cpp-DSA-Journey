// GFG Practice: Check if a Binary Tree is Heap

#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    int getCount(Node* root){
        if(!root)   return 0;
        return 1 + getCount(root->left) + getCount(root->right);
    }
    
    bool isCBT(Node* tree, int index, int count){
        if(!tree)   return true;
        if(index >= count) return false;
        return isCBT(tree->left, 2*index + 1, count) &&
               isCBT(tree->right, 2*index + 2, count);
    }
    
    bool isMaxHeap(Node* tree){
        if(!tree->left && !tree->right) return true;
        if(!tree->right) return tree->data > tree->left->data;
        return isMaxHeap(tree->left) &&
               isMaxHeap(tree->right) &&
               tree->data > tree->left->data &&
               tree->data > tree->right->data;
    }
  
    bool isHeap(Node* tree) {
        int count = getCount(tree);
        return isCBT(tree, 0, count) && isMaxHeap(tree);
    }
};

int main() {
    Solution s;

    Node* root1 = new Node(10);
    root1->left = new Node(9);
    root1->right = new Node(8);
    root1->left->left = new Node(7);
    root1->left->right = new Node(6);
    cout << s.isHeap(root1) << endl;

    Node* root2 = new Node(10);
    root2->left = new Node(15);
    root2->right = new Node(8);
    cout << s.isHeap(root2) << endl;

    Node* root3 = new Node(20);
    root3->left = new Node(18);
    root3->right = new Node(15);
    root3->left->left = new Node(10);
    root3->left->right = new Node(12);
    cout << s.isHeap(root3) << endl;

    return 0;
}
