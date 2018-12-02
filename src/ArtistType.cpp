#include "ArtistType.h"
#include "ArtistList.h"
#include "MusicList.h"
#include "AlbumList.h"
#include "GenreList.h"

void ArtistType::SetInfo(string inArtist, string inAgency)
{
	m_Artist = inArtist;
	m_Agency = inAgency;
}

void ArtistType::DisplayAllMusicInArtist()
{
	cout << "\n\n\n";
	RBIterator<SimpleMusicType> itor(m_ArtistMusicList);
	itor.GoLeft();
	int count = m_ArtistMusicList.GetLength();
	while (count--)	//RBT�� �����˻��Ѵ�.
	{
		(*itor).DisplayRecordOnScreen();
		if (count != 0) itor.GetNextNode();
	}
	SoundRepresentSong();
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
			if (command != m_ArtistMusicList.GetLength() + 1)
			{
				gotoxy(x, y);
				cout << "  ";
				command++;
				y++;
			}
			break;
		}
	}
	if (command == m_ArtistMusicList.GetLength() + 1) return;

	RBIterator<SimpleMusicType> itor2(m_ArtistMusicList);
	itor2.GoLeft();
	while (--command)
	{
		itor2.GetNextNode();
	}

	x -= 5;
	gotoxy(x, y - 1);
	cout << "����";
	gotoxy(x, y);
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
		gotoxy(11, m_ArtistMusicList.GetLength() + 8);
		cout << "������ �Ϸ�Ǿ����ϴ�." << endl << endl << "\t";
		system("pause");
		break;
	case 3:
		m_List.Get(mTemp);
		m_List.Delete(mTemp);
		m_abList.Delete(mTemp);
		m_atList.Delete(mTemp);
		m_gList.Delete(mTemp);
		gotoxy(10, m_ArtistMusicList.GetLength() + 8);
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

void ArtistType::DisplayRecordOnScreen()
{
	cout << "  " << setw(15) << m_Artist << "\   -";
	cout << "   " << m_Agency;
}

void ArtistType::AddMusicInArtist(SimpleMusicType inData)
{
	m_ArtistMusicList.insert(inData);
}

void ArtistType::DeleteMusicInArtist(SimpleMusicType inData)
{
	m_ArtistMusicList.erase(inData);
}

void ArtistType::ReplaceMusicInArtist(SimpleMusicType inData)
{
	SimpleMusicType* inTemp;
	bool found = m_ArtistMusicList.Retrieve(inData, inTemp);
	if (found)
	{
		m_ArtistMusicList.erase(*inTemp);
		m_ArtistMusicList.insert(inData);
	}
}

void ArtistType::DisplayMusicDetailInArtist(RedBlackTree<MusicType> *list)
{
	cout << "\n\t���� ���" << endl;

	// list�� ��� �����͸� ȭ�鿡 ���
	int length = m_ArtistMusicList.GetLength();
	int curIndex = 0;
	RBIterator<SimpleMusicType> itor(m_ArtistMusicList);
	itor.GoLeft();
	while (curIndex < length && curIndex != -1)
	{
		cout << curIndex + 1 << endl;
		(*itor).DisplayRecordOnScreen();
		curIndex++;
		itor.GetNextNode();
	}

	//?? SimpleMusicType �� data �� music id �� title ���� ���´�.
	// �ش� �ٹ��� ���ԵǴ� ��� ���� ������ ����ϱ� ���ؼ� �� ������ ������
	// �� �Լ��� �Ķ������ list�� �˻��Ͽ� music information �� ����� �־�� ��.
}

int ArtistType::GetLength()
{
	return m_ArtistMusicList.GetLength();
}

bool ArtistType::operator== (ArtistType obj)
{
	if (this->m_Artist.compare(obj.GetArtistName()) == 0) return true;
	else return false;

}

bool ArtistType::operator!= (ArtistType obj)
{
	if (this->m_Artist.compare(obj.GetArtistName()) != 0) return true;
	else return false;

}

bool ArtistType::operator> (ArtistType obj)
{
	if (this->m_Artist.compare(obj.GetArtistName()) > 0) return true;
	else return false;

}
bool ArtistType::operator< (ArtistType obj)
{
	if (this->m_Artist.compare(obj.GetArtistName()) < 0) return true;
	else return false;

}
bool ArtistType::operator>= (ArtistType obj)
{
	if (this->m_Artist.compare(obj.GetArtistName()) >= 0) return true;
	else return false;

}
bool ArtistType::operator<= (ArtistType obj)
{
	if (this->m_Artist.compare(obj.GetArtistName()) <= 0) return true;
	else return false;

}

void ArtistType::SoundRepresentSong()
{
	string FileTemp = "Artist\\";
	FileTemp.append(m_Artist);
	FileTemp.append(".wav");
	const char *FileName = FileTemp.c_str();
	PlaySound(TEXT(FileName), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	//						������ �� ã�� �� �⺻ �Ҹ� ���
	//							�Ҹ��� �񵿱������� ���(���� ����)
	//								�Ҹ��� �ݺ� ���(ASYNC�� �Բ�)
}

void ArtistType::gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}