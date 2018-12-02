/**
*	@mainpage	Array list.
*				This is a simple example of Lab01 on data structures course.<br>
*
*				- Doxygen GUI ������<br>
*				Step 1: Doxygen ���� ����ȭ �� ������Ʈ ��� ����.<br>
*				Step 2: Wizard �ǿ��� Project name ����.<br>
*				Step 3: Wizard �ǿ��� Source code directory �� ����ȭ �� �ҽ� ��� ���� �� Scan recursively �� üũ.
*						[Step 1] �� ��ο� ���� ��θ� �����ص� ��.<br>
*				Step 4: Destination directory �� ����ȭ�� �����Ͱ� ����� ��� ����.<br>
*				Step 5: Wizard ���� Output ���� LaTeX üũ ����.<br>
*				Step 6: Run ���� Run doxygen ���� ��, "Doxygen has finished" Ȯ��.<br>
*
*				- �ѱۻ���� ���ؼ��� Doxywizard���� �Ʒ��� ���� ������ ��.<br>
*				Expert �� -> Input (Topics ���� ����) -> INPUT_ENCODING �� "EUC-KR" �� ����.
*
*	@date	2018.09.12
*	@author	�̱�ȣ
*/
#include "Application.h"



/**
*	program main function for data structures course.
*/
int main()
{
	static HANDLE hOut;
	CONSOLE_CURSOR_INFO cInfo;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	cInfo.dwSize = 1;
	cInfo.bVisible = FALSE;
	SetConsoleCursorInfo(hOut, &cInfo);		// �ܼ� ������ ���ֱ�

	Application app;	// Program application
	app.FirstRun();			// run program

	return 0;
}