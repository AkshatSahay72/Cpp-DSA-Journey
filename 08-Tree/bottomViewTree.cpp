#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        vector<int> ans;
        if(!root) return ans;
        
        map<int, int> bottoms;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            
            Node* frontNode = temp.first;
            int hd = temp.second;
            
            // bottom view = overwrite every time
            bottoms[hd] = frontNode->data;
            
            if(frontNode->left)  
                q.push({frontNode->left, hd - 1});
            if(frontNode->right) 
                q.push({frontNode->right, hd + 1});
        }
        
        for(auto &i : bottoms)
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
    // Bottom view: 2 1 3
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);

    cout << "Testcase 1: ";
    printVector(sol.bottomView(root1));


    // ---------- TESTCASE 2 ----------
    // Tree:
    //         20
    //       /    \
    //      8      22
    //     / \       \
    //    5   3       25
    //       / \
    //      10 14
    //
    // Bottom view: 5 10 3 14 25
    Node* root2 = new Node(20);
    root2->left = new Node(8);
    root2->right = new Node(22);
    root2->left->left = new Node(5);
    root2->left->right = new Node(3);
    root2->left->right->left = new Node(10);
    root2->left->right->right = new Node(14);
    root2->right->right = new Node(25);

    cout << "Testcase 2: ";
    printVector(sol.bottomView(root2));


    // ---------- TESTCASE 3 ----------
    // Tree:
    //       10
    //         \
    //          15
    //            \
    //             20
    // Bottom view: 10 15 20
    Node* root3 = new Node(10);
    root3->right = new Node(15);
    root3->right->right = new Node(20);

    cout << "Testcase 3: ";
    printVector(sol.bottomView(root3));

    return 0;
}
