#include <iostream> 

template<typename T>
class Stack
{
	public:
	T* storage;
	int top,size;
	Stack(int size);
	~Stack();
	void push(const T& dat);
	T pop();

};