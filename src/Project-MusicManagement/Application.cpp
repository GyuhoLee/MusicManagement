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
	cout << "\t     �α���" << endl;
	cout << "\t     ȸ������" << endl;
	cout << "\t     ��� ����" << endl;
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
			cout << "\t ��й�ȣ�� Ʋ�Ƚ��ϴ�." << endl << endl;
			cout << "\t";
			system("pause");
			system("cls");
			return 0;
		}
	}
	int isOpen = OpenInFile(FileNameTemp);
	if (!isOpen)
	{
		cout << "\t �������� �ʴ� ID�Դϴ�." << endl << endl;
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
		cout << "\t ��й�ȣ�� Ʋ�Ƚ��ϴ�." << endl << endl;
		cout << "\t";
		system("pause");
		system("cls");
		m_InFile.close();
		return 0;
	}
}

void Application::SignUp()
{
	cout << "\n\n\t=====ȸ������=====" << endl;
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
	cout << endl << "\t ȸ�������� �Ϸ�Ǿ����ϴ�." << endl << endl;
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
	cout << "\t     ID �����ϱ�" << endl;
	//cout << "\t   2  : ���� ���� ����" << endl;
	cout << "\t     ��� ����" << endl;
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
	cout << "\n\n\t --������ ID�� �Է��ϼ���.--" << endl;
	cout << "\t      ID : ";
	cin >> m_UserId;
	m_FileName = "User\\";
	m_FileName.append(m_UserId);
	m_FileName.append(".txt");
	const char* fileTemp = m_FileName.c_str();
	if (!remove(fileTemp))
	{
		cout << "\n\t ID�� �����Ͽ����ϴ�." << endl << endl;
		cout << "\t";
		system("pause");
		system("cls");
	}
	else
	{
		cout << "\n\t �������� �ʴ� ID�Դϴ�." << endl << endl;
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
		case 1:	// ���� �߰�
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
	cout << "\t    ���� �߰��ϱ�" << endl;
	cout << "\t    ���� �˻�" << endl;
	cout << "\t    ���� ����" << endl;
	cout << "\t    ��� ����" << endl;
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
	cout << "\t    �������� ���� �˻�" << endl;
	cout << "\t    ������ ���� �˻�" << endl;
	cout << "\t    �ٹ��� ���� �˻�" << endl;
	cout << "\t    �۰��ں� ���� �˻�" << endl;
	cout << "\t    �ۻ��ں� ���� �˻�" << endl;
	cout << "\t    �Ҽӻ纰 ���� �˻�" << endl;
	cout << "\t    �ڷ� ����" << endl;
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
	case 1:	// ����Ʈ�� �ִ� ���� �˻�
			// ��, �˻�� ��� ���Եȴٸ� ����Ѵ�
			// 	ex) �˻��� : ������� / ��� : �����ѻ��,õ���ǻ��,..
		SearchByName();
		break;
	case 2:	// ����Ʈ�� �ִ� ���� �˻�
			// ��, �˻�� ������ ���Եȴٸ� ����Ѵ�
		SearchByArtist();
		break;
	case 3:	// ����Ʈ�� �ִ� �ٹ� �˻�
			// ��, �˻�� �ٹ��� ���Եȴٸ� ����Ѵ�
		SearchByAlbum();
		break;
	case 4:	// ����Ʈ�� �ִ� �۰��� �˻�
			// ��, �˻�� �۰��ڿ� ���Եȴٸ� ����Ѵ�
		SearchByComposer();
		break;
	case 5:	// ����Ʈ�� �ִ� �۰��� �˻�
			// ��, �˻�� �۰��ڿ� ���Եȴٸ� ����Ѵ�
		SearchByLyricist();
		break;
	case 6:	// ����Ʈ�� �ִ� �۰��� �˻�
			// ��, �˻�� �۰��ڿ� ���Եȴٸ� ����Ѵ�
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
	cout << "\t    ��� ���� ����" << endl;
	cout << "\t    �帣�� ���� ����" << endl;
	cout << "\t    ������ ���� ����" << endl;
	cout << "\t    �ٹ� ��� ����" << endl;
	cout << "\t    �ֱ� �߰� ��� ����" << endl;
	cout << "\t    �ڷ� ����" << endl;
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
	case 1:	// ����Ʈ�� �ִ� ��� �������� ���
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
	/* �Է¹��� ���ڵ带 ����Ʈ�� add, ����Ʈ�� full�� ���� add���� �ʰ� 0�� ����
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
		cout << "\t�̹� �ִ� �����Դϴ�." << endl << endl;
		cout << "\t";
		system("pause");
		system("cls");
		return 0;
	}
	else
	{
		SimpleMusicType sMusic;
		sMusic.SetRecord(music.GetNumber(), music.GetName());
		m_gList.Add(music);									// GenreList�� �߰�
		m_rList.EnQueue(sMusic);								// RecnetMusicList�� �߰�
		m_abList.Add(music);								// AlbumList�� �߰�
		m_atList.Add(music);								// ArtistList�� �߰�
	}

	// ���� list ���
	cout << endl;
	DisplayAllMusic();

	return 1;
}


// Display all records in the list on screen.
void Application::DisplayAllMusic()
{
	cout << "\n\n\t���� ���" << endl;

	// list�� ��� �����͸� ȭ�鿡 ���
	RedBlackTree<MusicType> bTemp = m_List.GetArray();
	RBIterator<MusicType> itor(bTemp);
	itor.GoLeft();
	int count = m_List.GetLength();
	while (count--)	//RBT�� �����˻��Ѵ�.
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

								// ���� ���¿� �����ϸ� 1, �׷��� �ʴٸ� 0�� ����.
	if (!m_InFile)	return 0;
	else	return 1;
}


// Open a file by file descriptor as an output file.
int Application::OpenOutFile(string fileName)
{
	m_OutFile.open(fileName);	// file open for writing.

								// ���� ���¿� �����ϸ� 1, �׷��� �ʴٸ� 0�� ����.
	if (!m_OutFile)	return 0;
	else	return 1;
}


// Open a file as a read mode, read all data on the file, and set list by the data.
int Application::ReadDataFromFile(string filename)
{
	int index = 0;
	MusicType data;	// �б�� �ӽ� ����

					// file open, open error�� �߻��ϸ� 0�� ����
					//if (!OpenInFile(filename))
					//	return 0;

					// ������ ��� ������ �о� list�� �߰�
	while (!m_InFile.eof())
	{
		// array�� �л����� ������ ����ִ� structure ����
		data.ReadDataFromFile(m_InFile);
		m_List.Add(data);
		m_abList.Add(data);
		m_atList.Add(data);
		m_gList.Add(data);
	}

	m_InFile.close();	// file close

						// ���� list ���

	return 1;
}


// Open a file as a write mode, and write all data into the file,
int Application::WriteDataToFile()
{
	// file open, open error�� �߻��ϸ� 0�� ����
	if (!OpenOutFile(m_FileName))
		return 0;
	m_OutFile << m_UserPassword;

	// list�� ��� �����͸� ���Ͽ� ����
	RedBlackTree<MusicType> bTemp = m_List.GetArray();
	RBIterator<MusicType> itor(bTemp);
	itor.GoLeft();
	int count = m_List.GetLength();
	while (count--)	//RBT�� �����˻��Ѵ�.
	{
		(*itor).WriteDataToFile(m_OutFile);
		if (count != 0) itor.GetNextNode();
	}

	m_OutFile.close();	// file close

	return 1;
}

// ������ ���ϴ� ������ �Է¹޾� ����
void Application::ReplaceMusic()
{
	MusicType music;
	cout << "\n\n\t ������ ���ϴ� �뷡�� �Է��ϼ���.\n";
	music.SetRecordFromKB();		// ������ ���ϴ� ���� �Է¹ޱ�
	int success = m_List.Replace(music);
	if (success == 0)	// ���� ���� �������� ���� ���
	{
		cout << "\t�뷡�� ã�� �� �����ϴ�." << endl << endl;
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

// ����ڰ� ���ϴ� ������ ������ ȭ�鿡 ���
void Application::DisplayMusic()
{
	MusicType music;
	cout << "\n\n\t���� ���� �뷡�� ��ȣ�� �Է��ϼ��� : ";
	int tempNumber;
	cin >> tempNumber;
	music.SetNumber(tempNumber);		// ���� ���� ���� �Է¹ޱ�
	int success = m_List.Get(music);		// ����
	if (success == 1)
		music.DisplayRecordOnScreen();		// ���
	else
	{
		cout << "\t�뷡�� ã�� �� �����ϴ�." << endl << endl;		// ���� ���ǰ��� �������� ���� ���
		cout << "\t";
		system("pause");
		system("cls");
	}
}

// ������ ���ϴ� ������ ������ ����
void Application::DeleteMusic()
{
	MusicType item;
	cout << "\n\n\t �����ϰ� ���� ������ �Է��ϼ��� : ";
	string tempName;
	cin >> tempName;		// �����ϰ� ���� ���� �Է¹ޱ�
	item.SetName(tempName);
	int succes = m_List.Delete(item);		// ����
	if (succes == 0)		// ���� ������ �������� ���� ���
	{
		cout << "\t�뷡�� ã�� �� �����ϴ�." << endl << endl;
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

// �Է��� ���ڿ��� ���� ���ԵǾ� �ִ� ���� �˻�
void Application::SearchByName()
{
	string strTemp;
	cout << "\n\t�˻��� ������ �Է��ϼ��� : ";
	cin >> strTemp;
	cout << endl;
	int have = m_List.Search(strTemp, NAME);
	if (have == 0)
		cout << "\t�뷡�� ã�� �� �����ϴ�." << endl << endl;
	cout << "\t";
	system("pause");
	system("cls");
}

// �Է��� ���ڿ��� ������ ���ԵǾ� �ִ� ���� �˻�
void Application::SearchByArtist()
{
	string strTemp;
	cout << "\t�˻��� ������ �Է��ϼ��� : ";
	cin >> strTemp;
	cout << endl;
	int have = m_List.Search(strTemp, ARTIST);
	if (have == 0)
		cout << "\t�뷡�� ã�� �� �����ϴ�." << endl << endl;
	cout << "\t";
	system("pause");
	system("cls");
}

// �Է��� ���ڿ��� �ٹ��� ���ԵǾ� �ִ� ���� �˻�
void Application::SearchByAlbum()
{
	string strTemp;
	cout << "\t�˻��� �ٹ��� �Է��ϼ��� : ";
	cin >> strTemp;
	cout << endl;
	int have = m_List.Search(strTemp, ALBUM);
	if (have == 0)
		cout << "\t�뷡�� ã�� �� �����ϴ�." << endl << endl;
	cout << "\t";
	system("pause");
	system("cls");
}

// �Է��� ���ڿ��� �۰��ڿ� ���ԵǾ� �ִ� ���� �˻�
void Application::SearchByComposer()
{
	string strTemp;
	cout << "\t�˻��� �۰�� �Է��ϼ��� : ";
	cin >> strTemp;
	cout << endl;
	int have = m_List.Search(strTemp, COMPOSER);
	if (have == 0)
		cout << "\t�뷡�� ã�� �� �����ϴ�." << endl << endl;
	cout << "\t";
	system("pause");
	system("cls");
}

void Application::SearchByLyricist()
{
	string strTemp;
	cout << "\t�˻��� �ۻ簡�� �Է��ϼ��� : ";
	cin >> strTemp;
	cout << endl;
	int have = m_List.Search(strTemp, LYRICIST);
	if (have == 0)
		cout << "\t�뷡�� ã�� �� �����ϴ�." << endl << endl;
	cout << "\t";
	system("pause");
	system("cls");
}

void Application::SearchByAgency()
{
	string strTemp;
	cout << "\t�˻��� �Ҽӻ縦 �Է��ϼ��� : ";
	cin >> strTemp;
	cout << endl;
	int have = m_List.Search(strTemp, AGENCY);
	if (have == 0)
		cout << "\t�뷡�� ã�� �� �����ϴ�." << endl << endl;
	cout << "\t";
	system("pause");
	system("cls");
}

// �帣���� ������ ȭ�鿡 ���
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

// �ֱ� �߰��� ���� ����� ȭ�鿡 ���
void Application::DisplayNewMusic()
{
	cout << endl << endl;
	m_rList.Print();
	cout << endl << "\t";
	system("pause");
	system("cls");
}

// ���� �帣�� ��ġ�ϴ� ������ ã�Ƽ� ȭ�鿡 ���
void Application::RetrieveByNameNGenre()
{
	string nameTemp, genreTemp;
	cout << "\t��� : ";
	cin >> nameTemp;
	cout << "\t�帣 : ";
	cin >> genreTemp;
	m_List.DisplayRetrieveNameNGenre(nameTemp, genreTemp);
}

void Application::gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
