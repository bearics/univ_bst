#pragma once

#include <cstdlib>
#include "tree.h"

template <class Item>
class bag
{
public:
	typedef size_t size_type;
	typedef Item value_type;
	bag() { root_ptr = NULL; }
	bag(const bag& source);
	~bag();
	size_type erase(const Item& target);
	bool erase_one(const Item& target);
	void insert(const Item& entry);
	void sort();
	void operator +=(const bag& addend);
	void operator =(const bag& source);
	size_type size() const;
	size_type count(const Item& target) const;
	void show_content() const { print(root_ptr, 2); }
private:
	tree<Item> *root_ptr; 
	void insert_all(tree<Item>* addroot_ptr);
};

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
typename bag<Item>::size_type bst_remove_all(tree<Item>*& root_ptr, const Item& target)
{	// �ߺ��� Ÿ���� ��� �����ϴ� �Լ�

	tree<Item> *oldroot_ptr;
	bag<Item>::size_type count = 0;

	if (root_ptr == NULL) // �� Ʈ���� ��
		return  count;
	if (target < root_ptr->data())	// �����Ͱ� Ÿ�ٺ��� ũ�� ���� Ʈ������ ����
		return bst_remove_all(root_ptr->left(), target);
	else if(target > root_ptr->data())// �����Ͱ� Ÿ�ٺ��� ������ ������ Ž��
		return bst_remove_all(root_ptr->right(), target);
		// Ÿ�ٰ� ������ ���� ������
	else
	{
		if (root_ptr->left() == NULL)
		{   // ���� Ʈ���� ������ ������ Ʈ���� ��Ʈ�� ��
			oldroot_ptr = root_ptr;
			root_ptr = root_ptr->right();
			delete oldroot_ptr;
			return 1;
		}
		else
		{
			bst_remove_max(root_ptr->left(), root_ptr->data());
			return 1 + bst_remove_all(root_ptr, target);
		}
	}

}

template <class Item>
bag<Item>::bag(const bag<Item>& source)
{
	root_ptr = tree_copy(source.root_ptr);
}

template <class Item>
bag<Item>::~bag()
{
	tree_clear(root_ptr);
}

template <class Item>
typename bag<Item>::size_type bag<Item>::size() const
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
	tree<Item>* cursor = root_ptr;

	if (root_ptr == NULL)	// �� Ʈ���� ��.
		return 0; 
	else
	{
		while (cursor != NULL)
		{
			if (cursor->data() < target)	// Ÿ�ٺ��� ������ ������ Ž��
				cursor = cursor->right();
			else if (cursor->data() > target) // Ÿ�ٺ��� ũ�� ���� Ž��
				cursor = cursor->left();
			else if (cursor->data() == target)
			{ // Ÿ���� ã���� ī��Ʈ �����ϰ� ���ʵ� Ž��
				answer++;
				cursor = cursor->left();
			}
		}
	}
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