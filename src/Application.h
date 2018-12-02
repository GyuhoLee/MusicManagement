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
	*	@brief	ó�� ȭ��(�α���, ȸ�� ���� ��)
	*	@pre	���α׷��� ����
	*	@post	Ŀ�ǵ忡 ���� ���� ����
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
	*	@brief	txt���ϸ��� �������� �α����� �ϰ�, �α��� ������ �����͸� ����Ʈ�� �߰�
	*	@pre	none.
	*	@post	����Ʈ�� �����Ͱ� �߰���.
	*	@return	�α��� ������ 1, ���н� 0 ��ȯ
	*/
	int Login();

	/**
	*	@brief	������ ���ϴ� ID�� txt���� ����
	*	@pre	none.
	*	@post	txt���� ����
	*/
	void SignUp();

	/**
	*	@brief	�������� ȭ��
	*	@pre	������ �α���
	*	@post	���α׷� ����
	*/
	void AdminRun();

	/**
	*	@brief	ID(txt����)�� ������
	*	@pre	none
	*	@post	txt���� ����
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
	*	@brief	�˻� ȭ��
	*	@pre	none
	*	@post	Ŀ�ǵ忡 ���� �˻� ����
	*/
	void SearchRun();


	/**
	*	@brief	���� ���� ȭ��
	*	@pre	none
	*	@post	Ŀ�ǵ忡 ���� ���� ����
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
	*	@brief	������ ���ϴ� ���� �Է¹޾� ����
	*	@pre	list�� �ʱ�ȭ
	*	@post	����ڰ� �Է��� ����� ���� ���� ���� list�� ������ ������ ����
	*/
	void ReplaceMusic();

	/**
	*	@brief	����ڰ� ���ϴ� ������ ������ ȭ�鿡 ���
	*/
	void DisplayMusic();

	/**
	*	@brief	������ ���ϴ� ������ ������ ����
	*	@pre	list�� �ʱ�ȭ
	*	@post	����ڰ� �Է��� ����� ���� ���� ���� list�� ������ ������ ����
	*/
	void DeleteMusic();

	/**
	*	@brief	�˻�� ��� ���ԵǾ� �ִ� ������ ������ ȭ�鿡 ���
	*/
	void SearchByName();

	/**
	*	@brief	�˻�� ������ ���ԵǾ� �ִ� ������ ������ ȭ�鿡 ���
	*/
	void SearchByArtist();

	/**
	*	@brief	�˻�� �ٹ��� ���ԵǾ� �ִ� ������ ������ ȭ�鿡 ���
	*/
	void SearchByAlbum();

	/**
	*	@brief	�˻�� �۰��ڿ� ���ԵǾ� �ִ� ������ ������ ȭ�鿡 ���
	*/
	void SearchByComposer();

	/**
	*	@brief	�˻�� �ۻ��ڿ� ���ԵǾ� �ִ� ������ ������ ȭ�鿡 ���
	*/
	void SearchByLyricist();

	/**
	*	@brief	�˻�� �Ҽӻ翡 ���ԵǾ� �ִ� ������ ������ ȭ�鿡 ���
	*/
	void SearchByAgency();

	/**
	*	@brief	�帣���� ������ ȭ�鿡 ���
	*/
	void DisplayMusicByGenre();

	/**
	*	@brief	�������� ������ ȭ�鿡 ���
	*/
	void DisplayMusicByArtist();

	/**
	*	@brief	�ٹ����� ������ ȭ�鿡 ���
	*/
	void DisplayMusicByAlbum();

	/**
	*	@brief	�ֱ� �߰��� ���� ����� ȭ�鿡 ���
	*/
	void DisplayNewMusic();

	/**
	*	@brief	���� �帣�� ��ġ�ϴ� ������ ã�Ƽ� ȭ�鿡 ���
	*/
	void RetrieveByNameNGenre();
	
	/**
	*	@brief	Ŀ���� x, y�� �̵�
	*	@post	Ŀ���� (x,y) �� �̵���.
	*	@pram	x	�̵��� x ��ǥ
	*	@pram	y	�̵��� y ��ǥ
	*/
	void gotoxy(int x, int y);

private:
	ifstream m_InFile;							///< input file descriptor.
	ofstream m_OutFile;							///< output file descriptor.
	string m_UserId;							///< login log
	string m_UserPassword;						///< login log2
	string m_FileName;							///< ���ϸ�
	RecentMusicList<SimpleMusicType> m_rList;	///< add recently music list.
	int m_Command;								///< current command number.
	int m_SearchCommand;						///< current search command number.
	int m_ViewCommand;							///< current view command number..
	int m_LoginCommand;							///< current login command number.
	int m_AdminCommand;							///< current admin command number
};

#endif	// _APPLICATION_H
