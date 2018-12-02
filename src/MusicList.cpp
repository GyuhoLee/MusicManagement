#include "MusicList.h"

// Make list empty.
void MusicList::MakeEmpty()
{
	m_Array.MakeEmpty();
}


// Get a number of records in current list.
int MusicList::GetLength()
{
	return m_Array.GetLength();
}



// 리스트가 비어있는지 확인
int MusicList::IsEmpty()
{
	if (m_Array.GetLength() == 0)
		return 1;
	else
		return 0;
}


// add a new data into list.
int MusicList::Add(MusicType inData)
{
	if (FindType(inData) == 1)	//ID가 중복일시
		return 0;			// 0을 반환
	m_Array.insert(inData);
	return 1;
}

// 곡번호를 기준으로 데이터를 검색하고 해당 데이터를 가져옴
int MusicList::Get(MusicType& data)
{
	MusicType* temp = new MusicType;
	bool found = m_Array.Retrieve(data, temp);
	data = *temp;
	if (found)
		return 1;
	else
		return 0;
}

// 곡번호를 기준으로 데이터를 검색하고 해당 데이터를 가져옴
int MusicList::FindType(MusicType data)
{
	MusicType* temp = new MusicType;
	bool found = m_Array.Retrieve(data, temp);
	if (found)
		return 1;
	else
		return 0;
}


// 기존 레코드 삭제
int MusicList::Delete(MusicType& data)
{
	return m_Array.erase(data);
}


// 기존 레코드 갱신
int MusicList::Replace(MusicType &data)
{
	MusicType* inTemp;
	bool found = m_Array.Retrieve(data, inTemp);
	if (found)
	{
		m_Array.erase(*inTemp);
		m_Array.insert(data);
		return true;
	}
	else return false;
}


// SearchType에 따라 검색 후 입력한 문자열을 포함하고 있는 정보 출력
int MusicList::Search(string sTerm, SearchType sType)
{
	int have = 0;
	if (GetLength() == 0) return 0;
	RBIterator<MusicType> itor(m_Array);
	itor.GoLeft();
	int count = m_Array.GetLength();
	switch (sType)
	{
	case 0:
		while(count--)	//RBT를 순차검색한다.
		{
			size_t pos;
			if (pos = (*itor).GetName().find(sTerm, 0) != string::npos)
			{
				(*itor).DisplayRecordOnScreen();
				have = 1;
			}
			if (count != 0) itor.GetNextNode();
		}
		break;
	case 1:
		while(count--)	//RBT를 순차검색한다.
		{
			size_t pos;
			if (pos = (*itor).GetArtist().find(sTerm, 0) != string::npos)
			{
				(*itor).DisplayRecordOnScreen();
				have = 1;
			}
			if (count != 0) itor.GetNextNode();
		}
		break;
	case 2:
		while(count--)	//RBT를 순차검색한다.
		{
			size_t pos;
			if (pos = (*itor).GetAlbum().find(sTerm, 0) != string::npos)
			{
				(*itor).DisplayRecordOnScreen();
				have = 1;
			}
			if (count != 0) itor.GetNextNode();
		}
		break;
	case 3:
		while(count--)	//RBT를 순차검색한다.
		{
			size_t pos;
			if (pos = (*itor).GetComposer().find(sTerm, 0) != string::npos)
			{
				(*itor).DisplayRecordOnScreen();
				have = 1;
			}
			if (count != 0) itor.GetNextNode();
		}
		break;
	case 4:
		while(count--)	//RBT를 순차검색한다.
		{
			size_t pos;
			if (pos = (*itor).GetLyricist().find(sTerm, 0) != string::npos)
			{
				(*itor).DisplayRecordOnScreen();
				have = 1;
			}
			if (count != 0) itor.GetNextNode();
		}
		break;
	case 5:
		while(count--)	//RBT를 순차검색한다.
		{
			size_t pos;
			if (pos = (*itor).GetAgency().find(sTerm, 0) != string::npos)
			{
				(*itor).DisplayRecordOnScreen();
				have = 1;
			}
			if (count != 0) itor.GetNextNode();
		}
		break;
	default:
		cout << "\t::Search Type Error::" << endl;
		break;
	}
	return have;
}

// 곡명과 장르가 검색한 내용과 일치하는 음악을 출력

void MusicList::DisplayRetrieveNameNGenre(string inName, string inGenre)
{
	RBIterator<MusicType> itor(m_Array);
	itor.GoLeft();
	int count = m_Array.GetLength();
	while (count--)	//RBT를 순차검색한다.
	{
		if ((*itor).GetName().compare(inName) == 0 && (*itor).GetGenre().compare(inGenre) == 0)
		{
			(*itor).DisplayRecordOnScreen();
		}
		if (count != 0) itor.GetNextNode();
	}
}

RedBlackTree<MusicType> MusicList::GetArray()
{
	return m_Array;
}