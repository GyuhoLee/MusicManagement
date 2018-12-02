#ifndef _SORTEDARRAYLIST_H
#define _SORTEDARRAYLIST_H

template <typename T>
class SortedArrayList
{
public:
	/**
	*	@brief	default constructor.
	*/
	SortedArrayList()
	{
	   m_Length = 0;
	   ResetList();
	   m_Array = new T;
	}
	
	/**
	*	@brief	destructor.
	*/
	~SortedArrayList()
	{ 
	   if (m_Length <= 1 && m_Array != NULL)
	      delete m_Array;
	   else if (m_Array != NULL)
	      delete[] m_Array;
	}

	/**
	*	@brief	Make list empty.
	*	@pre	none.
	*	@post	clear list.
	*/
	void MakeEmpty();

	/**
	*	@brief	Get a number of records in current list.
	*	@pre	none.
	*	@post	none.
	*	@return	number of records in current list.
	*/
	int GetLength();

	/**
	*	@brief	add a new data into list.
	*	@pre	list should be initialized.
	*	@post	added the new record into the list.
	*	@param	data   new data.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int Add(T data);

	/**
	*	@brief	Initialize list iterator.
	*	@pre	list should be initialized.
	*	@post	iterator is reset.
	*/
	void ResetList();

	/**
	*	@brief	move list iterator to the next item in list and get that item.
	*	@pre	list and list iterator should not be initialized.
	*	@post	iterator is moved to next item.
	*	@param	data   get current iterator's item. it does not need to be initialized.
	*	@return	index of current iterator's item if is not end of list, oterwise return -1.
	*/
	int GetNextItem(T*& data);

	/**
	*	@brief	move list iterator to the previous item in list and get that item.
	*	@pre	list and list iterator should not be initialized.
	*	@post	iterator is moved to previous item.
	*	@param	data   get current iterator's item. it does not need to be initialized.
	*	@return	index of current iterator's item if is not first of list, oterwise return -1.
	*/
	int GetPreItem(T*& data);

	/**
	*	@brief	item을 찾아서 해당 item을 반환한다.
	*	@pre	인수 data에 있는 id가 list 내에 존재하는 값이어야 한다.
	*	@post	list 내에서 찾은 item이 data에 입력된다.
	*	@param	data   찾고자 하는 id가 입력된 T값. 발견한 item이 리턴된다.
	*	@return	성공(발견)시 1, 실패시 0을 리턴한다.
	*/
	int Get(T& data);

	/**
	*	@brief	id가 일치하는 item을 찾아서 해당 item을 제거한다.
	*	@pre	인수 data에 있는 id가 list 내에 존재하는 값이어야 한다.
	*	@post	list 내에 해당 item이 제거된다.
	*	@param	data   제거하고자 하는 id가 입력된 T값.
	*	@return	성공시 1, 실패시 0을 리턴한다.
	*/
	int Delete(T data);

	/**
	*	@brief	이진탐색을 통해 id가 일치하는 list내 item을 찾아서 반환한다.
	*   @pre	없음.
	*   @post	배열 내에 넘겨받은 item과 id가 일치하는 값을 찾아서 data로 반환된다.
	*   @param	data   찾고자 하는 id가 입력된 T값.
	*   @return	성공(발견)시 1, 실패시 0을 리턴한다.
	*/
	int GetBinarySearch(T& data);

	/**
	*	@brief 배열이 추가 삭제 될때 마다 길이를 바꾸어줌
	*/
	T* ResizeArray(T* data);

	/**
	*	@brief	m_Array을 반환하기 위한 함수
	*	@pre	m_Array의 초기화
	*	@return	m_Array
	*/
	T* GetArray() { return m_Array; }

private:
   T* m_Array;            ///배열의 첫부분
   int m_Length;            ///배열의 길이
   int m_CurPointer;         ///현재 위치의 인덱스
};



//배열을 비우는 함수
template <typename T>
void SortedArrayList<T>::MakeEmpty()
{
   m_Length = 0;
}


//길이를 반환
template <typename T>
int SortedArrayList<T>::GetLength()
{
   return m_Length;
}



//크기에 따라 정렬 되도록 추가
template <typename T>
int SortedArrayList<T>::Add(T inData)
{
   T* CurItem;
   ResetList();
   GetNextItem(CurItem);

   if (m_Length == 0)
   {
      m_Array[m_CurPointer] = inData;   //처음 위치에 삽입
      ++m_Length;
      return 1;
   }
   while (m_CurPointer <= m_Length) //처음부터 끝까지
   {
      if (inData < *CurItem || m_CurPointer == m_Length)   //만약 CurItem>inData일경우 혹은 배열의 마지막이라서 비교대상이 없는경우
      {
         ++m_Length;
         m_Array = ResizeArray(m_Array);
         for (int i = m_Length-1; i>m_CurPointer; i--)   //맨뒤에서 부터 하나씩 땡긴다.
            m_Array[i] = m_Array[i - 1];   //배열 밀기
         m_Array[m_CurPointer] = inData;   //배열 밀은 후 현재 포인터에 아이템 넣는다.
         break;
      }
      GetNextItem(CurItem);   //다음아이템으로
   }
   return 1;
}


//인덱스를 초기화시킨다.
template <typename T>
void SortedArrayList<T>::ResetList()
{
   m_CurPointer = -1;
}


//다음인덱스로 이동하고 해당 인덱스의 데이터를 돌려주고 인덱스 반환
template <typename T>
int SortedArrayList<T>::GetNextItem(T*& data)
{
   m_CurPointer++;   // list pointer 증가
   if (m_CurPointer == m_Length && m_Length != 0)   // end of list이면 -1을 리턴
      return -1;
   data = &m_Array[m_CurPointer];   // 현재 list pointer의 레코드를 복사

   return m_CurPointer;
}

//이전인덱스로 이동하고 해당 인덱스의 데이터를 돌려주고 인덱스 반환
template <typename T>
int SortedArrayList<T>::GetPreItem(T*& data)
{
	m_CurPointer--;   // list pointer 감소
	if (m_CurPointer == -1 && m_Length != 0)   // end of list이면 -1을 리턴
		return -1;
	data = &m_Array[m_CurPointer];   // 현재 list pointer의 레코드를 복사

	return m_CurPointer;
}

//data가 배열속에 있는 지 확인
template <typename T>
int SortedArrayList<T>::Get(T& data)
{
   T* CurItem;

   ResetList();   //iterator 초기화
   GetNextItem(CurItem);   //첫아이템 가져옴
   while (m_CurPointer < m_Length)   //처음부터 끝까지
   {
      if (*CurItem == data)//일치하면
      {
         data = *CurItem;//data에 현재 아이템을 반환
		 return 1;
      }
      else if(data <   *CurItem)//현재 아이템의 id가 더 크면(정렬되있으므로 나머지에 찾는게 없다)
         return 0;   //실패(0)을 리턴
      else
      {
         GetNextItem(CurItem);   //다음 아이템을 가져온다.(계속 탐색)
      }
   }
   return 0; //실패시0
}

//해당 키워드를 가지고있으면 삭제
template <typename T>
int SortedArrayList<T>::Delete(T data)
{
   if (Get(data))   //id가 일치하는 item을 발견한다면(1)
   {
      for (int i = m_CurPointer; i < m_Length; i++)   //현재 포인터부터 입력된 배열 끝까지 반복
         m_Array[i] = m_Array[i + 1];   //배열 뒤에걸 앞으로 하나씩 땡김
      m_Length--;   //아이템 개수를 하나 줄임
      m_Array = ResizeArray(m_Array); //배열의 크기를 줄여줌
      return 1;   //성공(1)을 리턴
   }
   return 0;   //id일치하는 item을 찾지 못한다면 실패(0)을 리턴
}


//이진탐색을 하여 data와 일치하는 값을 찾아낸다.
template <typename T>
int SortedArrayList<T>::GetBinarySearch(T& data)
{
   if (m_Length == 0)   //만약 배열이 비었다면
      return 0;   //실패(0)을 리턴
   int currentPos = m_Length / 2;   //배열의 중간부터 시작
   while (1)
   {
      if (m_Array[currentPos] == data)   //현재 아이템과 입력 아이템의 id가 일치한다면
      {
         data = m_Array[currentPos];   //data에 발견한 값을 리턴
         return 1;   //성공(1)을 리턴
      }
      else if (data < m_Array[currentPos])//현재 아이템의 id가 입력 아이템의 id보다 크다면
      {
         if (currentPos == 0)   //처음 배열의 값보다 작은경우
            return 0;   //실패(0)을 리턴
         currentPos /= 2;   //더 작은쪽 인덱스의 절반로 이동
      }
      else if (m_Array[currentPos] < data)//현재 아이템의 id가 입력 아이템의 id보다 작다면
      {
         if (currentPos == m_Length - 1)   //마지막 배열의 값보다 큰경우
            return 0;   //실패(0)을 리턴
         currentPos = (currentPos + m_Length) / 2;   //더 큰쪽 인덱스의 절반으로 이동
      }
   }
   return 0;   //호출될 일 없는 리턴(WARNING 방지용)
}

//배열의 크기를 조정한다.
template <typename T>
T* SortedArrayList<T>::ResizeArray(T* data)
{
   T* resize = new T[m_Length];

   for (int i = 0; i < m_Length-1; i++)
   {
      resize[i] = data[i];
   }
   if (m_Length <= 2)
      delete data;
   else
      delete[] data;
   data = resize;

   return data;
}

#endif