// GFG Practice & LeetCode 106 - Construct Binary Tree from Inorder and Postorder Traversal
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
    void getMap(vector<int> &inorder, map<int, int> &nodeToIndex, int n){
        for(int i = 0; i < n; i++){
            nodeToIndex[inorder[i]] = i;
        }
    }

    TreeNode* magic(vector<int>& inorder, vector<int>& postorder, int &postIndex,
                    int inorderStart, int inorderEnd, map<int, int> &nodeToIndex){
        if(postIndex < 0 || inorderStart > inorderEnd){
            return NULL;
        }

        int value = postorder[postIndex--];
        TreeNode* root = new TreeNode(value);

        int idx = nodeToIndex[value];

        root->right = magic(inorder, postorder, postIndex, idx + 1, inorderEnd, nodeToIndex);
        root->left  = magic(inorder, postorder, postIndex, inorderStart, idx - 1, nodeToIndex);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> m;
        int n = inorder.size();
        getMap(inorder, m, n);
        int postIndex = n - 1;
        return magic(inorder, postorder, postIndex, 0, n - 1, m);
    }
};

void preorder(TreeNode* root){
    if(!root) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    Solution sol;

    // Test case 1
    vector<int> inorder1   = {9, 3, 15, 20, 7};
    vector<int> postorder1 = {9, 15, 7, 20, 3};
    TreeNode* root1 = sol.buildTree(inorder1, postorder1);
    preorder(root1);
    cout << endl;

    // Test case 2
    vector<int> inorder2   = {2, 1, 3};
    vector<int> postorder2 = {2, 3, 1};
    TreeNode* root2 = sol.buildTree(inorder2, postorder2);
    preorder(root2);
    cout << endl;

    // Test case 3
    vector<int> inorder3   = {4, 2, 5, 1, 6, 3};
    vector<int> postorder3 = {4, 5, 2, 6, 3, 1};
    TreeNode* root3 = sol.buildTree(inorder3, postorder3);
    preorder(root3);
    cout << endl;

    return 0;
}
