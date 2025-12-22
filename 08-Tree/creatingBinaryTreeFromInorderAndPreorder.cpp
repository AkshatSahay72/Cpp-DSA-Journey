// GFG Practice & LeetCode 105 - Construct Binary Tree from Preorder and Inorder Traversal
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
    void getPos(vector<int> &inorder, map<int, int> &helper){
        for(int i = 0; i < inorder.size(); i++){
            helper[inorder[i]] = i;
        }
    }

    TreeNode* magic(vector<int>& preorder, vector<int>& inorder,
                    int &preIndex, int inorderStart, int inorderEnd,
                    int n, map<int, int> &helper){
        if(preIndex >= n || inorderStart > inorderEnd){
            return NULL;
        }

        int value = preorder[preIndex++];
        TreeNode* root = new TreeNode(value);

        int pos = helper[value];
        root->left = magic(preorder, inorder, preIndex, inorderStart, pos - 1, n, helper);
        root->right = magic(preorder, inorder, preIndex, pos + 1, inorderEnd, n, helper);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIndex = 0;
        map<int, int> helper;
        getPos(inorder, helper);

        return magic(preorder, inorder, preIndex, 0,
                     preorder.size() - 1, preorder.size(), helper);
    }
};

void printTree(TreeNode* root) {
    if (!root) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int sz = q.size();
        while (sz--) {
            TreeNode* curr = q.front(); q.pop();
            cout << curr->val << " ";

            if (curr->left)  q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
        cout << endl;
    }
}


int main() {
    Solution sol;

    vector<int> preorder1 = {3, 9, 20, 15, 7};
    vector<int> inorder1  = {9, 3, 15, 20, 7};
    TreeNode* t1 = sol.buildTree(preorder1, inorder1);
    printTree(t1);
    cout<<endl;

    vector<int> preorder2 = {1, 2, 4, 5, 3};
    vector<int> inorder2  = {4, 2, 5, 1, 3};
    TreeNode* t2 = sol.buildTree(preorder2, inorder2);
    printTree(t2);
    cout << endl;

    vector<int> preorder3 = {1};
    vector<int> inorder3  = {1};
    TreeNode* t3 = sol.buildTree(preorder3, inorder3);
    printTree(t3);
    cout << endl;

    return 0;
}
