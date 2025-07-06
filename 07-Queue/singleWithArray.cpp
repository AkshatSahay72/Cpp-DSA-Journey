#include<iostream>
using namespace std;

class Queue{
    int *arr;
    int front;
    int rear;
    int size;

    public:
    Queue(int n){
        size = n;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    void enqueue(int data){
        if(rear == size){
            cout << "Queue overflow" << endl;
            return;
        }
        arr[rear++] = data;
    }

    void dequeue(){
        if(front == rear){
            cout << "Queue underflow" << endl;
            return;
        }
        cout << "Removed : " << arr[0] << endl;
        for(int i = 1; i < rear; i++){
            arr[i-1] = arr[i];
        }
        rear--;
    }

    void frontEle(){
        if(front == rear){
            cout << "Queue underflow" << endl;
            return;
        }
        cout << "Front element : " << arr[front] << endl;
    }
};

int main(){
    Queue q(5);
    q.enqueue(10);
    q.enqueue(13);
    q.enqueue(44);
    q.enqueue(22);
    q.dequeue();
    q.dequeue();
    q.frontEle();
    
}