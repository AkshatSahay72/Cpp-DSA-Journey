#include <iostream>
using namespace std;

int binsearch(int arr[], int n, int key)
{

  int start = 0;
  int end = n - 1;

  while (start <= end)
  {

    int mid = (start + end) / 2; // Optimization : "s + (e-s)/2" for edge case

    if (arr[mid] == key)
      return mid;

    else if (arr[mid] < key)
      start = mid + 1;

    else
      end = mid - 1;
  }
  return -1;
}

int main()
{
  int n = 6;
  int arr[n] = {1, 2, 5, 7, 15, 18};
  int key = 1;
  int ans = binsearch(arr, n, key);
  cout << ans;
}