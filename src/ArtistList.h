#pragma once
#ifndef _ARTISTLIST_H
#define _ARTISTLIST_H
#include "ArtistType.h"


/**
*	@brief	artist array based single linked list.
*/
class ArtistList
{
public:
	/**
	*	default constructor.
	*/
	ArtistList()
	{
	}

	/**
	*	destructor.
	*/
	~ArtistList()
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
	*	@brief	�������� �������� �����͸� �˻��ϰ� �ش� �����͸� ������
	*	@pre	list�� �ʱ�ȭ
	*	@post	���� ID���� ���� ������ �Է� �Ķ���Ϳ� ����
	*	@param	ID�� ����ִ� ItemType�� ������ ����
	*	@return	���� ID���� ������ 1��, ������ 0�� ��ȯ
	*/
	int Get(MusicType& data);

	/**
	*	@brief	���� ���ڵ� ����
	*	@pre	list�� �ʱ�ȭ
	*	@post	���� ID���� ���� ItemType�� �����ϰ�, list�� ũ�⸦ ����.
	*	@param	�����ϰ� ���� ID�� ����ִ� ItemType�� ������ ����
	*	@return	���� ID���� ������ 1, ������ 0�� ��ȯ
	*/
	int Delete(MusicType &inData);

	/**
	*	@brief	���� ���ڵ� ����
	*	@pre	list�� �ʱ�ȭ
	*	@post	���� ID���� ���� ItemType�� ����ڿ��� �Է¹޾� ����
	*	@param	�����ϰ� ���� ID�� ����ִ� ItemType�� ������ ����
	*	@return	���� ID���� ������ 1, ������ 0�� ��ȯ
	*/
	int Replace(MusicType &inData);

	/**
	*	@brief	����� ��� ������ �� ���� �ӿ� �ִ� ���ǵ��� ȭ�鿡 ���
	*	@pre	list�� �ʱ�ȭ
	*/
	void DisplayArtistAll();

	/**
	*	@brief	Ŀ���� x, y�� �̵�
	*	@post	Ŀ���� (x,y) �� �̵���.
	*	@pram	x	�̵��� x ��ǥ
	*	@pram	y	�̵��� y ��ǥ
	*/
	void gotoxy(int x, int y);
private:
	RedBlackTree<ArtistType> m_aArray;		///< list array.

};

#endif