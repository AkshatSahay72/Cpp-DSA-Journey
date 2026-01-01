// GFG Practice: Kth Smallest Element in BST
// LeetCode 230: Kth Smallest Element in a BST

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
    int magic(TreeNode* root, int &i, int k){
        if(!root)   return -1;

        int left = magic(root->left, i, k);
        if(left != -1) return left;

        i++;
        if(i == k){
            return root->val;
        }

        return magic(root->right, i, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        int i = 0;
        return magic(root, i, k);
    }
};

int main() {
    Solution s;

    TreeNode* t1 = new TreeNode(3,
                        new TreeNode(1,
                            nullptr,
                            new TreeNode(2)),
                        new TreeNode(4));
    cout << s.kthSmallest(t1, 1) << endl;

    TreeNode* t2 = new TreeNode(5,
                        new TreeNode(3,
                            new TreeNode(2,
                                new TreeNode(1),
                                nullptr),
                            new TreeNode(4)),
                        new TreeNode(6));
    cout << s.kthSmallest(t2, 3) << endl;

    TreeNode* t3 = new TreeNode(10,
                        new TreeNode(5,
                            new TreeNode(2),
                            new TreeNode(8)),
                        new TreeNode(15,
                            new TreeNode(12),
                            new TreeNode(20)));
    cout << s.kthSmallest(t3, 5) << endl;

    return 0;
}
