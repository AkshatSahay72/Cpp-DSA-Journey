#include<iostream>
#include<stack>
using namespace std;

int main(){
    // Creation of stack
    stack<int> s;

    // push operation
    s.push(2);
    s.push(3);

    // Pop
    s.pop();

    // Top
    cout << "Printing top element " << s.top() << endl;

    if(s.empty()){
        cout << "Stack is empty" << endl;
    }else{
        cout << "stack is not empty" << endl;
    }

    cout << "size of stack is " << s.size() << endl;

    return 0;
}