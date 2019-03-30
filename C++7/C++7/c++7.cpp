#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
#if 0
class A {
public:
	void funcA() {
		cout << "funcA..." << endl;
	}
	int a;
};

//类B依赖于类A,叫做B has A;
class C1 {
public:
	void funcB() {
		cout << "funcB..." << endl;
	}
	A a;
};
#endif
//耦合度   高内聚低耦合
//类C的成员方法需要类A的形参    C use A
#if 0
class C {
public:
	void funcC(A* a1) {
		cout << "funcC..." << endl;
	}
};
//类D继承于A      类D is A     继承的耦合度非常之高
class D :public A {
public:
	void funcD() {
		cout << a << endl;
	}
};
int main0() {


	return 0;
}
#endif
//继承的基本概念
#if 0
class Student {
public:
	Student(int id, string name) {
		this->id = id;
		this->name = name;
	}
	void PrintS() {
		cout << this->id <<"   "<< this->name << endl;
	}
private:
	int id;
	string name;
};

//学生类2继承学生类
class Student2 :public Student {
public:
	Student2(int id, string name, int score) :Student(id, name) {
		this->score = score;
	}
	void PrintS2() {
		Student::PrintS();
		cout << this->score << endl;
	}
private:
	int score;
};
int main1() {
	Student2 s1(2815, "weihang", 99);
	s1.PrintS2();
	return 0;
}

#endif
//继承的方式
#if 0
class SKT {
public:
	int pub;
protected:
	int pro;
private:
	int pri;
};
class SKT1 :public SKT {
public:
	void func() {
		cout << pub << endl;//pub父类的public成员变量,在public继承类的内部和外部都可以访问
		cout << pro << endl;//pro父类的protected成员变量,在public继承类的内部可以访问,外部不可以访问
//		cout << pri << endl;//pri父类的private成员变量,在public继承类的内部不可以访问,外部不可以访问
	}
};
int main02() {
	SKT1 T1;
	T1.func();
	T1.pub;
//	T1.pro;
//	T1.pri;
	return 0;
}
#endif	

//类的兼容性赋值原则
//子类对象可以当做父类对象使用
//子类对象可以直接赋值给父类对象
//子类对象可以直接初始化父类对象
//父类指针可以直接指向子类指针
//父类引用可以直接引用子类对象
#if 0
class prent {
public:
	prent() {

	}
	prent(int a, int b) {
		this->a = a;
		this->b = b;
	}
	void printP() {
		cout << this->b << endl;
		cout << this->a << endl;
	}
	int a;
	int b;
};
class clid :public prent {
public:
	clid() {

	}
	clid(int a, int b, int c) :prent(a, b) {
		this->c = c;
	}
	int c;
};
int main3() {
//	prent p;
	//clid c = p;//不能通过父类给子类赋值
//	clid c;
//	p = c;//可以通过子类给父类赋值
//	c.printP();//子类可以直接当做父类来使用
	prent* pp = NULL;
	clid* cp = NULL;
	prent p;
	clid c;
	pp = &c;//父类指针可以直接指向子类对象
//	cp = &p;//子类指针不能指向父类对象
	pp->printP();
	pp->a;//子类对象可以满足父类指针的所有需求
	pp->b;
	return 0;
}
#endif

//子类的构造和析构
//在构造子类时,会自动调用父类的构造函数
//析构时遵循谁先构造谁后析构
#if 0
class EDG {
public:
	EDG(int a) {
		cout << "EDG<int>" << endl;
		this->a = a;
	}
	~EDG() {
		cout << "~EDG.." << endl;
	}
	int a;
};
class EDGY :public EDG {
public:
	EDGY(int a, int y_a) :EDG(a){
		cout << "EDGY<int int>"<<endl;
		this->a = y_a;
	}
	~EDGY() {
		cout << "~EDGY" << endl;
	}
	void printY() {
		cout << this->a << endl;
		cout << EDG::a << endl;
	}
	int a;
};
int main4() {
	EDGY Y1(10, 20);
	Y1.printY();
	return 0;
}
#endif
//继承中关于static
#if 0
class B {
public:
	static int a;
};
class B2 :public B {
public:
	int b;
};
int B	::a = 0;
int main() {
	B b1;
	B b2;
	B2 a1;
	B2 a2;
	cout << b1.a << endl;
	cout << b2.a << endl;
	B::a = 300;
	cout << a1.a << endl;
	cout << a2.a << endl;
	return 0;
}
#endif

//多继承和虚继承
//出现菱形继承应该用虚继承进行,防止对象访问不明确.
#if 0
class haro {
public:
	int six;
};
class gailun :virtual public haro {
public:
	void gai() {
		cout << "正义之剑" << endl;
	}
};
class huangzi :virtual public haro {
public:
	void huang() {
		cout << "天崩地裂" << endl;
	}
};
class huanggai :public gailun, huangzi {
public:
	void hga() {
		gailun::gai();
		huangzi::huang();
	cout << "正义天崩" << endl;
	}
};
int main() {
	gailun g1;
	huangzi h1;
	huanggai hg;
	g1.gai();
	g1.six;
	hg.six;
	hg.hga();
	return 0;
}
#endif
//多态的使用以及虚函数
//多态发生的三个必要条件
//要有继承
//要有虚函数
//要有父类指针指向子类
#if 0
class yuebuqun {

public:
	yuebuqun(string kongfu) {
		this->kongfu = kongfu;
	}
	virtual void fight() {//加关键字virtual 使函数成为虚函数,在能完成多态
		cout << "岳不群使用" << kongfu << "打人" << endl;
	}
	string kongfu;
};
class linpingzhi :public yuebuqun {
public:
	linpingzhi(string kongfu) :yuebuqun(kongfu) {

	}
	void fight() {
		cout << "林平之使用" << kongfu << "打人" << endl;
	}
};
void fightpeople(yuebuqun*hero) {
	hero->fight();
}
int main() {
	yuebuqun *xiaoyy = new yuebuqun("葵花宝典");
	linpingzhi* xiaopp = new linpingzhi("辟邪剑法");
	fightpeople(xiaoyy);
	fightpeople(xiaopp);

	delete xiaoyy;
	delete xiaopp;
	return 0;
}
#endif
class A {
public:
	A() {
		cout << "调用了A的无参构造" << endl;
		this->p = new char[64];
		strcpy(this->p, "zhangsan");
	}
	virtual ~A() {
		cout << "调用了A的析构函数" << endl;
		if (this->p != NULL) {
			delete[] this->p;
			this->p = NULL;
		}
	}
private:
	char* p;
};
class B :public A {
public:
	B() {
		cout << "调用了B的无参构造" << endl;
		this->p = new char[64];
		strcpy(this->p, "wangwu");
	}
	~B() {
		cout << "调用了B的析构函数" << endl;
		if (this->p != NULL) {
			delete[] this->p;
			this->p = NULL;
		}
	}
private:
	char* p;
};
void deleteA(A*obj) {
	delete obj;
}
void test() {
	//A* aobj = new A;
	B* bobj = new B;
	deleteA(bobj);
}
int main() {
	test();

	return 0;
}


//重载  重写   重定义
//重载一定是在同一个作用域
//重定义:发生在两个不同的类中,一个父类,一个子类
//重写:重写一个虚函数,发生多态