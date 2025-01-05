#include<iostream>
using namespace std;

void insert(int arr[], int n, int &size, int val){
    arr[size] = val;
    int i = size;
    size++;

    while (i > size && arr[(i-1)/2]<arr[i]){
        swap(arr[i], arr[(i - 1) / 2]);
        i = (i - 1) / 2; 
    }
}

void heapify(int arr[], int n, int i){
    int large = i;
    int left = i / 2 + 1;
    int right = i / 2 + 2;

    if (left < n && arr[large]<arr[left]){
        large = left;
    }
    if (right < n && arr[large]<arr[right]){
        large = right;
    }

    if(i!=large){
        swap(arr[i], arr[large]);
        heapify(arr, n, large);
    }
}

void heapSort(int arr[], int n){
    for (int i = n - 1; i >= 0;i--){
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}


int main()
{
    int n;
    cin >> n;
    int arr[n];
    int size = 0;
    for (int i = 0; i < n;i++){
        int data;
        cin >> data;
        insert(arr, n, size, data);
    }
}