// GFG Practice & LeetCode 114: Flatten Binary Tree to Linked List

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
    void flatten(TreeNode* root) {
        TreeNode* cur = root;

        while(cur!=NULL){
            if(cur->left){
                TreeNode* pred = cur->left;
                while(pred->right)
                    pred = pred->right;
                
                pred->right = cur->right;
                cur->right = cur->left;
                cur->left = NULL;
            }

            cur = cur->right;
        }
    }
};

void printFlattened(TreeNode* root){
    while(root){
        cout << root->val << " ";
        root = root->right;
    }
    cout << endl;
}

int main() {
    Solution sol;

    // Test case 1
    TreeNode* root1 = new TreeNode(1,
        new TreeNode(2, new TreeNode(3), new TreeNode(4)),
        new TreeNode(5, nullptr, new TreeNode(6))
    );
    sol.flatten(root1);
    printFlattened(root1);

    // Test case 2
    TreeNode* root2 = new TreeNode(0);
    sol.flatten(root2);
    printFlattened(root2);

    // Test case 3
    TreeNode* root3 = nullptr;
    sol.flatten(root3);
    printFlattened(root3);

    return 0;
}
