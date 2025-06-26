#include <iostream>
// #include "PivotInArr.cpp"
using namespace std;

int pivot(int arr[], int n)
{
    int s = 0, e = n - 1;
    int mid = s + (e - s) / 2;
    while (s < e)
    {
        if (arr[mid] > arr[0])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
        mid = s + (e - s) / 2;
    }
    return s;
}

int search(int arr[], int s, int e, int key)
{
    int mid = s + (e - s) / 2;
    while (s < e)
    {
        if (arr[mid] == key)
        {
            return mid;
        }
        if (arr[mid] > key)
        {
            e = mid;
        }
        else
        {
            s = mid ;
        }
        mid = s + (e - s) / 2;
    }
    return -1;
}

int main()
{
    int n = 7;
    int arr[n] = {4,5,6,7,0,1,2};
    int key = 0;
    int p = pivot(arr, n);
    int ans;
    if (key >= p && key <= arr[n - 1])
    {
        ans = search(arr,  p, (n - 1), key);
    }
    else
    {
        ans = search(arr, 0, p - 1, key);
    }
    cout << "Key is placed in index " << ans;
}