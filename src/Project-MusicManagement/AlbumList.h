#pragma once
#ifndef _ALBUMLIST_H
#define _ALBUMLIST_H
#include "AlbumType.h"
#include "RedBlackTree.h"

/**
*	@brief	album array based single linked list.
*/
class AlbumList
{
public:
	/**
	*	default constructor.
	*/
	AlbumList()
	{
	}

	/**
	*	destructor.
	*/
	~AlbumList()
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
	*	@brief	리스트가 비어있는지 확인
	*	@pre	none.
	*	@post	none.
	*	@return	비어있으면 1 , 그렇지 않으면 0을 반환
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
	*	@brief	음악 제목을 기준으로 데이터를 검색하고 해당 데이터를 가져옴
	*	@pre	list의 초기화
	*	@post	같은 ID값을 가진 변수를 입력 파라미터에 저장
	*	@param	ID가 들어있는 ItemType형 변수를 전달
	*	@return	같은 ID값이 있을시 1을, 없을시 0을 반환
	*/
	int Get(MusicType& data);

	/**
	*	@brief	기존 레코드 삭제
	*	@pre	list의 초기화
	*	@post	같은 ID값을 가진 ItemType을 삭제하고, list의 크기를 줄임.
	*	@param	삭제하고 싶은 ID가 들어있는 ItemType형 변수를 전달
	*	@return	같은 ID값이 있을시 1, 없을시 0을 반환
	*/
	int Delete(MusicType &inData);

	/**
	*	@brief	기존 레코드 갱신
	*	@pre	list의 초기화
	*	@post	같은 ID값을 가진 ItemType을 사용자에게 입력받아 갱신
	*	@param	갱신하고 싶은 ID가 들어있는 ItemType형 변수를 전달
	*	@return	같은 ID값이 있을시 1, 없을시 0을 반환
	*/
	int Replace(MusicType &inData);

	/**
	*	@brief	저장된 모든 앨범과 그 앨범 속에 있는 음악들을 화면에 출력
	*	@pre	list의 초기화
	*/
	void DisplayAlbumAll();

	/**
	*	@brief	커서를 x, y로 이동
	*	@post	커서가 (x,y) 로 이동함.
	*	@pram	x	이동할 x 좌표
	*	@pram	y	이동할 y 좌표
	*/
	void gotoxy(int x, int y);

private:
	RedBlackTree<AlbumType> m_aArray;		///< list array.

};

#endif