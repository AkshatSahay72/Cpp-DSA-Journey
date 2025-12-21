#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    Node* magic(Node* root, int &k, int node){
        if(!root) return NULL;
        if(root->data == node) return root;

        Node* leftAns = magic(root->left, k, node);
        Node* rightAns = magic(root->right, k, node);

        if(leftAns && !rightAns){
            k--;
            if(k == 0) return root;
            return leftAns;
        }

        if(!leftAns && rightAns){
            k--;
            if(k == 0) return root;
            return rightAns;
        }

        return NULL;
    }

    int kthAncestor(Node *root, int k, int node) {
        Node* Ans = magic(root, k, node);
        if(!Ans || Ans->data == node) return -1;
        return Ans->data;
    }
};

int main() {
    /*
            1
           / \
          2   3
         / \
        4   5
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Solution obj;

    int k = 2;
    int node = 5;

    cout << obj.kthAncestor(root, k, node) << endl;

    return 0;
}
