#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//double getcirclel (int r) {
//	return 2 * 3.14*r;
//}
//double getcircle(int r) {
//
//	return 3.14*r*r;
//}//面向过程C语言写法; 
//int main() {
//	int r = 10;
//	double s = 0.0;
//	double l = 0.0;
//	l = getcirclel(r);
//	s = getcircle(r);
//	cout << "l=" << l << endl;
//	cout << "s=" << s << endl;
//	system("pause");
//	return 0;
//}

//void func(int a = 666) {
//	cout << "a=" << a << endl;
//}
//int  fun2(int a, int, int b = 0) {//占位参数,和默认参数
//	return a;
//}
//int fun3(int a, int b) {
//	cout << "fun3" << endl;
//	return 0;
//}
//int fun3(int a) {
//	cout << "fun3" << endl;
//	return 0;
//}//函数重载,c++支持函数重载,C语言不支持,函数重载是函数名相同而形参列表不同.返回值和函数重载没有任何关系
//int main() {
//	int ret = 10;
//	func(ret);
//	system("pause");
//	return 0;
//}

//int func(int a, int b) {
//	cout << "func" << endl;
//	return 0;
//}
//int func(int a, int b, int c) {
//	cout << "func(int int int )" << endl;
//	return 0;
//}
//int main() {
//	typedef int(MY_func)(int, int);
//	typedef int(*My_func2)(int, int);
//	int(*fp3)(int, int)=NULL;
//	int(*fp4)(int, int, int) = NULL;
//	fp4 = func;
//	MY_func *fp=NULL;
//	fp = func;
//	fp(10, 20);
//	My_func2 fp2 = NULL;
//	fp2 = func;
//	fp2(10, 20);
//	fp3 = func;
//	fp3(10, 20);
//	fp4(10, 20, 30);
//	system("pause");
//	return 0;
//}
//struct hero {
//	char name[64];
//	int sex;
//};
//void printhero(struct hero &h) {
//	cout << "char name=" << h.name << endl;
//	cout << "h.sex" << h.sex << endl;
//}
//class Advhero {
//public:
//	char name[64];
//	int sex;
//	void printhero() {
//		cout << "name" << name << endl;
//		cout << "sex" << sex << endl;
//	}
//};
//int main() {
//	hero h;
//	strcpy(h.name, "li4");
//	h.sex = 1;
//	Advhero h2;
//	h2.sex = 1;
//	strcpy(h2.name, "wang5");
//	printhero(h);
//	h2.printhero();
//	system("pause");
//	return 0;
//}



//class animal {
//public:
//	char kind[64];
//	char cloler[64];
//	void prints() {
//		cout << "kind     " << kind << endl;
//		cout << "cloler   " << kind << endl;
//	}
//	void write() {
//		cout << kind << "开始写字了" << endl;
//	}
//	void run() {
//		cout << kind << "开始跑步了" << endl;
//	}
//};
//int main() {
//	animal dog;
//	strcpy(dog.kind, "dog");
//	strcpy(dog.cloler, "black");
//	animal sheep;
//	strcpy(sheep.kind, "sheep");
//	strcpy(sheep.cloler, "white");
//	dog.run();
//	dog.prints();
//	sheep.write();
//	system("pause");
//	return 0;
//}


//class years {
//public:
//	int year;
//	int moth;
//	int day;
//	void inyear() {
//		cin >> year;
//		cin >> moth;
//		cin >> day;
//	}
//	void printyear() {
//		cout << year << "nian" << moth << "yue" << day << "ri" << endl;
//	}
//	int is_lend_year() {
//		if ((year % 4 == 0 && year % 100 != 0)||(year % 400 == 0)) {
//			return 1;
//		}
//		else {
//			return 0;
//		}
//	}
//};
//int main() {
//	years h;
//	h.inyear();
//	h.printyear();
//	int ret=h.is_lend_year();
//	if (ret == 1) {
//		cout << "yes" << endl;
//	}
//	else {
//		cout << "no" << endl;
//	}
//	system("pause");
//	return 0;
//}

//class circle {
//public:
//	double setr(double r) {
//		m_r = r;
//		return m_r;
//	}
//	double getl() {
//		return m_r * 2 * 3.14;
//	}
//	double getarce() {
//		return m_r*m_r*3.14;
//	}
//private:
//	double m_r;
//};
//int main() {
//	circle h;
//	h.setr(10);
//	h.getl();
//	h.getarce();
//	cout << "圆的半径" << h.setr(10) << endl;
//	cout << "圆的周长" << h.getl() << endl;
//	cout << "圆的面积" << h.getarce() << endl;
//	system("pause");
//	return 0;
//}

//class circle {
//public:
//	void set_r(double r) {
//
//		m_r = r;
//	}
//	double getgritg() {
//		m_grith = m_r * 2 * 3.14;
//		return m_grith;
//	}
//	double getarce() {
//		m_arce = m_r*m_r*3.14;
//		return m_arce;
//	}
//private:
//	double m_r;
//	double m_grith;
//	double m_arce;
//};
//int main() {
//	circle h;
//	h.set_r(10);
//	cout << h.getgritg() << endl;
//	cout << h.getarce() << endl;
//	system("pause");
//	return 0;
//}
class priont {
public:
	void priontxy(int x, int y) {
		m_x = x;
		m_y = y;
	}
	int getx() {
		return m_x;
	}
	int gety() {
		return m_y;
	}
private:
	int m_x;
	int m_y;
};
class circle {
public:
	void get_xyr(int x, int y, int r) {
		x0 = x;
		y0 = y;
		r = r;
	}
	int getx() {
		return x0;
	}
	int gety() {
		return y0;
	}
	int getr() {
		return r;
	}
	bool inout(class priont &p) {
		int dd = 0;
		dd = ((p.getx() - x0)*(p.getx() - x0)) - ((p.gety() - y0)*(p.gety() - y0));
		if (dd > r) {
			return false;
		}
		else {
			return true;
		}
	}
private:
	int x0;
	int y0;
	int r;
};

int main() {
	circle c;
	priont p;
	c.get_xyr(2, 2, 4);
	p.priontxy(8, 8);
	
	if (c.inout(p) == 1) {
		cout << "zaineibu" << endl;
	}
	else {
		cout << "zaiwaimian" << endl;
	}
	system("pause");
	return 0;
}