#include <iostream>
using namespace std;

int pivot(int arr[], int n)
{
    int s = 0, e = n - 1;
    int mid = s + (e - s) / 2;
    while (s < e)
    {
        if (arr[mid] >= arr[0])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
        mid = s + (e - s) / 2;
    }
    return arr[e];
}

// int main(){
//     int arr[5] = {6, 7, 3, 4, 5};
//     cout << "Pivot is " << pivot(arr, 5);
// }