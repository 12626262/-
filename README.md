# -
基于链表完成的控制台贪吃蛇小游戏（无闪烁并加入一些趣味玩法） 该贪吃蛇趣味玩法如下：  1.增加了随机形状的障碍物和随机的地图出口，逃出地图时会增加新障碍物并从另一边回来。  2.可以自行选择蛇移动速度  3.蛇头碰到蛇身时不会结束游戏而是吃掉蛇身  4.可以使用秘籍快速胜利游戏或者暂停游戏



//消除闪烁的完成：控制台闪烁是由于使用了cls函数清屏，清屏和重写的瞬间被眼睛动态捕捉到所以会感觉闪烁。一般有双缓冲和覆盖两种方式消除闪烁。我选择的是修改光标位置覆盖修改闪烁。原理是不需要清屏，把光标移动到地图的开头。然后再进行覆盖重写，将新数据覆盖到老数据上，这样没有清屏的过程所以察觉不到闪烁。

//代码如下

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
 
void snake::showmap() {
	gotoxy(0, 0); // 光标移动到原点位置，以下重画清屏
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 80; j++) {
			cout << map[i][j];
		}cout << endl;
	}
	cout << "您获得的分数为" << score << endl;
	Sleep(speed);
}

//蛇身的完成：使用双向链表的方法 ，链表的一个结点就代表一段蛇身。当蛇移动时，只需要蛇头前进然后蛇身移动到上一段蛇身的位置就可以了。这种方法相比用数组完成蛇身但是更好维护，例如想增加新功能或者修改某些功能不需要重新对于蛇身操作直接增加函数就可以了。

//下面是代码：

class body {//蛇结点，包括下一段蛇身和上一段蛇身，以及记录蛇身的坐标
public:body* next, * back; char data; int b_x, b_y;
	  body() {
		  data = ' ';
		  next = NULL;
		  back = NULL;
	  }
};
class snake {
public:body* head;
	  snake() { head = new body(); }
	  body* getbodyptr(int position);//得到当前位置的指针
	  int length();                //得到蛇身的长度
	  void addbody();              //增加蛇身
	  void debody(body* temptr);               //截断蛇身
	  void showsnake();               //展示蛇身
	  int move(char c);             //移动蛇身
	  bool reward();              //吃掉食物后生成新尾巴
	  void showmap();                //显示地图
};
body* snake::getbodyptr(int position) {
	body* temptr = head;
	for (int i = 0; i < position; i++) {
		temptr = temptr->next;
	}return temptr;
}
int snake::length() {
	int count = 0;
	body* temptr = head;
	for (temptr = head->next; temptr != NULL; temptr = temptr->next) {
		count++;
	}
	return count;
}
void snake::addbody() {
	if (length() == 0) {
		body* ptr = head;
		ptr->data = '*';
		ptr->b_x = 23;
		ptr->b_y = 39;
		ptr->next = new body();
		ptr->next->next = NULL;
		ptr->next->back = ptr;
		//ptr = ptr->next;
	}
	else {
		body* newptr = getbodyptr(length());
		newptr->data = '+';
		newptr->next = new body();
		newptr->next->back = newptr;
		newptr->next->next = NULL;
	}
}
 
void snake::debody(body* temptr) {
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
		head->b_x = head->b_x - 1;
	}
	else if (c == 'a') {
		head->b_y = head->b_y - 1;
	}
	else if (c == 's') {
		head->b_x = head->b_x + 1;
	}
	else if (c == 'd') {
		head->b_y = head->b_y + 1;
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
 
	for (temptr = head; temptr != NULL; temptr = temptr->next) {//显示蛇身
		map[temptr->b_x][temptr->b_y] = temptr->data;
	}
	return 0;
}
 
bool snake::reward() {
	if (map[f_x][f_y] != '&') {
		body* newptr = getbodyptr(length());
		addbody();
		food();
		return 1;
	}
	return 0;
}
}
