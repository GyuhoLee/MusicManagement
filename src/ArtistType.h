#pragma once
#ifndef _ARTISTTYPE_H
#define _ARTISTTYPE_H


#include "SimpleMusicType.h"
#include "RedBlackTree.h"
#include "Base.h"
#include "MusicType.h"
#include <iomanip>


/**
*	@class	ArtistType
*	@author	Gyuho Lee
*	@brief	Manages a artist type and music list which belongs to the artist.
*/
class ArtistType : public Base
{
public:
	/**
	*	default constructor.
	*/
	ArtistType()
	{
		m_Artist = "";
		m_Agency = "";
	}

	/**
	*	destructor.
	*/
	~ArtistType() {}


	/**
	*	@brief	set artist name.
	*	@param[in]	inArtist	artist name.
	*/
	void SetArtistName(string inArtist)
	{
		m_Artist = inArtist;
	}

	/**
	*	@brief	get artist name.
	*	@return	artist name.
	*/
	string GetArtistName()
	{
		return m_Artist;
	}

	/**
	*	@brief	set agency.
	*	@param[in]	inAgency	agency.
	*/
	void SetAgency(string inAgency)
	{
		m_Agency = inAgency;
	}

	/**
	*	@brief	get agency.
	*	@return	agency.
	*/
	string GetAgency()
	{
		return m_Agency;
	}

	/**
	*	@brief	set artist information.
	*	@param[in]	inArtist	artist name.
	*	@param[in]	inAgency	agency of artist.
	*/
	void SetInfo(string inArtist, string inAgency);


	/**
	*	@brief	display artist information on screen.
	*/

	void DisplayAllMusicInArtist();

	/**
	*	@brief	display artist and agency
	*/
	void DisplayRecordOnScreen();


	/**
	*	@brief	add a music information into this artist.
	*	@param[in]	indata	music information.
	*/
	void AddMusicInArtist(SimpleMusicType inData);

	/**
	*	@brief	delete a music information from this artist.
	*	@param[in]	indata	music information.
	*/
	void DeleteMusicInArtist(SimpleMusicType inData);

	/**
	*	@brief	replace a music information from this artist.
	*	@param[in]	indata	music information.
	*/
	void ReplaceMusicInArtist(SimpleMusicType inData);

	/**
	*	@brief	Displap all music information in this artist.
	*	@param[in]	list	music list.
	*/
	void DisplayMusicDetailInArtist(RedBlackTree<MusicType> *list);

	/**
	*	@brief	RBT�ȿ� �뷡�� ������ ��ȯ�ϴ� �Լ�
	*	@return	m_ArtistMusicList�� Length
	*/
	int GetLength();


	/**
	*	@brief �� ������ ��ǥ���� ����ش�.
	*	@pre	wav ������ Artist ���� ���� ����
	*	@post	wav���� ����
	*/
	void SoundRepresentSong();

	/**
	*	@brief	Ŀ���� x, y�� �̵�
	*	@post	Ŀ���� (x,y) �� �̵���.
	*	@pram	x	�̵��� x ��ǥ
	*	@pram	y	�̵��� y ��ǥ
	*/
	void gotoxy(int x, int y);



	// complete operation overloadings...
	bool operator== (ArtistType obj);
	bool operator!= (ArtistType obj);
	bool operator> (ArtistType obj);
	bool operator< (ArtistType obj);
	bool operator>= (ArtistType obj);
	bool operator<= (ArtistType obj);

protected:
	string m_Artist;
	string m_Agency;
	RedBlackTree<SimpleMusicType> m_ArtistMusicList;
};


#endif // _ARTISTTYPE