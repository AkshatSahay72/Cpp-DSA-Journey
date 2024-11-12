#include<iostream>
using namespace std;

int magic(int n){
    if(n<0)
        return 0;
    if (n == 0)
        return 1;

    int ans = magic(n - 1) + magic(n - 2);

    return ans;
}

int main(){
    int n;
    cout << "Enter stair: ";
    cin >> n;
    int ans = magic(n);
    cout << "No. of distinct way " << ans << endl;
}