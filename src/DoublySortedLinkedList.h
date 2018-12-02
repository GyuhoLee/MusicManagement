#pragma once
#ifndef _DOUBLYSORTEDLINKEDLIST_H
#define _DOUBLYSORTEDLINKEDLIST_H

#include "DoublyIterator.h"

template<typename T>
class DoublyIterator;

/**
*	���Ḯ��Ʈ���� ���̴� NodeType�� ����ü
*/
template <typename T>
struct DoublyNodeType
{
	T data; ///< �� ����� ������.
	DoublyNodeType *prev; ///< ����� ���� ����Ű�� ������.
	DoublyNodeType *next; ///< ����� ������ ����Ű�� ������.

	DoublyNodeType<T>& operator=(const DoublyNodeType<T>& node);
};

//���Կ����� �����ε�
template <typename T>
DoublyNodeType<T>& DoublyNodeType<T>::operator=(const DoublyNodeType<T>& node)
{
	data = node.data;   //�����͸� �����س���
	DoublyNodeType<T>* currentNode1;
	DoublyNodeType<T>* currentNode2;

	if (node.next == NULL)   //��(������)����̸�
	{
		next = NULL;   //�ؽ�Ʈ�� NULL
		prev = NULL;
	}
	else
	{
		currentNode2 = new DoublyNodeType<T>;   //�� ��带����
		next = currentNode2;   //next�� ���θ��� ���� ���Ը���
		currentNode2->data = node.next->data;   //���θ��� ����� �����͸� �Է¹��� ����� ���� �����ͷ� ����
		currentNode2->prev = this;
		currentNode1 = node.next->next;   //�ٸ� ��忡 �ٴ��� ���� ����

		while (currentNode1 != NULL)   //�ٴ�����尡 �������϶����� �ݺ�
		{
			currentNode2->next = new DoublyNodeType<T>;   //����带 ����
			currentNode2->next->prev = currentNode2;
			currentNode2 = currentNode2->next;   //���� ���� �̵��Ѵ�
			currentNode2->data = currentNode1->data;   //�̵��� ����� �����͸� �����Ѵ�
			currentNode1 = currentNode1->next;   //�ٴ�����嵵 �̵��Ѵ�.
		}
		currentNode2->next = NULL;   //���� ��带 NULL�� �����Ѵ�.
	}
	return *this;
}

/**
*	���ĵ� �����Ḯ��Ʈ Ŭ����
*/
template <typename T>
class DoublySortedLinkedList
{
	friend class DoublyIterator<T>; ///< DoublyIterator�� ģ�� Ŭ����.
public:
	/**
	*	@biref	����Ʈ ������.
	*/
	DoublySortedLinkedList();

	/**
	*	@brief	�Ҹ���.
	*/
	~DoublySortedLinkedList();

	/**
	*	@brief	����Ʈ�� ������� �ƴ��� �˻��Ѵ�.
	*	@pre	m_nLength�� ���� ������ �־�� �Ѵ�.
	*	@post	������� �ƴ����� �˷��ش�.
	*	@return	��������� true, �ƴϸ� false�� ��ȯ.
	*/
	bool IsEmpty();

	/**
	*	@brief	����Ʈ�� ���� á���� �ƴ��� �˻��Ѵ�.
	*	@pre	m_nLength�� ���� ������ �־�� �Ѵ�.
	*	@post	���� á���� �ƴ����� �˷��ش�.
	*	@return	���� �������� true, �ƴϸ� false�� ��ȯ.
	*/
	bool IsFull();

	/**
	*	@brief	����Ʈ�� ����.
	*	@pre	����.
	*	@post	m_pFirst�� m_pLast�� ������ ��� �����͸� �����.
	*/
	void MakeEmpty();

	/**
	*	@brief	����Ʈ�� ���̸� ��ȯ�Ѵ�.
	*	@pre	����.
	*	@post	����Ʈ�� ���̸� ��ȯ.
	*	@return	m_nLength ����Ʈ�� ���� ��ȯ.
	*/
	int GetLength() const;

	/**
	*	@brief	���ο� �������� ����Ʈ�� �߰��Ѵ�.
	*	@pre	item�� �Է¹޴´�.
	*	@post	�������� ����Ʈ�� �߰��Ѵ�.
	*	@return	���� �������� ������ 0�� ��ȯ�ϰ�, �Է¿� �����ϸ� 1�� ��ȯ.
	*/
	int Add(T item);

	/**
	*	@brief	�Է¹��� �������� ����Ʈ���� �����Ѵ�.
	*	@pre	item�� �Է¹޴´�.
	*	@post	�Է¹��� �������� ����Ʈ���� ã�� �����Ѵ�.
	*	@return	������ ���������� 1, �׷��� ������ 0�� ��ȯ
	*/
	int Delete(T item);

	/**
	*	@brief	�Է¹��� ���������� ������ �ٲ۴�.
	*	@pre	item�� �Է¹޴´�.
	*	@post	���ο� ������ ��ü�ȴ�.
	*	@return	���ſ� ���������� 1, �׷��� ������ 0�� ��ȯ
	*/
	int Replace(T item);

	/**
	*	@brief	�Է¹��� �������� ������ ���Ͽ� ���� ����Ʈ�� �������� �����´�.
	*	@pre	item�� �Է¹޴´�.
	*	@post	�˻��� �����͸� �����ۿ� �ִ´�.
	*	@return	��ġ�ϴ� �����͸� ã���� 1, �׷��� ������ 0�� ��ȯ.
	*/
	int Get(T &item);

	/**
	*	@brief	ù��° ����� �ּڰ��� �������ִ� �Լ�
	*	@return	ù��° ����� �ּڰ�
	*/
	DoublyNodeType<T>* GetFirst();

	/**
	*	@brief	������ ����� �ּڰ��� �������ִ� �Լ�
	*	@return	������ ����� �ּڰ�
	*/
	DoublyNodeType<T>* GetLast();

	//opearter
	DoublySortedLinkedList<T>& operator=(const DoublySortedLinkedList<T>& list);

private:
	DoublyNodeType<T>* m_pFirst; ///< �ּҰ��� ������ ����Ʈ�� �� ó��.
	DoublyNodeType<T>* m_pLast; ///< �ִ��� ������ ����Ʈ�� �� ��.
	int m_nLength; ///< ����Ʈ�� ����.
};

// ����Ʈ�� �� ó���� ���� ���θ� ����Ű�� �����ϰ� ����Ʈ�� ���̸� 0���� �ʱ�ȭ���ѳ��´�.
template <typename T>
DoublySortedLinkedList<T> ::DoublySortedLinkedList()
{
	m_pFirst = new DoublyNodeType<T>;
	m_pLast = new DoublyNodeType<T>;

	m_pFirst->next = m_pLast; // ���� ó���� ���θ� ����Ű�� �ʱ�ȭ.
	m_pFirst->prev = NULL; // ó��.

	m_pLast->next = NULL; // ��.
	m_pLast->prev = m_pFirst; // ���� ó���� ���θ� ����Ű�� �ʱ�ȭ.

	m_nLength = 0; // ���̴� 0.
}

// �Ҹ���.
template <typename T>
DoublySortedLinkedList<T>::~DoublySortedLinkedList()
{
	//delete m_pFirst;
	//delete m_pLast;
}

// ����Ʈ�� ������� �˻��Ѵ�.
template <typename T>
bool DoublySortedLinkedList<T>::IsEmpty()
{
	if (m_nLength == 0)
		return true;
	else
		return false;
}

// ����Ʈ�� �� ���ִ��� �˻��Ѵ�.
template <typename T>
bool DoublySortedLinkedList<T>::IsFull()
{
	if (m_nLength == 10)
		return true;
	else
		return false;
}

// ����Ʈ�� ����.
template <typename T>
void DoublySortedLinkedList<T>::MakeEmpty()
{
	DoublyNodeType<T> *pItem;
	DoublyIterator<T> itor(*this);
	itor.Next(); // �������� �̵�.

	while (itor.NextNotNull())
	{
		pItem = itor.m_pCurPointer;
		itor.Next(); // ���� �����͸� �������� �̵�.
		delete pItem;
	}

	m_pFirst->next = m_pLast;
	m_pFirst->prev = NULL;
	m_pLast->prev = m_pFirst;
	m_pLast->next = NULL;

	return;
}

// ����Ʈ�� ���̸� ��ȯ�Ѵ�.
template <typename T>
int DoublySortedLinkedList<T>::GetLength() const
{
	return m_nLength;
}

// �������� �Է¹޾� ����Ʈ�� �´� �ڸ��� ã�� �����Ѵ�.
template <typename T>
int DoublySortedLinkedList<T>::Add(T item)
{
	if (IsEmpty()) // ó�� ������ ��
	{

		DoublyNodeType<T> *pItem = new DoublyNodeType<T>;
		pItem->data = item;
		m_pFirst->next = pItem;
		pItem->prev = m_pFirst;
		pItem->next = m_pLast;
		m_pLast->prev = pItem; // ó���� �� ���̿� ����.
		m_nLength++;
		return 1;
	}
	else // ó���� �ƴ� ��
	{
		DoublyIterator<T> itor(*this);
		itor.Next(); // �������� �̵�.
		while (1)
		{
			if (item < itor.m_pCurPointer->data) // �´� �ڸ��� ã�´�.
			{
				DoublyNodeType<T> *pItem = new DoublyNodeType<T>;
				pItem->data = item;
				pItem->prev = itor.m_pCurPointer->prev;
				pItem->next = itor.m_pCurPointer;
				itor.m_pCurPointer->prev->next = pItem;
				itor.m_pCurPointer->prev = pItem; // �������� ����.
				m_nLength++;
				return 1;
			}
			else if (item == itor.m_pCurPointer->data) // ���� ������ �������� ������
				return 0; // 0�� ��ȯ.
			else if (itor.m_pCurPointer == m_pLast)	//����Ʈ�� Last�� ��
			{
				DoublyNodeType<T> *pItem = new DoublyNodeType<T>;
				pItem->data = item;
				pItem->prev = m_pLast->prev;
				pItem->next = m_pLast;
				m_pLast->prev->next = pItem;
				m_pLast->prev = pItem;
				m_nLength++;
				return 1;
			}
			else
				itor.Next(); // �������� �̵�.
		}
	}
}

// �Է¹��� �������� �����Ϳ��� ã�Ƴ��� �����Ѵ�.
template <typename T>
int DoublySortedLinkedList<T>::Delete(T item)
{
	DoublyIterator<T> itor(*this);
	itor.Next(); // �������� �̵�.

	while (itor.m_pCurPointer != m_pLast)
	{
		if (itor.m_pCurPointer->data == item) // ��ġ�ϴ� �����͸� ã�´�.
		{
			DoublyNodeType<T> *pItem = new DoublyNodeType<T>;
			pItem = itor.m_pCurPointer;
			itor.Next();
			pItem->prev->next = itor.m_pCurPointer;
			itor.m_pCurPointer->prev = pItem->prev; // �����ϴ� ����� �հ� �ڸ� ���� �̾��ش�.
			delete pItem; // ����.
			m_nLength--; // ���� ����.
			return 1;
		}
		else
			itor.Next();
	}
	return 0;
}

// �Է¹��� �������� ������ ��ü�Ѵ�.
template <typename T>
int DoublySortedLinkedList<T>::Replace(T item)
{
	DoublyIterator<T> itor(*this);
	itor.Next(); // �������� �̵�.

	while (itor.m_pCurPointer != m_pLast)
	{
		if (itor.m_pCurPointer->data == item)
		{
			itor.m_pCurPointer->data = item; // ������ ��ü.
			return 1;
		}
		else
			itor.Next();
	}

	return 0;
}

// �Է¹��� �����۰� ��ġ�ϴ� �������� ����Ʈ���� ã�� �����´�.
template <typename T>
int DoublySortedLinkedList<T>::Get(T &item)
{
	DoublyIterator<T> itor(*this);
	itor.Next();

	while (itor.m_pCurPointer != m_pLast)
	{
		if (itor.m_pCurPointer->data == item)
		{
			item = itor.m_pCurPointer->data;
			return 1; // ��ġ�ϸ� 1�� ��ȯ.
		}
		else
			itor.Next(); // �������� �̵�.
	}

	return 0; // ��ġ���� ������ 0�� ��ȯ.
}

template <typename T>
DoublyNodeType<T>* DoublySortedLinkedList<T>::GetFirst()
{
	return m_pFirst;
}

template <typename T>
DoublyNodeType<T>* DoublySortedLinkedList<T>::GetLast()
{
	return m_pLast;
}

template <typename T>
DoublySortedLinkedList<T>& DoublySortedLinkedList<T>::operator=(const DoublySortedLinkedList<T>& list)
{
	m_nLength = 0;
	DoublyIterator<T> itor(list);
	itor.Next();
	while(itor.GetCurrentNode() != itor.GetNodeLast())
	{
		Add(itor.GetCurrentNode()->data);
		itor.Next();
	}
	return *this;
}

#endif _DOUBLYSORTEDLINKEDLIST_H