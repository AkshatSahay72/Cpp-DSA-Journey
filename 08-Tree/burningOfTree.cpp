// GFG Practice & LeetCode 2385 - Amount of Time for Binary Tree to Be Infected
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
    TreeNode* createMapping(TreeNode* root, int target, map<TreeNode*, TreeNode*> &mp){
        TreeNode* res = NULL;
        queue<TreeNode*> q;
        mp[root] = NULL;
        q.push(root);

        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();

            if(front->val == target){
                res = front;
            }

            if(front->left) {
                mp[front->left] = front;
                q.push(front->left);
            }
            if(front->right){
                mp[front->right] = front;
                q.push(front->right);
            }
        }
        return res;
    }

    void burnTree(TreeNode* root, map<TreeNode*, TreeNode*> &parent, int &ans){
        map<TreeNode*, bool> visited;
        visited[root] = true;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            bool flag = false;

            for(int i = 0; i < size ; i++){
                TreeNode* front = q.front();
                q.pop();

                if(front->left && !visited[front->left]){
                    q.push(front->left);
                    visited[front->left] = true;
                    flag = true;
                }
                if(front->right && !visited[front->right]){
                    q.push(front->right);
                    visited[front->right] = true;
                    flag = true;
                }
                if(parent[front] && !visited[parent[front]]){
                    q.push(parent[front]);
                    visited[parent[front]] = true;
                    flag = true;
                }
            }
            if(flag) ans++;
        }
    }

    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*, TreeNode*> parent;
        TreeNode* target = createMapping(root, start, parent);
        int ans = 0;
        burnTree(target, parent, ans);
        return ans;
    }
};

int main() {
    Solution sol;

    // Test case 1
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(5);
    root1->right = new TreeNode(3);
    root1->right->left = new TreeNode(10);
    root1->right->right = new TreeNode(6);
    root1->left->right = new TreeNode(4);
    cout << sol.amountOfTime(root1, 3) << endl;

    // Test case 2
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);
    root2->left->left = new TreeNode(4);
    root2->left->right = new TreeNode(5);
    cout << sol.amountOfTime(root2, 2) << endl;

    // Test case 3
    TreeNode* root3 = new TreeNode(1);
    cout << sol.amountOfTime(root3, 1) << endl;

    return 0;
}
