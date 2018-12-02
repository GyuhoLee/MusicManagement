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
	*	@brief	item�� ã�Ƽ� �ش� item�� ��ȯ�Ѵ�.
	*	@pre	�μ� data�� �ִ� id�� list ���� �����ϴ� ���̾�� �Ѵ�.
	*	@post	list ������ ã�� item�� data�� �Էµȴ�.
	*	@param	data   ã���� �ϴ� id�� �Էµ� T��. �߰��� item�� ���ϵȴ�.
	*	@return	����(�߰�)�� 1, ���н� 0�� �����Ѵ�.
	*/
	int Get(T& data);

	/**
	*	@brief	id�� ��ġ�ϴ� item�� ã�Ƽ� �ش� item�� �����Ѵ�.
	*	@pre	�μ� data�� �ִ� id�� list ���� �����ϴ� ���̾�� �Ѵ�.
	*	@post	list ���� �ش� item�� ���ŵȴ�.
	*	@param	data   �����ϰ��� �ϴ� id�� �Էµ� T��.
	*	@return	������ 1, ���н� 0�� �����Ѵ�.
	*/
	int Delete(T data);

	/**
	*	@brief	����Ž���� ���� id�� ��ġ�ϴ� list�� item�� ã�Ƽ� ��ȯ�Ѵ�.
	*   @pre	����.
	*   @post	�迭 ���� �Ѱܹ��� item�� id�� ��ġ�ϴ� ���� ã�Ƽ� data�� ��ȯ�ȴ�.
	*   @param	data   ã���� �ϴ� id�� �Էµ� T��.
	*   @return	����(�߰�)�� 1, ���н� 0�� �����Ѵ�.
	*/
	int GetBinarySearch(T& data);

	/**
	*	@brief �迭�� �߰� ���� �ɶ� ���� ���̸� �ٲپ���
	*/
	T* ResizeArray(T* data);

	/**
	*	@brief	m_Array�� ��ȯ�ϱ� ���� �Լ�
	*	@pre	m_Array�� �ʱ�ȭ
	*	@return	m_Array
	*/
	T* GetArray() { return m_Array; }

private:
   T* m_Array;            ///�迭�� ù�κ�
   int m_Length;            ///�迭�� ����
   int m_CurPointer;         ///���� ��ġ�� �ε���
};



//�迭�� ���� �Լ�
template <typename T>
void SortedArrayList<T>::MakeEmpty()
{
   m_Length = 0;
}


//���̸� ��ȯ
template <typename T>
int SortedArrayList<T>::GetLength()
{
   return m_Length;
}



//ũ�⿡ ���� ���� �ǵ��� �߰�
template <typename T>
int SortedArrayList<T>::Add(T inData)
{
   T* CurItem;
   ResetList();
   GetNextItem(CurItem);

   if (m_Length == 0)
   {
      m_Array[m_CurPointer] = inData;   //ó�� ��ġ�� ����
      ++m_Length;
      return 1;
   }
   while (m_CurPointer <= m_Length) //ó������ ������
   {
      if (inData < *CurItem || m_CurPointer == m_Length)   //���� CurItem>inData�ϰ�� Ȥ�� �迭�� �������̶� �񱳴���� ���°��
      {
         ++m_Length;
         m_Array = ResizeArray(m_Array);
         for (int i = m_Length-1; i>m_CurPointer; i--)   //�ǵڿ��� ���� �ϳ��� �����.
            m_Array[i] = m_Array[i - 1];   //�迭 �б�
         m_Array[m_CurPointer] = inData;   //�迭 ���� �� ���� �����Ϳ� ������ �ִ´�.
         break;
      }
      GetNextItem(CurItem);   //��������������
   }
   return 1;
}


//�ε����� �ʱ�ȭ��Ų��.
template <typename T>
void SortedArrayList<T>::ResetList()
{
   m_CurPointer = -1;
}


//�����ε����� �̵��ϰ� �ش� �ε����� �����͸� �����ְ� �ε��� ��ȯ
template <typename T>
int SortedArrayList<T>::GetNextItem(T*& data)
{
   m_CurPointer++;   // list pointer ����
   if (m_CurPointer == m_Length && m_Length != 0)   // end of list�̸� -1�� ����
      return -1;
   data = &m_Array[m_CurPointer];   // ���� list pointer�� ���ڵ带 ����

   return m_CurPointer;
}

//�����ε����� �̵��ϰ� �ش� �ε����� �����͸� �����ְ� �ε��� ��ȯ
template <typename T>
int SortedArrayList<T>::GetPreItem(T*& data)
{
	m_CurPointer--;   // list pointer ����
	if (m_CurPointer == -1 && m_Length != 0)   // end of list�̸� -1�� ����
		return -1;
	data = &m_Array[m_CurPointer];   // ���� list pointer�� ���ڵ带 ����

	return m_CurPointer;
}

//data�� �迭�ӿ� �ִ� �� Ȯ��
template <typename T>
int SortedArrayList<T>::Get(T& data)
{
   T* CurItem;

   ResetList();   //iterator �ʱ�ȭ
   GetNextItem(CurItem);   //ù������ ������
   while (m_CurPointer < m_Length)   //ó������ ������
   {
      if (*CurItem == data)//��ġ�ϸ�
      {
         data = *CurItem;//data�� ���� �������� ��ȯ
		 return 1;
      }
      else if(data <   *CurItem)//���� �������� id�� �� ũ��(���ĵ������Ƿ� �������� ã�°� ����)
         return 0;   //����(0)�� ����
      else
      {
         GetNextItem(CurItem);   //���� �������� �����´�.(��� Ž��)
      }
   }
   return 0; //���н�0
}

//�ش� Ű���带 ������������ ����
template <typename T>
int SortedArrayList<T>::Delete(T data)
{
   if (Get(data))   //id�� ��ġ�ϴ� item�� �߰��Ѵٸ�(1)
   {
      for (int i = m_CurPointer; i < m_Length; i++)   //���� �����ͺ��� �Էµ� �迭 ������ �ݺ�
         m_Array[i] = m_Array[i + 1];   //�迭 �ڿ��� ������ �ϳ��� ����
      m_Length--;   //������ ������ �ϳ� ����
      m_Array = ResizeArray(m_Array); //�迭�� ũ�⸦ �ٿ���
      return 1;   //����(1)�� ����
   }
   return 0;   //id��ġ�ϴ� item�� ã�� ���Ѵٸ� ����(0)�� ����
}


//����Ž���� �Ͽ� data�� ��ġ�ϴ� ���� ã�Ƴ���.
template <typename T>
int SortedArrayList<T>::GetBinarySearch(T& data)
{
   if (m_Length == 0)   //���� �迭�� ����ٸ�
      return 0;   //����(0)�� ����
   int currentPos = m_Length / 2;   //�迭�� �߰����� ����
   while (1)
   {
      if (m_Array[currentPos] == data)   //���� �����۰� �Է� �������� id�� ��ġ�Ѵٸ�
      {
         data = m_Array[currentPos];   //data�� �߰��� ���� ����
         return 1;   //����(1)�� ����
      }
      else if (data < m_Array[currentPos])//���� �������� id�� �Է� �������� id���� ũ�ٸ�
      {
         if (currentPos == 0)   //ó�� �迭�� ������ �������
            return 0;   //����(0)�� ����
         currentPos /= 2;   //�� ������ �ε����� ���ݷ� �̵�
      }
      else if (m_Array[currentPos] < data)//���� �������� id�� �Է� �������� id���� �۴ٸ�
      {
         if (currentPos == m_Length - 1)   //������ �迭�� ������ ū���
            return 0;   //����(0)�� ����
         currentPos = (currentPos + m_Length) / 2;   //�� ū�� �ε����� �������� �̵�
      }
   }
   return 0;   //ȣ��� �� ���� ����(WARNING ������)
}

//�迭�� ũ�⸦ �����Ѵ�.
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