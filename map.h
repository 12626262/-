#pragma once
extern char map[25][80];


//������˫����ʵ�ֻ��治��˸���������Ǻ���ֻ����ʾһ�����飬û��ʹ��
//HANDLE hOutput, hOutBuf;//����̨��Ļ���������  ������������������
//COORD coord = { 0,0 };
////˫���崦����ʾ
//DWORD bytes = 0;
//hOutBuf = CreateConsoleScreenBuffer(
//	GENERIC_WRITE,//������̿�����������д����
//	FILE_SHARE_WRITE,//���建�����ɹ���дȨ��
//	NULL,
//	CONSOLE_TEXTMODE_BUFFER,
//	NULL
//);
//hOutput = CreateConsoleScreenBuffer(
//	GENERIC_WRITE,//������̿�����������д����
//	FILE_SHARE_WRITE,//���建�����ɹ���дȨ��
//	NULL,
//	CONSOLE_TEXTMODE_BUFFER,
//	NULL
//);
////���������������Ĺ��
//CONSOLE_CURSOR_INFO cci;                //������д�뻺��������ʾ  y�������꣬����79�Ǻ�����
//cci.bVisible = 0;
//cci.dwSize = 1;
//SetConsoleCursorInfo(hOutput, &cci);
//SetConsoleCursorInfo(hOutBuf, &cci);
//for (int i = 0; i < 25; i++)
//{
//	coord.Y = i;
//	WriteConsoleOutputCharacterA(hOutBuf, map[i], 79, coord, &bytes);
//}
////�����µĻ�����Ϊ���ʾ����
//SetConsoleActiveScreenBuffer(hOutBuf);
//Sleep(100);
//for (int i = 0; i < 25; i++)
//{
//	coord.Y = i;
//	WriteConsoleOutputCharacterA(hOutput, map[i], 79, coord, &bytes);
//}
////�����µĻ�����Ϊ���ʾ����
//SetConsoleActiveScreenBuffer(hOutput);
//Sleep(100);