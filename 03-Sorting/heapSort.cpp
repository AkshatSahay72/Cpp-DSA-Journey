#include<iostream>
using namespace std;

void heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left<n && arr[largest] < arr[left]){
        largest = left;
    }
    if(right<n && arr[largest] < arr[right]){
        largest = right;
    }
    if(largest!=i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }

    return;
}

void heapSort(int arr[], int n){

    for (int i = n - 1; i >= 0;i--){
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main(){
    int size = 6;
    int arr[size] = {76, 3, 6, 98, 22, 55};

    for (int i = size / 2 - 1; i >= 0;i--){
        heapify(arr, size, i);
    }

    heapSort(arr, size);

    for(auto ele: arr){
        cout << ele << " ";
    }
    cout << endl;
}