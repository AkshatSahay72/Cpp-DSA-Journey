// GFG Practice: Construct BST from Preorder
// LeetCode 1008: Construct Binary Search Tree from Preorder Traversal

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
    TreeNode* magic(int mini, int maxi, vector<int>& preorder, int &i){
        if(i >= preorder.size() || preorder[i] < mini || preorder[i] > maxi)
            return NULL;

        TreeNode* root = new TreeNode(preorder[i++]);
        root->left = magic(mini, root->val, preorder, i);
        root->right = magic(root->val, maxi, preorder, i);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return magic(INT_MIN, INT_MAX, preorder, i);
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

    vector<int> pre1 = {8, 5, 1, 7, 10, 12};
    TreeNode* r1 = sol.bstFromPreorder(pre1);
    printInorder(r1);
    cout << endl;

    vector<int> pre2 = {1, 2, 3, 4, 5};
    TreeNode* r2 = sol.bstFromPreorder(pre2);
    printInorder(r2);
    cout << endl;

    vector<int> pre3 = {5, 4, 3, 2, 1};
    TreeNode* r3 = sol.bstFromPreorder(pre3);
    printInorder(r3);
    cout << endl;

    return 0;
}
