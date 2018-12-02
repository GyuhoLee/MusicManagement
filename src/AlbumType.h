#pragma once
#ifndef _ALBUMTYPE_H
#define _ALBUMTYPE_H


#include "SimpleMusicType.h"
#include "DoublySortedLinkedList.h"
#include "MusicType.h"
#include "Base.h"
#include <iomanip>
#include <stdio.h>
#include <Windows.h>
#include <gdiplus.h>

#pragma comment(lib, "gdiplus.lib")


/**
*	@class	AlbumType
*	@author	Gyuho Lee
*	@brief	Manages a album type and music list which belongs to the album.
*/
class AlbumType : public Base
{
public:
	/**
	*	default constructor.
	*/
	AlbumType()
	{
		m_Album = "";
		m_Artist = "";
		m_Agency = "";
	}

	/**
	*	destructor.
	*/
	~AlbumType() {}

	/**
	*	@brief	set album artist.
	*	@param[in]	inArtist	album artist.
	*/
	void SetArtist(string inArtist)
	{
		m_Artist = inArtist;
	}

	/**
	*	@brief	get album artist.
	*	@return	album artist.
	*/
	string GetArtist()
	{
		return m_Artist;
	}

	/**
	*	@brief	set album name.
	*	@param[in]	inAlbum	album name.
	*/
	void SetAlbumName(string inAlbum)
	{
		m_Album = inAlbum;
	}

	/**
	*	@brief	get album name.
	*	@return	album name.
	*/
	string GetAlbumName()
	{
		return m_Album;
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
	*	@brief	set album information.
	*	@param[in]	inAlbum		album name.
	*	@param[in]	inArtist	album artist.
	*	@param[in]	inAgency	agency of artist.
	*/
	void SetInfo(string inAlbum, string inArtist, string inAgency);


	/**
	*	@brief	display album information on screen.
	*/
	void DisplayAllMusicInAlbum();

	/**
	*	@brief	display album name and artist.
	*/
	void DisplayRecordOnScreen();

	/**
	*	@brief	add a music information into this album.
	*	@param[in]	indata	music information.
	*/
	void AddMusicInAlbum(SimpleMusicType inData);

	/**
	*	@brief	delete a music information from this album.
	*	@param[in]	indata	music information.
	*/
	void DeleteMusicInAlbum(SimpleMusicType inData);

	/**
	*	@brief	replace a music information from this album.
	*	@param[in]	indata	music information.
	*/
	void ReplaceMusicInAlbum(SimpleMusicType inData);

	/**
	*	@brief	Displap all music information in this album.
	*	@param[in]	list	music list.
	*/
	void DisplayMusicDetailInAlbum(DoublySortedLinkedList<MusicType> *list);

	/**
	*	@brief	Doubly안에 노래의 갯수를 반환하는 함수
	*	@return	m_AlbumMusicList의 Length
	*/
	int GetLength();

	/**
	*	@brief	jpg파일을 읽어서 콘솔에 출력하는 함수(GDI+ 기반)
	*/

	void DisplayAlbumCover();

	/**
	*	@brief	커서를 x, y로 이동
	*	@post	커서가 (x,y) 로 이동함.
	*	@pram	x	이동할 x 좌표
	*	@pram	y	이동할 y 좌표
	*/
	void gotoxy(int x, int y);



	// complete operation overloadings...
	bool operator== (AlbumType obj);
	bool operator!= (AlbumType obj);
	bool operator> (AlbumType obj);
	bool operator< (AlbumType obj);
	bool operator>= (AlbumType obj);
	bool operator<= (AlbumType obj);

protected:
	string m_Album;
	string m_Artist;
	string m_Agency;
	DoublySortedLinkedList<SimpleMusicType> m_AlbumMusicList;
};


#endif // _ALBUMTYPE_H