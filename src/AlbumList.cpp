#include "AlbumList.h"

// Make list empty.
void AlbumList::MakeEmpty()
{
	m_aArray.MakeEmpty();
}


// Get a number of records in current list.
int AlbumList::GetLength()
{
	return m_aArray.GetLength();
}



// 리스트가 비어있는지 확인
int AlbumList::IsEmpty()
{
	if (m_aArray.GetLength() == 0)
		return 1;
	else
		return 0;
}


// add a new data into list.
int AlbumList::Add(MusicType inData)
{
	AlbumType inDataTemp;
	SimpleMusicType ForAddTemp;
	ForAddTemp.SetRecord(inData.GetNumber(), inData.GetName());
	inDataTemp.SetInfo(inData.GetAlbum(), inData.GetArtist(), inData.GetAgency());
	if (Get(inData) == 1)	//벌써 만들어진 앨범일시
	{
		RBIterator<AlbumType> itor(m_aArray);
		itor.GoLeft();
		int count = m_aArray.GetLength();
		while (count--)	//RBT를 순차검색한다.
		{
			if ((*itor).GetAlbumName().compare(inDataTemp.GetAlbumName()) == 0) break;
			if (count != 0) itor.GetNextNode();
		}
		(*itor).AddMusicInAlbum(ForAddTemp);
	}
	else
	{
		AlbumType newAlbum;
		newAlbum.SetInfo(inData.GetAlbum(), inData.GetArtist(), inData.GetAgency());
		m_aArray.insert(newAlbum);
		RBIterator<AlbumType> itor(m_aArray);
		itor.GoLeft();
		int count = m_aArray.GetLength();
		while (count--)	//RBT를 순차검색한다.
		{
			if ((*itor).GetAlbumName().compare(inDataTemp.GetAlbumName()) == 0) break;
			if (count != 0) itor.GetNextNode();
		}
		(*itor).AddMusicInAlbum(ForAddTemp);
	}
	return 1;
}

// 곡번호를 기준으로 데이터를 검색하고 해당 데이터를 가져옴
int AlbumList::Get(MusicType& data)
{
	AlbumType aTemp;
	aTemp.SetInfo(data.GetAlbum(), data.GetArtist(), data.GetAgency());
	AlbumType* temp = new AlbumType;
	bool found = m_aArray.Retrieve(aTemp, temp);
	if (found)
		return 1;
	else
		return 0;
}


// 기존 레코드 삭제
int AlbumList::Delete(MusicType& inData)
{
	AlbumType inDataTemp;			// AlbumType으로 전환
	SimpleMusicType ForDeleteTemp;	// 삭제할 데이터
	ForDeleteTemp.SetRecord(inData.GetNumber(), inData.GetName());
	inDataTemp.SetInfo(inData.GetAlbum(), inData.GetArtist(), inData.GetAgency());
	if (Get(inData) == 1)		// 데이터가 존재할때만
	{
		RBIterator<AlbumType> itor(m_aArray);
		itor.GoLeft();
		int count = m_aArray.GetLength();
		while (count--)	//RBT를 순차검색한다.
		{
			if ((*itor).GetAlbumName().compare(inDataTemp.GetAlbumName()) == 0) break;
			if (count != 0) itor.GetNextNode();
		}
		(*itor).DeleteMusicInAlbum(ForDeleteTemp);
		if ((*itor).GetLength() == 0) m_aArray.erase(inDataTemp);
		return 1;
	}
	else
		return 0;
}


// 기존 레코드 갱신
int AlbumList::Replace(MusicType &inData)
{
	AlbumType inDataTemp;		// AlbumType으로 전환을 위해
	SimpleMusicType ForReplaceTemp;		// 갱신할 정보
	ForReplaceTemp.SetRecord(inData.GetNumber(), inData.GetName());
	inDataTemp.SetInfo(inData.GetAlbum(), inData.GetArtist(), inData.GetAgency());
	if (Get(inData) == 1)		// 데이터가 존재할때만
	{
		RBIterator<AlbumType> itor(m_aArray);
		itor.GoLeft();
		int count = m_aArray.GetLength();
		while (count--)	//RBT를 순차검색한다.
		{
			if ((*itor).GetAlbumName().compare(inDataTemp.GetAlbumName()) == 0) break;
			if (count != 0) itor.GetNextNode();
		}
		(*itor).DeleteMusicInAlbum(ForReplaceTemp);
		return 1;
	}
	else
		return 0;
}

void AlbumList::DisplayAlbumAll()
{
	cout << "\n\n\t     ---- 앨범  ------  가수 ----- " << endl;
	RBIterator<AlbumType> itor(m_aArray);
	itor.GoLeft();
	int count = m_aArray.GetLength();
	while (count--)	//RBT를 순차검색한다.
	{
		(*itor).DisplayRecordOnScreen();
		cout << endl;
		if (count != 0) itor.GetNextNode();
	}
	cout << "\n\t         < Choose and Enter > ";
	int command = 1;
	int x = 6, y = 4;
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
	RBIterator<AlbumType> itor2(m_aArray);
	itor2.GoLeft();
	while (--command)	//RBT를 순차검색한다.		// command와 같은 string Search
	{
		itor2.GetNextNode();
	}
	system("cls");
	(*itor2).DisplayAllMusicInAlbum();
	system("cls");
	return;

	cout << "\t 잘못된 커맨드를 입력하였습니다.";	// return으로 탈출을 못 하는 경우
	cout << endl << endl;
	cout << "\n\t";
	system("pause");
	system("cls");
}

void AlbumList::gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}