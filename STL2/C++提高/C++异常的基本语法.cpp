#include <iostream>
using namespace std;

//1.异常的基本语法
//2.接收异常可以不进行处理,继续往下抛异常
//3.发生异常以后是跨函数的
void devide(int x, int y) {
	if (y == 0) {
		//抛出异常,异常是跨函数的,有异常,后面的直接不执行
		throw x;
	}
	cout << x / y << endl;
}

void mydevide(int x,int y) {
	try
	{
		devide(x, y);
	}
	catch (...)
	{
		cout << "我捕获了异常但是我没有处理,继续往下抛异常" << endl;
		throw;
	}
}
int main() {

	try
	{
		mydevide(100,0);

	}
	catch (int e)
	{
		cout << e << "被0整除" << endl;
	}
	catch (...)
	{
		cout << "其他异常" << endl;
	}
	cout<<"hello....."<<endl;
	system("pause");
	return 0;
}