#include <iostream>
using namespace std;

template <class T>
struct Node
{
	T data;
	Node<T> *next;
	Node<T> *prev;
	Node(T const &dat) : data(dat), next(nullptr), prev(nullptr) {}
};

template <class T>
class Doubly
{
	Node<T> *head;
	Node<T> *tail;

public:
	Doubly()
	{
		head = nullptr;
		tail = nullptr;
	}

	void insertAtHead(T const element)
	{
		Node<T> *temp = new Node<T>(element);
		if (temp == nullptr)
		{
			return;
		}
		if (head == nullptr)
		{
			head = temp;
			tail = temp;
		}
		else
		{
			temp->next = head;
			head->prev = temp;
			head = temp;
		}
	}

	void insertAtTail(T const element)
	{
		Node<T> *temp = new Node<T>(element);
		if (temp == nullptr)
		{
			return;
		}
		if (head == nullptr)
		{
			head = temp;
			tail = temp;
		}
		else
		{
			tail->next = temp;
			temp->prev = tail;
			tail = temp;
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

	void deleteRandom()
	{
		int index;
		cout << "Enter the index at which you want to delete element: ";
		cin >> index;
		if (index < 0)
		{
			return;
		}
		Node<T> *curr = head;
		while (index && curr)
		{
			curr = curr->next;
			index--;
		}
		if (!curr)
		{
			return;
		}
		if (curr == head)
		{
			head = head->next;
			head->prev = nullptr;
			delete curr;
			return;
		}
		else if (curr->next == nullptr)
		{
			tail = curr->prev;
			tail->next = nullptr;
			delete curr;
		}
		else
		{
			curr->next->prev = curr->prev;
			curr->prev->next = curr->next;
			delete curr;
		}
	}

	void insertSorted(T const element)
	{
		Node<T> *newNode = new Node<T>(element);

		if (!head)
		{
			head = tail = newNode;
		}
		else if (element <= head->data)
		{
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
		}
		else if (element >= tail->data)
		{
			newNode->prev = tail;
			tail->next = newNode;
			tail = newNode;
		}
		else
		{
			Node<T> *current = head;
			while (current->next && current->next->data < element)
			{
				current = current->next;
			}
			newNode->next = current->next;
			newNode->prev = current;
			current->next->prev = newNode;
			current->next = newNode;
		}
	}

	void deleteDuplicates()
	{
		if (!head || !head->next)
		{
			return;
		}

		Node<T> *current = head;

		while (current)
		{
			Node<T> *nextNode = current->next;

			if (nextNode && current->data == nextNode->data)
			{
				if (nextNode == tail)
				{
					tail = current;
					current->next = nullptr;
					delete nextNode;
				}
				else
				{
					current->next = nextNode->next;
					nextNode->next->prev = current;
					delete nextNode;
				}
			}
			else
			{
				current = current->next;
			}
		}
	}

	void swapNodes(int n)
	{
		if (n <= 0)
		{
			return;
		}

		if (!head || !head->next)
		{
			return;
		}

		Node<T> *curr_start = head;
		Node<T> *prev_start = nullptr;

		for (int i = 1; i < n && curr_start; ++i)
		{
			prev_start = curr_start;
			curr_start = curr_start->next;
		}

		Node<T> *curr_end = tail;
		Node<T> *prev_end = nullptr;

		for (int i = 1; i < n && curr_end; ++i)
		{
			prev_end = curr_end;
			curr_end = curr_end->prev;
		}

		if (!curr_start || !curr_end || curr_start == curr_end)
		{
			return;
		}

		if (prev_start)
		{
			prev_start->next = curr_end;
		}
		else
		{
			head = curr_end;
		}

		if (prev_end)
		{
			prev_end->prev = curr_start;
		}
		else
		{
			tail = curr_start;
		}

		Node<T> *temp_next = curr_start->next;
		curr_start->next = curr_end->next;
		curr_end->next = temp_next;

		Node<T> *temp_prev = curr_start->prev;
		curr_start->prev = curr_end->prev;
		curr_end->prev = temp_prev;
	}

	Node<T> *get_nth_node_from_end(int n)
	{
		if (n <= 0 || !head)
		{
			return nullptr;
		}

		Node<T> *firstPtr = head;
		Node<T> *secondPtr = head;

		for (int i = 0; i < n; ++i)
		{
			if (firstPtr)
			{
				firstPtr = firstPtr->next;
			}
			else
			{
				return nullptr;
			}
		}

		while (firstPtr)
		{
			firstPtr = firstPtr->next;
			secondPtr = secondPtr->next;
		}

		return secondPtr;
	}

	void partition(int value)
	{
		if (!head)
		{
			return;
		}

		Doubly<T> lessList;
		Doubly<T> greaterList;
		Node<T> *current = head;

		while (current)
		{
			if (current->data < value)
			{
				lessList.insertAtTail(current->data);
			}
			else
			{
				greaterList.insertAtTail(current->data);
			}
			current = current->next;
		}

		if (!lessList.head)
		{
			head = greaterList.head;
			tail = greaterList.tail;
		}
		else
		{
			head = lessList.head;
			tail = greaterList.tail;
			lessList.tail->next = greaterList.head;
			greaterList.head->prev = lessList.tail;
		}
	}
};

int main()
{
	Doubly<int> arr;
	arr.insertAtHead(1);
	arr.insertAtHead(3);
	arr.insertAtHead(5);
	arr.insertAtHead(2);
	arr.insertAtHead(1);
	arr.insertAtTail(6);
	arr.insertAtTail(7);
	arr.insertAtTail(8);
	arr.insertAtTail(8);
	arr.insertAtTail(9);
	arr.insertAtTail(9);
	arr.print();
	arr.insertSorted(3);
	arr.insertSorted(11);
	cout << "After inserting 3 and 11 using sorted set function: ";
	arr.print();
	arr.deleteDuplicates();
	cout << "After deleting duplicates: ";
	arr.print();
	arr.partition(5);
	cout << "After partioning with value of 5: ";
	arr.print();
	Node<int> *temp = arr.get_nth_node_from_end(3);
	cout << "Value at 3rd node from end: " << temp->data << endl;
	arr.deleteRandom();
	arr.print();
	system("pause");
	return 0;
}