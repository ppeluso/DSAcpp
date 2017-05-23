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
		
		Node<T>* head, tail;
		int len;
	public: 
		
		LinkedList(): head(NULL), tail(NULL), len(0) {}
		~LinkedList();
		void AddToHead(T data);
		void AddToTail(T data);
		T DeleteFromHead();
		T DeleteFromTail();
		void Delete(T& val);
		bool isEmpty();

};
template<class T>
void LinkedList<T>::AddToHead(T data)
{
	head = new Node<T>(data, head);

	if(tail == NULL)
	{
		tail = head; 
	} 
	len++;

}
template <class T>
void LinkedList<T>::AddToTail(T data)
{
	if( tail != NULL)
	{
	tail->next = new Node<T>(data, NULL);
	tail = tail->next;
	}
	else
	{
		tail = head = new  Node<T>(data, NULL);
	} 
	len++;
}
template<class T>
LinkedList<T>::~LinkedList()
{
	Node<T>* p;
	while(!isEmpty())
	{
		p = head->next; 
		delete head;
		head = p;
	}
}
template<class T>
bool LinkedList<T>::isEmpty()
{
	return head == NULL; 
}
template<class T>
T LinkedList<T>::DeleteFromHead()
{
	if(!isEmpty())
	{	
		T dat = head->data;
		if(head == tail)
		{
			delete head; 
			head = tail = NULL;
			len--;
			return dat;
		}
		else
		{
		Node<T>* p = head;
		head = head->next;
		len--; 
		delete p; 
		return dat;
		}

	}
	else 
	{
		std::cout<< "empty list" << std::endl; 
		return 0;
	}

}
template<class T>
T LinkedList<T>::DeleteFromTail()
{
	if(!isEmpty())
	{
		if(head == tail)
		{
			delete head; 
			head = tail =  NULL;
		}
		else
		{
			Node<T>* i;
			for( i = head; i->next != tail; i = i->next);
			delete tail;
			i->next = NULL;
		    tail = i;


		}
	}
}
template<class T>
void LinkedList<T>::Delete(T& val)
{
	if( head->data == val && tail == head)
	{
		delete head; 
		head = tail = NULL; 
		return;
	}
	if( head->data == val)
	{
		Node<T>* tmp = head; 
		head = tmp->next;
		delete head;
		return; 
	}
	else 
	{
		Node<T>* prev = head; 
		Node<T>* tmp = head->next;

		while(tmp != NULL)
		{

		
		  if(tmp->data == val)
		  {
		  	prev->next = tmp->next; 

		  	if(tail == tmp)
		  	{
		  		tail = prev;
		  	}

		  	delete tmp; 
		  	break;  
          } 
			tmp = tmp->next; 
			prev = prev->next;
	    }
	    	return; 
    }
}
int main()
{

}