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
		std::cout<<"del" <<std::endl;
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
	std::cout<<"enqueue"<< std::endl;
	std::cout<<x.dequeue()<<std::endl;
	return 0; 
}