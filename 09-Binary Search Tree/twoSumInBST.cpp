// GFG Practice: Find a pair with given target in BST
// LeetCode 653: Two Sum IV - Input is a BST

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void inorder(TreeNode* root, vector<int> &arr){
        if(!root) return;

        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> sorted;
        inorder(root, sorted);
        
        int i = 0, j = sorted.size() - 1;

        while(i < j){
            int sum = sorted[i] + sorted[j];
            if(sum == k) return true;
            else if(sum > k) j--;
            else i++;
        }
        return false;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    TreeNode* root1 = new TreeNode(5);
    root1->left = new TreeNode(3);
    root1->right = new TreeNode(6);
    root1->left->left = new TreeNode(2);
    root1->left->right = new TreeNode(4);
    root1->right->right = new TreeNode(7);
    cout << sol.findTarget(root1, 9) << endl;   // expected: 1

    // Test Case 2
    TreeNode* root2 = new TreeNode(2);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(3);
    cout << sol.findTarget(root2, 4) << endl;   // expected: 1

    // Test Case 3
    TreeNode* root3 = new TreeNode(1);
    root3->right = new TreeNode(3);
    cout << sol.findTarget(root3, 5) << endl;   // expected: 0

    return 0;
}
