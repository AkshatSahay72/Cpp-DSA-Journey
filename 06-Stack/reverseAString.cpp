#include<iostream>
#include<stack>
using namespace std;

int main(){
    string input = "Hello world";
    stack<char> s;
    for(auto i: input){
        s.push(i);
    }
    string ans;
    while (!s.empty())
    {
        ans += s.top();
        s.pop();
    }

    cout << ans << endl;
}