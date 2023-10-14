#include <iostream>
using namespace std;

template <class T>
class SortedSet;

template <class T>
class Node
{
    T data;
    Node<T> *next;
    friend class SortedSet<T>;
public:
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
    ~SortedSet()
    {
        while (head)
        {
            Node<T> *temp = head;
            head = head->next;
            delete temp;
        }
    }
    void Insert(T const &);
    void Delete(int const);
    void print() const;
    void Union(SortedSet<T> const &);
    void rotate();
    Node<T> *gethead();
    void setTail(Node<T> *);
    void sethead(Node<T> *);
};

template <class T>
void SortedSet<T>::Insert(T const &data)
{
    Node<T> *temp = new Node<T>(data);
    if (temp == nullptr)
    {
        return;
    }
    else
    {
        Node<T> *prev;
        Node<T> *current = head;
        while (current != nullptr && current->data < data)
        {
            prev = current;
            current = current->next;
        }
        if (current && data == current->data)
        {
            delete temp;
            return;
        }
        temp->next = current;
        if (current == head)
        {
            head = temp;
        }
        else
        {
            prev->next = temp;
        }
        if (current == nullptr)
        {
            tail = temp;
        }
    }
}

template <class T>
void SortedSet<T>::print() const
{
    Node<T> *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

template <class T>
void SortedSet<T>::Delete(int const index)
{
    if (index < 0)
    {
        return;
    }
    int k = index;
    Node<T> *prev = nullptr;
    Node<T> *current = head;
    while (k != 0 && current != nullptr)
    {
        prev = current;
        current = current->next;
        k--;
    }
    if (!current)
    {
        return;
    }
    if (current == head)
    {
        head = current->next;
        delete current;
    }
    else
    {
        if(!prev->next){
            tail = prev;
            delete current;
        }
        prev->next = current->next;
        delete current;
    }
}

template <class T>
void SortedSet<T>::Union(const SortedSet<T> &otherSet)
{
    Node<T> *otherCurrent = otherSet.head;

    while (otherCurrent)
    {
        Insert(otherCurrent->data);
        otherCurrent = otherCurrent->next;
    }
}

template <class T>
void SortedSet<T>::rotate()
{
    int k;
    while (true)
    {
        cout << "\nEnter how many times you want to Rotate: ";
        cin >> k;
        if (k <= 0)
        {
            cout << "\n------Enter valid value------\n";
            continue;
        }
        break;
    }
    if (!head || !head->next)
    {
        return;
    }
    while (k != 0)
    {
        tail->next = head;
        tail = tail->next;
        head = head->next;
        tail->next = nullptr;
        k--;
    }
}

template <class T>
Node<T> *SortedSet<T>::gethead()
{
    return head;
}

template <class T>
void SortedSet<T>::setTail(Node<T> *temp)
{
    tail = temp;
}

template <class T>
void SortedSet<T>::sethead(Node<T> *temp)
{
    head = temp;
}

template <class T>
void reverse(SortedSet<T> &obj)
{
    Node<T> *prev = nullptr;
    Node<T> *curr = obj.gethead();
    Node<T> *next = curr->next;
    obj.setTail(obj.gethead());
    while (curr != nullptr)
    {
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    obj.sethead(prev);
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
    cout << "List 1: ";
    a.print();
    SortedSet<int> b;
    b.Insert(30);
    b.Insert(40);
    b.Insert(90);
    b.Insert(70);
    b.Insert(80);
    cout << "List 2: ";
    b.print();
    a.Union(b);
    cout << "(After Union of list 1 and 2) list 1: ";
    a.print();
    b.Delete(0);
    cout << "After deleting at index 0 of list 2: ";
    b.print();
    a.Delete(8);
    cout << "After deleting at index 8 of list 1: ";
    a.print();
    a.Delete(3);
    cout << "After deleting at index 3 of list 1: ";
    a.print();
    cout << "For list 1:";
    a.rotate();
    cout << "List 1 after rotating positions: ";
    a.print();
    return 0;
}