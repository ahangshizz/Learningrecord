#include <iostream>
#include <cmath>
using namespace std;
class Test {

public:
	Test(int a, int b) {
		m_a = a;
		m_b = b;
	}
	int get_c() {
		++m_c;
		return m_c;
	}
	static int m_c;
private:
	int m_a;
	int m_b;
};
int Test::m_c = 0;   //静态成员的初始化一定写在类的外面
int main01() {
	Test t1(10, 20);
	Test t2(100, 200);
	cout << t1.get_c() << endl;
	cout << t2.get_c() << endl;
	system("pause");
	return 0;
}

//小练习
class box {
public:
	box(int l, int w) {
		len = l;
		wid = w;
	}
	int voilem() {
		int v=len*hig*wid;
		cout << "高等于 " << hig << endl;
		cout << "体积等于" << v << endl;
		return v;
	}
	static int changehig(int h) {
		hig = h;
		return hig;
	}
private:
	int len;
	int wid;
	static int hig;
};
int box::hig = 100;
int main3() {
	box b1(10, 20);
	box b2(100, 200);
	b1.voilem();
	b2.voilem();
	box::changehig(300);
	b1.voilem();
	b2.voilem();
	return 0;
}

//小练习   仓库进货出货
class goods {

public:
	goods() {
		weight = 0;
		next = NULL;
	}
	goods(int w) {
		weight = w;
		total_weight = total_weight + weight;
		cout << "进货重量为:" << w << endl;
		cout << "仓库总重量为:" << total_weight << endl;
	}
	~goods() {
		total_weight -= weight;
		cout << "卖出了一箱重量为" << weight << "的货物" << endl; 
	}
	static int getweight() {
		return total_weight;
	}
	goods* next = NULL;
private:
	int weight;
	static int total_weight;
};
int goods::total_weight = 0;
void buy(goods* &head, int w) {
	goods* new_goods = new goods(w);
	if (head == NULL) {
		head=new_goods;
	}
	else {
		new_goods->next = head;
		head = new_goods;
	}
}
void sale(goods*&head) {
	if (head == NULL) {
		cout << "没有货物" << endl;
		return;
	}
	else {
		goods* tmp =head;
		head = head->next;
		delete tmp;
	}
}
int main4() {
	int choocie;
	goods* head = NULL;
	do
	{
		cout << "1 买货" << endl;
		cout << "2 卖货" << endl;
		cout << "3 退出" << endl;
		cin >> choocie;
		int w = 0;
		switch (choocie) {
		case 1:
			cout << "请输入货物重量" << endl;
			cin >> w;
			buy(head, w);
			break;
		case 2:
			sale(head);
			break;
		case 3:
			exit(0);
		}
		cout << "当前仓库的总重量" << goods::getweight() << endl;
	} while (1);
	return 0;
}

//实现两个对象的相加,运用this指针
class Test2 {
public:
	Test2(int a, int b) {
		this->a = a;
		this->b = b;
	}
	int get_a() {
		return this->a;
	}
	int get_b() {
		return this->b;
	}
	void prinT2() {
		cout << "a=" << this->a << ",b=" << this->b << endl;
	}
	Test2 TestAdd(Test2&t2) {
		Test2 tmp((this->a +t2.a), (this->b + t2.b));
		return tmp;
	}
	void TestAdd2(Test2&t2) {
		this->a += t2.a;
		this->b += t2.b;
	}
	Test2& TestAdd3(Test2&t2) {
		this->a += t2.a;
		this->b += t2.b;
		return *this;//函数返回它本身   返回他本身以后可以一直进行+=操作
	}
private:
	int a;
	int b;
};
//全局函数                 放入类的内部
//Test2 Test2Add(Test2&t1, Test2&t2) {
//	Test2 tmp((t1.get_a() + t2.get_a()), (t1.get_b() + t2.get_b()));
//	return tmp;
//}
int main5() {
	Test2 t1(10, 20);
	Test2 t2(100, 200);
	Test2 t3 = t1.TestAdd(t2);                                //Test2Add(t1, t2);        //全局函数换成类中的函数   调用方式也要改变
	t1.TestAdd2(t2);
	t3.prinT2();
	//t1.prinT2();
//实现   (((t1+=t2)+=t2)+=t2)
	//如果想对一个对象连续的调用成员方法必须返回引用,并且每次都会改变对象本身
	t1.TestAdd3(t2).TestAdd3(t2).TestAdd3(t2);
	t1.prinT2();
	return 0;
}


//友元函数    类
class SKT {
public:
	SKT(int x, int y) {
		m_x = x;
		m_y = y;
	}
	int getX() {
		return m_x;
	}
	int getY() {
		return m_y;
	}
	friend double SKTJL(SKT&t1, SKT&t2);//声明 全局函数是我类的友元函数,可以放在头部或者尾部
private:
	int m_x;
	int m_y;
};
double SKTJL(SKT&t1, SKT&t2) {
	double dis;
	//老办法,在SKT类里面写一个获取的函数   拿到类的私有成员
	//int d_xx = t1.getX() - t2.getX();
	//int d_yy = t1.getY() - t2.getY();
	//dis = sqrt(d_xx*d_xx + d_yy*d_yy);
	//友元函数的方法,告诉类这个函数是兄弟函数,可以访问私有成员
	int d_xx = t1.m_x - t2.m_x;
	int d_yy = t1.m_y - t2.m_y;
	dis = sqrt(d_xx*d_xx + d_yy*d_yy);
	return dis;
}

int main6() {
	SKT t1(1, 2);
	SKT t2(2, 2);
	cout << "两点之间的距离是" << SKTJL(t1, t2)<<endl;
		return 0;
}


//友元类
class A {
	friend class B;
public:
	A(int a) {
		this->a = a;
	}
private:
	int a;
};
class B {
public:
	B(int b) {
		this->b = b;
	}
	void PrintB() {
		A a1(100);
		cout << a1.a << endl;
		cout << b << endl;
	}
private:
	int b;
};
int main7() {
	B b1(200);
	b1.PrintB();

	return 0;
}


//操作符重载

class Wh {
	//friend Wh operator+(Wh&w1, Wh&w2);
	friend Wh& operator+=(Wh&w1, Wh&w2);
public:
	Wh(int a, int b) {
		this->a = a;
		this->b = b;
	}
	void PRInt() {
		cout << "<" << this->a << "+" << this->b << "i>" << endl;
	}
	Wh operator+(Wh & w2) {
		Wh tmp(this->a + w2.a, this->b + w2.b);
		return tmp;
	}
private:
	int a;
	int b;
};
//Wh operator+(Wh&w1, Wh&w2) {
//	Wh tmp(w1.a + w2.a, w1.b + w2.b);
//	return tmp;
//}
Wh& operator+=(Wh&w1, Wh&w2) {
	w1.a += w2.a;
	w1.b += w2.b;
	return w1;
}
int main8() {
	Wh w1(1, 2);
	Wh w2(2, 3);
	Wh w3 = w1+w2;
	w1.PRInt();
	w2.PRInt();
	w3.PRInt();
	w1 += w2+=w2;
	w1.PRInt();
	return 0;
}


//左移运算符的重载
//右移运算符的重载

class LT {
public:
	LT() {
		;
	}
	LT(int a, int b) {
		this->a = a;
		this->b = b;
	}
	friend ostream& operator<<(ostream&os, LT&t1);
	friend istream& operator>>(istream&is, LT&t1);
private:
	int a;
	int b;
};

ostream& operator<<(ostream&os, LT&t1) {//cout的定义,
	os << "<" << t1.a << "," << t1.b << "i>" << endl;
	return os;
}
istream& operator>>(istream&is,LT&t1) {//cin的定义
	cout << "a:" << endl;
	is >> t1.a;
	cout << "b:" << endl;
	is >> t1.b;
	return is;
}
int main() {
	LT t1(1, 3);
	LT t2;
	cout << t1;
	cin >> t2;
	cout << t2;
	return 0;
}