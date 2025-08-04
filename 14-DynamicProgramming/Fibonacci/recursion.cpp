#include<iostream>
#include<vector>
using namespace std;

int fibo(int n){
    if(n<=1)
        return n;

    return fibo(n - 1) + fibo(n - 2);
}

int main(){
    int n = 6;

    cout << fibo(n) << endl;
}