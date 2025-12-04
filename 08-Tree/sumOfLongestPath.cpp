#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

// Your solution class here
class Solution {
  public:
    int sumOfLongRootToLeafPath(Node *root) {
        if(!root) return 0;

        pair<int,int> ans = {root->data, 1};

        queue<pair<Node*, pair<int,int>>> q;
        q.push({root, {root->data,1}});

        while(!q.empty()){
            Node* temp = q.front().first;
            auto dta = q.front().second;
            q.pop();

            if(!temp->left && !temp->right)
                if(dta.second > ans.second || 
                   (dta.second == ans.second && dta.first > ans.first))
                    ans = dta;

            if(temp->left)
                q.push({temp->left, {dta.first + temp->left->data, dta.second+1}});

            if(temp->right)
                q.push({temp->right, {dta.first + temp->right->data, dta.second+1}});
        }

        return ans.first;
    }
};

int main() {
    // Build a sample tree
    /*
            1
           / \
          2   3
         /   / \
        4   5   6
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);

    Solution obj;

    cout << obj.sumOfLongRootToLeafPath(root) << endl;

    return 0;
}
