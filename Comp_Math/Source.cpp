
#include <iostream>
#include <queue>
//#include "Tree.h"


template <class T>
class Tree
{
private:
	T field;
	Tree<T>* left = nullptr;
	Tree<T>* right = nullptr;

	int level_counter_left(Tree<T>* v);
	int level_counter_right(Tree<T>* v);
	Tree<T>* make_node(T data);
public:
	Tree<T>* build_balanced_tree(Tree<T>*& v, int k);

	void print_tree_inorder(Tree<T>* v);

	int level_tree(Tree<T>* v);

	Tree<T>* max();
	Tree<T>* min();

	T max_T();
	T min_T();
};

template<class T>
inline Tree<T>* Tree<T>::make_node(T data)
{
	Tree<T>* v = new Tree<T>;
	v->field = data;
	v->left = nullptr;
	v->right = nullptr;
	return v;
}

template<class T>
inline int Tree<T>::level_counter_left(Tree<T>* v)
{
	static int n = 0;
	if (v == nullptr)
	{
		return 0;
	}
	n++;
	level_counter_left(v->left);
	return n;
}

template<class T>
inline int Tree<T>::level_counter_right(Tree<T>* v)
{
	static int n = 0;
	if (v == nullptr)
	{
		return 0;
	}
	n++;
	level_counter_right(v->right);
	return n;
}

template<class T>
inline int Tree<T>::level_tree(Tree<T>* v)
{
	int left = level_counter_left(v);
	int right = level_counter_right(v);
	if (left > right)
	{
		return left;
	}
	return right;
}


template<class T>
void Tree<T>::print_tree_inorder(Tree<T>* v)
{
	static int n = 0;
	if (v == nullptr)
	{
		return;
	}
	n++;
	print_tree_inorder(v->right);
	std::cout << "Level " << n << " field: " << v->field << "\n";
	print_tree_inorder(v->left);
	n--;
}


template<class T>
inline Tree<T>* Tree<T>::max()
{
	std::queue<Tree<T>*> _tmp_queue;
	Tree<T>* _node;
	Tree<T>* rb = nullptr;
	if (this == nullptr)
	{
		return nullptr;
	}
	else
	{
		T _max = this->field;
		_tmp_queue.push(this);
		while (!_tmp_queue.empty())
		{
			_node = _tmp_queue.front();
			_tmp_queue.pop();

			if (_max < _node->field)
			{
				_max = _node->field;
				rb = _node;
			}
			if (_node->left)
			{
				_tmp_queue.push(_node->left);
			}
			if (_node->right)
			{
				_tmp_queue.push(_node->right);
			}
		}
		return rb;
	}
}

template<class T>
inline Tree<T>* Tree<T>::min()
{
	std::queue<Tree<T>*> _tmp_queue;
	Tree<T>* _node;
	Tree<T>* rb = nullptr;
	if (this == nullptr)
	{
		return nullptr;
	}
	else
	{
		T _min = this->field;
		_tmp_queue.push(this);
		while (!_tmp_queue.empty())
		{
			_node = _tmp_queue.front();
			_tmp_queue.pop();

			if (_min > _node->field)
			{
				_min = _node->field;
				rb = _node;
			}
			if (_node->left)
			{
				_tmp_queue.push(_node->left);
			}
			if (_node->right)
			{
				_tmp_queue.push(_node->right);
			}
		}
		return rb;
	}
}



template<class T>
inline T Tree<T>::max_T()
{
	std::queue<Tree<T>*> _tmp_queue;
	Tree<T>* _node;
	if (this == nullptr)
	{
		return T();
	}
	else
	{
		T _max = this->field;
		_tmp_queue.push(this);
		while (!_tmp_queue.empty())
		{
			_node = _tmp_queue.front();
			_tmp_queue.pop();

			if (_max < _node->field)
				_max = _node->field;

			if (_node->left)
			{
				_tmp_queue.push(_node->left);
			}
			if (_node->right)
			{
				_tmp_queue.push(_node->right);
			}
		}
		return _max;
	}
}

template<class T>
inline T Tree<T>::min_T()
{
	std::queue<Tree<T>*> _tmp_queue;
	Tree<T>* _node;
	if (this == nullptr)
	{
		return T();
	}
	else
	{
		T _min = this->field;
		_tmp_queue.push(this);
		while (!_tmp_queue.empty())
		{
			_node = _tmp_queue.front();
			_tmp_queue.pop();

			if (_min > _node->field)
				_min = _node->field;

			if (_node->left)
			{
				_tmp_queue.push(_node->left);
			}
			if (_node->right)
			{
				_tmp_queue.push(_node->right);
			}
		}
		return _min;
	}
}
template<class T>
inline Tree<T>* Tree<T>::build_balanced_tree(Tree<T>*& v, int k)
{
	T i = rand() % 100 + 10;
	int n1 = k / 2;
	int n2 = k - n1 - 1;
	if (v == nullptr and k > 0)
	{
		v = make_node(i);
		v->left = build_balanced_tree(v->left, n1);
		v->right = build_balanced_tree(v->right, n2);
	}
	return v;
}

int main()
{

	Tree<int>* tree = nullptr;
	tree->build_balanced_tree(tree, 31);
	tree->print_tree_inorder(tree);
	std::cout << tree->level_tree(tree);
	tree->max();
	tree->min();

	return 0;
}

