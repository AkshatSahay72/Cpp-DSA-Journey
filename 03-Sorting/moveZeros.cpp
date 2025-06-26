#include<iostream>
using namespace std;

int main(){
    int n = 6;
    int arr[n] = {0, 1, 0, 3, 12, 0};
    int i = 0;
    for (int j = 0; j < n;j++){
        if(arr[j]!=0){
            swap(arr[j], arr[i]);
            i++;
        }
    }
    for (int i = 0; i < n-1;i++){
        cout << arr[i] << " ";
    }
}