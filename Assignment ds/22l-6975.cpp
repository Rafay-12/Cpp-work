#include <iostream>
using namespace std;
template <class T>
struct Node
{
    T data;
    Node *next;

    Node() {}
    Node(const T &item) : data(item), next(nullptr) {}
};

template <class T>
class SortedSet
{
    Node<T> *head;
    Node<T> *tail;

public:
    SortedSet() : head(nullptr), tail(nullptr) {}

    void Insert(const T &data)
    {
        Node<T> *newNode = new Node<T>(data);
        if (newNode == nullptr)
        {
            return;
        }

        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            Node<T> *prev = nullptr;
            Node<T> *current = head;

            while (current && current->data < data)
            {
                prev = current;
                current = current->next;
            }

            if (current && data == current->data)
            {
                delete newNode;
                return;
            }

            if (!prev)
            {
                newNode->next = head;
                head = newNode;
            }
            else
            {
                newNode->next = current;
                prev->next = newNode;
            }

            if (!current)
            {
                tail = newNode;
            }
        }
    }

    void print() const
    {
        Node<T> *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void Delete(int index)
    {
        if (index < 0 || !head)
        {
            return;
        }

        if (index == 0)
        {
            Node<T> *temp = head;
            head = head->next;
            delete temp;
            if (!head)
            {
                tail = nullptr;
            }
            return;
        }

        Node<T> *prev = nullptr;
        Node<T> *current = head;
        int count = 0;

        while (count < index && current)
        {
            prev = current;
            current = current->next;
            count++;
        }

        if (!current)
        {
            return;
        }
        prev->next = current->next;
        delete current;
        if (!prev->next)
        {
            tail = prev;
        }
    }

    void Union(SortedSet<T> &other)
    {
        Node<T>* curr = other.head;
        while (curr)
        {
            Insert(curr->data);
            curr = curr->next;
        }
    }

    void rotate(int k)
    {
        if (k <= 0 || !head)
        {
            return;
        }

        int count = 1;
        Node<T> *current = head;

        while (count < k && current)
        {
            current = current->next;
            count++;
        }

        if (!current)
        {
            return;
        }

        tail->next = head;
        head = current->next;
        current->next = nullptr;
        tail = current;
    }

    Node<T> *getHead() const
    {
        return head;
    }

    void setHead(Node<T> *newHead)
    {
        head = newHead;
    }

    void setTail(Node<T> *newTail)
    {
        tail = newTail;
    }

    ~SortedSet()
    {
        while (head)
        {
            Node<T> *temp = head;
            head = head->next;
            delete temp;
        }
    }
};

template <class T>
void reverseList(SortedSet<T> &list)
{
    Node<T> *prev = nullptr;
    Node<T> *current = list.getHead();
    Node<T> *next = nullptr;

    while (current != nullptr)
    {
        next = current->next;
        current->next = prev;

        prev = current;
        current = next;
    }
    list.setTail(list.getHead());
    list.setHead(prev);
}

int main()
{
    SortedSet<int> a;
    a.Insert(30);
    a.Insert(20);
    a.Insert(10);
    a.Insert(40);
    a.Insert(50);
    a.Insert(60);

    cout << "List A: ";
    a.print();

    SortedSet<int> b;
    b.Insert(6);
    b.Insert(10);
    b.Insert(11);

    cout << "List B: ";
    b.print();

    a.Union(b);
    cout << "(After Union of A and B) List A: ";
    a.print();

    int k;
    while (true)
    {
        cout << "Enter the value of k for rotation: ";
        cin >> k;
        if (k < 0)
        {
            cout << "Please enter a valid positive value for k." << endl;
        }
        else
        {
            break;
        }
    }
    a.rotate(k);
    cout << "List A after rotating by " << k << " positions: ";
    a.print();

    b.Delete(0);
    cout << "After deleting at index 0 of list B: ";
    b.print();
    a.Delete(5);
    cout << "After deleting at index 5 of list A: ";
    a.print();
    a.Delete(3);
    cout << "After deleting at index 3 of list A: ";
    a.print();
    cout << "List A after reversing: ";
    reverseList(a);
    a.print();

    return 0;
}
