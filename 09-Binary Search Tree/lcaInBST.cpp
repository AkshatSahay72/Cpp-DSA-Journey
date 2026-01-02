// GFG Practice: Lowest Common Ancestor in a BST
// LeetCode 235: Lowest Common Ancestor of a Binary Search Tree

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* temp = root;
        while(temp){
            if((temp->val >= p->val && temp->val <= q->val) ||
               (temp->val <= p->val && temp->val >= q->val)) 
                return temp;
            if(temp->val > p->val && temp->val > q->val)
                temp = temp->left;
            else
                temp = temp->right;
        }
        return NULL;
    }
};

int main() {
    Solution sol;

    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    cout << sol.lowestCommonAncestor(root, root->left, root->right)->val << endl;
    cout << sol.lowestCommonAncestor(root, root->left, root->left->right)->val << endl;
    cout << sol.lowestCommonAncestor(root, root->left->right->left, root->left->right->right)->val << endl;

    return 0;
}
