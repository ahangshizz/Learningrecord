#include <iostream>
using namespace std;

class Animal{};
class Student{};
class Cat:public Animal{};
//static_cast
//进行基本类型的转换
void test01() {
	int a = 97;
	char b = static_cast<char>(a);
	cout << b << endl;
	//进行指针或者引用的转换
	Animal* ani = NULL;
	Student peter;
	//只能转换具有继承关系的转换
	//peter = static_cast<Student>(ani);
	Cat* cat = NULL;
	ani = static_cast<Animal*>(cat);
}
//dynamic_cast
//只能进行继承间的类型转换
//不能进行普通的类型转换
//只能从子类转换成父类
void test02() {
	//int a = NULL;
	//char b = dynamic_cast<char>(a);
	Animal ani;
	Animal& aniobj = ani;
	//Cat cat = dynamic_cast<Cat>(aniobj);;
	Cat cat;
	aniobj = dynamic_cast<Animal&>(cat);
}
//const_cast
//指针,引用,对象指针
void test03() {
	int a = 10;
	const int& b = a;
	int& c = const_cast<int&>(b);
	c = 20;
}
int main() {

	test01();

	
	cout<<"hello....."<<endl;
	system("pause");
	return 0;
}