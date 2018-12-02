#pragma once
#ifndef _SIMPLEMUSICTYPE_H
#define _SIMPLEMUSICTYPE_H

#include <iostream>
#include <string>
#include <Windows.h>
#include <mmsystem.h>

using namespace std;

/**
*	@brief music simple information type.
*/
class SimpleMusicType
{
public:

	/**
	*	default constructor.
	*/
	SimpleMusicType()
	{
		m_Number = -1;
		m_Name = "";
	}

	/**
	*	destructor.
	*/
	~SimpleMusicType() {}

	/**
	*	@brief	Get music number.
	*	@pre	music number is set.
	*	@post	none.
	*	@return music number.
	*/
	int GetNumber()
	{
		return m_Number;
	}

	/**
	*	@brief	Get music name.
	*	@pre	music name is set.
	*	@post	none.
	*	@return music name.
	*/
	string GetName()
	{
		return m_Name;
	}

	/**
	*	@brief	Set music number.
	*	@pre	none.
	*	@post	music number is set.
	*	@param	inNumber	music number.
	*/
	void SetNumber(int inNumber)
	{
		m_Number = inNumber;
	}

	/**
	*	@brief	Set music Name.
	*	@pre	none.
	*	@post	music name is set.
	*	@param	inName	music name.
	*/
	void SetName(string inName)
	{
		m_Name = inName;
	}

	/**
	*	@brief	Set music record.
	*	@pre	none.
	*	@post	music record is set.
	*	@param	inNumber	music number.
	*	@param	inName		music name.
	*/
	void SetRecord(int inNumber, string inName)
	{
		SetNumber(inNumber);
		SetName(inName);
	}

	/**
	*	@brief	Display an music record on screen.
	*	@pre	music record is set.
	*	@post	music record is on screen.
	*/
	void DisplayRecordOnScreen()
	{
		cout << "\t   번호 : " << m_Number << "\t곡명 : " << m_Name << endl;
	}

	/**
	*	@brief	입력한 MusicType형 클래스의 멤버 변수들을 복사
	*	@pre	none.
	*	@oost	this에 para의 데이터를 복사
	*	@param	복사하고 싶은 Data
	*/
	void CopyRecord(SimpleMusicType data)
	{
		SetRecord(data.GetNumber(), data.GetName());
	}

	// complete operation overloadings...
	void operator=(const SimpleMusicType &obj)
	{
		CopyRecord(obj);
	}

	bool operator==(SimpleMusicType obj)
	{
		if (this->GetName().compare(obj.GetName()) == 0) return true;
		else return false;
	}

	bool operator!=(SimpleMusicType obj)
	{
		if (this->GetName().compare(obj.GetName()) != 0) return true;
		else return false;
	}

	bool operator<(SimpleMusicType obj)
	{
		if (this->GetName().compare(obj.GetName()) < 0) return true;
		else return false;
	}

	bool operator>(SimpleMusicType obj)
	{
		if (this->GetName().compare(obj.GetName()) > 0) return true;
		else return false;
	}

	bool operator<=(SimpleMusicType obj)
	{
		if (this->GetName().compare(obj.GetName()) <= 0) return true;
		else return false;
	}

	bool operator>=(SimpleMusicType obj)
	{
		if (this->GetName().compare(obj.GetName()) >= 0) return true;
		else return false;
	}

private:
	int m_Number;		///< primary key.
	string m_Name;		///< music name.
};

#endif