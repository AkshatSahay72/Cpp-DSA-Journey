#include<iostream>
#include<stack>
using namespace std;

class Solution {
  public:
    void magic(stack<int>&s, int count,int size){
        if(count == size/2){
            s.pop();
            return;
        }
        int a = s.top();
        s.pop();
        magic(s,count+1,size);
        s.push(a);
    }
  
    // Function to delete middle element of a stack.
    void deleteMid(stack<int>& s) {
        // code here..
        int count = 0;
        magic(s,count,s.size());
    }
};

int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);

    Solution solve;
    solve.deleteMid(s);

    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}