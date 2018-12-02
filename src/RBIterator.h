#pragma once
#ifndef _RBITERATOR_H
#define _RBITERATOR_H
#include "Stack.h"

template <class T> class RedBlackTree;
template <class T> class RedBlackNode;

/**
*	@brief	RBIterator 클래스.
*/
template <class Type>
class RBIterator
{
public:
	/**
	*	@brief	iterator를 세팅하는 트리를 입력받는 생성자
	*	@pre	입력받은 트리가 초기화 되거나, 올바른 트리여야 한다.
	*	@post	list와 current가 트리의 정보로 변경된다.
	*/
	RBIterator(RedBlackTree<Type> &list) :_list(&list), _current(list.root()) {}

	/**
	*	@brief	기본소멸자
	*/
	~RBIterator() { }

	/**
	*	@brief	현재 노드의 자료가 비었는지 확인하는 함수
	*	@pre	iterator가 세팅되어 있어야 한다.
	*	@post
	*	@return
	*/
	bool IsNull();

	/**
	*	@brief	current를 제일 좌측으로 보내는 함수
	*	@pre	iterator가 세팅되어 있어야 한다.
	*	@post
	*	@return
	*/
	void GoLeft();

	RedBlackNode<Type>* GetNextNode();

	RedBlackNode<Type>* GetPreNode();

	/**
	*	@brief	다음노드로 넘어가는 전위증가 연산자오버로딩
	*	@pre	iterator에 할당이 되어 있어야한다.
	*	@post	DFS로 다음 노드로 넘어간다
	*	@return	현재 노드의 레퍼런스가 반환된다.
	*/
	RBIterator<Type>& operator++();

	/**
	*	@brief	다음노드로 넘어가는 후위증가 연산자오버로딩
	*	@pre	iterator에 할당이 되어 있어야한다.
	*	@post	DFS로 다음 노드로 넘어간다
	*	@return	this노드의 복사가 반환된다
	*/
	RBIterator<Type> operator++(int);

	/**
	*	@brief	현재 노드의 레퍼런스를 반환함
	*	@pre	itearator에 BST할당이 되어 있어야한다.
	*	@return	현재노드의 레퍼런스를 반환한다.
	*/
	Type& operator*();

	RedBlackNode<Type>* GetCurrent();

private:
	///트리 리스트
	RedBlackTree<Type>* _list;
	///현재노드포인터
	RedBlackNode<Type>* _current;
	///순회를 위한 스택
	Stack<RedBlackNode<Type>*> stack;
};

///현재포인터가 nullptr인지 반환하는 함수
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
	if (_current->right_->right_ != nullptr) //오른쪽 노드가 nullptr가 아니면
	{
		temp = _current->right_;
		while (temp->left_->left_ != nullptr)//현재노드 오른쪽에서 가장 왼쪽노드 반환
		{
			temp = temp->left_;
		}
		_current = temp;
		return _current;
	}
	else //오른쪽노드가 nullptr이면
	{
		temp = _current->parent_;
		while (temp->v_ < _current->v_ && temp != temp->parent_) //자신보다 큰 부모노드를 찾아서 반복
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
	if (_current->left_->left_ != nullptr) //왼쪽 노드가 nullptr가 아니면
	{
		temp = _current->left_;
		while (temp->right_->right_ != nullptr)//현재노드 왼쪽에서 가장 오른노드 반환
		{
			temp = temp->right_;
		}
		_current = temp;
		return _current;
	}
	else //왼쪽노드가 nullptr이면
	{
		temp = _current->parent_;
		while (temp->v_ > _current->v_ && temp != temp->parent_) //자신보다 작은 부모노드를 찾아서 반복
		{
			temp = temp->parent_;
		}
		_current = temp;
		return _current;
	}
	return NULL;
}


///다음으로 넘어가위한 증가 연산자 오버로딩
template<class Type>
inline RBIterator<Type>& RBIterator<Type>::operator++()
{
	//Stack을 이용한 DFS
	while (_current != nullptr)	//현재가 nullptr일때까지 반복
	{
		stack.Push(_current);	//현재를 스택에 추가
		_current = _current->left_;	//현재의 왼쪽으로 이동(왼쪽 맨아래로 이동)
	}
	do
	{
		_current = stack.Pop();
	} while (_current->left_ == NULL && _current->right_ == NULL);
	_current = _current->right_;	//우측으로 이동
	return *this;
}

///음으로 넘어가위한 증가 연산자 오버로딩
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
	return temporaryItem;	//임시객체를 반환한다.
}

///현재노드의 데이터 레퍼런스를 반환하는 연산자오버로딩
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