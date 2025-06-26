#include <iostream>
using namespace std;

int mountain(int arr[], int n)
{
    int s = 0, e = n - 1;
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
        {
            return mid;
        }
        else if (arr[mid] > arr[mid + 1])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
        mid = s + (e - s) / 2;
    }
    return -1;
}

int main()
{
    int arr[5] = {4, 5, 6, 1, 2};
    int ans = mountain(arr, 5);

    cout << ans << " = " << arr[ans];
}