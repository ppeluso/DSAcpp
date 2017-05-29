#include <iostream>

template<typename T>
class circNode
{
public:
	T data; 
	circNode* next;
	circNode(const T& data, circNode* next): data(data), next(next) {}


};

template<typename T>
class circLL
{

public:
	circNode<T>* tail;
	circLL(): tail(nullptr) {}
	~circLL();
	void InsertToTail(const T& dat);
};