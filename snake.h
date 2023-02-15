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
	body *getbodyptr(int position);//�õ���ǰλ�õ�ָ��
	int length();                //�õ�����ĳ���
	void addbody();              //��������
	void debody(body *temptr);               //�ض�����
	void showsnake();               //չʾ����
	int move(char c);             //�ƶ�����
	bool reward();              //�Ե�ʳ���������β��
	void showmap();                //��ʾ��ͼ
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
	body* temptr;       //�����ƶ���ǰһ�������λ��
		for (temptr = getbodyptr(length()); temptr->back != NULL; temptr = temptr->back) {
			temptr->b_x = temptr->back->b_x;
			temptr->b_y = temptr->back->b_y;
		
	}
	if (c == 'w') {     //��ͷ�ƶ�
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

	if (head->b_x > 23 || head->b_x == 0) {//�����Խ��ͼ�����һ�߻������ٴ������ϰ���
		head->b_x = 24 - (head->b_x); wall();
	}
	if (head->b_y > 77 || head->b_y == 0) {
		head->b_y = 78 - (head->b_y); wall();
	}

	for (temptr = head->next; temptr->next != NULL; temptr = temptr->next) {//�ض�����
		if ((head->b_x == temptr->b_x) && (head->b_y == temptr->b_y)) {
			debody(temptr);
		}
	}

	if (map[head->b_x][head->b_y] == '#') {   //�ж���ײ�ϰ���
		cout << " ��ʧ����!" << endl; system("pause");
		return 1;
	}             

	for (temptr = head; temptr != NULL; temptr=temptr->next) {//��ʾ����
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
	gotoxy(0,0); // ����ƶ���ԭ��λ�ã������ػ�����
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 80; j++) {
			cout << map[i][j];
		}cout << endl;
	}
	cout << "����õķ���Ϊ" << score << endl;
	Sleep(speed);
}