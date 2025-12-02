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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int, map<int, vector<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> q;

        if(root == NULL) return ans;

        q.push({root, {0,0}});
        while(!q.empty()){
            auto temp = q.front();
            q.pop();

            TreeNode* frontNode = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;

            nodes[hd][lvl].push_back(frontNode->val);

            if(frontNode->left)  
                q.push({frontNode->left, {hd-1, lvl+1}});
            if(frontNode->right)  
                q.push({frontNode->right, {hd+1, lvl+1}});
        }

        for(auto &i : nodes){
            vector<int> cur;
            for(auto &j : i.second){
                auto &v = j.second;
                sort(v.begin(), v.end());
                cur.insert(cur.end(), v.begin(), v.end());
            }
            ans.push_back(cur);
        }
        return ans;
    }
};

int main() {
    // making a small tree to test:
    //        3
    //       / \
    //      9  20
    //         /  \
    //        15   7

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution s;
    vector<vector<int>> res = s.verticalTraversal(root);

    for(auto &col : res){
        for(int x : col) cout << x << " ";
        cout << endl;
    }

    return 0;
}
