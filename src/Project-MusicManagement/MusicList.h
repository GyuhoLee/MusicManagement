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
	*	@brief	음악 제목을 기준으로 데이터를 검색하고 해당 데이터를 가져옴
	*	@pre	list의 초기화
	*	@post	같은 ID값을 가진 변수를 입력 파라미터에 저장
	*	@param	ID가 들어있는 ItemType형 변수를 전달
	*	@return	같은 ID값이 있을시 1을, 없을시 0을 반환
	*/
	int FindType(MusicType data);

	/**
	*	@brief	기존 레코드 삭제
	*	@pre	list의 초기화
	*	@post	같은 ID값을 가진 ItemType을 삭제하고, list의 크기를 줄임.
	*	@param	삭제하고 싶은 ID가 들어있는 ItemType형 변수를 전달
	*	@return	같은 ID값이 있을시 1, 없을시 0을 반환
	*/
	int Delete(MusicType &data);

	/**
	*	@brief	기존 레코드 갱신
	*	@pre	list의 초기화
	*	@post	같은 ID값을 가진 ItemType을 사용자에게 입력받아 갱신
	*	@param	갱신하고 싶은 ID가 들어있는 ItemType형 변수를 전달
	*	@return	같은 ID값이 있을시 1, 없을시 0을 반환
	*/
	int Replace(MusicType &data);

	/**
	*	@brief	sType에 따라서 입력어와 같은 문자열을 지닌 정보 검색 후 출력
	*	@pre	list의 초기화
	*	@post	검색된 정보 출력
	*	@param	sTerm	검색할 문자열
	*	@param	sType	곡명, 가수, 앨범, 장르 중 분야 선택
	*	@return	검색 후 정보가 있을 시 1, 없을 시 0을 반환
	*/
	int Search(string sTerm, SearchType sType);

	/**
	*	@brief	곡명과 장르가 검색한 내용과 일치하는 음악을 출력
	*	@param	inName	검색할 곡명
	*	@param	inGenre	검색할 장르
	*/
	void DisplayRetrieveNameNGenre(string inName, string inGenre);

	/**
	*	@brief	RedBlackTree의 Array를 전달
	*	@pre	m_Array의 초기화
	*	@return	RedBlackTree의 Array
	*/
	RedBlackTree<MusicType> GetArray();


private:
	RedBlackTree<MusicType> m_Array;  ///< list array.
};


#endif