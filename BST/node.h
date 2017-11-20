#pragma once

#include <cstdlib>
#include "tree.h"

template <class Item>
class bag
{
public:
	typedef size_t size_type;
	typedef Item value_type;
	// CONSTRUCTORS and DESTRUCTOR ....
	bag() { root_ptr = NULL; }
	bag(const bag& source);
	~bag();
	// MODIFICATION functions
	size_type erase(const Item& target);
	bool erase_one(const Item& target);
	void insert(const Item& entry);
	void sort();
	void operator +=(const bag& addend);
	void operator =(const bag& source);
	// CONSTANT functions
	size_type size() const;
	size_type count(const Item& target) const;
	void debug() const { print(root_ptr, 3); }
private:
	tree<Item> *root_ptr; // Root pointer of binary search tree
	void insert_all(tree<Item>* addroot_ptr);
};

// NONMEMBER functions for the tree<Item> template class
template <class Item>
bag<Item> operator +(const bag<Item>& b1, const bag<Item>& b2);

template <class Item>
void bst_remove_max(tree<Item>*& root_ptr, Item& removed)
// ���� data �� �ڸ��� ���� Ʈ�� �߿� ���� ū ������ ��ü�ϰ� �����ϴ� �Լ�
{
	tree<Item> *oldroot;

	if (root_ptr == NULL)
	{	// ��Ʈ���� �Ұ� ����
		return;
	}

	if (root_ptr->right() == NULL)
	{	// ������ Ʈ���� ���� ���
		removed = root_ptr->data();
		oldroot = root_ptr;
		root_ptr = root_ptr->left();
		delete oldroot;
	}
	else // ������ Ʈ���� ������ 
	{
		bst_remove_max(root_ptr->right(), removed);
	}
	return;
}

template <class Item>
bool bst_remove(tree<Item>*& root_ptr, const Item& target)
// Ʈ������ Ÿ���� ����� �Լ�(erase_one �Լ��� ���� ����)
{
	tree<Item> *oldroot_ptr;

	if (root_ptr == NULL)
	{   // �� Ʈ���� �����Ұ� ����
		return false;
	}

	if (target < root_ptr->data())
	{	// �����Ͱ� Ÿ�ٺ��� ũ�� ���� Ʈ���� Ž��
		return bst_remove(root_ptr->left(), target);
	}
	else if (target > root_ptr->data())
	{   // �����Ͱ� Ÿ�ٺ��� ������ ������ Ʈ�� Ž��
		return bst_remove(root_ptr->right(), target);
	}
	else // data == target
	{	// ������ ���� Ÿ�ٰ� ���� ��� ���� Ʈ���� �ִ� ���� ���� ��� �и�
		if (root_ptr->left() == NULL)
		{   // ���� Ʈ���� ������ ������ Ʈ���� ��Ʈ�� ��
			oldroot_ptr = root_ptr;
			root_ptr = root_ptr->right();
			delete oldroot_ptr;
			return true;
		}
		else
		{	// ���� Ʈ���� ������ �� �߿� ���� ū ���� ��Ʈ�� �����
			bst_remove_max(root_ptr->left(), root_ptr->data());
			return true;
		}
	}

	}

template <class Item>
bool bst_search(tree<Item>*& root_ptr, const Item& target)
{	// Ÿ�ٰ� ��ġ�ϴ� ������ ���� ���� Ʈ���� �ִ��� Ȯ��
	if(root_ptr->data() == target )
		return true;
	else
	{
		if (root_ptr->left() != NULL)
			return bst_search(root_ptr->left(), target);
		if (root_ptr->right() != NULL)
			return bst_search(root_ptr->right(), target);
		return false;
	}
}

template <class Item>
typename bag<Item>::size_type bst_remove_all
(tree<Item>*& root_ptr, const Item& target)
// �ߺ��� Ÿ���� ��� �����ϴ� �Լ�
{

	tree<Item> *oldroot_ptr;
	bag<Item>::size_type count = 0;

	while (bst_search(root_ptr, target))
	{	// bst_search �Լ��� ���� Ÿ���� Ʈ���� �ִٸ� �ϳ��� �����.
		bst_remove(root_ptr, target);
		count++;
	}

	return count;
}

template <class Item>
bag<Item>::bag(const bag<Item>& source)
// Library facilities used: bintree.h
{
	root_ptr = tree_copy(source.root_ptr);
}

template <class Item>
bag<Item>::~bag()
// Header file used: bintree.h
{
	tree_clear(root_ptr);
}

template <class Item>
typename bag<Item>::size_type bag<Item>::size() const
// Header file used: bintree.h
{
	return tree_size(root_ptr);
}

template <class Item>
void bag<Item>::insert(const Item& entry)
{
	tree<Item> *cursor;

	if (root_ptr == NULL)
	{	// ó���̸� �׳� ���ο� Ʈ�� �߰�
		root_ptr = new tree<Item>(entry);
		return;
	}
	else
	{	// ó���� �ƴϸ� entry ���� ���� Ʈ�� �߰�
		cursor = root_ptr;
		while (1)
		{
			if (entry <= cursor->data())
			{
				if (cursor->left() == NULL)
				{
					cursor->set_left(new tree<Item>);
					cursor->left()->set_data(entry);
					return;
				}
				else
				{
					cursor = cursor->left();
				}
			}
			else
			{
				if (cursor->right() == NULL)
				{
					cursor->set_right(new tree<Item>);
					cursor->right()->set_data(entry);
					return;
				}
				else
				{
					cursor = cursor->right();
				}
			}
		}
	}
}

template <class Item>
void bag<Item>::sort()
{
	inorder(root_ptr);
}

template <class Item>
typename bag<Item>::size_type bag<Item>::count(const Item& target) const
{
	size_type answer = 0;
	tree<Item> *cursor;

	cursor = root_ptr;
	/* STUDENT WORK */


	return answer;
}

template <class Item>
typename bag<Item>::size_type bag<Item>::erase(const Item& target)
{
	return bst_remove_all(root_ptr, target);
}

template <class Item>
bool bag<Item>::erase_one(const Item& target)
{
	return bst_remove(root_ptr, target);
}

template <class Item>
void bag<Item>::operator =(const bag<Item>& source)
// Header file used: bintree.h
{
	if (root_ptr == source.root_ptr)
		return;
	tree_clear(root_ptr);
	root_ptr = tree_copy(source.root_ptr);
}

template <class Item>
void bag<Item>::operator +=(const bag<Item>& addend)
{
	tree<Item> *addroot_ptr;
	if (root_ptr == addend.root_ptr)
	{
		addroot_ptr = tree_copy(addend.root_ptr);
		insert_all(addroot_ptr);
		tree_clear(addroot_ptr);
	}
	else
		insert_all(addend.root_ptr);
}

template <class Item>
bag<Item> operator +(const bag<Item>& b1, const bag<Item>& b2)
{
	bag<Item> answer = b1;
	answer += b2;
	return answer;
}

template <class Item>
void bag<Item>::insert_all(tree<Item>* root_ptr)
{	// �ش� ��Ʈ�� �ִ� Ʈ���� ���� ��忡 ��� insert�Ѵ�.
	if (root_ptr != NULL)
	{
		insert(root_ptr->data());
		insert_all(root_ptr->left());
		insert_all(root_ptr->right());
	}
}