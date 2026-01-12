// GFG Practice: Balanced BST
// LeetCode 1382: Balance a Binary Search Tree

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

    TreeNode* magic(int s, int e, vector<int> &arr){
        if(s > e) return NULL;
        int mid = (s + e) / 2;
        TreeNode* root = new TreeNode(arr[mid]);
        root->left = magic(s, mid - 1, arr);
        root->right = magic(mid + 1, e, arr);
        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inord;
        inorder(root, inord);
        return magic(0, inord.size() - 1, inord);
    }
};

void printInorder(TreeNode* root){
    if(!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    Solution sol;

    TreeNode* root1 = new TreeNode(1);
    root1->right = new TreeNode(2);
    root1->right->right = new TreeNode(3);
    root1->right->right->right = new TreeNode(4);
    TreeNode* b1 = sol.balanceBST(root1);
    printInorder(b1);
    cout << endl;

    TreeNode* root2 = new TreeNode(10);
    root2->left = new TreeNode(8);
    root2->left->left = new TreeNode(7);
    root2->left->left->left = new TreeNode(6);
    TreeNode* b2 = sol.balanceBST(root2);
    printInorder(b2);
    cout << endl;

    TreeNode* root3 = new TreeNode(2);
    root3->left = new TreeNode(1);
    root3->right = new TreeNode(3);
    TreeNode* b3 = sol.balanceBST(root3);
    printInorder(b3);
    cout << endl;

    return 0;
}
