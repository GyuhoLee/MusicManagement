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
	*	@brief	RBT안에 노래의 갯수를 반환하는 함수
	*	@return	m_ArtistMusicList의 Length
	*/
	int GetLength();


	/**
	*	@brief 각 가수의 대표곡을 들려준다.
	*	@pre	wav 파일이 Artist 폴더 내에 존재
	*	@post	wav파일 실행
	*/
	void SoundRepresentSong();

	/**
	*	@brief	커서를 x, y로 이동
	*	@post	커서가 (x,y) 로 이동함.
	*	@pram	x	이동할 x 좌표
	*	@pram	y	이동할 y 좌표
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