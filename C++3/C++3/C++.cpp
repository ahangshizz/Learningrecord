#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//using namespace std;
//class Test {
//public:
//	Test(int x, int y) {
//		m_x = x;
//		m_y = y;
//	}
//	Test(int x) {
//		m_x = x;
//		m_y = 0;
//	}
//	int get_x() {
//
//		return m_x;
//	}
//	int get_y() {
//		return m_y;
//	}
//	void printtest() {
//		cout << get_x() << endl << get_y() << endl;
//	}
//	char* name = (char*)malloc(sizeof(name));
//private:
//	int m_x;
//	int m_y;
//	char* name[100];
//};
//void test1() {
//	Test c(100, 200);
//
//}
//int main() {
//	Test c(100,200);
//	cout << c.get_x() << endl << c.get_y() << endl;
//	Test c1(100);
//	c1.printtest();
//	system("pause");
//	return 0;
//}



//#include <iostream>
//using namespace std;
//class Test {
//public:
//	Test(int x, int y) {
//		m_x = x;
//		m_y = y;
//	}
//	void Print() {
//		cout << "x=" << m_x << "y=" << m_y << endl;
//	}
//#if 0
//	Test(const class Test&another) {
//		cout << "Test(const class Test&another)" << endl;
//		m_x = another.m_x;
//		m_y = another.m_y;
//		cout << "x=" << m_x << "y=" << m_y << endl;
//	}
//#endif
//private:
//	int m_x;
//	int m_y;
//};
//int main() {
//	Test t1(10,20);
//	t1.Print(); 
//	Test t2(t1);
//	t2.Print();     
//	Test t3 = t1;
//	t3.Print();
//	system("pause");
//	return 0;
//}


//#include <iostream>
//using namespace std;
//class Test {
//public:
//	Test() {
//		cout << "Test()" << endl;
//	}
//	Test(int x, int y) {
//		cout << "Test(int x, int y)" << endl;
//		m_x = x;
//		m_y = y;
//	}
//	Test(Test &another) {
//		cout << "Teas(const Test &)" << endl;
//	}
//	~Test() {
//		cout << "~Test()" << endl;
//	}
//private:
//	int m_x;
//	int m_y;
//};
//void fun1() {
//	Test t1;
//	Test t2(t1);
//
//}
//void fun2() {
//	Test t1(10, 20);
//	Test t2;
//	t2 = t1;
//}
//int main() {
//	fun1();
//	fun2();
//	system("pause");
//	return 0;
//}


//#include <iostream>
//using namespace std;
//class Test {
//
//public:
//	Test(int id, char* name) {
//		m_id = id;
//		m_name = (char*)malloc(sizeof(name));
//		strcpy(m_name, name);
//	}
//	Test(const Test &t1) {
//		m_id = t1.m_id;
//		m_name = (char *)malloc(sizeof(t1.m_name));
//		strcpy(m_name, t1.m_name);
//	}
//	~Test() {
//		if (m_name != NULL) {
//			free(m_name);
//			m_name = NULL;
//		}
//	}
//	void prinT() {
//		cout << "m_id=" << m_id << ",m_name=" << m_name << endl;
//	}
//private:
//	int m_id;
//	char* m_name;
//};
//void func() {
//	Test t1(20, "zhang3");
//	Test t2(t1);
//	t1.prinT();
//	t2.prinT();
//}
//int main() {
//	func();
//	system("pause");
//	return 0;
//}


//#include <iostream>
//using namespace std;
//class A {
//public:
//	A(int a) {
//		cout << "A()..." << endl;
//		m_a = a;
//	}
//	void printA() {
//		cout << "m_a=" << m_a << endl;
//	}
//	~A() {
//		cout << "~A..." << endl;
//	}
//private:
//	int m_a;
//};
//class B {
//public:
//	B(A&a1,A&a2,int id) :a1(a1), a2(a2) {
//		cout << "B()...." << endl;
//		m_id = id;
//	}
//	void printB() {
//		cout << "id=" << m_id << endl;
//		a1.printA();
//		a2.printA();
//	}
//	~B() {
//		cout << "~b...." << endl;
//	}
//private:
//	int m_id;
//	A a1;
//	A a2;
//};
//int main() {
//	A a1(10), a2(100);
//	B b(a1, a2, 1000);
//	b.printB();
//	system("pause");
//	return 0;
//}


#include <iostream>
using namespace std;
void test1() {
	int* p = NULL;
	p = (int*)malloc(sizeof(int));
	*p = 10;
	int* arr = NULL;
	arr = (int*)malloc(sizeof(int) * 10);
	int i = 0;
	for (i = 0; i < 10; i++) {
		arr[i] = i + 1;
	}
	for (i = 0; i < 10; i++) {
		printf("arr[%d]=%d\n	", i, arr[i]);
	}
	if (p != NULL) {
		free(p);
		p = NULL;
	}
	if (arr != NULL) {
		free(arr);
		arr = NULL;
	}
}


void test2() {
	int* p = NULL;
	p = new int;
	*p = 20;
	int* arr = NULL;
	arr = new int[10];
	int i = 0;
	for (i = 0; i < 10; i++) {
		arr[i] = i + 1;
	}
	for (i = 0; i < 10; i++) {
		cout << arr[i] <<"  " << endl;
	}
	if (p != NULL) {
		delete p;
	}
	if (arr != NULL) {
		delete[] arr;
	}
}
int main() {
	test1();
	test2();
	system("pause");
	return 0;
}