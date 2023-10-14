#include <iostream>
using namespace std;

template <class T>
class DoublyLinkedList;

template <class T>
class Node
{
    T data;
    Node<T> *next;
    Node<T> *prev;
    friend class DoublyLinkedList<T>;

public:
    Node(const T &element) : data(element), next(nullptr), prev(nullptr) {}
};

template <class T>
class DoublyLinkedList
{
    Node<T> *head;
    Node<T> *tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void insertAtHead(const T &element)
    {
        Node<T> *newNode = new Node<T>(element);
        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtTail(const T &element)
    {
        Node<T> *newNode = new Node<T>(element);
        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void print() const
    {
        Node<T> *current = head;
        while (current)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void printReverse() const
    {
        Node<T> *current = tail;
        while (current)
        {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }

    void deleteAtStart()
    {
        if (head)
        {
            Node<T> *temp = head;
            head = head->next;
            if (head)
            {
                head->prev = nullptr;
            }
            else
            {
                tail = nullptr;
            }
            delete temp;
        }
    }

    void deleteAtTail()
    {
        if (tail)
        {
            Node<T> *temp = tail;
            tail = tail->prev;
            if (tail)
            {
                tail->next = nullptr;
            }
            else
            {
                head = nullptr;
            }
            delete temp;
        }
    }

    void deleteAtPosition(int k)
    {
        if (k <= 0 || !head)
        {
            return;
        }

        Node<T> *current = head;
        int count = 1;

        while (current && count < k)
        {
            current = current->next;
            count++;
        }

        if (!current)
        {
            return;
        }

        if (current == head)
        {
            deleteAtStart();
        }
        else if (current == tail)
        {
            deleteAtTail();
        }
        else
        {
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
        }
    }

    ~DoublyLinkedList()
    {
        while (head)
        {
            Node<T> *temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main()
{
    using namespace std;

    DoublyLinkedList<int> dll;

    dll.insertAtHead(2);
    dll.insertAtHead(1);
    dll.insertAtTail(3);
    dll.insertAtTail(4);
    dll.insertAtTail(5);

    cout << "Original List: ";
    dll.print();
    cout << "Reverse List: ";
    dll.printReverse();

    dll.deleteAtStart();
    cout << "After deleting at the start: ";
    dll.print();

    dll.deleteAtTail();
    cout << "After deleting at the end: ";
    dll.print();

    dll.deleteAtPosition(2);
    cout << "After deleting at position 2: ";
    dll.print();

    return 0;
}
