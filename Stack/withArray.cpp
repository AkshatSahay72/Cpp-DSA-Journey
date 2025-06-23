#include<iostream>
using namespace std;

class Stack{

    // Properties
    public:
        int *arr;
        int top;
        int size;

    // Behaviour
    Stack(int size){
        this->size = size;
        arr = new int[size];
        top = -1; 
    }

    void push(int element){
        if(size - top > -1){
            top++;
            arr[top] = element;
        }else{
            cout << "Stack Overflow" << endl;
        }
    }

    void pop(){
        if(top>=0){
            cout << "Popped: " << arr[top];
            top--;
        }else{
            cout << "Stack Underflow" << endl;
        }

    }

    int peek(){
        if(top>-1){
            return arr[top];
        }else{
            cout << "Stack underflow" << endl;
            return -1;
        }

    }

    bool isEmpty(){
        return (top == -1);
    }

    void printMenu(){
        cout << endl;
        cout << "Menu: " << endl;
        cout << "0. Exit" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << endl;
    }
};

int main(){
    int size;
    cout << "Enter size of stack:";
    cin >> size;
    Stack s(size);
    int  n;
    do{
        s.printMenu();
        cin >> n;
        switch (n)
        {
        case 1:
            int data;
            cout << "Enter the element: ";
            cin >> data;
            s.push(data);
            break;

        case 2:
            s.pop();
            break;

        case 3:
            cout << s.peek() << endl;
            break;

        case 0:
            return 0;


        default : 
            break;
        }
    } while (n != 0);
}