#include "MusicType.h"

// Set music number from keyboard.
void MusicType::SetNumberFromKB()
{
	cout << "\t��ȣ : ";
	cin >> m_Number;
}

// Set music name from keyboard.
void MusicType::SetNameFromKB()
{
	cout << "\t��� : ";
	cin >> m_Name;
}


// Set music artist from keyboard.
void MusicType::SetArtistFromKB()
{
	cout << "\t���� : ";
	cin >> m_Artist;
}

void MusicType::SetComposerFromKB()
{
	cout << "\t�۰��� : ";
	cin >> m_Composer;
}

void MusicType::SetLyricistFromKB()
{
	cout << "\t�ۻ��� : ";
	cin >> m_Lyricist;
}


// Set music album from keyboard.
void MusicType::SetAlbumFromKB()
{
	cout << "\t�ٹ� : ";
	cin >> m_Album;
}

void MusicType::SetAgencyFromKB()
{
	cout << "\t�Ҽӻ� : ";
	cin >> m_Agency;
}

void MusicType::SetReleaseDateFromKB()
{
	cout << "\t�߸��� : ";
	cin >> m_ReleaseDate;
}

// Set music genre from keyboard.
void MusicType::SetGenreFromKB()
{
	cout << "\t�帣 : ";
	cin >> m_Genre;
}

// Set music Lyrics from keyboard.
void MusicType::SetLyricsFromKB()
{
	cout << "\t���� : ";
	cin.ignore();
	getline(cin, m_Lyrics);
}


// Set student record from keyboard.
void MusicType::SetRecordFromKB()
{
	SetNumberFromKB();
	SetNameFromKB();
	SetArtistFromKB();
	SetComposerFromKB();
	SetLyricistFromKB();
	SetAlbumFromKB();
	SetAgencyFromKB();
	SetReleaseDateFromKB();
	SetGenreFromKB();
	SetLyricsFromKB();
}


// Read a record from file.
int MusicType::ReadDataFromFile(ifstream& fin)
{
	fin >> m_Number;
	fin >> m_Name;
	fin >> m_Artist;
	fin >> m_Composer;
	fin >> m_Lyricist;
	fin >> m_Album;
	fin >> m_Agency;
	fin >> m_ReleaseDate;
	fin >> m_Genre;
	fin >> m_PlayTime;
	fin.ignore();
	getline(fin, m_Lyrics);
	return 1;
};


// Write a record into file.
int MusicType::WriteDataToFile(ofstream& fout)
{
	fout << endl;
	fout << m_Number << " ";
	fout << m_Name << " ";
	fout << m_Artist << " ";
	fout << m_Composer << " ";
	fout << m_Lyricist << " ";
	fout << m_Album << " ";
	fout << m_Agency << " ";
	fout << m_ReleaseDate << " ";
	fout << m_Genre << " ";
	fout << m_PlayTime << endl;
	fout << m_Lyrics;

	return 1;
}


// Compare two itemtypes.
RelationType MusicType::CompareByID(const MusicType &data)
{
	if (this->m_Number > data.m_Number)
		return GREATER;
	else if (this->m_Number < data.m_Number)
		return LESS;
	else
		return EQUAL;
}

// �Է��� MusicType�� Ŭ������ ��� �������� ���� 
void MusicType::CopyRecord(MusicType data)
{
	SetRecord(data.GetNumber(), data.GetName(), data.GetArtist(), data.GetComposer(), data.GetLyricist(), data.GetAlbum(), data.GetAgency(), data.GetReleaseDate(), data.GetGenre(), data.GetLyrics());
	SetPlayTime(data.GetPlayTime());
}

void MusicType::operator=(const MusicType &obj)
{
	CopyRecord(obj);
}

bool MusicType::operator==(MusicType obj)
{
	if (this->GetName().compare(obj.GetName()) == 0) return true;
	else return false;
}

bool MusicType::operator!=(MusicType obj)
{
	if (this->GetName().compare(obj.GetName()) != 0) return true;
	else return false;
}

bool MusicType::operator<(MusicType obj)
{
	if (this->GetName().compare(obj.GetName()) < 0) return true;
	else return false;
}

bool MusicType::operator>(MusicType obj)
{
	if (this->GetName().compare(obj.GetName()) > 0) return true;
	else return false;
}

bool MusicType::operator<=(MusicType obj)
{
	if (this->GetName().compare(obj.GetName()) <= 0) return true;
	else return false;
}

bool MusicType::operator>=(MusicType obj)
{
	if (this->GetName().compare(obj.GetName()) >= 0) return true;
	else return false;
}

bool MusicType::SoundSong()
{
	if (m_PlayTime == 0) return false;

	string FileTemp = "Music\\";
	FileTemp.append(m_Name);
	FileTemp.append(".wav");
	const char *FileName = FileTemp.c_str();
	PlaySound(TEXT(FileName), NULL, SND_FILENAME | SND_ASYNC);
	//						������ �� ã�� �� �⺻ �Ҹ� ���
	//							�Ҹ��� �񵿱������� ���(���� ����)
	int pTime = m_PlayTime / 100 * 60 + m_PlayTime % 100;
	int key = 0;
	for (float i = 0; i < pTime; i+= 0.5)
	{
		if (_kbhit())
		{
			key = _getch();
			if (key == 32)
			{
				break;
			}
			if (key == 13)
			{
				PlaySound(NULL, NULL, NULL);
				break;
			}
		}
		gotoxy(6, 13);
		float gage = i / (float)pTime * 40;
		cout << "��������";
		for (int j = 0; j < 41; j++) cout << "��";
		cout << "��";
		gotoxy(6, 14);
		cout << "������ ";
		for (int j = 0; j < 40; j++) cout << "-";
		cout << "��";
		gotoxy(10 + gage, 14);
		cout << "��";
		gotoxy(6, 15);
		cout << "��������";
		for (int j = 0; j < 41; j++) cout << "��";
		cout << "��";
		cout << endl << endl << "\t ���ư��÷��� EnterŰ�� �����ּ���." << endl;
		cout << "\t �뷡�� �����Ųä�� ���ư��÷��� SpaceBar�� �����ּ���.";
		Sleep(500);
	}
	return true;
}

void MusicType::gotoxy(float x, int y)
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}