#pragma once
#include<conio.h>
#include"snake.h"
using namespace std;

int main()
{
	cout << "************欢迎来到贪吃蛇！************" << endl;
	cout << "请选择选项"<<endl;
	cout << "1：开始新游戏" << endl;
	cout << "2: 选择难度(默认中等)" << endl;
	cout << "3：查看秘籍" << endl;
	cout << "4：退出游戏" << endl;
	snake* m = new snake(); char key,key_s;
	int chioce;
	cin >> chioce;
	while (1) {
		switch (chioce) {
		case 1:
			m->addbody();
			map[m->head->b_x][m->head->b_y] = m->head->data;
			food();
			wall();
			HideCursor();  //隐藏光标
			m->showmap(); key = getch(); 
			while (1) {
				switch (key) {
				case 'w':
					if (m->move(key) == 1) { map[m->head->b_x][m->head->b_y] = m->head->data; m->showmap(); return 0; }        
					m->showmap();           //显示地图
					m->reward();            //判断是否吃到食物
					if (end() == 1) return 0; key_s = key;
					if (kbhit()) {
						key = getch();
						if (key == 's') { key = 'w'; break; }
						else break;
					}
					break;
				case 'a':
					if (m->move(key) == 1) { map[m->head->b_x][m->head->b_y] = m->head->data; m->showmap(); return 0; }
					m->showmap();
					m->reward();
					if (end() == 1)return 0; key_s = key;
					if (kbhit()) {
						key = getch();
						if (key == 'd') { key = 'a'; break; }
						else break;
					}break;
				case 's':
					if (m->move(key) == 1) { map[m->head->b_x][m->head->b_y] = m->head->data; m->showmap(); return 0; }
					m->showmap();
					m->reward();
					if (end() == 1)return 0; key_s = key;
					if (kbhit()) {
						key = getch();
						if (key == 'w') { key = 's'; break; }
						else break;
					}break;
				case 'd':
					if (m->move(key) == 1) { map[m->head->b_x][m->head->b_y] = m->head->data; m->showmap(); return 0; }
					m->showmap();
					m->reward();
					if (end() == 1)return 0; key_s = key;
					if (kbhit()) {
						key = getch();
						if (key == 'a') { key = 'd'; break; }
						else break;
					}break;
				case 'e':
					return 0;
				case 'p':system("pause"); key = getch();
					break;
				case 'r':					
					victory(); m->showmap(); if (end() == 1)return 0; break;
				case 'c':
					if (speed == 10) { cout << "速度已最大"; key = key_s; break; }
					speed -= 10;
					cout << "速度已增加,当前速度为" << 500.000 / speed << "格每秒" << endl; key = key_s; break;
				case 'v':
					speed += 10; 
					cout << "速度已减小,当前速度为" << 500.000 / speed << "格每秒" << endl; key = key_s; break;
				default:
					key = getch();
				}
			}break;
		case 2:
			cout << "请选择难度（a 快速 b 中等 c 缓慢）" << endl;
			char difficulty;
			cin >> difficulty;
			switch (difficulty) {
			case 'a': speed = 50;
				cout << "选择成功"; system("pause"); chioce = 1; break;
			case 'b': speed = 100;
				cout << "选择成功"; system("pause"); chioce = 1; break;
			case 'c': speed = 150;
				cout << "选择成功"; system("pause"); chioce = 1; break;
			default:
				cout << "输入无效";
				break;
			}break;
		case 3:
			cout << "******欢迎使用柯南的秘籍！******" << endl;
			cout << "e:结束游戏" << endl;
			cout << "r:快速胜利游戏" << endl;
			cout << "p:暂停游戏" << endl;
			cout << "c:游戏中按c加速" << endl;
			cout << "v:游戏中按v减速" << endl;
			cout << "持续更新中..." << endl; 
			cout << "请重新选择选项" << endl;cin >> chioce;
			break;
		case 4:
			return 0;
		default:
			cout << "输入无效请重新输入"<<endl; cin>>chioce;
			break;
		}
	}
}

