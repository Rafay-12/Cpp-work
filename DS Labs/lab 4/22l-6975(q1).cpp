#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node *child;

    Node(const int &data) : data(data), next(nullptr), child(nullptr) {}
};

Node *flatten_linkedlist(Node *head)
{
    if (head == nullptr)
    {
        return head;
    }
    Node *current = head;
    while (current != nullptr)
    {
        if (current->child != nullptr)
        {
            Node *child = current->child;
            while (child->next != nullptr)
            {
                child = child->next;
            }

            Node *temp = current->next;
            current->next = current->child;
            current->child = nullptr;
            child->next = temp;
        }
        current = current->next;
    }
    return head;
}

void print(Node *head)
{
    Node *current = head;
    while (current)
    {
        cout << current->data << "->";
        current = current->next;
    }
    cout << "nullptr" << std::endl;
}

int main()
{
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);
    Node *node5 = new Node(5);
    Node *node6 = new Node(6);
    Node *node7 = new Node(7);
    Node *node8 = new Node(8);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node2->child = node5;
    node5->next = node6;
    node5->child = node7;
    node7->next = node8;
    Node *flattened_head = flatten_linkedlist(node1);
    print(flattened_head);
    return 0;
}