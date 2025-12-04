#include <bits/stdc++.h>
using namespace std;

/* A binary tree node */
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    vector<int> diagonal(Node *root) {
        vector<int> ans;
        queue<Node*> q;
        if(!root) return ans;  
        
        q.push(root);
        
        while(!q.empty()){
            Node* cur = q.front();
            q.pop();
            
            while(cur){
                if(cur->left) q.push(cur->left);
                ans.push_back(cur->data);
                cur = cur->right;
            }
        }
        return ans;
    }
};

// helper to print vector
void printVector(const vector<int>& v){
    for(int x : v) cout << x << " ";
    cout << "\n";
}

int main() {
    Solution sol;

    // ------------------ TEST CASE 1 ------------------
    // Tree:
    //       8
    //     /   \
    //    3     10
    //   / \      \
    //  1   6      14
    //     / \     /
    //    4   7   13

    Node* root1 = new Node(8);
    root1->left = new Node(3);
    root1->right = new Node(10);
    root1->left->left = new Node(1);
    root1->left->right = new Node(6);
    root1->left->right->left = new Node(4);
    root1->left->right->right = new Node(7);
    root1->right->right = new Node(14);
    root1->right->right->left = new Node(13);

    cout << "Diagonal Traversal Test Case 1: ";
    printVector(sol.diagonal(root1));

    // ------------------ TEST CASE 2 ------------------
    // Tree:
    //        1
    //         \
    //          2
    //           \
    //            3
    //             \
    //              4

    Node* root2 = new Node(1);
    root2->right = new Node(2);
    root2->right->right = new Node(3);
    root2->right->right->right = new Node(4);

    cout << "Diagonal Traversal Test Case 2: ";
    printVector(sol.diagonal(root2));

    return 0;
}
