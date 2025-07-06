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

class Queue{
    public:
        Node *head;
        Node *tail;

        Queue(){
            head = NULL;
            tail = NULL;
        }

        bool empty(){
            return head == NULL;
        }

        void enqueue(int data){
            Node *newNode = new Node(data);
            if(head == NULL){
                head = newNode;
                tail = head;
                return;
            }
            tail->next = newNode;
            tail = newNode;
        }

        void dequeue(){
            if(head==NULL){
                cout << "Queue is empty" << endl;
                return;
            }
            Node *toBeDeleted = head;
            head = head->next;
            cout << "Deleted the element : " << toBeDeleted->val << endl;
            delete toBeDeleted;
        }

        int front(){
            if(head)
                return head->val;
            return -1;
        }
};

int main(){
    Queue q;
    q.enqueue(10);
    q.enqueue(83);
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.enqueue(23);
    q.enqueue(56);
    cout << "Front element : " << q.front() << endl;

}