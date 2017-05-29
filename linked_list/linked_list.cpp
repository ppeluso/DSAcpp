#include <iostream> 
#include "ll.hpp"
template<class T>
LinkedList<T>::~LinkedList()
{
	auto prev = head;
	auto tmp = head->next;
	 
	while(tmp != nullptr)
	{
		delete prev;
		prev = tmp; 
		tmp = tmp->next;
	}
	delete prev;


	
}

template<class T>
void LinkedList<T>::AddToHead(T data)
{
	head = new Node<T>(data, head);
	return; 

}

template<class T>
void LinkedList<T>::DeleteFromHead()
{
	if(head == nullptr)
	{
		std::cout<< "empty list"<<std::endl;
	}

	else
	{
		auto tmp = head;
		head = head->next;
		delete tmp;
	}

}


int main()
{
	LinkedList<int> list = LinkedList<int>();
	list.AddToHead(1);
	list.AddToHead(2);
	list.AddToHead(3);
}