#include<iostream>
using namespace std;

void magic(string &str,int s,int e){
    if(s>e){
        return;
    }
    swap(str[s], str[e]);
 
    magic(str, s+1, e-1);
}

int main(){
    string s = "Aki";
    magic(s, 0, s.size() - 1);
    cout << s << endl;
}
