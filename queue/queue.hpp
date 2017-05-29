#include<iostream>
template<typename T> 
class Node 
{
public:

	T data;
	Node* prev;
	Node* next; 
	Node(T data, Node* prev, Node* next) :
	data(data),
	prev(prev),
	next(next)
	{}
};

template<typename T> 
class Queue
{

public:
	Node<T>* head;
	Node<T>* tail; 

	Queue(): head(nullptr), tail(nullptr) {}
	~Queue();
	void enqueue(T data); 
	T dequeue();

};