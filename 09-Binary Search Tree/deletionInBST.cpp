// GFG Practice & LeetCode: Delete Node in a BST (LeetCode 450)

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

Node* getMin(Node* root){
    Node* temp = root;
    while(temp->left){
        temp = temp->left;
    }
    return temp;
}

Node* getMax(Node* root){
    Node* temp = root;
    while(temp->right){
        temp = temp->right;
    }
    return temp;
}

Node* deletionInBST(Node* root, int val){
    if(root == NULL)    return root;

    if(root->data == val){
        // 0 child
        if(!root->left && !root->right){
            delete root;
            return NULL;
        }

        // 1 child
        if(root->left && !root->right){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        if(!root->left && root->right){
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // 2 child
        int mini = getMin(root->right)->data;
        root->data = mini;
        root->right = deletionInBST(root->right, mini);
        return root;
    }

    if(root->data > val){
        root->left = deletionInBST(root->left, val);
    }else{
        root->right = deletionInBST(root->right, val);
    }
    return root;
}

void inorder(Node* root){
    if(!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main(){
    Node* root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->right->right = new Node(14);

    root = deletionInBST(root, 1);
    inorder(root);
    cout << endl;

    root = deletionInBST(root, 10);
    inorder(root);
    cout << endl;

    root = deletionInBST(root, 3);
    inorder(root);
    cout << endl;

    return 0;
}
