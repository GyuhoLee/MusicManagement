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



// ����Ʈ�� ����ִ��� Ȯ��
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
	if (FindType(inData) == 1)	//ID�� �ߺ��Ͻ�
		return 0;			// 0�� ��ȯ
	m_Array.insert(inData);
	return 1;
}

// ���ȣ�� �������� �����͸� �˻��ϰ� �ش� �����͸� ������
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

// ���ȣ�� �������� �����͸� �˻��ϰ� �ش� �����͸� ������
int MusicList::FindType(MusicType data)
{
	MusicType* temp = new MusicType;
	bool found = m_Array.Retrieve(data, temp);
	if (found)
		return 1;
	else
		return 0;
}


// ���� ���ڵ� ����
int MusicList::Delete(MusicType& data)
{
	return m_Array.erase(data);
}


// ���� ���ڵ� ����
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


// SearchType�� ���� �˻� �� �Է��� ���ڿ��� �����ϰ� �ִ� ���� ���
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
		while(count--)	//RBT�� �����˻��Ѵ�.
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
		while(count--)	//RBT�� �����˻��Ѵ�.
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
		while(count--)	//RBT�� �����˻��Ѵ�.
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
		while(count--)	//RBT�� �����˻��Ѵ�.
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
		while(count--)	//RBT�� �����˻��Ѵ�.
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
		while(count--)	//RBT�� �����˻��Ѵ�.
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

// ���� �帣�� �˻��� ����� ��ġ�ϴ� ������ ���

void MusicList::DisplayRetrieveNameNGenre(string inName, string inGenre)
{
	RBIterator<MusicType> itor(m_Array);
	itor.GoLeft();
	int count = m_Array.GetLength();
	while (count--)	//RBT�� �����˻��Ѵ�.
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