#include "stackll.hpp"
#include <iostream>
#include <string>
template<typename T> 
Node<T>::Node(const T& data, Node* next): 
data(data), 
next(next)
{}

template<typename T>
StackLL<T>::~StackLL()
{
	Node<T>* tmp;

	while(top != nullptr)
	{
		tmp = top; 
		top = top->next; 
		delete tmp; 
	}
}
template<typename T> 
void StackLL<T>::push(const T& dat)
{
	auto tmp = new Node<T>(dat, top);
	top = tmp; 
	
}

template<typename T>
T StackLL<T>::pop()
{
	if(top == nullptr)
	{
		throw("empty stack");
	}

	auto ret = top->data; 
	auto tmp = top; 
	top = top->next; 
	delete tmp; 
	return ret; 

}
template<typename T>
bool StackLL<T>::isEmpty()
{
	return top == nullptr;
}
int main()
{
	std::string x = "(())))";
	std::cout<<parChecker(x);
}

bool parChecker(std::string& str)
{
	StackLL<std::string> stack; 

	std::string::iterator it = str.begin();

	while(it != str.end())
	{
		if(*it == '(')
		{
			stack.push("(");
		}
		else
		{
			if(stack.isEmpty())
			{
				return false; 
			}

			stack.pop();
		}

		++it;
	}

	return true; 


}