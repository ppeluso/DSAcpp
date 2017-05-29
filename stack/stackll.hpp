#include <iostream>
#include <string>
template<typename T>
class Node
{ 
public:
	T data;
	Node* next; 
	Node(const T& data, Node* next);

};

template<typename T>
class StackLL
{
public:
	~StackLL();
	Node<T>* top;

	void push(const T& dat);
	T pop();
	bool isEmpty();
	StackLL(): top(nullptr) {}

};

bool parChecker(std::string& str);