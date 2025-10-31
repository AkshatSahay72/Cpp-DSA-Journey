#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

    Node(int val){
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildFromLevelOrder(){
    queue<Node*> q;
    int data;
    cin>>data;
    if (data == -1) return NULL;

    Node* root = new Node(data);
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        int leftData, rightData;
        cin>>leftData>>rightData;
        if(leftData != -1){
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        if(rightData!=-1){
            temp->right = new Node(rightData);
            q.push(temp->right);
        }

    }
    return root;
}

void inorderTraversal(Node* root){
    if(!root)   return;

    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}



int main(){
    Node* ans = buildFromLevelOrder();
    inorderTraversal(ans);

    return 0;

}