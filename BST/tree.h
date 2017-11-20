#pragma once
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

template <class Item>
class tree
{
public:
	typedef Item value_type;
	tree(const Item& init_data = Item(), tree* init_left = NULL, tree* init_right = NULL)
	{
		data_field = init_data;
		left_field = init_left;
		right_field = init_right;
	}
	Item& data() { return data_field; }
	tree*& left() { return left_field; }
	tree*& right() { return right_field; }
	void set_data(const Item& new_data) { data_field = new_data; }
	void set_left(tree* new_left) { left_field = new_left; }
	void set_right(tree* new_right) { right_field = new_right; }
	const Item& data() const { return data_field; }
	const tree* left() const { return left_field; }
	const tree* right() const { return right_field; }
private:
	Item data_field;
	tree *left_field;
	tree *right_field;
};

template <class Item>
void inorder(tree<Item>* node_ptr)
{
	if (node_ptr != NULL)
	{
		inorder(node_ptr->left( ));
		cout << node_ptr->data() << " ";
		inorder(node_ptr->right( ));
	}
}

template <class Item, class SizeType>
void print(tree<Item>* node_ptr, SizeType depth)
{
	if (node_ptr != NULL)
	{
		print(node_ptr->right( ), depth+1);
		std::cout << std::setw(4*depth) << "";
		std::cout << node_ptr->data( ) << std::endl;
		print(node_ptr->left( ),  depth+1);
	}
}    
	
template <class Item>
void tree_clear(tree<Item>*& root_ptr)
{
if (root_ptr != NULL)
{
	tree_clear( root_ptr->left( ) );
	tree_clear( root_ptr->right( ) );
	delete root_ptr;
	root_ptr = NULL;
}
}

template <class Item>
tree<Item>* tree_copy(const tree<Item>* root_ptr)
{
tree<Item> *left;
tree<Item> *right;

if (root_ptr == NULL)
	return NULL;
else
{
	left = tree_copy( root_ptr->left( ) );
	right = tree_copy( root_ptr->right( ) );
	return
	new tree<Item>( root_ptr->data( ), left, right);
}
}

template <class Item>
size_t tree_size(const tree<Item>* root_ptr)
{
	if (root_ptr == NULL)
		return 0;
	else 
		return (1 + tree_size(root_ptr->left( )) + tree_size(root_ptr->right( )));
}