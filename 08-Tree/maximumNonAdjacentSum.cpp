#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
  public:
    pair<int, int> magic(Node* root){
        if(!root){
            return make_pair(0, 0);
        }
        
        pair<int, int> leftPair = magic(root->left);
        pair<int, int> rightPair = magic(root->right);
        
        pair<int, int> res;
        
        // include current node
        res.first = root->data + leftPair.second + rightPair.second;
        
        // exclude current node
        res.second = max(leftPair.first, leftPair.second) 
                   + max(rightPair.first, rightPair.second);
        
        return res;
    }
  
    int getMaxSum(Node *root) {
        pair<int, int> ans = magic(root);
        return max(ans.first, ans.second);
    }
};

int main() {
    /*
            10
           /  \
          1    2
         / \    \
        3   4    5
    */

    Node* root = new Node(10);
    root->left = new Node(1);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(5);

    Solution obj;
    cout << obj.getMaxSum(root) << endl;

    return 0;
}
