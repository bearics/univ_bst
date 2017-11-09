#pragma once
#include <cstdlib>  // Provides NULL and size_t
#include <iostream>
#include <iomanip>
using namespace std;

template <class Item>
class tree
{
public:
	// TYPEDEF
	typedef Item value_type;
	// CONSTRUCTOR
	tree(
		const Item& init_data = Item(),
		tree* init_left = NULL,
		tree* init_right = NULL
	)
	{
		data_field = init_data;
		left_field = init_left;
		right_field = init_right;
	}
	// MODIFICATION MEMBER FUNCTIONS
	Item& data() { return data_field; }
	tree*& left() { return left_field; }
	tree*& right() { return right_field; }
	void set_data(const Item& new_data) { data_field = new_data; }
	void set_left(tree* new_left) { left_field = new_left; }
	void set_right(tree* new_right) { right_field = new_right; }
	// CONST MEMBER FUNCTIONS
	const Item& data() const { return data_field; }
	const tree* left() const { return left_field; }
	const tree* right() const { return right_field; }
	bool is_leaf() const
	{
		return (left_field == NULL) && (right_field == NULL);
	}
private:
	Item data_field;
	tree *left_field;
	tree *right_field;
};

// NON-MEMBER FUNCTIONS for the tree<Item>:
template <class Process, class BTNode>
void inorder(Process f, BTNode* node_ptr);

template <class Process, class BTNode>
void preorder(Process f, BTNode* node_ptr);

template <class Process, class BTNode>
void postorder(Process f, BTNode* node_ptr);

template <class Item, class SizeType>
void print(tree<Item>* node_ptr, SizeType depth);

template <class Item>
void tree_clear(tree<Item>*& root_ptr);

template <class Item>
tree<Item>* tree_copy(const tree<Item>* root_ptr);

template <class Item>
size_t tree_size(const tree<Item>* node_ptr);

template <class Process, class BTNode>
	void inorder(Process f, BTNode* node_ptr)
	// Library facilities used: cstdlib
	{
		if (node_ptr != NULL)
		{
			inorder(f, node_ptr->left( ));
			f( node_ptr->data( ) );
			inorder(f, node_ptr->right( ));
		}
	}

	template <class Process, class BTNode>
	void postorder(Process f, BTNode* node_ptr)
	// Library facilities used: cstdlib
	{
		if (node_ptr != NULL)
		{
			postorder(f, node_ptr->left( ));
			postorder(f, node_ptr->right( ));
			f(node_ptr->data( ));
		}
	}

	template <class Process, class BTNode>
	void preorder(Process f, BTNode* node_ptr)
	// Library facilities used: cstdlib
	{
		if (node_ptr != NULL)
		{
			f( node_ptr->data( ) );
			preorder(f, node_ptr->left( ));
			preorder(f, node_ptr->right( ));
		}
	}

	template <class Item, class SizeType>
	void print(tree<Item>* node_ptr, SizeType depth)
	// Library facilities used: iomanip, iostream, stdlib
	{
		if (node_ptr != NULL)
		{
			print(node_ptr->right( ), depth+1);
			std::cout << std::setw(4*depth) << ""; // Indent 4*depth spaces.
			std::cout << node_ptr->data( ) << std::endl;
			print(node_ptr->left( ),  depth+1);
		}
	}    
	
	template <class Item>
	void tree_clear(tree<Item>*& root_ptr)
	// Library facilities used: cstdlib
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
	// Library facilities used: cstdlib
	{
	tree<Item> *l_ptr;
	tree<Item> *r_ptr;

	if (root_ptr == NULL)
		return NULL;
	else
	{
		l_ptr = tree_copy( root_ptr->left( ) );
		r_ptr = tree_copy( root_ptr->right( ) );
		return
		new tree<Item>( root_ptr->data( ), l_ptr, r_ptr);
	}
	}

	template <class Item>
	size_t tree_size(const tree<Item>* node_ptr)
	// Library facilities used: cstdlib
	{
		if (node_ptr == NULL)
			return 0;
		else 
			return 
		1 + tree_size(node_ptr->left( )) + tree_size(node_ptr->right( ));
	}