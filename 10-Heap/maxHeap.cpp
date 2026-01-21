#include<iostream>
using namespace std;

class heap{
    public:
        int arr[100];
        int size = 0;

    heap(){
        arr[0] = -1;
        size = 0;
    }

    void insert(int val){
        size = size + 1;
        int index = size;
        arr[index] = val;

        while(index > 1){
            int parent = index/2;
            
            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }else{
                return;
            }
        }
    }

    void deletee(){
        if(size == 0){
            cout<< "Nothing to delete"<< endl;
            return;
        }    

        arr[1] = arr[size];
        size--;
        int i = 1;
        int largest = i;
        while(i<=size){
            int leftChild = 2*i;
            int rightChild = 2*i + 1;

            if(leftChild <= size && arr[leftChild] > arr[i]){
                largest = leftChild;
            }
            if(rightChild <= size && arr[rightChild] > arr[i]){
                largest = rightChild;
            }
            if(largest!=i){
                swap(arr[largest], arr[i]);
                i = largest;
            }
            else{
                return;
            }
        }
    }

    void print(){
        for(int i = 1; i<=size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(54);
    h.insert(52);
    h.print();
    h.deletee();
    h.print();

}