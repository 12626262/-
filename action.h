#pragma once
#include<iostream>
#include <Windows.h>
#include"map.h"

int f_x, f_y;//食物的坐标
int w_x, w_y;  //墙坐标
int speed=100;    //速度 默认为100
int score;      //分数

void gotoxy(int x, int y)//光标移动到x,y出开始输出，覆盖之后输出的信息而不是清屏。所以不会觉得闪烁
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle, pos);
}

void HideCursor()//隐藏光标
{
	CONSOLE_CURSOR_INFO curInfo; //定义光标信息的结构体变量
	curInfo.dwSize = 1; //如果没赋值的话，光标隐藏无效
	curInfo.bVisible = FALSE; //将光标设置为不可见
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); //获取控制台句柄
	SetConsoleCursorInfo(handle, &curInfo); //设置光标信息
}
void food() {
	srand(time(nullptr));
	f_x = rand() % 24; if (f_x == 0)f_x++;
	f_y = rand() % 78; if (f_y == 0)f_y++;
	if (map[f_x][f_y] == '#')food();
	map[f_x][f_y] = '&';
}
void wall() {
	int notch_x = 0,notch_y=0;
	int s_x = rand() % 5; int s_y = rand() % 8;
	srand(time(nullptr));
	w_x = rand() % (24-s_x); if (w_x == 0)w_x++;
	w_y = rand() % (78-s_y); if (w_y == 0)w_y++;
	notch_x = rand() % 20; if (notch_x == 0)w_x++;
	notch_y = rand() % 73; if (notch_y == 0)w_y++;
	for (int i = 0; i <= s_x; i++) {
		map[w_x + i][w_y] = '#';
	}
	for (int i = 0; i <= s_y; i++) {
		map[w_x ][w_y+i] = '#';
	}
	map[notch_x][0] = ' ';
	map[notch_x][78] = ' ';
	map[0][notch_y] = ' ';
	map[24][notch_y] = ' ';
}

void victory() {
	for (int i = 1; i < 24; i++) {
		for (int j = 1; j < 78; j++) {
			if (map[i][j] != '#' && map[i][j] != '*')map[i][j] = '+';
		}
	}
	score = 999999;
}

int end() {
	if (score > 60) {
		gotoxy(25,12);
		std::cout << "什么！难道你就是传说中的天才！" << std::endl; 
		gotoxy(0,26); system("pause");return 1;
	}
	return 0;
}
