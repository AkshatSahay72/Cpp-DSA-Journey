#include <iostream>
#include <stack>
using namespace std;

class SortedStack {
public:
    stack<int> s;
    void sort();
};

void magic(stack<int> &s, int a){
    if(s.empty() || s.top()<a){
        s.push(a);
        return;
    }
    
    int top = s.top();
    s.pop();
    magic(s,a);
    s.push(top);
    
}
void SortedStack ::sort() {
    // Your code here
    if(s.empty()){
        return;
    }
    int a = s.top();
    s.pop();
    sort();
    magic(s, a);
}
void printStack(stack<int> s) {
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}


int main() {
    SortedStack ss;

    // Push elements (you can modify this)
    ss.s.push(30);
    ss.s.push(10);
    ss.s.push(50);
    ss.s.push(20);
    ss.s.push(40);

    cout << "Original stack (top to bottom): ";
    printStack(ss.s);

    ss.sort();

    cout << "Sorted stack (top to bottom): ";
    printStack(ss.s);

    return 0;
}