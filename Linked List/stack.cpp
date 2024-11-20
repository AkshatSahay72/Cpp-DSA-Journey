#include<iostream>
using namespace std;

class Node{
    public:
        int val;
        Node *next;

        Node(int val){
            this->val = val;
            this->next = NULL;
        }
};

class Stack{
    private:
        Node *head = NULL;
    
    public:
        void push(int data){
            Node *newNode = new Node(data);
            newNode->next = head;
            head = newNode;
            cout << "Pushed Item" << endl;
        }

        void pop(){
            if(!head){
                cout << "Stack Underflow" << endl;
                return;
            }
            Node *toBeDeleted = head;
            head = head->next;
            cout << "Popped Element: " << toBeDeleted->val << endl;
            free(toBeDeleted);
        }

        void peek(){
            if(!head){
                cout << "Stack Underflow" << endl;
                return;
            }
            cout << "Top element: " << head->val;
        }

        void printMenu(){
            cout << endl;
            cout << "Menu: " << endl;
            cout << "0. Exit" << endl;
            cout << "1. Push" << endl;
            cout << "2. Pop" << endl;
            cout << "3. Peek" << endl;
            cout << endl;
        }
};

int main(){
    Stack s;
    int  n;
    do{
        s.printMenu();
        cin >> n;
        switch (n)
        {
        case 1:
            int data;
            cin >> data;
            s.push(data);
            break;

        case 2:
            s.pop();
            break;

        case 3:
            s.peek();
            break;

        case 0:
            return 0;


        default : 
            break;
        }
    } while (n != 0);

}