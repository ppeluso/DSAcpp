#include <iostream>

template<typename T>
class DbNode
{

public:
	T data;
	DbNode* prev; 
	DbNode* next;

	DbNode(const T& data, DbNode* prev, DbNode* next) : 
	data(data), 
	prev(prev), 
	next(next){}

};

template<typename T> 
class DbLinkedList
{
	DbNode<T>* head; 
	DbNode<T>* tail; 

	DbLinkedList() : head(nullptr), tail(nullptr) {}
	~DbLinkedList();
	void InsertAtHead(const T& val);
};

template<typename T> 
DbLinkedList<T>::~DbLinkedList()
{
	for(auto i = head; i->next != nullptr; i = i->next)
	{
		delete i;
	}
};

template<typename T> 
void DbLinkedList<T>::InsertAtHead(const T& val)
{
	if(head == nullptr && tail == nullptr)
	{
		auto tmp = new DbNode<T>(val,nullptr, nullptr) ;
		head = tail = tmp; 
	}
	else
	{
		auto tmp = new DbNode<T>(val, nullptr, head);
		head->prev = tmp ;
		head = tmp; 
	}

}
int main()
{

}