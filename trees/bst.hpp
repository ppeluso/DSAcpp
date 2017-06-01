
template<typename T>
class BSTNode
{
public:
	T data;
	BSTNode* left; 
	BSTNode* right; 
	BSTNode() : left(nullptr), right(nullptr) {}
	BSTNode(const T& data) : data(data), left(nullptr), right(nullptr){}
	BSTNode(const T& data, BSTNode* left, BSTNode* right) :
	data(data), 
	left(left), 
	right(right)
	{}
};

template<typename T>
class BST 
{

public:
	BSTNode<T>* root; 
	BST(): root(nullptr){}
	void insert(const T& data);
	void recursionInsert(const T& data, BSTNode<T>*& rt);
	void breadthFirst();

};