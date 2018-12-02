#include "AlbumType.h"
#include "ArtistList.h"
#include "MusicList.h"
#include "AlbumList.h"
#include "GenreList.h"

void AlbumType::SetInfo(string inAlbum, string inArtist, string inAgency)
{
	m_Album = inAlbum;
	m_Artist = inArtist;
	m_Agency = inAgency;
}

void AlbumType::DisplayRecordOnScreen()
{
	cout << "  " << setw(23) << m_Album << "\   -";
	cout << "   " << m_Artist;
}

void AlbumType::DisplayAllMusicInAlbum()
{
	DisplayAlbumCover();
	cout << "\n\n";
	cout << "\t      -----음악 목록-----" << endl;
	DoublyIterator<SimpleMusicType> itor(m_AlbumMusicList);
	itor.Next();
	while (itor.GetCurrentNode() != itor.GetNodeLast())
	{
		itor.GetCurrentNode()->data.DisplayRecordOnScreen();
		itor.Next();
	}
	cout << "\t\t  " << "< 돌아가기 >" << endl;

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
			if (command != m_AlbumMusicList.GetLength() + 1)
			{
				gotoxy(x, y);
				cout << "  ";
				command++;
				y++;
			}
			break;
		}
	}
	if (command == m_AlbumMusicList.GetLength() + 1) return;

	DoublyIterator<SimpleMusicType> itor2(m_AlbumMusicList);
	itor2.Next();
	while (--command)
	{
		itor2.Next();
	}

	x -= 5;
	gotoxy(x, y - 1);
	cout << "보기";
	gotoxy(x, y);
	cout << "삭제";
	gotoxy(x, y + 1);
	cout << "수정";

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
	mTemp.SetName(itor2.GetCurrentNode()->data.GetName());
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
		gotoxy(11, m_AlbumMusicList.GetLength() + 8);
		cout << "삭제가 완료되었습니다." << endl << endl << "\t";
		system("pause");
		break;
	case 3:
		m_List.Get(mTemp);
		m_List.Delete(mTemp);
		m_abList.Delete(mTemp);
		m_atList.Delete(mTemp);
		m_gList.Delete(mTemp);
		gotoxy(10, m_AlbumMusicList.GetLength() + 8);
		cout << "수정할 정보를 입력해주세요." << endl;
		mTemp.SetRecordFromKB();		// 갱신을 원하는 음악 입력받기
		m_List.Add(mTemp);
		m_abList.Add(mTemp);
		m_atList.Add(mTemp);
		m_gList.Add(mTemp);
		cout << "\n\t수정이 완료되었습니다." << endl << endl << "\t";
		system("pause");
	}
}

void AlbumType::AddMusicInAlbum(SimpleMusicType inData)
{
	m_AlbumMusicList.Add(inData);
}

void AlbumType::DeleteMusicInAlbum(SimpleMusicType inData)
{
	m_AlbumMusicList.Delete(inData);
}

void AlbumType::ReplaceMusicInAlbum(SimpleMusicType inData)
{
	m_AlbumMusicList.Replace(inData);
}

void AlbumType::DisplayMusicDetailInAlbum(DoublySortedLinkedList<MusicType> *list)
{	
	SimpleMusicType data;
	cout << "\t음악 목록" << endl;

	// list의 모든 데이터를 화면에 출력
	int length = m_AlbumMusicList.GetLength();
	int curIndex = 0;
	DoublyIterator<SimpleMusicType> itor(m_AlbumMusicList);
	itor.Next();
	while (curIndex < length && curIndex != -1)
	{
		cout << curIndex + 1 << endl;
		data.DisplayRecordOnScreen();
		curIndex++;
		itor.Next();
	}

	//?? SimpleMusicType 인 data 는 music id 와 title 만을 갖는다.
	// 해당 앨범에 포함되는 모든 음악 정보를 출력하기 위해서 이 정보를 가지고
	// 이 함수의 파라미터인 list를 검색하여 music information 을 출력해 주어야 함.
}

int AlbumType::GetLength()
{
	return m_AlbumMusicList.GetLength();
}

bool AlbumType::operator== (AlbumType obj)
{
	if (this->m_Album.compare(obj.GetAlbumName()) == 0) return true;
	else return false;
}

bool AlbumType::operator!= (AlbumType obj)
{
	if (this->m_Album.compare(obj.GetAlbumName()) != 0) return true;
	else return false;
}

bool AlbumType::operator> (AlbumType obj)
{
	if (this->m_Album.compare(obj.GetAlbumName()) > 0) return true;
	else return false;
}

bool AlbumType::operator< (AlbumType obj)
{
	if (this->m_Album.compare(obj.GetAlbumName()) < 0) return true;
	else return false;
}

bool AlbumType::operator>= (AlbumType obj)
{
	if (this->m_Album.compare(obj.GetAlbumName()) >= 0) return true;
	else return false;
}

bool AlbumType::operator<= (AlbumType obj)
{
	if (this->m_Album.compare(obj.GetAlbumName()) <= 0) return true;
	else return false;
}

void AlbumType::DisplayAlbumCover()
{
	char keyInput[10] = "";
	Gdiplus::GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR gdiplusToken = NULL;
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

	string temp = "Image\\" + m_Album + ".jpg";
	wstring widestr = wstring(temp.begin(), temp.end());	//변환 과정
	const wchar_t* widecstr = widestr.c_str();
	Gdiplus::Graphics *pGraphics = new Gdiplus::Graphics(GetDC(GetConsoleWindow()));
	Gdiplus::Image *pImage = pGraphics ? new Gdiplus::Image(widecstr) : NULL;


	if (pImage)
	{
		pGraphics->DrawImage(pImage, 440, 30, pImage->GetWidth() / 5, pImage->GetHeight() / 5);		//그리기
	}
	else
	{
		printf("Error\n");
	}

	//fgets(keyInput, 10, stdin);

	delete pImage;
	delete pGraphics;
	Gdiplus::GdiplusShutdown(gdiplusToken);
}

void AlbumType::gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}