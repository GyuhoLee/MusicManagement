#pragma once
#ifndef _GENRETYPE_H
#define _GENRETYPE_H


#include "SimpleMusicType.h"
#include "RedBlackTree.h"
#include "MusicType.h"
#include "Base.h"
class GenreList;
/**
*	@class	GenreType
*	@author	Gyuho Lee
*	@brief	Manages a genre type and music list which belongs to the genre.
*/
class GenreType : public Base
{
public:
	/**
	*	default constructor.
	*/
	GenreType()
	{
		m_GenreId = -1;
		m_Genre = "";
	}

	/**
	*	destructor.
	*/
	~GenreType() {}

	/**
	*	@brief	set genre id.
	*	@param[in]	inGenreId	genre id.
	*/
	void SetId(int inGenreId)
	{
		m_GenreId = inGenreId;
	}

	/**
	*	@brief	get genre id.
	*	@return	genre id.
	*/
	int GetId()
	{
		return m_GenreId;
	}

	/**
	*	@brief	set genre name.
	*	@param[in]	inGenre	genre name.
	*/
	void SetGenreName(string inGenre)
	{
		m_Genre = inGenre;
	}

	/**
	*	@brief	get genre name.
	*	@return	genre name.
	*/
	string GetGenreName()
	{
		return m_Genre;
	}

	/**
	*	@brief	set genre information.
	*	@param[in]	inGenre	genre name.
	*/
	void SetInfo(string inGenre);


	/**
	*	@brief	display genre information on screen.
	*/
	void DisplayRecordOnScreen();

	/**
	*	@brief	add a music information into this genre.
	*	@param[in]	indata	music information.
	*/
	void AddMusicInGenre(SimpleMusicType inData);

	/**
	*	@brief	delete a music information from this genre.
	*	@param[in]	indata	music information.
	*/
	void DeleteMusicInGenre(SimpleMusicType inData);

	/**
	*	@brief	replace a music information from this genre.
	*	@param[in]	indata	music information.
	*/
	void ReplaceMusicInGenre(SimpleMusicType inData);

	/**
	*	@brief	Display Genre Name and ID.
	*	@param[in]	list	music list.
	*/
	void DisplayMusicDetailInGenre(RedBlackTree<MusicType> *list);

	/**
	*	@brief	Display all music genren in this genre.
	*/
	void DisplayAllMusicInGenre();

	/**
	*	@brief	RBT�ȿ� �뷡�� ������ ��ȯ�ϴ� �Լ�
	*	@return	m_GenreMusicList�� Length
	*/
	int GetLength();

	/**
	*	@brief	Ŀ���� x, y�� �̵�
	*	@post	Ŀ���� (x,y) �� �̵���.
	*	@pram	x	�̵��� x ��ǥ
	*	@pram	y	�̵��� y ��ǥ
	*/
	void gotoxy(int x, int y);

	// complete operation overloadings...
	bool operator== (GenreType obj);
	bool operator> (GenreType obj);
	bool operator< (GenreType obj);
	bool operator>= (GenreType obj);
	bool operator<= (GenreType obj);

protected:
	int m_GenreId;	///< Primary key
	string m_Genre;
	RedBlackTree<SimpleMusicType> m_GenreMusicList;
};

#endif // !_GENRE_TYPE_H