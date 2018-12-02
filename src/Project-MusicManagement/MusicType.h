#pragma once
#ifndef _MUSICTYPE_H
#define _MUSICTYPE_H

#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <mmsystem.h>
#include <ctime>
#include <conio.h>
#include <atlstr.h>
#pragma comment(lib, "winmm.lib")

using namespace std;


/**
*	@brief Relation between two items.
*/
enum RelationType { LESS, GREATER, EQUAL };


/**
*	@brief music information class.
*/
class MusicType
{
public:
	/**
	*	default constructor.
	*/
	MusicType()
	{
		m_Number = -1;
		m_Name = "";
		m_Artist = "";
		m_Album = "";
		m_Genre = "";
		m_Lyrics = "";
		m_Composer = "";
		m_Lyricist = "";
		m_Agency = "";
		m_ReleaseDate = "";
		m_PlayTime = 0;
	}

	/**
	*	destructor.
	*/
	~MusicType() {}

	/**
	*	@brief	Get music number.
	*	@pre	music number is set.
	*	@post	none.
	*	@return music number.
	*/
	int GetNumber()
	{
		return m_Number;
	}

	/**
	*	@brief	Get music name.
	*	@pre	music name is set.
	*	@post	none.
	*	@return music name.
	*/
	string GetName()
	{
		return m_Name;
	}

	/**
	*	@brief	Get music artist.
	*	@pre	music artist is set.
	*	@post	none.
	*	@return	music artist.
	*/
	string GetArtist()
	{
		return m_Artist;
	}

	/**
	*	@brief	Get music album
	*	@pre	music album is set.
	*	@post	none.
	*	@return	music album.
	*/
	string GetAlbum()
	{
		return m_Album;
	}

	/**
	*	@brief	Get music genre
	*	@pre	music genre is set.
	*	@post	none.
	*	@return	music genre.
	*/
	string GetGenre()
	{
		return m_Genre;
	}

	/**
	*	@brief	Get music lyrics
	*	@pre	music lyrics is set.
	*	@post	none.
	*	@return	music lyrics.
	*/
	string GetLyrics()
	{
		return m_Lyrics;
	}

	/**
	*	@brief	Get music composer
	*	@pre	music composer is set.
	*	@post	none.
	*	@return	music composer.
	*/
	string GetComposer()
	{
		return m_Composer;
	}

	/**
	*	@brief	Get music lyricist
	*	@pre	music lyricist is set.
	*	@post	none.
	*	@return	music lyricist.
	*/
	string GetLyricist()
	{
		return m_Lyricist;
	}

	/**
	*	@brief	Get music agency
	*	@pre	music agency is set.
	*	@post	none.
	*	@return	music agency.
	*/
	string GetAgency()
	{
		return m_Agency;
	}

	/**
	*	@brief	Get music release date
	*	@pre	music release date is set.
	*	@post	none.
	*	@return	music release date.
	*/
	string GetReleaseDate()
	{
		return m_ReleaseDate;
	}

	/**
	*	@brief	Get music time
	*	@pre	music time is set.
	*	@post	none.
	*	@return	music time.
	*/
	int GetPlayTime()
	{
		return m_PlayTime;
	}

	/**
	*	@brief	Set music number.
	*	@pre	none.
	*	@post	music number is set.
	*	@param	inNumber	music number.
	*/
	void SetNumber(int inNumber)
	{
		m_Number = inNumber;
	}

	/**
	*	@brief	Set music Name.
	*	@pre	none.
	*	@post	music name is set.
	*	@param	inName	music name.
	*/
	void SetName(string inName)
	{
		m_Name = inName;
	}

	/**
	*	@brief	Set music artist.
	*	@pre	none.
	*	@post	music artist is set.
	*	@param	inArtist	music artist.
	*/
	void SetArtist(string inArtist)
	{
		m_Artist = inArtist;
	}

	/**
	*	@brief	Set music album.
	*	@pre	none.
	*	@post	music album is set.
	*	@param	inAlbum	music album.
	*/
	void SetAlbum(string inAlbum)
	{
		m_Album = inAlbum;
	}

	/**
	*	@brief	Set music genre.
	*	@pre	none.
	*	@post	music genre is set.
	*	@param	inGenre	music genre.
	*/
	void SetGenre(string inGenre)
	{
		m_Genre = inGenre;
	}

	/**
	*	@brief	Set music lyrics.
	*	@pre	none.
	*	@post	music lyrics is set.
	*	@param	inLyrics	music lyrics.
	*/
	void SetLyrics(string inLyrics)
	{
		m_Lyrics = inLyrics;
	}

	/**
	*	@brief	Set music composer.
	*	@pre	none.
	*	@post	music composer is set.
	*	@param	inComposer	music composer.
	*/
	void SetComposer(string inComposer)
	{
		m_Composer = inComposer;
	}

	/**
	*	@brief	Set music lyricist.
	*	@pre	none.
	*	@post	music lyricist is set.
	*	@param	inLyricist	music lyricist.
	*/
	void SetLyricist(string inLyricist)
	{
		m_Lyricist = inLyricist;
	}

	/**
	*	@brief	Set music agency.
	*	@pre	none.
	*	@post	music agency is set.
	*	@param	inAgency	music agency.
	*/
	void SetAgency(string inAgency)
	{
		m_Agency = inAgency;
	}

	/**
	*	@brief	Set music release date.
	*	@pre	none.
	*	@post	music release date is set.
	*	@param	inReleaseDate	music release date.
	*/
	void SetReleaseDate(string inReleaseDate)
	{
		m_ReleaseDate = inReleaseDate;
	}

	/**
	*	@brief	Set music time.
	*	@pre	none.
	*	@post	music time is set.
	*	@param	inPlayTime	music time.
	*/
	void SetPlayTime(int inPlayTime)
	{
		m_PlayTime = inPlayTime;
	}

	/**
	*	@brief	Set music record.
	*	@pre	none.
	*	@post	music record is set.
	*	@param	inNumber	music number.
	*	@param	inName		music name.
	*	@param	inArtist	music artist.
	*	@param	inAlbum		music album.
	*	@param  inGenre		music genre.
	*	@param	inLyrics	music lyrics.
	*/
	void SetRecord(int inNumber, string inName, string inArtist, string inComposer, string inLyricist, string inAlbum, string inAgency, string inReleaseDate, string inGenre, string inLyrics)
	{
		SetNumber(inNumber);
		SetName(inName);
		SetArtist(inArtist);
		SetComposer(inComposer);
		SetLyricist(inLyricist);
		SetAlbum(inAlbum);
		SetAgency(inAgency);
		SetReleaseDate(inReleaseDate);
		SetGenre(inGenre);
		SetLyrics(inLyrics);
	}

	/**
	*	@brief	Display music number on screen.
	*	@pre	music number is set.
	*	@post	music number is on screen.
	*/
	void DisplayNumberOnScreen()
	{
		cout << "\t��ȣ   : " << m_Number << endl;
	};

	/**
	*	@brief	Display music name on screen.
	*	@pre	music name is set.
	*	@post	music name is on screen.
	*/
	void DisplayNameOnScreen()
	{
		cout << "\t���   : " << m_Name << endl;
	};

	/**
	*	@brief	Display music artist on screen.
	*	@pre	music artist is set.
	*	@post	music artist is on screen.
	*/
	void DisplayArtistOnScreen()
	{
		cout << "\t���� : " << m_Artist << endl;
	};

	/**
	*	@brief	Display music composer on screen.
	*	@pre	music composer is set.
	*	@post	music composer is on screen.
	*/
	void DisplayComposerOnScreen()
	{
		cout << "\t�۰��� : " << m_Composer << endl;
	};

	/**
	*	@brief	Display music lyricist on screen.
	*	@pre	music lyricist is set.
	*	@post	music lyricist is on screen.
	*/
	void DisplayLyricistOnScreen()
	{
		cout << "\t�ۻ��� : " << m_Lyricist << endl;
	};

	/**
	*	@brief	Display music album on screen.
	*	@pre	music album is set.
	*	@post	music album is on screen.
	*/
	void DisplayAlbumOnScreen()
	{
		cout << "\t�ٹ� : " << m_Album << endl;
	};

	/**
	*	@brief	Display artist agency on screen.
	*	@pre	artist agency is set.
	*	@post	artist agency is on screen.
	*/
	void DisplayAgencyOnScreen()
	{
		cout << "\t�Ҽӻ� : " << m_Agency << endl;
	};

	/**
	*	@brief	Display music release date on screen.
	*	@pre	music release date is set.
	*	@post	music release date is on screen.
	*/
	void DisplayReleaseDateOnScreen()
	{
		if (m_ReleaseDate.length() == 8)
		{
			cout << "\t�߸��� : ";
			for (int i = 0; i < 4; i++) cout << m_ReleaseDate.at(i);
			cout << "�� ";
			if (m_ReleaseDate.at(4) != '0') cout << m_ReleaseDate.at(4);
			cout << m_ReleaseDate.at(5) << "�� ";
			if (m_ReleaseDate.at(6) != '0') cout << m_ReleaseDate.at(6);
			cout << m_ReleaseDate.at(7) << "��" << endl;
		}
		else
		{
			cout << "\t�߸��� : " << m_ReleaseDate << endl;
		}
	};

	/**
	*	@brief	Display music genre on screen.
	*	@pre	music genre is set.
	*	@post	music genre is on screen.
	*/
	void DisplayGenreOnScreen()
	{
		cout << "\t�帣 : " << m_Genre << endl;
	};

	/**
	*	@brief	Display music lyrics on screen.
	*	@pre	music lyrics is set.
	*	@post	music lyrics is on screen.
	*/
	void DisplayLyricsOnScreen()
	{
		cout << "\t���� : " << m_Lyrics << endl;
	};

	/**
	*	@brief	Display an music record on screen.
	*	@pre	music record is set.
	*	@post	music record is on screen.
	*/
	void DisplayRecordOnScreen()
	{
		DisplayNameOnScreen();
		DisplayArtistOnScreen();
		DisplayComposerOnScreen();
		DisplayLyricistOnScreen();
		DisplayAlbumOnScreen();
		DisplayAgencyOnScreen();
		DisplayGenreOnScreen();
		DisplayReleaseDateOnScreen();
		DisplayLyricsOnScreen();
		cout << endl;
	};

	/**
	*	@brief	Set music number from keyboard.
	*	@pre	none.
	*	@post	music number is set.
	*/
	void SetNumberFromKB();

	/**
	*	@brief	Set music name from keyboard.
	*	@pre	none.
	*	@post	music name is set.
	*/
	void SetNameFromKB();

	/**
	*	@brief	Set music artist from keyboard.
	*	@pre	none.
	*	@post	music artist is set.
	*/
	void SetArtistFromKB();

	/**
	*	@brief	Set music composer from keyboard.
	*	@pre	none.
	*	@post	music composer is set.
	*/
	void SetComposerFromKB();

	/**
	*	@brief	Set music lyricist from keyboard.
	*	@pre	none.
	*	@post	music lyricist is set.
	*/
	void SetLyricistFromKB();

	/**
	*	@brief	Set music album from keyboard.
	*	@pre	none.
	*	@post	music album is set.
	*/
	void SetAlbumFromKB();

	/**
	*	@brief	Set artist agency from keyboard.
	*	@pre	none.
	*	@post	artist agency is set.
	*/
	void SetAgencyFromKB();

	/**
	*	@brief	Set music release date from keyboard.
	*	@pre	none.
	*	@post	music release date is set.
	*/
	void SetReleaseDateFromKB();

	/**
	*	@brief	Set music genre from keyboard.
	*	@pre	none.
	*	@post	music genre is set.
	*/
	void SetGenreFromKB();

	/**
	*	@brief	Set music lyrics from keyboard.
	*	@pre	none.
	*	@post	music lyrics is set.
	*/
	void SetLyricsFromKB();

	/**
	*	@brief	Set music record from keyboard.
	*	@pre	none.
	*	@post	music record is set.
	*/
	void SetRecordFromKB();

	/**
	*	@brief	Read a record from file.
	*	@pre	the target file is opened.
	*	@post	music record is set.
	*	@param	fin	file descriptor.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int ReadDataFromFile(ifstream& fin);

	/**
	*	@brief	Write a record into file.
	*	@pre	the target file is opened. And the list should be initialized.
	*	@post	the target file is included the new music record.
	*	@param	fout	file descriptor.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int WriteDataToFile(ofstream& fout);

	/**
	*	Compare two itemtypes.
	*	@brief	Compare two item types by item id.
	*	@pre	two item types should be initialized.
	*	@post	the target file is included the new item record.
	*	@param	data	target item for comparing.
	*	@return	return LESS if this.id < data.id,
	*			return GREATER if this.id > data.id then,
	*			otherwise return EQUAL.
	*/
	RelationType CompareByID(const MusicType &data);

	/**
	*	@brief	�Է��� MusicType�� Ŭ������ ��� �������� ����
	*	@pre	none.
	*	@post	this�� param�� �����͸� ����
	*	@param	�����ϰ� ���� Data
	*/
	void CopyRecord(MusicType data);

	/**
	*	@brief �� ������ ��ǥ���� ����ش�.
	*	@pre	wav ������ Music ���� ���� ����
	*	@post	wav���� ����
	*/
	bool SoundSong();

	/**
	*	@brief	Ŀ���� x, y�� �̵�
	*	@post	Ŀ���� (x,y) �� �̵���.
	*	@pram	x	�̵��� x ��ǥ
	*	@pram	y	�̵��� y ��ǥ
	*	@return	�뷡�� ������ true ������ false
	*/
	void gotoxy(float x, int y);

	// complete operation overloadings...
	void operator=(const MusicType &obj);
	bool operator==(MusicType obj);
	bool operator!=(MusicType obj);
	bool operator<(MusicType obj);
	bool operator>(MusicType obj);
	bool operator<=(MusicType obj);
	bool operator>=(MusicType obj);

protected:
	int m_Number;			///< primary key.
	string m_Name;			///< ���
	string m_Artist;		///< ����
	string m_Album;			///< �ٹ�
	string m_Genre;			///< �帣
	string m_Lyrics;		///< ����
	string m_Composer;		///< �۰
	string m_Lyricist;		///< �ۻ簡
	string m_Agency;		///< �Ҽӻ�
	string m_ReleaseDate;	///< �߸���
	int m_PlayTime;			///< ������ �ð�
};

#endif	// _MUSICTYPE_H
