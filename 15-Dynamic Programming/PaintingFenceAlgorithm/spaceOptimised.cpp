#include<iostream>
#include<vector>
using namespace std;

int numberOfWays(int n, int k){
    if(n==1) return k;

    int prev1 = k;
    int prev2 = k + (k * (k-1));

    for(int i = 3; i<=n;i++){
        int ans = prev1*(k-1) + prev2*(k-1);
        prev2 = prev1;
        prev1 = ans;
    }

    return prev1;
}

int main(){
    cout<< numberOfWays(3,2)<<endl;
}
