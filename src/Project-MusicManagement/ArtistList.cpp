#include "ArtistList.h"

// Make list empty.
void ArtistList::MakeEmpty()
{
	m_aArray.MakeEmpty();
}


// Get a number of records in current list.
int ArtistList::GetLength()
{
	return m_aArray.GetLength();
}



// 리스트가 비어있는지 확인
int ArtistList::IsEmpty()
{
	if (m_aArray.GetLength() == 0)
		return 1;
	else
		return 0;
}


// add a new data into list.
int ArtistList::Add(MusicType inData)
{
	ArtistType inDataTemp;
	SimpleMusicType ForAddTemp;
	ForAddTemp.SetRecord(inData.GetNumber(), inData.GetName());
	inDataTemp.SetInfo(inData.GetArtist(), inData.GetAgency());
	if (Get(inData) == 1)	//벌써 만들어진 가수일시
	{
		RBIterator<ArtistType> itor(m_aArray);
		itor.GoLeft();
		int count = m_aArray.GetLength();
		while (count--)	//RBT를 순차검색한다
		{
			if ((*itor).GetArtistName().compare(inDataTemp.GetArtistName()) == 0) break;
			if (count != 0) itor.GetNextNode();
		}
		(*itor).AddMusicInArtist(ForAddTemp);
	}
	else
	{
		ArtistType newArtist;
		newArtist.SetInfo(inData.GetArtist(), inData.GetAgency());
		m_aArray.insert(newArtist);
		RBIterator<ArtistType> itor(m_aArray);
		itor.GoLeft();
		int count = m_aArray.GetLength();
		while (count--)	//RBT를 순차검색한다
		{
			if ((*itor).GetArtistName().compare(inDataTemp.GetArtistName()) == 0) break;
			if (count != 0) itor.GetNextNode();
		}
		(*itor).AddMusicInArtist(ForAddTemp);
	}
	return 1;
}

// 가수명을 기준으로 데이터를 검색하고 해당 데이터를 가져옴
int ArtistList::Get(MusicType& data)
{
	ArtistType aTemp;
	aTemp.SetInfo(data.GetArtist(), data.GetAgency());
	ArtistType* temp = new ArtistType;
	bool found = m_aArray.Retrieve(aTemp, temp);
	if (found)
		return 1;
	else
		return 0;
}


// 기존 레코드 삭제
int ArtistList::Delete(MusicType& inData)
{
	ArtistType inDataTemp;
	SimpleMusicType ForDeleteTemp;
	ForDeleteTemp.SetRecord(inData.GetNumber(), inData.GetName());
	inDataTemp.SetInfo(inData.GetArtist(), inData.GetAgency());
	if (Get(inData) == 1)
	{
		RBIterator<ArtistType> itor(m_aArray);
		itor.GoLeft();
		int count = m_aArray.GetLength();
		while (count--)	//RBT를 순차검색한다
		{
			if ((*itor).GetArtistName().compare(inDataTemp.GetArtistName()) == 0) break;
			if (count != 0) itor.GetNextNode();
		}
		(*itor).DeleteMusicInArtist(ForDeleteTemp);
		if ((*itor).GetLength() == 0) m_aArray.erase(inDataTemp);
		return 1;
	}
	else
		return 0;
}


// 기존 레코드 갱신
int ArtistList::Replace(MusicType &inData)
{
	ArtistType inDataTemp;
	SimpleMusicType ForReplaceTemp;
	ForReplaceTemp.SetRecord(inData.GetNumber(), inData.GetName());
	inDataTemp.SetInfo(inData.GetArtist(), inData.GetAgency());
	if (Get(inData) == 1)
	{
		RBIterator<ArtistType> itor(m_aArray);
		itor.GoLeft();
		int count = m_aArray.GetLength();
		while (count--)	//RBT를 순차검색한다
		{
			if ((*itor).GetArtistName().compare(inDataTemp.GetArtistName()) == 0) break;
			if (count != 0) itor.GetNextNode();
		}
		(*itor).DeleteMusicInArtist(ForReplaceTemp);
		return 1;
	}
	else
		return 0;
}

void ArtistList::DisplayArtistAll()
{
	cout << "\n\n\t  --- 가수 ---- 소속사 ----- " << endl;
	RBIterator<ArtistType> itor(m_aArray);
	itor.GoLeft();
	int count = m_aArray.GetLength();
	while (count--)	//RBT를 순차검색한다
	{
		(*itor).DisplayRecordOnScreen();
		cout << endl;
		if (count != 0) itor.GetNextNode();
	}
	cout << "\n\t   < Choose and Enter > ";
	int command = 1;
	int x = 7, y = 4;
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
			if (command != m_aArray.GetLength())
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
	RBIterator<ArtistType> itor2(m_aArray);
	itor2.GoLeft();
	while (--command)	//RBT를 순차검색한다
	{
		*(itor2).GetNextNode();
	}
	system("cls");
	(*itor2).DisplayAllMusicInArtist();
	system("cls");
	PlaySound(NULL, NULL, NULL);
	return;

	cout << "\t 잘못된 커맨드를 입력하였습니다.";	// return으로 탈출을 못 하는 경우
	cout << endl << endl;
	cout << "\n\t";
	system("pause");
	system("cls");
}

void ArtistList::gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}