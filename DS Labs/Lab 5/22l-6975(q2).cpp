#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value) : data(value), next(nullptr) {}
};

class CircularLinkedList
{
private:
    Node *head;

public:
    CircularLinkedList() : head(nullptr) {}

    void insert(int value)
    {
        Node *newNode = new Node(value);
        if (!newNode)
        {
            return;
        }
        if (!head)
        {
            head = newNode;
            newNode->next = head;
        }
        else
        {
            Node *current = head;
            while (current->next != head)
            {
                current = current->next;
            }
            current->next = newNode;
            newNode->next = head;
        }
    }

    void splitEvenOdd(CircularLinkedList &evenList, CircularLinkedList &oddList)
    {
        if (!head)
        {
            return;
        }

        Node *current = head;
        int position = 1;

        do
        {
            if (position % 2 == 0)
            {
                evenList.insert(current->data);
            }
            else
            {
                oddList.insert(current->data);
            }
            current = current->next;
            position++;
        } while (current != head);
    }

    void display()
    {
        if (!head)
        {
            return;
        }

        Node *current = head;

        do
        {
            cout << current->data << " ";
            current = current->next;
        } while (current != head);

        cout << endl;
    }

    bool search(int value)
    {
        if (!head)
        {
            return false;
        }

        Node *current = head;

        do
        {
            if (current->data == value)
            {
                return true;
            }
            current = current->next;
        } while (current != head);

        return false;
    }

    void update(int oldValue, int newValue)
    {
        if (!head)
        {
            return;
        }

        Node *current = head;

        do
        {
            if (current->data == oldValue)
            {
                current->data = newValue;
            }
            current = current->next;
        } while (current != head);
    }
};

int main()
{
    CircularLinkedList cll;
    CircularLinkedList evenList;
    CircularLinkedList oddList;

    cll.insert(1);
    cll.insert(2);
    cll.insert(3);
    cll.insert(4);
    cll.insert(5);
    cll.insert(6);
    cll.insert(7);
    cll.insert(8);
    cll.insert(9);

    cout << "List after inserting values: ";
    cll.display();

    cll.splitEvenOdd(evenList, oddList);

    cout << "Even-positioned nodes: ";
    evenList.display();

    cout << "Odd-positioned nodes: ";
    oddList.display();

    int searchValue;
    cout << "Enter a value to search: ";
    cin >> searchValue;

    if (cll.search(searchValue))
    {
        cout << "Value " << searchValue << " found in the circular linked list." << endl;
    }
    else
    {
        cout << "Value " << searchValue << " not found in the circular linked list." << endl;
    }

    int insertValue;
    cout << "Enter a value to insert: ";
    cin >> insertValue;

    cll.insert(insertValue);
    cout << "Circular linked list after inserting " << insertValue << ": ";
    cll.display();

    int oldValue, newValue;
    cout << "Enter the value to update: ";
    cin >> oldValue;
    cout << "Enter the new value: ";
    cin >> newValue;

    cll.update(oldValue, newValue);
    cout << "Circular linked list after updating " << oldValue << " to " << newValue << ": ";
    cll.display();

    return 0;
}
