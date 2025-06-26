#include<iostream>
using namespace std;

class Node{
    public:
        int val;
        Node *next;
        Node *prev;

    Node(int val){
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class DoublyLinkedList{
    private:
        Node *head = NULL;
    
    public:
        int getLength(){
            int len = 0;
            Node *helper = head;
            while(helper){
                helper = helper->next;
                len++;
            }
            return len;
        }

        void printList(){
            cout << "Doubly Linked List: ";
            Node *helper = head;
            while(helper){
                cout << helper->val << " -> ";
                helper = helper->next;
            }
            cout << "NULL" << endl;
        }

        void insertion(int pos, int data){
            if(pos<0 || pos>getLength()){
                cout << "Invalid Index" << endl;
                return;
            }
            Node *newNode = new Node(data);
            if(pos == 0){
                newNode->next = head;
                if(head){
                    head->prev = newNode;
                }
                head = newNode;
            }else{
                int index = 1;
                Node *helper = head;
                while(pos<index){
                    pos++;
                    helper = helper->next;
                }

                newNode->next = helper->next;
                if(helper->next){
                    helper->next->prev = newNode;
                }
                newNode->prev = helper;
                helper->next = newNode;
            }
            cout << "Insertion done sucessfully." << endl;
        }

        void deletion(int pos){
            if(pos<0 || pos>getLength()){
                cout << "Invalid Index" << endl;
                return;
            }

            Node *toBeDeleted;
            if(pos == 0){
                toBeDeleted = head;
                head = head->next;
                if(head){
                    head->prev = NULL;
                }
                free(toBeDeleted);
                cout << "Deletion done sucessfully." << endl;
                return;
            }

            int index = 1;
            Node *helper = head;
            while(index<pos){
                index++;
                helper = helper->next;
            }

            toBeDeleted = helper->next;
            helper->next = helper->next->next;
            if(helper->next){
                helper->next->prev = helper;
            }
            free(toBeDeleted);
        }

        void updation(int pos, int data){
            if(pos<0 || pos>getLength()){
                cout << "Invalid Index" << endl;
                return;
            }

            Node *helper = head;
            int index = 1;
            while(index<pos){
                index++;
                helper = helper->next;
            }
            helper->val = data;
            cout << "Updation done sucessfully." << endl;
        }

        void printMenu(){
            cout << endl;
            cout << "Menu" << endl;
            cout << "1. Insertion" << endl;
            cout << "2. Deletion" << endl;
            cout << "3. Updation" << endl;
            cout << "-1. Exiting" << endl;
            cout << endl;
        }
};

int main(){
    DoublyLinkedList list;
    
    int n;
    do{
        list.printMenu();
        cin >> n;
        switch (n)
        {
        int pos, data;
        case 1:
            cin >> pos >> data;
            list.insertion(pos, data);
            cout << endl;
            list.printList();
            break;
        
        case 2:
            cin >> pos;
            list.deletion(pos);
            list.printList();
            break;

        case 3:
            cin >> pos >> data;
            list.updation(pos, data);
            list.printList();
            break;

        case -1:
            cout << "Exiting" << endl;
            return 0;

        default:
            cout << "Invalid Input";
            break;
        }
    } while (n != -1);
}