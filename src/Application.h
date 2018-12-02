#pragma once
#ifndef _APPLICATION_H
#define _APPLICATION_H

using namespace std;

#include "Base.h"
#include "MusicList.h"
#include "GenreList.h"
#include "ArtistList.h"
#include "AlbumList.h"
#include "RecentMusicList.h"
#pragma warning(disable:4996)

#define FILENAMESIZE 1024
#define UP 72
#define DOWN 80
#define ENTER 13

/**
*	@brief	application class for music management simply.
*/
class Application : public Base
{
public:
	/**
	*	default constructor.
	*/
	Application()
	{
		m_Command = 0;
		m_SearchCommand = 0;
		m_ViewCommand = 0;
		m_LoginCommand = 0;
		m_UserId = "";
		m_FileName = "";
	}

	/**
	*	destructor.
	*/
	~Application()
	{

	}

	/**
	*	@brief	처음 화면(로그인, 회원 가입 등)
	*	@pre	프로그램의 시작
	*	@post	커맨드에 따른 동작 실행
	*/
	void FirstRun();

	/**
	*	@brief	Display login command on screen and get a input from keyboard.
	*	@pre	none.
	*	@post	none.
	*	@return	user's login command.
	*/
	int GetLoginCommand();

	/**
	*	@brief	txt파일명을 기준으로 로그인을 하고, 로그인 성공시 데이터를 리스트에 추가
	*	@pre	none.
	*	@post	리스트에 데이터가 추가됨.
	*	@return	로그인 성공시 1, 실패시 0 반환
	*/
	int Login();

	/**
	*	@brief	유저가 원하는 ID의 txt파일 생성
	*	@pre	none.
	*	@post	txt파일 생성
	*/
	void SignUp();

	/**
	*	@brief	관리자의 화면
	*	@pre	관리자 로그인
	*	@post	프로그램 종료
	*/
	void AdminRun();

	/**
	*	@brief	ID(txt파일)을 삭제함
	*	@pre	none
	*	@post	txt파일 삭제
	*/
	void DeleteUserId();

	/**
	*	@brief	Display admin command on screen and get a input from keyboard.
	*	@pre	none.
	*	@post	none.
	*	@return	user's admin command.
	*/
	int GetAdminCommand();

	/**
	*	@brief	검색 화면
	*	@pre	none
	*	@post	커맨드에 따른 검색 실행
	*/
	void SearchRun();


	/**
	*	@brief	음악 보기 화면
	*	@pre	none
	*	@post	커맨드에 따른 음악 보기
	*/
	void ViewRun();

	/**
	*	@brief	Program driver.
	*	@pre	program is started.
	*	@post	program is finished.
	*/
	void Run();

	/**
	*	@brief	Display command on screen and get a input from keyboard.
	*	@pre	none.
	*	@post	none.
	*	@return	user's command.
	*/
	int GetCommand();

	/**
	*	@brief	Display search command on screen and get a input from keyboard.
	*	@pre	none.
	*	@post	none.
	*	@return	user's search command.
	*/
	int GetSearchCommand();

	/**
	*	@brief	Display view command on screen and get a input from keyboard.
	*	@pre	none.
	*	@post	none.
	*	@return	user's view command.
	*/
	int GetViewCommand();

	/**
	*	@brief	Add new record into list.
	*	@pre	list should be initialized.
	*	@post	new record is added into the list.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int AddMusic();

	/**
	*	@brief	Display all records in the list on screen.
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayAllMusic();

	/**
	*	@brief	Open a file by file descriptor as an input file.
	*	@pre	a file for reading is exist.
	*	@post	open the file for reading.
	*	@param	fileName	a filename to open for reading.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int OpenInFile(string fileName);

	/**
	*	@brief	Open a file by file descriptor as an output file.
	*	@pre	list should be initialized.
	*	@post	open the file for writing.
	*	@param	fileName	a filename to open for writing.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int OpenOutFile(string fileName);

	/**
	*	@brief	Open a file as a read mode, read all data on the file, and set list by the data.
	*	@pre	The file is not opened.
	*	@post	list holds all records from the file.
	*	@param	file name
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int ReadDataFromFile(string filename);

	/**
	*	@brief	Open a file as a write mode, and write all data into the file,
	*	@pre	The file is not opened.
	*	@post	the list is stored in the output file.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int WriteDataToFile();

	/**
	*	@brief	갱신을 원하는 음악 입력받아 갱신
	*	@pre	list의 초기화
	*	@post	사용자가 입력한 제목과 같은 값을 가진 list내 음악의 정보를 갱신
	*/
	void ReplaceMusic();

	/**
	*	@brief	사용자가 원하는 음악의 정보를 화면에 출력
	*/
	void DisplayMusic();

	/**
	*	@brief	유저가 원하는 음악의 정보를 삭제
	*	@pre	list의 초기화
	*	@post	사용자가 입력한 제목과 같은 값을 가진 list내 음악의 정보를 삭제
	*/
	void DeleteMusic();

	/**
	*	@brief	검색어가 곡명에 포함되어 있는 음악의 정보를 화면에 출력
	*/
	void SearchByName();

	/**
	*	@brief	검색어가 가수에 포함되어 있는 음악의 정보를 화면에 출력
	*/
	void SearchByArtist();

	/**
	*	@brief	검색어가 앨범에 포함되어 있는 음악의 정보를 화면에 출력
	*/
	void SearchByAlbum();

	/**
	*	@brief	검색어가 작곡자에 포함되어 있는 음악의 정보를 화면에 출력
	*/
	void SearchByComposer();

	/**
	*	@brief	검색어가 작사자에 포함되어 있는 음악의 정보를 화면에 출력
	*/
	void SearchByLyricist();

	/**
	*	@brief	검색어가 소속사에 포함되어 있는 음악의 정보를 화면에 출력
	*/
	void SearchByAgency();

	/**
	*	@brief	장르별로 음악을 화면에 출력
	*/
	void DisplayMusicByGenre();

	/**
	*	@brief	가수별로 음악을 화면에 출력
	*/
	void DisplayMusicByArtist();

	/**
	*	@brief	앨범별로 음악을 화면에 출력
	*/
	void DisplayMusicByAlbum();

	/**
	*	@brief	최근 추가한 음악 목록을 화면에 출력
	*/
	void DisplayNewMusic();

	/**
	*	@brief	곡명과 장르가 일치하는 음악을 찾아서 화면에 출력
	*/
	void RetrieveByNameNGenre();
	
	/**
	*	@brief	커서를 x, y로 이동
	*	@post	커서가 (x,y) 로 이동함.
	*	@pram	x	이동할 x 좌표
	*	@pram	y	이동할 y 좌표
	*/
	void gotoxy(int x, int y);

private:
	ifstream m_InFile;							///< input file descriptor.
	ofstream m_OutFile;							///< output file descriptor.
	string m_UserId;							///< login log
	string m_UserPassword;						///< login log2
	string m_FileName;							///< 파일명
	RecentMusicList<SimpleMusicType> m_rList;	///< add recently music list.
	int m_Command;								///< current command number.
	int m_SearchCommand;						///< current search command number.
	int m_ViewCommand;							///< current view command number..
	int m_LoginCommand;							///< current login command number.
	int m_AdminCommand;							///< current admin command number
};

#endif	// _APPLICATION_H
