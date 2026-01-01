// GFG Practice: Check for BST
// LeetCode 98: Validate Binary Search Tree

#include <bits/stdc++.h>
using namespace std;

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
    bool magic(TreeNode* root, long long min, long long max){
        if(!root)   return true;
        if(root->val > min && root->val < max){
            bool left = magic(root->left, min, root->val);
            bool right = magic(root->right, root->val, max);
            return left && right;
        }
        return false;
    }

    bool isValidBST(TreeNode* root) {
        return magic(root, LLONG_MIN, LLONG_MAX);
    }
};

int main() {
    Solution s;

    TreeNode* t1 = new TreeNode(2,
                        new TreeNode(1),
                        new TreeNode(3));
    cout << s.isValidBST(t1) << endl;

    TreeNode* t2 = new TreeNode(5,
                        new TreeNode(1),
                        new TreeNode(4,
                            new TreeNode(3),
                            new TreeNode(6)));
    cout << s.isValidBST(t2) << endl;

    TreeNode* t3 = new TreeNode(10,
                        new TreeNode(5,
                            new TreeNode(2),
                            new TreeNode(8)),
                        new TreeNode(15,
                            new TreeNode(12),
                            new TreeNode(20)));
    cout << s.isValidBST(t3) << endl;

    return 0;
}
