#include <iostream>
using namespace std;

template <class T>
struct Node
{
    T data;
    Node *next;
    Node(T data) : data(data), next(NULL) {}
};

template <class T>
class Queue
{
    Node<T> *fr;
    Node<T> *re;
    int s = 0;

public:
    Queue() : fr(NULL), re(NULL) {}

    bool isEmpty() // function to check if queue is empty
    {
        return fr == NULL;
    }

    void enqueue(T element) // function to enqueue the element
    {
        Node<T> *temp = new Node(element);
        if (re == NULL)
        {
            re = fr = temp;
        }
        else
        {
            re->next = temp;
            re = temp;
        }
        s++;
    }

    void dequeue() // function to dequeue the element
    {
        if (!isEmpty())
        {
            Node<T> *temp = fr;
            fr = fr->next;
            if (fr == NULL)
            {
                re = NULL;
            }
            delete (temp);
            s--;
        }
        else
        {
            cout << "Queue underflow" << endl;
        }
    }

    int size() // function which return the total element of queue
    {
        return s;
    }

    T front() // function to return the front element of queue
    {
        T data = 0;
        if (!isEmpty())
        {
            data = fr->data;
            return data;
        }
        return data;
    }

    T rear() // function to return the rear element of queue
    {
        T data = 0;
        if (!isEmpty())
        {
            data = re->data;
            return data;
        }
        return data;
    }

    void display() // funtion to display queue
    {
        if (!isEmpty())
        {
            Node<T> *temp = fr;
            cout << "Queue: ";
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
        }
    }
};

int main()
{
    Queue<int> d;
    d.enqueue(5); // enqueue the 5 in queue
    d.enqueue(4); // enqueue the 4 in queue
    d.enqueue(3); // enqueue the 3 in queue
    d.enqueue(2); // enqueue the 2 in queue
    d.enqueue(1); // enqueue the 1 in queue
    d.display();
    cout << "\nFront element of Queue: " << d.front() << endl;
    cout << "Rear element of Queue: " << d.rear() << endl;
    cout << "Number of elements in Queue: " << d.size() << endl;
    d.dequeue(); // dequeue the element
    d.dequeue(); // dequeue the element
    cout << "After calling dequeue 2 times\n";
    d.display();
    cout << "\nFront element of Queue: " << d.front() << endl;
    cout << "Rear element of Queue: " << d.rear() << endl;
    cout << "Number of elements in Queue: " << d.size() << endl;

    system("\npause");
    return 0;
}