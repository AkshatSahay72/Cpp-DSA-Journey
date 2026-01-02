// GFG Practice: Predecessor and Successor in BST
// LeetCode Equivalent: Inorder Successor in BST (LC 285 – variant)

#include <bits/stdc++.h>
using namespace std;

/* BST Node */
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        Node* temp = root;
        Node* pred = NULL;
        Node* suced = NULL;
        
        while(temp && temp->data != key){
            if(temp->data < key){
                pred = temp;
                temp = temp->right;
            }else{
                suced = temp;
                temp = temp->left;
            }
        }
        
        if(!temp)   return {pred, suced};
        
        Node* leftTree = temp->left;
        while(leftTree){
            pred = leftTree;
            leftTree = leftTree->right;
        }
        
        Node* rightTree = temp->right;
        while(rightTree){
            suced = rightTree;
            rightTree = rightTree->left;
        }
        
        return {pred, suced};
    }
};

int main() {
    Solution sol;

    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);

    auto res1 = sol.findPreSuc(root, 50);
    cout << (res1[0] ? res1[0]->data : -1) << " "
         << (res1[1] ? res1[1]->data : -1) << endl;

    auto res2 = sol.findPreSuc(root, 20);
    cout << (res2[0] ? res2[0]->data : -1) << " "
         << (res2[1] ? res2[1]->data : -1) << endl;

    auto res3 = sol.findPreSuc(root, 80);
    cout << (res3[0] ? res3[0]->data : -1) << " "
         << (res3[1] ? res3[1]->data : -1) << endl;

    return 0;
}
