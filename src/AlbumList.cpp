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



// ����Ʈ�� ����ִ��� Ȯ��
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
	if (Get(inData) == 1)	//���� ������� �ٹ��Ͻ�
	{
		RBIterator<AlbumType> itor(m_aArray);
		itor.GoLeft();
		int count = m_aArray.GetLength();
		while (count--)	//RBT�� �����˻��Ѵ�.
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
		while (count--)	//RBT�� �����˻��Ѵ�.
		{
			if ((*itor).GetAlbumName().compare(inDataTemp.GetAlbumName()) == 0) break;
			if (count != 0) itor.GetNextNode();
		}
		(*itor).AddMusicInAlbum(ForAddTemp);
	}
	return 1;
}

// ���ȣ�� �������� �����͸� �˻��ϰ� �ش� �����͸� ������
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


// ���� ���ڵ� ����
int AlbumList::Delete(MusicType& inData)
{
	AlbumType inDataTemp;			// AlbumType���� ��ȯ
	SimpleMusicType ForDeleteTemp;	// ������ ������
	ForDeleteTemp.SetRecord(inData.GetNumber(), inData.GetName());
	inDataTemp.SetInfo(inData.GetAlbum(), inData.GetArtist(), inData.GetAgency());
	if (Get(inData) == 1)		// �����Ͱ� �����Ҷ���
	{
		RBIterator<AlbumType> itor(m_aArray);
		itor.GoLeft();
		int count = m_aArray.GetLength();
		while (count--)	//RBT�� �����˻��Ѵ�.
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


// ���� ���ڵ� ����
int AlbumList::Replace(MusicType &inData)
{
	AlbumType inDataTemp;		// AlbumType���� ��ȯ�� ����
	SimpleMusicType ForReplaceTemp;		// ������ ����
	ForReplaceTemp.SetRecord(inData.GetNumber(), inData.GetName());
	inDataTemp.SetInfo(inData.GetAlbum(), inData.GetArtist(), inData.GetAgency());
	if (Get(inData) == 1)		// �����Ͱ� �����Ҷ���
	{
		RBIterator<AlbumType> itor(m_aArray);
		itor.GoLeft();
		int count = m_aArray.GetLength();
		while (count--)	//RBT�� �����˻��Ѵ�.
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
	cout << "\n\n\t     ---- �ٹ�  ------  ���� ----- " << endl;
	RBIterator<AlbumType> itor(m_aArray);
	itor.GoLeft();
	int count = m_aArray.GetLength();
	while (count--)	//RBT�� �����˻��Ѵ�.
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
	while (--command)	//RBT�� �����˻��Ѵ�.		// command�� ���� string Search
	{
		itor2.GetNextNode();
	}
	system("cls");
	(*itor2).DisplayAllMusicInAlbum();
	system("cls");
	return;

	cout << "\t �߸��� Ŀ�ǵ带 �Է��Ͽ����ϴ�.";	// return���� Ż���� �� �ϴ� ���
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