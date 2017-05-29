
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
public:
	DbNode<T>* head; 
	DbNode<T>* tail; 

	DbLinkedList() : head(nullptr), tail(nullptr) {}
	~DbLinkedList();
	void InsertAtHead(const T& val);
	void DeleteHead();
};
