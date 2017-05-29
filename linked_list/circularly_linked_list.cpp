
#include "circll.hpp"
template<typename T>
circLL<T>::~circLL()
{
	if(tail == nullptr)
	{
		std::cout<<"none"<<std::endl;
	}
	else if( tail->next == nullptr)
	{
		delete tail; 
	}
	else
	{
		auto tmp = tail;
		auto next = tail->next;
		while(next != tail)
		{
			
			next = next->next;  
			
			delete tmp;
			tmp = tmp->next;

		}
		delete tmp;

	}
}
template<typename T>
void circLL<T>::InsertToTail(const T& dat)
{
	if(tail == nullptr)
	{
		auto tmp = new circNode<T>(dat, nullptr);
		tmp->next = tmp;
		tail = tmp; 

	}
	else 
	{
		auto tmp = new circNode<T>(dat, tail->next);
		tail->next = tmp; 
		tail = tmp; 
		
	}
}

int main()
{
	circLL<int> list = circLL<int>();
	list.InsertToTail(1);
	list.InsertToTail(2);
	list.InsertToTail(3);
}