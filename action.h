#pragma once
#include<iostream>
#include <Windows.h>
#include"map.h"

int f_x, f_y;//ʳ�������
int w_x, w_y;  //ǽ����
int speed=100;    //�ٶ� Ĭ��Ϊ100
int score;      //����

void gotoxy(int x, int y)//����ƶ���x,y����ʼ���������֮���������Ϣ���������������Բ��������˸
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle, pos);
}

void HideCursor()//���ع��
{
	CONSOLE_CURSOR_INFO curInfo; //��������Ϣ�Ľṹ�����
	curInfo.dwSize = 1; //���û��ֵ�Ļ������������Ч
	curInfo.bVisible = FALSE; //���������Ϊ���ɼ�
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); //��ȡ����̨���
	SetConsoleCursorInfo(handle, &curInfo); //���ù����Ϣ
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
		std::cout << "ʲô���ѵ�����Ǵ�˵�е���ţ�" << std::endl; 
		gotoxy(0,26); system("pause");return 1;
	}
	return 0;
}
