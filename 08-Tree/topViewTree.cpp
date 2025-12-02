#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
  public:
    vector<int> topView(Node *root) {
        vector<int> ans;
        if(!root) return ans;

        map<int, int> tops;
        queue<pair<Node*, int>> q;
        q.push({root, 0});

        while(!q.empty()){
            auto frontNode = q.front();
            q.pop();
            
            Node* nod = frontNode.first;
            int hd = frontNode.second;
            
            if(tops.find(hd) == tops.end())
                tops[hd] = nod->data;
            
            if(nod->left)
                q.push({nod->left, hd-1});
            if(nod->right)
                q.push({nod->right, hd+1});
        }

        for(auto &i : tops)
            ans.push_back(i.second);

        return ans;
    }
};

void printVector(vector<int> v){
    for(int x : v) cout << x << " ";
    cout << "\n";
}

int main(){

    Solution sol;

    // ---------- TESTCASE 1 ----------
    // Tree:
    //       1
    //     /   \
    //    2     3
    // Top view: 2 1 3
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);

    cout << "Testcase 1: ";
    printVector(sol.topView(root1));


    // ---------- TESTCASE 2 ----------
    // Tree:
    //         10
    //       /    \
    //      5      20
    //     / \       \
    //    3   7       30
    // Top view: 3 5 10 20 30
    Node* root2 = new Node(10);
    root2->left = new Node(5);
    root2->right = new Node(20);
    root2->left->left = new Node(3);
    root2->left->right = new Node(7);
    root2->right->right = new Node(30);

    cout << "Testcase 2: ";
    printVector(sol.topView(root2));


    // ---------- TESTCASE 3 ----------
    // Tree:
    //           8
    //            \
    //             10
    //               \
    //                14
    // Top view: 8 10 14
    Node* root3 = new Node(8);
    root3->right = new Node(10);
    root3->right->right = new Node(14);

    cout << "Testcase 3: ";
    printVector(sol.topView(root3));

    return 0;
}
