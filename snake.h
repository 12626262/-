#pragma once
#include"action.h"
using namespace std;

class body {
public:body* next,*back; char data; int b_x, b_y;
	body() {
		data = ' ';
		next = NULL;
		back = NULL;
	}
};
class snake {
public:body *head;
	  snake() { head=new body(); }
	body *getbodyptr(int position);//得到当前位置的指针
	int length();                //得到蛇身的长度
	void addbody();              //增加蛇身
	void debody(body *temptr);               //截断蛇身
	void showsnake();               //展示蛇身
	int move(char c);             //移动蛇身
	bool reward();              //吃掉食物后生成新尾巴
	void showmap();                //显示地图
};
body *snake::getbodyptr(int position) {
	body* temptr=head;
		for (int i = 0; i < position; i++) {
			temptr = temptr->next;
			}return temptr;
}
int snake::length() {
	int count = 0;
	body* temptr=head;
		for (temptr = head->next; temptr != NULL; temptr = temptr->next) {
			count++;
		}
		return count;
	}
void snake::addbody() {
	if (length() == 0) {
		body *ptr = head;
		ptr->data = '*';
		ptr->b_x = 23;
		ptr->b_y = 39;
		ptr->next = new body();
		ptr->next->next = NULL;
		ptr->next->back=ptr;
		//ptr = ptr->next;
	}
	else {
		body *newptr = getbodyptr(length());
		newptr->data = '+';
		newptr->next = new body();
		newptr->next->back = newptr;
		newptr->next->next=NULL;
	}
}

void snake::debody(body *temptr){
	for (body* newptr = getbodyptr(length()); newptr->back != temptr; ) {
		map[newptr->b_x][newptr->b_y] = ' ';
		newptr = newptr->back;
		delete newptr->next;
		newptr->data = ' ';
		newptr->next = NULL;
	}
}

void snake::showsnake() {
	for (body* temptr = head; temptr != NULL; temptr = temptr->next) {
		cout << temptr->data;
	}
}
int snake::move(char c) {
	score = (length() - 1) * 10;
	body* temptr;       //蛇身移动到前一个蛇身的位置
		for (temptr = getbodyptr(length()); temptr->back != NULL; temptr = temptr->back) {
			temptr->b_x = temptr->back->b_x;
			temptr->b_y = temptr->back->b_y;
		
	}
	if (c == 'w') {     //蛇头移动
		head->b_x=head->b_x-1;
	}
	else if (c == 'a') {
		head->b_y=head->b_y-1;
	}
	else if (c == 's'){
		head->b_x=head->b_x+1;
	}
	else if (c == 'd') {
		head->b_y=head->b_y+1;
	}

	if (head->b_x > 23 || head->b_x == 0) {//如果穿越地图则从另一边回来且再次生成障碍物
		head->b_x = 24 - (head->b_x); wall();
	}
	if (head->b_y > 77 || head->b_y == 0) {
		head->b_y = 78 - (head->b_y); wall();
	}

	for (temptr = head->next; temptr->next != NULL; temptr = temptr->next) {//截段蛇身
		if ((head->b_x == temptr->b_x) && (head->b_y == temptr->b_y)) {
			debody(temptr);
		}
	}

	if (map[head->b_x][head->b_y] == '#') {   //判断碰撞障碍物
		cout << " 你失败了!" << endl; system("pause");
		return 1;
	}             

	for (temptr = head; temptr != NULL; temptr=temptr->next) {//显示蛇身
		map[temptr->b_x][temptr->b_y] = temptr->data;
	}
	return 0;
}

bool snake:: reward() {
	if (map[f_x][f_y] != '&') {
		body* newptr = getbodyptr(length());
		addbody();
		food();
		return 1;
	}
	return 0;
}
void snake::showmap() {
	gotoxy(0,0); // 光标移动到原点位置，以下重画清屏
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 80; j++) {
			cout << map[i][j];
		}cout << endl;
	}
	cout << "您获得的分数为" << score << endl;
	Sleep(speed);
}