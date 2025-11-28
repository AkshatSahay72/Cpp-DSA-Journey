#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;

        queue<TreeNode*> q;
        q.push(root);

        bool leftToRight = true;
        
        while(!q.empty()){
            int size = q.size();
            vector<int> temp;

            for(int i = 0; i < size; i++){
                TreeNode* frontNode = q.front();
                q.pop();

                temp.push_back(frontNode->val);

                if(frontNode->left)  q.push(frontNode->left);
                if(frontNode->right) q.push(frontNode->right);
            }

            if(!leftToRight) reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            leftToRight = !leftToRight;
        }
        return ans;
    }
};

int main() {
    /*
            1
           / \
          2   3
         / \   \
        4   5   6

    Zigzag Output:
    1
    3 2
    4 5 6
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    Solution obj;
    vector<vector<int>> result = obj.zigzagLevelOrder(root);

    for(auto level : result){
        for(int val : level){
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
