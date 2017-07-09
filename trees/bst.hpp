#include <iostream>
template<typename T>
class Node
{
public:
  T data;
  Node* left;
  Node* right;
  Node() : data(), left(nullptr), right() {}
  Node(const T& data) : data(data), left(nullptr), right(nullptr) {}
  Node(const T& data, Node* left, Node* right) : data(data), left(left), right(right){}
};

template<typename T> 
class BST
{
void clear(Node<T>* node); 
void insert(Node<T>*& node, const T& data);
void inOrder(Node<T>* node);
void preOrder(Node<T>* node);
void postOrder(Node<T>* node);
public:
	Node<T>* root;
	BST() :root(nullptr){} 
	~BST() {clear(root);}
	void insert(const T& data) {insert(root, data);}
	void view(Node<T>* node);
	void inOrder(){inOrder(root);}
	void preOrder(){preOrder(root);}
	void postOrder(){postOrder(root);}
	void breadthFirst();
	void deleteNode(Node<T>* node, T data);
	Node<T> findMin(Node<T>* root);
};
