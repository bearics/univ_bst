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
typename bag<Item>::size_type bst_remove_all
(tree<Item>*& root_ptr, const Item& target)
// Precondition: root_ptr is a root pointer of a binary search tree 
// or may be NULL for an empty tree).
// Postcondition: All copies of target have been removed from the tree
// has been removed, and root_ptr now points to the root of the new 
// (smaller) binary search tree. The return value tells how many copies
// of the target were removed.
{
	/** STUDENT WORK
	** Note: This implementation is similar to bst_remove, except that
	** all occurrences of the target must be removed, and the return
	** value is the number of copies that were removed.
	*/

	tree<Item> *oldroot_ptr;

	if (root_ptr == NULL)
	{   // Empty tree
		/* STUDENT WORK */
	}

	if (target < root_ptr->data())
	{   // Continue looking in the left subtree
		/* STUDENT WORK */
	}

	if (target > root_ptr->data())
	{   // Continue looking in the right subtree
		/* STUDENT WORK */
	}

	if (root_ptr->left() == NULL)
	{   // Target was found and there is no left subtree, so we can
		// remove this node, making the right child be the new root.
		oldroot_ptr = root_ptr;
		root_ptr = root_ptr->right();
		delete oldroot_ptr;
		return 1;
	}

	// If code reaches this point, then we must remove the target from
	// the current node. We'll actually replace this target with the
	// maximum item in our left subtree. We then continue
	// searching for more copies of the target to remove.
	// This continued search must start at the current root (since
	// the maximum element that we moved up from our left subtree
	// might also be a copy of the target).
	/* STUDENT WORK */

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
	if (root_ptr == addend.root_ptr)
	{
		bag<Item> copy = addend;
		insert_all(copy.root_ptr);
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
void bag<Item>::insert_all(tree<Item>* addroot_ptr)
// Precondition: addroot_ptr is the root pointer of a binary search tree that
// is separate for the binary search tree of the bag that activated this
// method.
// Postcondition: All the items from the addroot_ptr's binary search tree
// have been added to the binary search tree of the bag that activated this
// method.
{
	if (addroot_ptr != NULL)
	{
		insert(addroot_ptr->data());
		insert_all(addroot_ptr->left());
		insert_all(addroot_ptr->right());
	}
}