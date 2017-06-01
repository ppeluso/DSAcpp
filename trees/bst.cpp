#include "bst.hpp"
#include <iostream>
#include <queue>
template<typename T> 
void BST<T>::insert(const T& data)
{
	if(root == nullptr)
	{
		root = new BSTNode<T>(data);
		return; 
	}

	auto tmp = root; 
	while(tmp != nullptr)
	{
		if(data < tmp->data)
		{
			tmp = tmp->left;
		}
		if(data > tmp->data)
		{
			tmp = tmp->right; 
		}

		if(data == tmp->data)
		{
			std::cout<<"data already exists"<< std::endl;
		}
	}

	tmp = new BSTNode<T>(data);

	return;
}

template<typename T>
void BST<T>::recursionInsert(const T& data, BSTNode<T>*& rt)
{
	if(rt == nullptr)
	{
		rt = new BSTNode<T>(data);
		return;
	}
	if(data == rt->data)
	{
		std::cout<< "value already exists \n";
		return; 
	}
	if(data < rt->data)
	{
		recursionInsert(data, rt->left);
	}
	if(data > rt->data)
	{
		recursionInsert(data, rt->right);
	}

}
template<typename T> 
void BST<T>::breadthFirst()
{
	std::queue<BSTNode<T>*> q{};

	auto tmp = root; 

	if( tmp != nullptr)
	{
		q.push(tmp);
	}

	while(!q.empty())
	{
		tmp = q.front();
		q.pop();
		std::cout<<tmp->data <<std::endl;
		if(tmp->right != nullptr)
			q.push(tmp->right);
		if(tmp->left != nullptr)
			q.push(tmp->left);
	}

	return;
}
int main()
{
	auto tree = BST<int>();

	tree.recursionInsert(1, tree.root);
	tree.recursionInsert(2,tree.root);
	tree.breadthFirst();
	delete tree.root; 
	delete tree.root->right;

}