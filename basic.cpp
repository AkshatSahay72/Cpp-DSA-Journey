// Forward declaration for insertIntoBST
Node* insertIntoBST(Node* root, int data);

void takeInput(Node*& root){ // Pass root by reference to modify it
    int data;
    cin >> data;
    while (data != -1) {
        root = insertIntoBST(root, data); // Assign the returned root
        cin >> data;
    }
}