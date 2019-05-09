#include <iostream>
using namespace std;

template <typename T>
//函数模板
void My_Swap(T& a, T& b) {
	T	tmp;
	tmp = a;
	a = b;
	b = tmp;
	cout << "模板函数" << endl;
}
//函数重载
void My_Swap(int a, char c) {
	cout << "a:" << a << "c:" << c << endl;
	cout << "普通函数" << endl;
}

int main03() {
	{
		int a = 10;
		char c = 'c';
		My_Swap(a, c);//调用普通函数
		My_Swap(c, a);//调用普通函数
		My_Swap(a, a);//调用模板函数
		//模板函数进行严格的类型匹配
		//普通函数存在隐式类型转换
	}
	return 0;
}