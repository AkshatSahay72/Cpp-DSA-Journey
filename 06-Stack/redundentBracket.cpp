#include<iostream>
#include<stack>
using namespace std;

class Solution {
  public:
    int checkRedundancy(string s) {
        // code here
        stack<char> st;
        for(char i: s){
            if(i == '(' || i == '+' || i == '-' || i == '*' || i == '/'){
                st.push(i);
            }else{
                if(i == ')'){
                    bool check = true;
                    while(st.top() != '('){
                        char top = st.top();
                        if(top == '+' || top == '-' || top == '*' || top == '/'){
                            check = false;
                        }
                        st.pop();
                    }
                    if(check){
                        return 1;
                    }
                    st.pop();
                }
            }
        }
        return 0;
    }
};

int main(){
    string t1 = "((a+b))";
    string t2 = "(a+b+(c+d+(a*g)))";
    Solution test;
    cout << t1 << " : " << test.checkRedundancy(t1) << endl;
    cout << t2 << " : " << test.checkRedundancy(t2) << endl;
}