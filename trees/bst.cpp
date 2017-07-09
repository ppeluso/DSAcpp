#include "bst.hpp"
#include <cstdlib>
#include <ctime>
#include <queue>
#include <stack>
template<typename T>
void BST<T>::clear(Node<T>* node)
{
	if (node == nullptr)
		return; 
	if(node->left != nullptr)
		clear(node->left);
	if(node->right != nullptr)
		clear(node->right);
	delete node; 
}
template<typename T>
void BST<T>::insert(Node<T>*& node, const T& data)
{
	if(node == nullptr)
	{
	    node = new Node<T>(data);
	    return;
	}
	if(data < node->data)
	{
		insert(node->left, data);
		return;
	}
	if(data > node->data)
	{
		insert(node->right, data);
		return;
	}

	std::cout << "Data already exists. Not inserted" << std::endl;
}
template<typename T> 
void BST<T>:: view(Node<T>* node)
{
	std::cout<<node->data << std::endl;
}
template<typename T>
void BST<T>::inOrder(Node<T>* node)
{
	if(node == nullptr)
		return; 
	if(node->left != nullptr)
		inOrder(node->left);
	view(node);
	if(node->right != nullptr)
		inOrder(node->right); 
}
template<typename T>
void BST<T>::preOrder(Node<T>* node)
{
	if(node == nullptr)
		return; 
	view(node);
	if(node->left != nullptr)
		preOrder(node->left);
	if(node->right != nullptr)
		preOrder(node->right); 
}
template<typename T>
void BST<T>::postOrder(Node<T>* node)
{
	if(node == nullptr)
		return; 
	if(node->left != nullptr)
		preOrder(node->left);
	if(node->right != nullptr)
		preOrder(node->right);
	view(node); 
}
template<typename T> 
void BST<T>::breadthFirst()
{	
	if(root == nullptr)
		return; 

	std::queue<Node<T>*> q; 
	Node<T> tmp;
	q.push(root); 

	while(!q.empty())
	{
		tmp = q.front(); 
		q.pop();

		std::cout << tmp->data;

		if(tmp->left != nullptr)
			q.push(tmp->left);
		if(tmp->right != nullptr)
			q.push(tmp->right);

	}
}
template<typename T> 
Node<T> BST<T>::findMin(node <T>* node)
{
	if(node == nullptr)
	{
		return nullptr;
	}
	if(node->left == nullptr)
	{
		return node; 
	}
	else
	{
		findMin(node->left);
	}


}
template<typename T>
void BST<T>::deleteNode(Node<T>* node, T data)
{
	if(node == nullptr)
	{
		std::cout << "not found" << std::endl; 
		return;
	}
	if(node->data < data)
	{
		deleteNode(node->right, data);
	}
	else if(node->data > data)
	{
		deleteNode(node->left, data);
	}
	else
	{
		if(node->right == nullptr&& node->left == nullptr)
		{
			delete node; 
			node = nullptr;

		}
		else if ( node->right == nullptr)
		{
			auto tmp = node;
			node = node->left; 
			delete tmp; 
		}
		else if(node->left == nullptr)
		{
			auto tmp = node; 
			node = node->right;
			delete tmp; 
		}
		else 
		{
			auto tmp = findMin(node->right); 
			node->data = tmp->data;
			deleteNode(node->right, tmp->data);

		}
	}
}
int main()
{	

	auto tree = BST<int>();
	tree.insert(10);
	tree.insert(15);
	tree.insert(4);
	tree.insert(6);
	tree.insert(2);
	tree.insert(1);
	tree.insert(20);


	return 0;
}