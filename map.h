#pragma once
extern char map[25][80];


//下面是双缓冲实现画面不闪烁方法，但是好像只能显示一个数组，没有使用
//HANDLE hOutput, hOutBuf;//控制台屏幕缓冲区句柄  创建两个缓冲区对象
//COORD coord = { 0,0 };
////双缓冲处理显示
//DWORD bytes = 0;
//hOutBuf = CreateConsoleScreenBuffer(
//	GENERIC_WRITE,//定义进程可以往缓冲区写数据
//	FILE_SHARE_WRITE,//定义缓冲区可共享写权限
//	NULL,
//	CONSOLE_TEXTMODE_BUFFER,
//	NULL
//);
//hOutput = CreateConsoleScreenBuffer(
//	GENERIC_WRITE,//定义进程可以往缓冲区写数据
//	FILE_SHARE_WRITE,//定义缓冲区可共享写权限
//	NULL,
//	CONSOLE_TEXTMODE_BUFFER,
//	NULL
//);
////隐藏两个缓冲区的光标
//CONSOLE_CURSOR_INFO cci;                //将数组写入缓冲区并显示  y是纵坐标，后面79是横坐标
//cci.bVisible = 0;
//cci.dwSize = 1;
//SetConsoleCursorInfo(hOutput, &cci);
//SetConsoleCursorInfo(hOutBuf, &cci);
//for (int i = 0; i < 25; i++)
//{
//	coord.Y = i;
//	WriteConsoleOutputCharacterA(hOutBuf, map[i], 79, coord, &bytes);
//}
////设置新的缓冲区为活动显示缓冲
//SetConsoleActiveScreenBuffer(hOutBuf);
//Sleep(100);
//for (int i = 0; i < 25; i++)
//{
//	coord.Y = i;
//	WriteConsoleOutputCharacterA(hOutput, map[i], 79, coord, &bytes);
//}
////设置新的缓冲区为活动显示缓冲
//SetConsoleActiveScreenBuffer(hOutput);
//Sleep(100);