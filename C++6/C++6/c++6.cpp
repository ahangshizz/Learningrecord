#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>
using namespace std;
class sqr 
{
public:
	sqr(int a) {
		cout << "srq构造函数" << endl;
		this->a = a;
	}
	~sqr() {
		cout << "~sqr....." << endl;
	}
	int operator()(int a) {//关于()符号的重载
		return a*a;
	}
	void* operator new(size_t size) {//new操作符的重载
		cout << "new的重载" << endl;
		return malloc(size);
	}
	void operator delete(void*op) {//delete操作符的重载
		if (op != NULL) {
			free(op);
			op = NULL;
		}
	}
private:
	int a;
};
int main01() {

	sqr s(10);
	int value = s(2);//把对象当成仿函数处理
	cout << s(2) << endl;
	sqr* A = new sqr(10);//会出发构造函数
	delete A;//会自动调取析构函数
	return 0;
}

class A {
public:
	A(int a) {
		cout << "触发构造函数" << endl;
		this->a = a;
	}
	void func() {
		cout << "a=" << this->a << endl;
	}
	~A() {
		cout << "触发析构函数" << endl;
	}
private:
	int a;
};
int main02() {
	auto_ptr<int> ptr(new int);//这是一个智能指针,开辟空间会自动回收,添加头文件<memory>
	*ptr = 10;
	auto_ptr<A> a(new A(10));
	a->func();
	return 0;
}



class mystring {
public:
	mystring() {
		this->len =0;
		this->str = NULL;
	}
	mystring(const char* str) {//mystring的构造函数
		cout << "调用了构造函数" << endl;
		this->len = strlen(str);
		this->str = new char[len+1];
		strcpy(this->str, str);
	}
	~mystring() {
		cout << "调用了析构函数" << endl;
		if (str != NULL) {
			delete str;
			str = NULL;
		}
	}
	char& operator[](int idex) {//重载[]操作符
		return this->str[idex];
	}
	mystring(const mystring &another) {//mystring的拷贝
		this->len = another.len;
		this->str = new char[len + 1];
		strcpy(this->str, another.str);
	}
	mystring& operator=(mystring&another) {
		if (this == &another) {
			return *this;
		}
		if (this->str != NULL) {
			delete[] this->str;
			this->str = NULL;
			this->len = 0;
		}
		this->len = another.len;
		this->str = new char[len + 1];
		strcpy(this->str, another.str);
		return *this;
	}
	friend ostream&  operator<<(ostream&os, mystring&s);
	friend istream& operator>>(istream&is, mystring&s);
private:
	int len;
	char* str;
};
ostream&  operator<<(ostream&os, mystring&s) {
	os << s.str;
	return os;
}
istream& operator>>(istream&is, mystring&s) {
	if (s.str != NULL) {
		delete[] s.str;
		s.str = NULL;
		s.len = 0;
	}
	char tmp[4096];
	is >> tmp;
	s.len=strlen(tmp);
	s.str = new char[s.len + 1];
	strcpy(s.str, tmp);
	return is;
}
int main15() {
	mystring s1("abc");
	mystring s2(s1);
	mystring s4("abcd");
	cin >> s4;
	cout << s4;
	s1[1] = 'x';
	cout << s1 << endl;
	cout << s2 << endl;
	mystring s3 = s1;
	cout << s3 << endl;
	return 0;
}