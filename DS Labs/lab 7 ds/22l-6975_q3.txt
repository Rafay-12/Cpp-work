#include <iostream>
#include <queue>
using namespace std;

template <typename T>

class MinQueue
{
public:
    queue<T> Queue;

    deque<T> Dequeue;

    void enqueue(T element) // function to enqueue element in queue and push samller element in back of dequeue after poping greater elements otherwise at back without poping
    {
        if (Queue.size() == 0)
        {
            Queue.push(element);
            Dequeue.push_back(element);
        }
        else
        {
            Queue.push(element);

            while (!Dequeue.empty() && element < Dequeue.back())
            {
                Dequeue.pop_back();
            }
            Dequeue.push_back(element);
        }
    }

    void dequeue() // dequeuing the element in queue (if front of queue is equal to front of dequeue we have to pop front element of dequeue because we are dequeuing the minimum element)
    {
        if (Queue.front() == Dequeue.front())
        {
            Queue.pop();
            Dequeue.pop_front();
        }
        else
        {
            Queue.pop();
        }
    }

    T getMin() { return Dequeue.front(); }
};

int main()
{
    MinQueue<int> d;
    d.enqueue(1);
    d.enqueue(5);
    d.enqueue(2);
    cout << d.getMin() << endl; // Output 1
    d.dequeue();
    cout << d.getMin() << endl; // Output 2
}