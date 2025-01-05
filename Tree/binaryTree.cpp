#include<iostream>
#include<queue>
using namespace std;

class TreeNode{
    public:
        int data;
        TreeNode *left;
        TreeNode *right;
    
    TreeNode(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

TreeNode* buildTree(TreeNode* root){
    // cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new TreeNode(data);

    if(data == -1){
        return NULL;
    }

    // cout << "Enter data for Left child of " << data << endl;
    root->left = buildTree(root->left);
    // cout << "Enter data for Right child of " << data << endl;
    root->right = buildTree(root->right);
    return root;
} 

void levelOrderTraversal(TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        TreeNode *front = q.front();
        q.pop();
        if(!front){   
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            
            cout << front->data << " ";
            if(front->left){
                q.push(front->left);
            }
            if(front->right){
                q.push(front->right);
            }
        }
    }
    cout << endl;
}

void inorderTraversal(TreeNode* root){
    if(!root){
        return;
    }

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

void preOrderTraversal(TreeNode* root){
    if(!root){
        return;
    }

    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(TreeNode* root){
    if(!root){
        return;
    }

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

int main(){
    TreeNode *root = NULL;
    cout << "Enter Tree: ";
    root = buildTree(root);
    //Sample tree: 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
    //Sample tree: 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
    cout << "Level order traversal: "<<endl;
    levelOrderTraversal(root);

    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    cout << endl;

    cout << "Preorder Traversal: ";
    preOrderTraversal(root);
    cout << endl;

    cout << "Inorder Traversal: ";
    postOrderTraversal(root);
    cout << endl;
}