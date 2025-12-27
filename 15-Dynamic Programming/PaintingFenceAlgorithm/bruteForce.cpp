#include<iostream>
using namespace std;

int numberOfWays(int n, int k){
    if(n==1) return k;
    if(n==2) return k + (k * (k-1));

    int ans = (numberOfWays(n-2,k) * (k-1)) + (numberOfWays(n-1, k) * (k-1));
    return ans;
}

int main(){
    cout<< numberOfWays(3,2)<<endl;
}
