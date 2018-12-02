#include "GenreList.h"

// Make list empty.
void GenreList::MakeEmpty()
{
	m_gArray.MakeEmpty();
}


// Get a number of records in current list.
int GenreList::GetLength()
{
	return m_gArray.GetLength();
}



// 리스트가 비어있는지 확인
int GenreList::IsEmpty()
{
	if (m_gArray.GetLength() == 0)
		return 1;
	else
		return 0;
}


// add a new data into list.
int GenreList::Add(MusicType inData)
{
	GenreType inDataTemp;
	SimpleMusicType ForAddTemp;
	ForAddTemp.SetRecord(inData.GetNumber(), inData.GetName());
	inDataTemp.SetInfo(inData.GetGenre());
	if (Get(inData) == 1)	//벌써 만들어진 장르일시
	{
		m_gArray.ResetList();
		GenreType *gTemp = new GenreType;
		while (m_gArray.GetNextItem(gTemp) != -1)
		{
			if (gTemp->GetId() == inDataTemp.GetId()) break;
		}
		gTemp->AddMusicInGenre(ForAddTemp);
	}
	else
	{
		GenreType newGenre;
		newGenre.SetInfo(inData.GetGenre());
		m_gArray.Add(newGenre);
		m_gArray.ResetList();
		GenreType *gTemp = new GenreType;
		while (m_gArray.GetNextItem(gTemp) != -1)
		{
			if (gTemp->GetId() == inDataTemp.GetId()) break;
		}
		gTemp->AddMusicInGenre(ForAddTemp);
	}
	return 1;
}


// Initialize list iterator.
void GenreList::ResetList()
{
	m_gArray.ResetList();
}


// move list iterator to the next item in list and get that item.
void GenreList::GetNextMusic(GenreType& data)
{
	GenreType *temp = &data;
	m_gArray.GetNextItem(temp);
}


// 곡번호를 기준으로 데이터를 검색하고 해당 데이터를 가져옴
int GenreList::Get(MusicType& data)
{
	GenreType temp;
	temp.SetInfo(data.GetGenre());
	int found = m_gArray.Get(temp);
	if (found)
		return 1;
	else
		return 0;
}


// 기존 레코드 삭제
int GenreList::Delete(MusicType& inData)
{
	GenreType inDataTemp;
	SimpleMusicType ForDeleteTemp;
	ForDeleteTemp.SetRecord(inData.GetNumber(), inData.GetName());
	inDataTemp.SetInfo(inData.GetGenre());
	if (Get(inData) == 1)
	{
		m_gArray.ResetList();
		GenreType* gTemp = new GenreType;
		while (m_gArray.GetNextItem(gTemp) != -1)
		{
			if (gTemp->GetId() == inDataTemp.GetId()) break;
		}
		gTemp->DeleteMusicInGenre(ForDeleteTemp);
		if (gTemp->GetLength() == 0) m_gArray.Delete(inDataTemp);
		return 1;
	}
	else
		return 0;
}


// 기존 레코드 갱신
int GenreList::Replace(MusicType &inData)
{
	GenreType inDataTemp;
	SimpleMusicType ForReplaceTemp;
	ForReplaceTemp.SetRecord(inData.GetNumber(), inData.GetName());
	inDataTemp.SetInfo(inData.GetGenre());
	if (Get(inData) == 1)
	{
		m_gArray.ResetList();
		GenreType* gTemp = new GenreType;
		while (m_gArray.GetNextItem(gTemp) != -1)
		{
			if (gTemp->GetId() == inDataTemp.GetId()) break;
		}
		gTemp->DeleteMusicInGenre(ForReplaceTemp);
		return 1;
	}
	else
		return 0;
}

void GenreList::DisplayGenreAll()
{
	cout << "\n\n\t----- Command ----- " << endl;
	m_gArray.ResetList();
	GenreType* gTemp = new GenreType;
	while (m_gArray.GetNextItem(gTemp) != -1)
	{
		gTemp->DisplayRecordOnScreen();
		cout << endl;
	}
	cout << "\n\t< Choose and Enter > ";
	m_gArray.ResetList();
	int command = 1;
	int x = 9, y = 4;
	int key = 0;
	while (key != 13)
	{
		gotoxy(x, y);
		cout << "->";
		key = _getch();
		switch (key)
		{
		case 72:
			if (command != 1)
			{
				gotoxy(x, y);
				cout << "  ";
				command--;
				y--;
			}
			break;
		case 80:
			if (command != m_gArray.GetLength())
			{
				gotoxy(x, y);
				cout << "  ";
				command++;
				y++;
			}
			break;
		}
	}
	while (command--)
	{
		m_gArray.GetNextItem(gTemp);
	}
	system("cls");
	gTemp->DisplayAllMusicInGenre();
	cout << "\n\t";
	system("cls");
	return;
	cout << "\t 잘못된 커맨드를 입력하였습니다.";	// return으로 탈출을 못 하는 경우
	cout << endl << endl;
}

void GenreList::gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}