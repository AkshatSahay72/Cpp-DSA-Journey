#include<iostream>
using namespace std;

class Node{
    public:
        int val;
        Node *next;

        Node(int val){
            this->val = val;
            this->next = NULL;
        }
};

class CircularSinglyLinkedList{
    private:
        Node *head = NULL;
    
    public:
        int getLength(){
            int len = 0;
            if(!head){
                return 0;
            }
            Node *helper = head;
            do{
                helper = helper->next;
                len++;
            } while (helper != head);
            return len;
        }

        void printList(){
            Node *helper = head;
            if(!head){
                cout << "List is empty" << endl;
            }
            do{
                cout << helper->val << "->";
                helper = helper->next;
            } while (helper != head);
            cout << "HEAD" << endl;
        }

        void insertion(int pos, int data){
            if(pos<0 || pos>getLength()){
                cout << "Invalid Index" << endl;
                return;
            }
            Node *newNode = new Node(data);
            Node *helper = head;
            if(pos == 0){
                if(!head){
                    head = newNode;
                    head->next = head;
                }else{
                    newNode->next = head;
                    do{
                        helper = helper->next;
                    } while (helper != head);
                    helper->next = newNode;
                    head = newNode;
                }
                return;
            }else{
                int index = 1;
                    while(index<pos){
                        index++;
                        helper = helper->next;
                    }
                    newNode->next = helper->next;
                    helper->next = newNode;
            }
            cout << "Insertion done sucessfully." << endl;
        }

        void deletion(int pos){
            if(pos<0 || pos>getLength()){
                cout << "Invalid Index" << endl;
                return;
            }

            Node *helper = head;
            Node *toBeDeleted;

            if (head->next == head) {

                free(head);
                head = NULL;
                return;
            }


            if(pos == 0){
                toBeDeleted = head;
                if(head->next == head){
                    head = NULL;
                }else{
                    while(helper->next != head){
                        helper = helper->next;
                    }
                    
                    helper->next = helper->next->next;
                    head = helper->next;
                    free(toBeDeleted);
                }
                return;
            }else{
                int index = 1;
                while(index<pos){
                    helper = helper->next;
                    index++;
                }
                toBeDeleted = helper->next;
                helper->next = helper->next->next;
                free(toBeDeleted);
            }
            cout << "Deletion done sucessfully." << endl;
        }

        void updation(int pos, int data){
            if(pos<0 || pos>=getLength()){
                cout << "Invalid Index" << endl;
                return;
            }
            Node *helper = head;
            int index = 0;
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
    CircularSinglyLinkedList list;
    
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