#include "GenreType.h"
#include "GenreList.h"
#include "MusicList.h"
#include "AlbumList.h"
#include "ArtistList.h"

void GenreType::SetInfo(string inGenre)
{
	m_Genre = inGenre;
	if (m_Genre == "��") m_GenreId = 1;
	else if (m_Genre == "��") m_GenreId = 2;
	else if (m_Genre == "�߶��") m_GenreId = 3;
	else if (m_Genre == "�ε�����") m_GenreId = 4;
	else if (m_Genre == "Ŭ����") m_GenreId = 5;
	else if (m_Genre == "Ʈ��Ʈ") m_GenreId = 6;
	else if (m_Genre == "��") m_GenreId = 7;
	else if (m_Genre == "����") m_GenreId = 8;
	else
	{
		m_Genre = "��Ÿ";
		m_GenreId = 9;
	}
}

void GenreType::DisplayRecordOnScreen()
{
	cout << "\t       " << m_Genre;
}

void GenreType::AddMusicInGenre(SimpleMusicType inData)
{
	m_GenreMusicList.insert(inData);
}

void GenreType::DeleteMusicInGenre(SimpleMusicType inData)
{
	m_GenreMusicList.erase(inData);
}

void GenreType::ReplaceMusicInGenre(SimpleMusicType inData)
{
	SimpleMusicType* inTemp;
	bool found = m_GenreMusicList.Retrieve(inData, inTemp);
	if (found)
	{
		m_GenreMusicList.erase(*inTemp);
		m_GenreMusicList.insert(inData);
	}
}

void GenreType::DisplayMusicDetailInGenre(RedBlackTree<MusicType> *list)
{
	cout << "\n\t���� ���" << endl;

	// list�� ��� �����͸� ȭ�鿡 ���
	int length = m_GenreMusicList.GetLength();
	int curIndex = 0;
	RBIterator<SimpleMusicType> itor(m_GenreMusicList);
	itor.GoLeft();
	while (curIndex < length && curIndex != -1)
	{
		cout << curIndex + 1 << endl;
		(*itor).DisplayRecordOnScreen();
		curIndex++;
		itor.GetNextNode();
	}

	//?? SimpleMusicType �� data �� music id �� title ���� ���´�.
	// �ش� �帣�� ���ԵǴ� ��� ���� ������ ����ϱ� ���ؼ� �� ������ ������
	// �� �Լ��� �Ķ������ list�� �˻��Ͽ� music information �� ����� �־�� ��.
}

void GenreType::DisplayAllMusicInGenre()
{
	cout << "\n\n\t         ------" << m_Genre << "----- " << endl;
	RBIterator<SimpleMusicType> itor(m_GenreMusicList);
	itor.GoLeft();
	int count = m_GenreMusicList.GetLength();
	while (count--)
	{
		(*itor).DisplayRecordOnScreen();
		if (count != 0) itor.GetNextNode();
	}
	cout << "\t\t  " << "< ���ư��� >" << endl;
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
			if (command != m_GenreMusicList.GetLength() + 1)
			{
				gotoxy(x, y);
				cout << "  ";
				command++;
				y++;
			}
			break;
		}
	}
	if (command == m_GenreMusicList.GetLength() + 1) return;
	
	RBIterator<SimpleMusicType> itor2(m_GenreMusicList);
	itor2.GoLeft();
	while (--command)
	{
		itor2.GetNextNode();
	}

	x -= 5;
	gotoxy(x, y - 1);
	cout << "����";
	gotoxy(x, y );
	cout << "����";
	gotoxy(x, y + 1);
	cout << "����";

	key = 0;
	x -= 2;
	y -= 1;
	command = 1;
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
	MusicType mTemp;
	mTemp.SetName((*itor2).GetName());
	switch (command)
	{
	case 1:
		m_List.Get(mTemp);
		system("cls");
		cout << "\n\n";
		mTemp.DisplayRecordOnScreen();
		if (!(mTemp.SoundSong()))
		{
			cout << "\n\t";
			system("pause");
		}
		break;
	case 2:
		m_List.Get(mTemp);
		m_List.Delete(mTemp);
		m_abList.Delete(mTemp);
		m_atList.Delete(mTemp);
		m_gList.Delete(mTemp);
		gotoxy(11, m_GenreMusicList.GetLength() + 8);
		cout << "������ �Ϸ�Ǿ����ϴ�." << endl << endl << "\t";
		system("pause");
		break;
	case 3:
		m_List.Get(mTemp);
		m_List.Delete(mTemp);
		m_abList.Delete(mTemp);
		m_atList.Delete(mTemp);
		m_gList.Delete(mTemp);
		gotoxy(10, m_GenreMusicList.GetLength() + 8);
		cout << "������ ������ �Է����ּ���." << endl;
		mTemp.SetRecordFromKB();		// ������ ���ϴ� ���� �Է¹ޱ�
		m_List.Add(mTemp);
		m_abList.Add(mTemp);
		m_atList.Add(mTemp);
		m_gList.Add(mTemp);
		cout << "\n\t������ �Ϸ�Ǿ����ϴ�." << endl << endl << "\t";
		system("pause");
	}
}

int GenreType::GetLength()
{
	return m_GenreMusicList.GetLength();
}

bool GenreType::operator== (GenreType obj)
{
	if (this->m_GenreId == obj.GetId()) return true;
	else return false;

}
bool GenreType::operator> (GenreType obj)
{
	if (this->m_GenreId > obj.GetId()) return true;
	else return false;

}
bool GenreType::operator< (GenreType obj)
{
	if (this->m_GenreId < obj.GetId()) return true;
	else return false;

}
bool GenreType::operator>= (GenreType obj)
{
	if (this->m_GenreId >= obj.GetId()) return true;
	else return false;

}
bool GenreType::operator<= (GenreType obj)
{
	if (this->m_GenreId <= obj.GetId()) return true;
	else return false;

}

void GenreType::gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}