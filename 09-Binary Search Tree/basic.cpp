#include<bits/stdc++.h>
using namespace std;

class Node{

public:
    int data;
    Node* left; 
    Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

};

Node* insertIntoBST(Node* root, int data){
    if(root == nullptr){
        return new Node(data);
    }
    
    if(data > root->data){
        root->right = insertIntoBST(root->right, data);
    } else {
        root->left = insertIntoBST(root->left, data);
    }
    return root;
}

void takeInput(Node*& root){
    int data;
    cin >> data;
    while (data != -1) {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

void LevelOrderTraversal(Node* root){
    if(root == NULL) return;
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()){
        int s = q.size();
        for(int i = 0; i< s;i++){
            Node* front = q.front();
            q.pop();

            cout<<front->data<<" ";

            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
        }
        cout<<endl;
    }
}

void inorder(Node* root){
    if(!root)   return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    Node* root = NULL;
    cout << "Enter data to create BST"<<endl;
    takeInput(root);

    cout << "Level Order Traversal of BST:" << endl;
    LevelOrderTraversal(root);
    cout<<"Inorder Traversal of BST:"<<endl;
    inorder(root);
}