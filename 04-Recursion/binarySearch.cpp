#include<iostream>
using namespace std;

int search(int *arr, int key,int s,int e){
    if(s>e){
        return -1;
    }
    int mid = s + (e - s) / 2;
    if(arr[mid] == key){
        return mid;
    }
    if(arr[mid]<key){
        return search(arr, key, mid + 1, e);
    }else{
        return search(arr, key, s, mid - 1);

    }

}

int main()
{
    int arr[5] = {4, 7, 8, 9, 11};
    int size = 5;
    int key = 9;
    int ans = search(arr, key, 0, size - 1);
    cout << ans << endl;
}
