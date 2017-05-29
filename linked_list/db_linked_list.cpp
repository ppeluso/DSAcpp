#include "dbll.hpp"
int main()
{
	DbLinkedList<int> list = DbLinkedList<int>();
	list.InsertAtHead(1);
	list.InsertAtHead(2);
	list.InsertAtHead(3);
	return 0;
}
template<typename T> 
DbLinkedList<T>::~DbLinkedList()
{
		auto tmp = head->next;
		auto prev = head;

		while(tmp != nullptr)
		{
			delete prev; 
			prev = tmp; 
			tmp = tmp->next;
		}
		delete prev;



};

template<typename T> 
void DbLinkedList<T>::InsertAtHead(const T& val)
{
	if(head == nullptr && tail == nullptr)
	{
		auto tmp = new DbNode<T>(val,nullptr, nullptr) ;
		head = tail = tmp; 
		return ;
	}
	else
	{
		auto tmp = new DbNode<T>(val, nullptr, head);
		head->prev = tmp ;
		head = tmp; 
		return; 
	}

}

template<typename T>
void DbLinkedList<T>::DeleteHead()
{
	if(head == nullptr)
	{
		std::cout<<"empty list" << std::endl;
		return;
	}
	else if(head->next == nullptr)
	{
		delete head; 
		head = tail =  nullptr;
		return;
	}
	else
	{
		auto tmp = head->next; 
		tmp->prev = nullptr; 
		delete head; 
		head = tmp; 
		return; 
	}
}