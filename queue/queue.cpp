#include <iostream>
#include "queue.hpp"

template<typename T>
Queue<T>::~Queue()
{
	auto tmp = head; 

	while(head != nullptr)
	{
		head = tmp->next;  
		delete tmp;
		tmp = head;  
	}
}

template<typename T>
void Queue<T>::enqueue(T data)
{
	if(head == nullptr)
	{
		auto tmp = new Node<T>(data, nullptr, nullptr);

		head = tail = tmp; 
		return;
	}

	auto tmp = new Node<T>(data, nullptr, head); 
	head->prev = tmp; 
	head = tmp; 
	return;

}

template<typename T>
T Queue<T>::dequeue()
{
	if(head == nullptr)
	{
		throw("queue is empty");
	}

	if(head == tail)
	{
		auto tmp = tail->data;
		delete tail; 
		head = tail = nullptr;
		return tmp; 
	}
	auto tmp = tail;
	auto tdata = tail->data; 
	tail = tail->prev; 
	tail->next = nullptr;
	delete tmp; 

	return tdata; 

}

int main()
{
	auto x = Queue<int>();
	x.enqueue(5);
	x.enqueue(10);
	std::cout<<x.dequeue()<<std::endl;
	return 0; 
}