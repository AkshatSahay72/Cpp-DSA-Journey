// GFG Practice: Largest BST | LeetCode equivalent: 333. Largest BST Subtree

#include <bits/stdc++.h>
using namespace std;

/* Tree node structure  used in the program */
struct Node {
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
    class Info{
        public:
            int mini;
            int maxi;
            bool isBST;
            int size;
    };
    
    Info magic(Node* root, int &maxHeight){
        if(root == NULL){
            return { INT_MAX, INT_MIN, true, 0};
        }
        
        Info left = magic(root->left, maxHeight);
        Info right = magic(root->right, maxHeight);
        
        Info cur;
        
        cur.size = left.size + right.size + 1;
        cur.maxi = max(root->data , right.maxi);
        cur.mini = min(left.mini , root->data);
        
        if(left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini)){
            cur.isBST = true;
            maxHeight = max(maxHeight, cur.size);
        }else{
            cur.isBST = false;
        }
        
        return cur;
    }
    
    int largestBst(Node *root) {
        int maxHeight = 0;
        magic(root, maxHeight);
        return maxHeight;
    }
};

int main() {
    Solution sol;

    Node* root1 = new Node(10);
    root1->left = new Node(5);
    root1->right = new Node(15);
    root1->left->left = new Node(1);
    root1->left->right = new Node(8);
    root1->right->right = new Node(7);
    cout << sol.largestBst(root1) << endl;

    Node* root2 = new Node(5);
    root2->left = new Node(2);
    root2->right = new Node(4);
    root2->left->left = new Node(1);
    root2->left->right = new Node(3);
    cout << sol.largestBst(root2) << endl;

    Node* root3 = new Node(1);
    root3->left = new Node(0);
    root3->right = new Node(2);
    cout << sol.largestBst(root3) << endl;

    return 0;
}
