#include<iostream>
#include<queue>
using namespace std;

int main(){
    priority_queue<int> pq;
    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);

    cout<< pq.top()<<endl;
    pq.pop();
    cout<< pq.top()<<endl;

    priority_queue<int, vector<int>,greater<int>> minHeap;
    minHeap.push(4);
    minHeap.push(2);
    minHeap.push(5);
    minHeap.push(3);

    cout<< minHeap.top()<<endl;
    minHeap.pop();
    cout<< minHeap.top()<<endl;
    

}