#pragma once
#ifndef _DOUBLYITERATOR_H
#define _DOUBLYITERATOR_H

#include "DoublySortedLinkedList.h"

template<typename T>
struct DoublyNodeType;
template<typename T>
class DoublySortedLinkedList;

/**
*	연결리스트에서 쓰이는 Iterator의 클래스.
*/
template <typename T>
class DoublyIterator
{
	friend class DoublySortedLinkedList<T>;
public:
	/**
	*	디폴트 생성자.
	*/
	DoublyIterator(const DoublySortedLinkedList<T> &list) : m_List(list), m_pCurPointer(list.m_pFirst)
	{}; ///< DoublySortedLinkedList와 친구 클래스.

		/**
		*	@brief	list가 비어있는지 확인해주는 함수
		*	@return	비어 있을시 1, 아닐 시 0 반환
		*/
	bool NotNull();
	/**
	*	@brief	list의 다음 노드가 비어있는지 확인해주는 함수
	*	@return	비어 있을시 1, 아닐 시 0 반환
	*/
	bool NextNotNull();

	/**
	*	@brief	첫 노드가 가리키고 있는 data값을 반환해주는 함수
	*	@return	첫 노드가 가리키고 있는 data
	*/
	T First();

	/**
	*	@brief	iterator를 다음 노드값을 가리키게 하는 함수
	*	@return 넘어간 node내 data
	*/
	T Next();

	/**
	*	@brief	node의 마지막 주솟값을 전달해주는 함수
	*	@return	node의 마지막 주솟값
	*/
	DoublyNodeType<T>* GetNodeLast();

	/**
	*	@brief	node의 현재 가리키고 있는 노드의 주솟값을 전달해주는 함수
	*	@return	node의 현재 가리키고 있는 노드의 주솟값
	*/
	DoublyNodeType<T>* GetCurrentNode();
private:
	const DoublySortedLinkedList<T> &m_List;	///< DoublySortedLinkedList 를 저장할 List
	DoublyNodeType<T>* m_pCurPointer;			///< Iterator
};

template <typename T>
bool DoublyIterator<T> ::NotNull()
{
	if (m_pCurPointer == NULL)
		return false;
	else
		return true;
}

template <typename T>
bool DoublyIterator<T> ::NextNotNull()
{
	if (m_pCurPointer->next == NULL)
		return false;
	else
		return true;
}

template <typename T>
T DoublyIterator<T> ::First()
{
	return m_List.m_pFirst->data;
}

template <typename T>
DoublyNodeType<T>* DoublyIterator<T> ::GetNodeLast()
{
	return m_List.m_pLast;
}

template <typename T>
T DoublyIterator<T> ::Next()
{
	m_pCurPointer = m_pCurPointer->next;
	return m_pCurPointer->data;
}

template <typename T>
DoublyNodeType<T>* DoublyIterator<T> ::GetCurrentNode()
{
	return m_pCurPointer;
}

#endif _DOUBLYITERATOR_H