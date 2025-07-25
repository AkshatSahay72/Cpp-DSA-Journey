#include<iostream>
using namespace std;

class Queue{
    public:
    int n;
    int k;
    int freeSpot;
    int *arr;
    int *front;
    int *rear;
    int *next;

    Queue(int n, int k){
        this->n = n;
        this->k = k;
        arr = new int[n];
        front = new int[k];
        rear = new int[k];
        next = new int[n];
        freeSpot = 0;

        for (int i = 0; i < k;i++){
            front[i] = -1;
            rear[i] = -1; 
        }
        for (int i = 0; i < n; i++)
        {
            next[i] = i + 1;
        }
        next[n - 1] = -1;


    }
    
    void push(int q, int val){
        if(freeSpot == -1){
            cout << "Queue Overflowed" << endl;
            return;
        }
        int index = freeSpot;
        freeSpot = next[index];

        if(front[q-1] == -1){
            front[q-1] = index;
        }else{
            
            next[rear[q-1]] = index;
        }
        rear[q-1] = index;
        arr[index] = val;
        next[index] = -1;

    }

    int pop(int q){
        if(front[q-1] == -1){
            cout << "Queue underflow" << endl;
            return -1;
        }

        int index = front[q-1];
        front[q-1] = next[index];
        next[index] = freeSpot;
        freeSpot = index;
        return arr[index];
    }

    int top(int q){
        if(isEmpty(q-1)){
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front[q]];
    }

    bool isEmpty(int q){
        return front[q - 1] == -1;
    }
};

int main() {
    Queue q(10, 3); // 10-sized array for 3 queues

    q.push(1, 10);
    q.push(1, 20);
    q.push(2, 30);
    q.push(3, 40);
    q.push(1, 50);

    cout << "Pop from queue 1: " << q.pop(1) << endl;
    cout << "Top of queue 1: " << q.top(1) << endl;

    cout << "Pop from queue 2: " << q.pop(2) << endl;
    cout << "Top of queue 3: " << q.top(3) << endl;

    q.push(2, 60);
    q.push(2, 70);

    cout << "Pop from queue 2: " << q.pop(2) << endl;
    cout << "Top of queue 2: " << q.top(2) << endl;

    return 0;
}