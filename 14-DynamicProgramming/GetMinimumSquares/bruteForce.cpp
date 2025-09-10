#include<iostream>
#include <algorithm>
using namespace std;

int getMin(int n){
    if(n==0) return 0;
    int ans = n;
    for(int i = 1; i*i <=n ;i++){
        ans = min(ans, 1 + getMin(n - (i*i)));
    }
    return ans;
}

int main(){
    int n = 12;
    cout<<getMin(n)<<endl;
}