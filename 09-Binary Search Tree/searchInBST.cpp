// GFG Practice & LeetCode: Search in a Binary Search Tree (LeetCode 700)

#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left; 
    Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

bool searchInBST(Node* root, int x){
    if(root == NULL)    return false;
    if(root->data == x) return true;
    if(root->data < x)  return searchInBST(root->right, x);
    else                return searchInBST(root->left, x);
}

bool searchInBSTOptimised(Node* root, int x){
    Node* temp = root;
    while(temp != NULL){
        if(temp->data == x) return true;
        if(temp->data < x)  temp = temp->right;
        else                temp = temp->left;
    }
    return false;
}

int main(){
    Node* root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->right->right = new Node(14);

    cout << searchInBSTOptimised(root, 6) << endl;
    cout << searchInBSTOptimised(root, 14) << endl;
    cout << searchInBSTOptimised(root, 7) << endl;

    return 0;
}
