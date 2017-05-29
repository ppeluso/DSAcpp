#include <iostream>

template<class T>
class Node 
{
public:
	T data; 
	Node *next;
	 Node(const T& dat, Node* ptr ): data(dat), next(ptr){}

};

template<class T>
class LinkedList
{
	private:
		
		Node<T>* head;

	public: 
		
		LinkedList(): head(nullptr){}
		~LinkedList();
		void AddToHead(T data);
		void DeleteFromHead();

};