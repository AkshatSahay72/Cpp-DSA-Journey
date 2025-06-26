#include<iostream>
using namespace std;

void sortArr(int *arr, int n){

    if(n <= 1){
        return;
    }

    for (int i = 0; i < n - 1; i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i], arr[i + 1]);
        }
    }
    sortArr(arr, n - 1);
}

int main(){
    int arr[7] = {4, 7, 2, 6, 1, 7, 9};
    sortArr(arr, 7);

    for(int i: arr){
        cout << i << " ";
    }
}