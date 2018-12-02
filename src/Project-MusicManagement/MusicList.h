#pragma once
#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

using namespace std;

#include "MusicType.h"
#include "RedBlackTree.h"

#define MAXSIZE 5

/**
*	biref Search primary key.
*/
enum SearchType { NAME, ARTIST, ALBUM, COMPOSER, LYRICIST, AGENCY };
/**
*	@brief array based single linked list.
*/
class MusicList
{
public:
	/**
	*	default constructor.
	*/
	MusicList()
	{
	}

	/**
	*	destructor.
	*/
	~MusicList()
	{
	}

	/**
	*	@brief	Make list empty.
	*	@pre	none.
	*	@post	clear list.
	*/
	void MakeEmpty();

	/**
	*	@brief	Get a number of records in current list.
	*	@pre	none.
	*	@post	none.
	*	@return	number of records in current list.
	*/
	int GetLength();

	/**
	*	@brief	����Ʈ�� ����ִ��� Ȯ��
	*	@pre	none.
	*	@post	none.
	*	@return	��������� 1 , �׷��� ������ 0�� ��ȯ
	*/
	int IsEmpty();

	/**
	*	@brief	add a new data into list.
	*	@pre	list should be initialized.
	*	@post	added the new record into the list.
	*	@param	data	new data.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int Add(MusicType data);

	/**
	*	@brief	���� ������ �������� �����͸� �˻��ϰ� �ش� �����͸� ������
	*	@pre	list�� �ʱ�ȭ
	*	@post	���� ID���� ���� ������ �Է� �Ķ���Ϳ� ����
	*	@param	ID�� ����ִ� ItemType�� ������ ����
	*	@return	���� ID���� ������ 1��, ������ 0�� ��ȯ
	*/
	int Get(MusicType& data);

	/**
	*	@brief	���� ������ �������� �����͸� �˻��ϰ� �ش� �����͸� ������
	*	@pre	list�� �ʱ�ȭ
	*	@post	���� ID���� ���� ������ �Է� �Ķ���Ϳ� ����
	*	@param	ID�� ����ִ� ItemType�� ������ ����
	*	@return	���� ID���� ������ 1��, ������ 0�� ��ȯ
	*/
	int FindType(MusicType data);

	/**
	*	@brief	���� ���ڵ� ����
	*	@pre	list�� �ʱ�ȭ
	*	@post	���� ID���� ���� ItemType�� �����ϰ�, list�� ũ�⸦ ����.
	*	@param	�����ϰ� ���� ID�� ����ִ� ItemType�� ������ ����
	*	@return	���� ID���� ������ 1, ������ 0�� ��ȯ
	*/
	int Delete(MusicType &data);

	/**
	*	@brief	���� ���ڵ� ����
	*	@pre	list�� �ʱ�ȭ
	*	@post	���� ID���� ���� ItemType�� ����ڿ��� �Է¹޾� ����
	*	@param	�����ϰ� ���� ID�� ����ִ� ItemType�� ������ ����
	*	@return	���� ID���� ������ 1, ������ 0�� ��ȯ
	*/
	int Replace(MusicType &data);

	/**
	*	@brief	sType�� ���� �Է¾�� ���� ���ڿ��� ���� ���� �˻� �� ���
	*	@pre	list�� �ʱ�ȭ
	*	@post	�˻��� ���� ���
	*	@param	sTerm	�˻��� ���ڿ�
	*	@param	sType	���, ����, �ٹ�, �帣 �� �о� ����
	*	@return	�˻� �� ������ ���� �� 1, ���� �� 0�� ��ȯ
	*/
	int Search(string sTerm, SearchType sType);

	/**
	*	@brief	���� �帣�� �˻��� ����� ��ġ�ϴ� ������ ���
	*	@param	inName	�˻��� ���
	*	@param	inGenre	�˻��� �帣
	*/
	void DisplayRetrieveNameNGenre(string inName, string inGenre);

	/**
	*	@brief	RedBlackTree�� Array�� ����
	*	@pre	m_Array�� �ʱ�ȭ
	*	@return	RedBlackTree�� Array
	*/
	RedBlackTree<MusicType> GetArray();


private:
	RedBlackTree<MusicType> m_Array;  ///< list array.
};


#endif