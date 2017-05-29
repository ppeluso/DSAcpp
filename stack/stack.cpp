#include "stack.hpp"

template<typename T>
Stack<T>::Stack(int size): size(size), top(0)
{
	storage = new T [size];
} 
template<typename T>
Stack<T>::~Stack()
{
	delete [] storage; 
}

template<typename T>
void Stack<T>::push(const T& dat)
{
	if(top ==size)
	{
		std::cout<<"stack is full"<<std::endl;
		return; 
	}

	storage[top] = dat;
	top++; 

	return; 	
}

template<typename T>
T Stack<T>::pop()
{
	if(top == 0)
	{
		throw("stack is empty");
	}

	top--;
	return storage[top +1];

}

int main()
{
	
	return 0;
}