#include<iostream>
using namespace std;

int countDistinctWay(int n, int i){
    if(i == n){
        return 1;
    }

    if(i>n){
        return 0;
    }

    return (countDistinctWay(n, i + 1) + countDistinctWay(n, i + 2)); 
}

int main(){
    int n = 7;
    cout << countDistinctWay(n,0) << endl;
}