#pragma once
#ifndef _RBITERATOR_H
#define _RBITERATOR_H
#include "Stack.h"

template <class T> class RedBlackTree;
template <class T> class RedBlackNode;

/**
*	@brief	RBIterator Ŭ����.
*/
template <class Type>
class RBIterator
{
public:
	/**
	*	@brief	iterator�� �����ϴ� Ʈ���� �Է¹޴� ������
	*	@pre	�Է¹��� Ʈ���� �ʱ�ȭ �ǰų�, �ùٸ� Ʈ������ �Ѵ�.
	*	@post	list�� current�� Ʈ���� ������ ����ȴ�.
	*/
	RBIterator(RedBlackTree<Type> &list) :_list(&list), _current(list.root()) {}

	/**
	*	@brief	�⺻�Ҹ���
	*/
	~RBIterator() { }

	/**
	*	@brief	���� ����� �ڷᰡ ������� Ȯ���ϴ� �Լ�
	*	@pre	iterator�� ���õǾ� �־�� �Ѵ�.
	*	@post
	*	@return
	*/
	bool IsNull();

	/**
	*	@brief	current�� ���� �������� ������ �Լ�
	*	@pre	iterator�� ���õǾ� �־�� �Ѵ�.
	*	@post
	*	@return
	*/
	void GoLeft();

	RedBlackNode<Type>* GetNextNode();

	RedBlackNode<Type>* GetPreNode();

	/**
	*	@brief	�������� �Ѿ�� �������� �����ڿ����ε�
	*	@pre	iterator�� �Ҵ��� �Ǿ� �־���Ѵ�.
	*	@post	DFS�� ���� ���� �Ѿ��
	*	@return	���� ����� ���۷����� ��ȯ�ȴ�.
	*/
	RBIterator<Type>& operator++();

	/**
	*	@brief	�������� �Ѿ�� �������� �����ڿ����ε�
	*	@pre	iterator�� �Ҵ��� �Ǿ� �־���Ѵ�.
	*	@post	DFS�� ���� ���� �Ѿ��
	*	@return	this����� ���簡 ��ȯ�ȴ�
	*/
	RBIterator<Type> operator++(int);

	/**
	*	@brief	���� ����� ���۷����� ��ȯ��
	*	@pre	itearator�� BST�Ҵ��� �Ǿ� �־���Ѵ�.
	*	@return	�������� ���۷����� ��ȯ�Ѵ�.
	*/
	Type& operator*();

	RedBlackNode<Type>* GetCurrent();

private:
	///Ʈ�� ����Ʈ
	RedBlackTree<Type>* _list;
	///������������
	RedBlackNode<Type>* _current;
	///��ȸ�� ���� ����
	Stack<RedBlackNode<Type>*> stack;
};

///���������Ͱ� nullptr���� ��ȯ�ϴ� �Լ�
template<class Type>
inline bool RBIterator<Type>::IsNull()
{
	return (_current == nullptr);
}

template<class Type>
void RBIterator<Type>::GoLeft()
{
	while (_current->left_->left_ != NULL)
	{
		_current = _current->left_;
	}
}

template<class Type>
RedBlackNode<Type>* RBIterator<Type>::GetNextNode()
{
	RedBlackNode<Type>* temp;
	if (_current->right_->right_ != nullptr) //������ ��尡 nullptr�� �ƴϸ�
	{
		temp = _current->right_;
		while (temp->left_->left_ != nullptr)//������ �����ʿ��� ���� ���ʳ�� ��ȯ
		{
			temp = temp->left_;
		}
		_current = temp;
		return _current;
	}
	else //�����ʳ�尡 nullptr�̸�
	{
		temp = _current->parent_;
		while (temp->v_ < _current->v_ && temp != temp->parent_) //�ڽź��� ū �θ��带 ã�Ƽ� �ݺ�
		{
			temp = temp->parent_;
		}
		_current = temp;
		return _current;
	}
	return NULL;
}

template<class Type>
RedBlackNode<Type>* RBIterator<Type>::GetPreNode()
{
	RedBlackNode<Type>* temp;
	if (_current->left_->left_ != nullptr) //���� ��尡 nullptr�� �ƴϸ�
	{
		temp = _current->left_;
		while (temp->right_->right_ != nullptr)//������ ���ʿ��� ���� ������� ��ȯ
		{
			temp = temp->right_;
		}
		_current = temp;
		return _current;
	}
	else //���ʳ�尡 nullptr�̸�
	{
		temp = _current->parent_;
		while (temp->v_ > _current->v_ && temp != temp->parent_) //�ڽź��� ���� �θ��带 ã�Ƽ� �ݺ�
		{
			temp = temp->parent_;
		}
		_current = temp;
		return _current;
	}
	return NULL;
}


///�������� �Ѿ���� ���� ������ �����ε�
template<class Type>
inline RBIterator<Type>& RBIterator<Type>::operator++()
{
	//Stack�� �̿��� DFS
	while (_current != nullptr)	//���簡 nullptr�϶����� �ݺ�
	{
		stack.Push(_current);	//���縦 ���ÿ� �߰�
		_current = _current->left_;	//������ �������� �̵�(���� �ǾƷ��� �̵�)
	}
	do
	{
		_current = stack.Pop();
	} while (_current->left_ == NULL && _current->right_ == NULL);
	_current = _current->right_;	//�������� �̵�
	return *this;
}

///������ �Ѿ���� ���� ������ �����ε�
template<class Type>
inline RBIterator<Type> RBIterator<Type>::operator++(int)
{
	RBIterator temporaryItem = *this;
	while (current != nullptr)
	{
		stack.Push(_current);
		_current = _current->left_;
	}
	do
	{
		_current = stack.Pop();
	} while (_current->left_ == NULL && _current->right_ == NULL);
	_current = _current->right_;
	return temporaryItem;	//�ӽð�ü�� ��ȯ�Ѵ�.
}

///�������� ������ ���۷����� ��ȯ�ϴ� �����ڿ����ε�
template<class Type>
inline Type & RBIterator<Type>::operator*()
{
	return (_current->v_);
}

template<class Type>
RedBlackNode<Type>* RBIterator<Type>::GetCurrent()
{
	return _current;
}

#endif