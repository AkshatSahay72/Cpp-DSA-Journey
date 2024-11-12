#include <iostream>
using namespace std;

void sorting(int arr[], int n)
{
    for (int i = 1; i < n;i++){
        int j = i-1;
        int temp = arr[i];
        // for (j = i - 1; j >= 0;j--){
        //     if(arr[j]>temp){
        //         arr[j + 1] = arr[j];
        //     }
        //     else{
        //         break;

        //     }
        // }

        while(j >= 0 && arr[j]>temp){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }

        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
}

int main()
{
    int n = 5;
    int arr[n] = {6, 3, 2, 6, 7};
    sorting(arr, n);
}