#include<iostream>
using namespace std;

class TreeNode{
    public:
        int data;
        TreeNode* left;
        TreeNode* right;

    TreeNode(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void noOfLeafNodes(TreeNode* root, int &count){
    if(!root){
        return;
    }

    noOfLeafNodes(root->left,count);
    noOfLeafNodes(root->right,count);

    if(!root->left && !root->right){
        count++; 
    }

}

// Yeah Yeah I Know main() is ai generated 
int main() {
    // 🌳 Test Case 1: Simple tree with only one node
    TreeNode* root1 = new TreeNode(10);
    int count1 = 0;
    noOfLeafNodes(root1, count1);
    cout << "Test 1 - Leaf Nodes: " << count1 << endl; // Expected: 1

    // 🌲 Test Case 2: Tree with 3 nodes
    //       5
    //      / \
    //     3   7
    TreeNode* root2 = new TreeNode(5);
    root2->left = new TreeNode(3);
    root2->right = new TreeNode(7);
    int count2 = 0;
    noOfLeafNodes(root2, count2);
    cout << "Test 2 - Leaf Nodes: " << count2 << endl; // Expected: 2

    // 🌴 Test Case 3: Bigger unbalanced tree
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5
    TreeNode* root3 = new TreeNode(1);
    root3->left = new TreeNode(2);
    root3->right = new TreeNode(3);
    root3->left->left = new TreeNode(4);
    root3->left->right = new TreeNode(5);
    int count3 = 0;
    noOfLeafNodes(root3, count3);
    cout << "Test 3 - Leaf Nodes: " << count3 << endl; // Expected: 3 (nodes 3,4,5)

    return 0;
}