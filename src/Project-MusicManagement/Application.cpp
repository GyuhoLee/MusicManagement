#include "Application.h"


void Application::FirstRun()
{
	m_LoginCommand = GetLoginCommand();
	system("cls");
	switch (m_LoginCommand)
	{
	case 1:
		switch (Login())
		{
		case 0:
			FirstRun();
			break;
		case 1:
			Run();
			break;
		case 2:
			AdminRun();
			break;
		}
		break;
	case 2:
		SignUp();
		FirstRun();
		break;
	default:
		break;

	}
}

int Application::GetLoginCommand()
{
	int command = 1;
	cout << "\n\n\t---- Command ----- " << endl;
	cout << "\t     로그인" << endl;
	cout << "\t     회원가입" << endl;
	cout << "\t     사용 종료" << endl;
	cout << "\n\t< Choose and Enter > ";
	int x = 9, y = 4;
	int key = 0;
	while (key != ENTER)
	{
		gotoxy(x, y);
		cout << "->";
		key = _getch();
		switch (key)
		{
		case UP:
			if (command != 1)
			{
				gotoxy(x, y);
				cout << "  ";
				command--;
				y--;
			}
			break;
		case DOWN:
			if (command != 3)
			{
				gotoxy(x, y);
				cout << "  ";
				command++;
				y++;
			}
			break;
		}
	}
	cout << endl;

	return command;
}

int Application::Login()
{
	string IdTemp;
	string PasswordTemp;
	cout << "\n\n\t=====Login Menu=====" << endl;
	cout << "\t   ID : ";
	cin >> IdTemp;
	string FileNameTemp = "User\\";
	FileNameTemp.append(IdTemp);
	FileNameTemp.append(".txt");
	cout << "\t   PassWord : ";
	cin >> PasswordTemp;
	if (IdTemp == "admin")
	{
		if (PasswordTemp == "admin")
		{
			return 2;
		}
		else
		{
			cout << "\t 비밀번호가 틀렸습니다." << endl << endl;
			cout << "\t";
			system("pause");
			system("cls");
			return 0;
		}
	}
	int isOpen = OpenInFile(FileNameTemp);
	if (!isOpen)
	{
		cout << "\t 존재하지 않는 ID입니다." << endl << endl;
		cout << "\t";
		system("pause");
		system("cls");
		m_InFile.close();
		return 0;
	}
	string PassWord;
	m_InFile >> PassWord;
	if (PasswordTemp.compare(PassWord) == 0)
	{
		ReadDataFromFile(FileNameTemp);
		m_UserId = IdTemp;
		m_UserPassword = PasswordTemp;
		m_FileName = FileNameTemp;
		system("cls");
		return 1;
	}
	else
	{
		cout << "\t 비밀번호가 틀렸습니다." << endl << endl;
		cout << "\t";
		system("pause");
		system("cls");
		m_InFile.close();
		return 0;
	}
}

void Application::SignUp()
{
	cout << "\n\n\t=====회원가입=====" << endl;
	cout << "\t   ID : ";
	cin >> m_UserId;
	cout << "\t   PassWord : ";
	cin >> m_UserPassword;
	m_FileName = "User\\";
	m_FileName.append(m_UserId);
	m_FileName.append(".txt");
	OpenOutFile(m_FileName);
	m_OutFile << m_UserPassword;
	m_OutFile.close();
	cout << endl << "\t 회원가입이 완료되었습니다." << endl << endl;
	cout << "\t";
	system("pause");
	system("cls");

}

void Application::AdminRun()
{
	while (1)
	{
		m_AdminCommand = GetAdminCommand();
		system("cls");
		switch (m_AdminCommand)
		{
		case 1:
			DeleteUserId();
			break;
		case 2:
			return;
		default:
			return;
		}
	}
}

int Application::GetAdminCommand()
{
	int command = 1;
	system("cls");
	cout << "\n\n\t----- Command ----- " << endl;
	cout << "\t     ID 삭제하기" << endl;
	//cout << "\t   2  : 유저 정보 보기" << endl;
	cout << "\t     사용 종료" << endl;
	cout << "\n\t< Choose and Enter > ";
	int x = 9, y = 4;
	int key = 0;
	while (key != ENTER)
	{
		gotoxy(x, y);
		cout << "->";
		key = _getch();
		switch (key)
		{
		case UP:
			if (command != 1)
			{
				gotoxy(x, y);
				cout << "  ";
				command--;
				y--;
			}
			break;
		case DOWN:
			if (command != 2)
			{
				gotoxy(x, y);
				cout << "  ";
				command++;
				y++;
			}
			break;
		}
	}
	cout << endl;

	return command;
}

void Application::DeleteUserId()
{
	cout << "\n\n\t --삭제할 ID를 입력하세요.--" << endl;
	cout << "\t      ID : ";
	cin >> m_UserId;
	m_FileName = "User\\";
	m_FileName.append(m_UserId);
	m_FileName.append(".txt");
	const char* fileTemp = m_FileName.c_str();
	if (!remove(fileTemp))
	{
		cout << "\n\t ID를 삭제하였습니다." << endl << endl;
		cout << "\t";
		system("pause");
		system("cls");
	}
	else
	{
		cout << "\n\t 존재하지 않는 ID입니다." << endl << endl;
		cout << "\t";
		system("pause");
		system("cls");
	}
}

// Program driver.
void Application::Run()
{
	while (1)
	{
		m_Command = GetCommand();
		system("cls");

		switch (m_Command)
		{
		case 1:	// 음악 추가
			AddMusic();
			break;
		case 2:
			SearchRun();
			break;
		case 3:
			ViewRun();
			break;
		case 4:
			WriteDataToFile();
			return;
		default:
			cout << "\tIllegal selection...\n";
			break;
		}

	}
}


// Display command on screen and get a input from keyboard.
int Application::GetCommand()
{
	int command = 1;
	cout << "\n\n\t----- Command ----- " << endl;
	cout << "\t    음악 추가하기" << endl;
	cout << "\t    음악 검색" << endl;
	cout << "\t    음악 보기" << endl;
	cout << "\t    사용 종료" << endl;
	cout << "\n\t< Choose and Enter > ";
	int x = 9, y = 4;
	int key = 0;
	while (key != ENTER)
	{
		gotoxy(x, y);
		cout << "->";
		key = _getch();
		switch (key)
		{
		case UP:
			if (command != 1)
			{
				gotoxy(x, y);
				cout << "  ";
				command--;
				y--;
			}
			break;
		case DOWN:
			if (command != 4)
			{
				gotoxy(x, y);
				cout << "  ";
				command++;
				y++;
			}
			break;
		}
	}
	cout << endl;

	return command;
}

int Application::GetSearchCommand()
{
	int command = 1;
	cout << "\n\n\t----- Command ----- " << endl;
	cout << "\t    제목으로 음악 검색" << endl;
	cout << "\t    가수별 음악 검색" << endl;
	cout << "\t    앨범별 음악 검색" << endl;
	cout << "\t    작곡자별 음악 검색" << endl;
	cout << "\t    작사자별 음악 검색" << endl;
	cout << "\t    소속사별 음악 검색" << endl;
	cout << "\t    뒤로 가기" << endl;
	cout << "\n\t < Choose and Enter > ";
	int x = 9, y = 4;
	int key = 0;
	while (key != ENTER)
	{
		gotoxy(x, y);
		cout << "->";
		key = _getch();
		switch (key)
		{
		case UP:
			if (command != 1)
			{
				gotoxy(x, y);
				cout << "  ";
				command--;
				y--;
			}
			break;
		case DOWN:
			if (command != 7)
			{
				gotoxy(x, y);
				cout << "  ";
				command++;
				y++;
			}
			break;
		}
	}
	gotoxy(4, 14);

	return command;
}

void Application::SearchRun()
{
	m_SearchCommand = GetSearchCommand();
	switch (m_SearchCommand)
	{
	case 1:	// 리스트에 있는 음악 검색
			// 단, 검색어가 곡명에 포함된다면 출력한다
			// 	ex) 검색어 : ‘사랑’ / 출력 : 가난한사랑,천년의사랑,..
		SearchByName();
		break;
	case 2:	// 리스트에 있는 가수 검색
			// 단, 검색어가 가수명에 포함된다면 출력한다
		SearchByArtist();
		break;
	case 3:	// 리스트에 있는 앨범 검색
			// 단, 검색어가 앨범명에 포함된다면 출력한다
		SearchByAlbum();
		break;
	case 4:	// 리스트에 있는 작곡자 검색
			// 단, 검색어가 작곡자에 포함된다면 출력한다
		SearchByComposer();
		break;
	case 5:	// 리스트에 있는 작곡자 검색
			// 단, 검색어가 작곡자에 포함된다면 출력한다
		SearchByLyricist();
		break;
	case 6:	// 리스트에 있는 작곡자 검색
			// 단, 검색어가 작곡자에 포함된다면 출력한다
		SearchByAgency();
		break;
	default:
		system("cls");
		break;
	}
}

int Application::GetViewCommand()
{
	int command = 1;
	cout << "\n\n\t------- Command ------- " << endl;
	cout << "\t    모든 음악 보기" << endl;
	cout << "\t    장르별 음악 보기" << endl;
	cout << "\t    가수별 음악 보기" << endl;
	cout << "\t    앨범 목록 보기" << endl;
	cout << "\t    최근 추가 목록 보기" << endl;
	cout << "\t    뒤로 가기" << endl;
	cout << "\n\t < Choose and Enter > ";
	int x = 9, y = 4;
	int key = 0;
	while (key != ENTER)
	{
		gotoxy(x, y);
		cout << "->";
		key = _getch();
		switch (key)
		{
		case UP:
			if (command != 1)
			{
				gotoxy(x, y);
				cout << "  ";
				command--;
				y--;
			}
			break;
		case DOWN:
			if (command != 6)
			{
				gotoxy(x, y);
				cout << "  ";
				command++;
				y++;
			}
			break;
		}
	}
	system("cls");

	return command;
}

void Application::ViewRun()
{
	m_ViewCommand = GetViewCommand();
	switch (m_ViewCommand)
	{
	case 1:	// 리스트에 있는 모든 음악정보 출력
		DisplayAllMusic();
		break;
	case 2:
		DisplayMusicByGenre();
		break;
	case 3:
		DisplayMusicByArtist();
		break;
	case 4:
		DisplayMusicByAlbum();
		break;
	case 5:
		DisplayNewMusic();
		break;
	default:
		system("cls");
		break;
	}
}


// Add new record into list.
int Application::AddMusic()
{
	/* 입력받은 레코드를 리스트에 add, 리스트가 full일 경우는 add하지 않고 0을 리턴
	if (m_List.IsFull())
	{
	cout << "List is full" << endl;
	return 0;
	}*/

	cout << endl << endl;
	MusicType music;
	music.SetRecordFromKB();
	int check = m_List.Add(music);
	if (check == 0)
	{
		cout << "\t이미 있는 음악입니다." << endl << endl;
		cout << "\t";
		system("pause");
		system("cls");
		return 0;
	}
	else
	{
		SimpleMusicType sMusic;
		sMusic.SetRecord(music.GetNumber(), music.GetName());
		m_gList.Add(music);									// GenreList에 추가
		m_rList.EnQueue(sMusic);								// RecnetMusicList에 추가
		m_abList.Add(music);								// AlbumList에 추가
		m_atList.Add(music);								// ArtistList에 추가
	}

	// 현재 list 출력
	cout << endl;
	DisplayAllMusic();

	return 1;
}


// Display all records in the list on screen.
void Application::DisplayAllMusic()
{
	cout << "\n\n\t음악 목록" << endl;

	// list의 모든 데이터를 화면에 출력
	RedBlackTree<MusicType> bTemp = m_List.GetArray();
	RBIterator<MusicType> itor(bTemp);
	itor.GoLeft();
	int count = m_List.GetLength();
	while (count--)	//RBT를 순차검색한다.
	{
		(*itor).DisplayRecordOnScreen();
		if(count != 0) itor.GetNextNode();
	}
	cout << endl;
	cout << "\t";
	system("pause");
	system("cls");
}


// Open a file by file descriptor as an input file.
int Application::OpenInFile(string fileName)
{
	m_InFile.open(fileName);	// file open for reading.

								// 파일 오픈에 성공하면 1, 그렇지 않다면 0을 리턴.
	if (!m_InFile)	return 0;
	else	return 1;
}


// Open a file by file descriptor as an output file.
int Application::OpenOutFile(string fileName)
{
	m_OutFile.open(fileName);	// file open for writing.

								// 파일 오픈에 성공하면 1, 그렇지 않다면 0을 리턴.
	if (!m_OutFile)	return 0;
	else	return 1;
}


// Open a file as a read mode, read all data on the file, and set list by the data.
int Application::ReadDataFromFile(string filename)
{
	int index = 0;
	MusicType data;	// 읽기용 임시 변수

					// file open, open error가 발생하면 0을 리턴
					//if (!OpenInFile(filename))
					//	return 0;

					// 파일의 모든 내용을 읽어 list에 추가
	while (!m_InFile.eof())
	{
		// array에 학생들의 정보가 들어있는 structure 저장
		data.ReadDataFromFile(m_InFile);
		m_List.Add(data);
		m_abList.Add(data);
		m_atList.Add(data);
		m_gList.Add(data);
	}

	m_InFile.close();	// file close

						// 현재 list 출력

	return 1;
}


// Open a file as a write mode, and write all data into the file,
int Application::WriteDataToFile()
{
	// file open, open error가 발생하면 0을 리턴
	if (!OpenOutFile(m_FileName))
		return 0;
	m_OutFile << m_UserPassword;

	// list의 모든 데이터를 파일에 쓰기
	RedBlackTree<MusicType> bTemp = m_List.GetArray();
	RBIterator<MusicType> itor(bTemp);
	itor.GoLeft();
	int count = m_List.GetLength();
	while (count--)	//RBT를 순차검색한다.
	{
		(*itor).WriteDataToFile(m_OutFile);
		if (count != 0) itor.GetNextNode();
	}

	m_OutFile.close();	// file close

	return 1;
}

// 갱신을 원하는 음악을 입력받아 갱신
void Application::ReplaceMusic()
{
	MusicType music;
	cout << "\n\n\t 수정을 원하는 노래를 입력하세요.\n";
	music.SetRecordFromKB();		// 갱신을 원하는 음악 입력받기
	int success = m_List.Replace(music);
	if (success == 0)	// 같은 값이 존재하지 않을 경우
	{
		cout << "\t노래를 찾을 수 없습니다." << endl << endl;
		cout << "\t";
		system("pause");
		system("cls");
	}

	else
	{
		m_gList.Replace(music);
		m_atList.Replace(music);
		m_abList.Replace(music);
		SimpleMusicType temp;
		temp.SetRecord(music.GetNumber(), music.GetName());
		m_rList.EnQueue(temp);
		cout << "\t";
		system("pause");
		system("cls");
	}

}

// 사용자가 원하는 음악의 정보를 화면에 출력
void Application::DisplayMusic()
{
	MusicType music;
	cout << "\n\n\t보고 싶은 노래의 번호를 입력하세요 : ";
	int tempNumber;
	cin >> tempNumber;
	music.SetNumber(tempNumber);		// 보고 싶은 음악 입력받기
	int success = m_List.Get(music);		// 복사
	if (success == 1)
		music.DisplayRecordOnScreen();		// 출력
	else
	{
		cout << "\t노래를 찾을 수 없습니다." << endl << endl;		// 같은 음악값이 존재하지 않을 경우
		cout << "\t";
		system("pause");
		system("cls");
	}
}

// 유저가 원하는 음악의 정보를 삭제
void Application::DeleteMusic()
{
	MusicType item;
	cout << "\n\n\t 삭제하고 싶은 음악을 입력하세요 : ";
	string tempName;
	cin >> tempName;		// 삭제하고 싶은 음악 입력받기
	item.SetName(tempName);
	int succes = m_List.Delete(item);		// 삭제
	if (succes == 0)		// 같은 음악이 존재하지 않을 경우
	{
		cout << "\t노래를 찾을 수 없습니다." << endl << endl;
		cout << "\t";
		system("pause");
		system("cls");
	}
	else
	{
		m_gList.Delete(item);
		m_atList.Delete(item);
		m_abList.Delete(item);
		cout << "\t";
		system("pause");
		system("cls");
	}
}

// 입력한 문자열이 제목에 포함되어 있는 음악 검색
void Application::SearchByName()
{
	string strTemp;
	cout << "\n\t검색할 제목을 입력하세요 : ";
	cin >> strTemp;
	cout << endl;
	int have = m_List.Search(strTemp, NAME);
	if (have == 0)
		cout << "\t노래를 찾을 수 없습니다." << endl << endl;
	cout << "\t";
	system("pause");
	system("cls");
}

// 입력한 문자열이 가수에 포함되어 있는 음악 검색
void Application::SearchByArtist()
{
	string strTemp;
	cout << "\t검색할 가수를 입력하세요 : ";
	cin >> strTemp;
	cout << endl;
	int have = m_List.Search(strTemp, ARTIST);
	if (have == 0)
		cout << "\t노래를 찾을 수 없습니다." << endl << endl;
	cout << "\t";
	system("pause");
	system("cls");
}

// 입력한 문자열이 앨범에 포함되어 있는 음악 검색
void Application::SearchByAlbum()
{
	string strTemp;
	cout << "\t검색할 앨범을 입력하세요 : ";
	cin >> strTemp;
	cout << endl;
	int have = m_List.Search(strTemp, ALBUM);
	if (have == 0)
		cout << "\t노래를 찾을 수 없습니다." << endl << endl;
	cout << "\t";
	system("pause");
	system("cls");
}

// 입력한 문자열이 작곡자에 포함되어 있는 음악 검색
void Application::SearchByComposer()
{
	string strTemp;
	cout << "\t검색할 작곡가를 입력하세요 : ";
	cin >> strTemp;
	cout << endl;
	int have = m_List.Search(strTemp, COMPOSER);
	if (have == 0)
		cout << "\t노래를 찾을 수 없습니다." << endl << endl;
	cout << "\t";
	system("pause");
	system("cls");
}

void Application::SearchByLyricist()
{
	string strTemp;
	cout << "\t검색할 작사가를 입력하세요 : ";
	cin >> strTemp;
	cout << endl;
	int have = m_List.Search(strTemp, LYRICIST);
	if (have == 0)
		cout << "\t노래를 찾을 수 없습니다." << endl << endl;
	cout << "\t";
	system("pause");
	system("cls");
}

void Application::SearchByAgency()
{
	string strTemp;
	cout << "\t검색할 소속사를 입력하세요 : ";
	cin >> strTemp;
	cout << endl;
	int have = m_List.Search(strTemp, AGENCY);
	if (have == 0)
		cout << "\t노래를 찾을 수 없습니다." << endl << endl;
	cout << "\t";
	system("pause");
	system("cls");
}

// 장르별로 음악을 화면에 출력
void Application::DisplayMusicByGenre()
{
	m_gList.DisplayGenreAll();
}

void Application::DisplayMusicByArtist()
{
	m_atList.DisplayArtistAll();
}

void Application::DisplayMusicByAlbum()
{
	m_abList.DisplayAlbumAll();
}

// 최근 추가한 음악 목록을 화면에 출력
void Application::DisplayNewMusic()
{
	cout << endl << endl;
	m_rList.Print();
	cout << endl << "\t";
	system("pause");
	system("cls");
}

// 곡명과 장르가 일치하는 음악을 찾아서 화면에 출력
void Application::RetrieveByNameNGenre()
{
	string nameTemp, genreTemp;
	cout << "\t곡명 : ";
	cin >> nameTemp;
	cout << "\t장르 : ";
	cin >> genreTemp;
	m_List.DisplayRetrieveNameNGenre(nameTemp, genreTemp);
}

void Application::gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
