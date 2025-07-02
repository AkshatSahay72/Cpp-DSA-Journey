#include <iostream>
#include <vector>
using namespace std;

class NStack{
    int *arr, *top, *next;
    int n, s;
    int freeSpot;

    public:
    NStack(int n, int s){
        this->n = n;
        this->s = s;
        arr = new int[s];

        top = new int[n];
        next = new int[s];

        for (int i = 0; i < n;i++){
            top[i] = -1;

        }

        for (int i = 0; i < s;i++){
            next[i] = i + 1;
        }
        next[s - 1] = -1;
        freeSpot = 0;
    }

    void push(int x, int m){
        if(freeSpot == -1){
            cout << "Stack Overflow" << endl;
            return;
        }
        int index = freeSpot;
        freeSpot = next[index];
        arr[index] = x;
        next[index] = top[m - 1];
        top[m - 1] = index;
    }

    int pop(int m){
        if(top[m-1] == -1){
            return -1;
        }
        int index = top[m - 1];
        top[m - 1] = next[index];
        next[index] = freeSpot;
        freeSpot = index;
        return arr[index];
    }
};

int main() {
    NStack stacks(3, 10); // 3 stacks in total size 10

    // Stack 1
    stacks.push(10, 1);
    stacks.push(20, 1);
    stacks.push(30, 1);

    // Stack 2
    stacks.push(100, 2);
    stacks.push(200, 2);

    // Stack 3
    stacks.push(1000, 3);

    cout << "Popped from stack 1: " << stacks.pop(1) << endl; // 30
    cout << "Popped from stack 2: " << stacks.pop(2) << endl; // 200
    cout << "Popped from stack 3: " << stacks.pop(3) << endl; // 1000

    // Push more into Stack 3
    stacks.push(3000, 3);
    stacks.push(4000, 3);

    cout << "Popped from stack 3: " << stacks.pop(3) << endl; // 4000
    cout << "Popped from stack 3: " << stacks.pop(3) << endl; // 3000
    cout << "Popped from stack 3 (empty): " << stacks.pop(3) << endl; // -1

    return 0;
}
