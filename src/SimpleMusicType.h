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
		cout << "\t   ��ȣ : " << m_Number << "\t��� : " << m_Name << endl;
	}

	/**
	*	@brief	�Է��� MusicType�� Ŭ������ ��� �������� ����
	*	@pre	none.
	*	@oost	this�� para�� �����͸� ����
	*	@param	�����ϰ� ���� Data
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