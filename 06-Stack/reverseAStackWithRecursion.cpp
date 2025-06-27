#include<iostream>
#include<stack>
using namespace std;

class Solution {
  public:
    void magic(stack<int> &St, int top){
        if(St.empty()){
            St.push(top);
            return;
        }
        int i = St.top();
        St.pop();
        magic(St,top);
        St.push(i);
    }
    void Reverse(stack<int> &St) {
        if(St.empty()){
            return;
        }
        int top = St.top();
        St.pop();
        Reverse(St);
        magic(St, top);
        
    }
};

int main(){
    stack<int> s;
    s.push(6);
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);


    stack<int> ns = s;
    while(!ns.empty()){
        cout << ns.top() << " ";
        ns.pop();
    }
    cout << endl;

    Solution solve;
    solve.Reverse(s);

    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}