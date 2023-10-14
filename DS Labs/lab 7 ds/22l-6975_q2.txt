#include <iostream>
using namespace std;

class CircularQueue
{
    int *data;
    int front;
    int rear;
    int Maxsize;
    int size = 0;

public:
    CircularQueue(int s) // constructor
    {
        Maxsize = s;
        data = new int[Maxsize];
        front = -1;
        rear = -1;
    }

    ~CircularQueue() // destructor
    {
        delete[] data;
    }

    bool isEmpty() // funtion to check if queue is empty
    {
        return size == 0;
    }

    bool isFull() // funtion to check if queue is full
    {
        return size == Maxsize;
    }

    void enqueue(int value) // funtion to enqueue element in circular queue
    {
        if (isFull())
        {
            cout << "Queue is full." << endl;
            return;
        }
        if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % Maxsize;
        }
        data[rear] = value;
        size++;
    }

    int dequeue() // funtion to dequeue elemeent in circular queue
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int value = data[front];
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % Maxsize;
        }
        size--;
        return value;
    }

    bool isPalindrome() // funtion to check if queue is palindrome or not
    {
        if (isEmpty())
        {
            return false;
        }
        int start = front;
        int end = rear;

        while (start < end)
        {
            if (data[start] != data[end])
            {
                return false;
            }
            start = (start + 1) % Maxsize;
            end = (end - 1 + Maxsize) % Maxsize;
        }

        return true;
    }

    void display() // funtion to display queue
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return;
        }
        int current = front;
        cout << "Queue Elements: ";
        while (current != rear)
        {
            cout << data[current] << " ";
            current = (current + 1) % Maxsize;
        }
        cout << data[current] << endl;
    }
};

int main()
{
    CircularQueue queue(5);

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(2);
    queue.enqueue(1);

    queue.display(); // Output Queue Elements: 1 2 3 2 1

    if (queue.isPalindrome()) // condition is true
    {
        cout << "The circular queue is a palindrome." << endl;
    }
    else
    {
        cout << "The circular queue is not a palindrome." << endl;
    }

    return 0;
}
