#pragma once
#include<iostream>

using namespace std;

template<class T>
struct node
{
	T data;
	node<T>* next;
	node<T>* prev;
};

template<class T>
class Queue
{
private:
	node<T>* head = NULL;
	node<T>* tail = NULL;

public:
	Queue();
	void enqueue(T data);
	void print();
	T dequeue();
	bool isEmpty();
	void makeEmpty();
	T peek();
	void reversePrint();
};


template<class T>
Queue<T>::Queue()
{

}

template<class T>
void Queue<T>::enqueue(T data)
{
	node<T>* n = new node<T>;
	n->data = data;
	n->prev = tail;
	if (tail != NULL)
	{
		tail->next = n;
	}
	if (head == NULL)
	{
		head = n;
	}
	tail = n;
	tail->next = NULL;
}

template<class T>
void Queue<T>::print()
{
	node<T>* temp = head;

	while (temp != NULL)
	{
		cout << temp->data << endl;
		temp = temp->next;
	}
	cout << "\nEnd of list...\n\n" << endl;
}

template<class T>
T Queue<T>::dequeue()
{
	if (isEmpty())
	{
		cout << "Cannot remove nothing.";
		exit(1);
	}

	T result = head->data;

	node<T>* discard;
	discard = head;
	head = discard->next;
	if (head != NULL)
		head->prev = NULL;
	else if (head == NULL)
		tail == NULL;
	delete discard;
	return result;
}

template< class T>
bool Queue<T>::isEmpty()
{
	if (head == NULL)
	{
		return true;
	}
	return false;
}

template< class T>
void Queue<T>::makeEmpty()
{
	while (!isEmpty())
	{
		dequeue();
	}
}

template< class T>
T Queue<T>::peek()
{
	node<T>* n = head;
	return n->data;
}

template< class T>
void Queue<T>::reversePrint()
{
	node<T>* temp = tail;

	while (temp != NULL)
	{
		cout << temp->data << endl;
		temp = temp->prev;
	}
	cout << "\nEnd  of list...\n\n" << endl;
}

