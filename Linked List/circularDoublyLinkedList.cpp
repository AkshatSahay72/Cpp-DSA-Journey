#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *prev;

    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class CircularDoublyLinkedList
{
private:
    Node *head = NULL;

public:
    int getLength()
    {
        int len = 0;
        Node *helper = head;
        if(!head){
            return 0;
        }
        while (helper->next != head)
        {
            helper = helper->next;
            len++;
        }
        return len;
    }

    void printList()
    {
        if (!head)
        {
            cout << "List is empty" << endl;
            return;
        }
        Node *helper = head;
        cout << "Linked List: ";
        while (helper->next != head)
        {
            cout << helper->val << " <-> ";
            helper = helper->next;
        }
        cout << "HEAD" << endl;
    }

    void insertion(int pos, int data)
    {
        if (pos < 0 || pos > getLength())
        {
            cout << "Invalid Index" << endl;
        }
        Node *newNode = new Node(data);
        if (pos == 0)
        {
            if (!head)
            {
                head = newNode;
                head->next = head;
                head->prev = head;
            }
            else
            {
                newNode->prev = head->prev;
                head->prev->next = newNode;
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
        }
        else
        {
            int index = 1;
            Node *helper = head;
            while (index < pos)
            {
                index++;
                helper = helper->next;
            }
            newNode->next = helper->next;
            helper->next = newNode;
            newNode->next->prev = newNode;
            newNode->prev = helper;
        }
    }

    void deletion(int pos)
    {
        if (pos < 0 || pos > getLength())
        {
            cout << "Invalid Index" << endl;
        }
        Node *toBeDeleted;
        if (pos == 0)
        {
            toBeDeleted = head;
            if (head->next != head)
            {
                Node *last = head->prev;
                head = head->next;
                last->next = head;
                head->prev = last;
            }
            else
            {
                head = NULL;
            }
            free(toBeDeleted);
        }
        else
        {
            Node *helper = head;
            int index = 1;
            while (index < pos)
            {
                index++;
                helper = helper->next;
            }

            Node *last = helper->prev;
            last->next = helper->next;
            helper->next->prev = last;
            free(helper);
        }
    }

    void updation(int pos, int data)
    {
        if (pos < 0 || pos > getLength())
        {
            cout << "Invalid Index" << endl;
            return;
        }
        Node *helper = head;
        int index = 0;
        while (index <= pos)
        {
            helper = helper->next;
            index++;
        }
        helper->val = data;
    }

    void printMenu()
    {
        cout << endl;
        cout << "Menu" << endl;
        cout << "1. Insertion" << endl;
        cout << "2. Deletion" << endl;
        cout << "3. Updation" << endl;
        cout << "-1. Exiting" << endl;
        cout << endl;
    }
};

int main()
{
    CircularDoublyLinkedList list;

    int n;
    do
    {
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