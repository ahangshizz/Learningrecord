#include <iostream>
using namespace std;


#if 0
int main1() {

	double dpi = 3.1415926;
	int num1 = (int)dpi;//c风格的类型转换
	int num2 = static_cast<int>(dpi);//c++风格的类型转换,编译时c++编译器会做类型检查
	//int num3 = dpi;//C语言中的隐式类型转换的地方,全都可以使用static_cast<>()

	cout<<"hello....."<<endl;
	system("pause");
	return 0;
}

//定义一个动物类型
class Animal {
public:
	virtual void cry() = 0;
private:
};
class Dog :public Animal {
public:
	virtual void cry() {
		cout << "汪汪" << endl;
	}
	void DoHome() {
		cout << "狗可以看家" << endl;
	}
private:
};
class Cat :public Animal {
public:
	virtual void cry() {
		cout << "喵喵" << endl;
	}
	void DoNothing() {
		cout << "猫会抓老鼠" << endl;
	}
private:
};

void Print(Animal* base) {
	base->cry();//多态发生的条件,虚函数重写,有继承,父类指针指向子类对象

	//dynamic_cast可以把父类对象转换成子类对象,
	//向下转型  把老子转为小子
	Dog* dog = dynamic_cast<Dog*>(base);
	if (dog != NULL) {
		dog->DoHome();
	}
	Cat* cat = dynamic_cast<Cat*>(base);
	if (cat != NULL) {
		cat->DoNothing();
	}

}
int main2() {
	Dog d1;
	Cat c1;
	Print(&d1);
	Print(&c1);
	system("pause");
	return 0;
}
#endif
//const char*修饰让形参具有了只读属性
void Print(const char*myp) {
	cout << myp << endl;
	char* p = NULL;
	//const_cast只是把只读属性去掉
	p = const_cast<char*>(myp);
	//通过指针修改这个空间的值
	p[0] = 'A';
	cout << p << endl;
}
int main() {

	const char *buf = "helloweihang";//指针指向的是只读空间
	char* p1 = const_cast<char*>(buf);//去除只读属性
	//p1="aaaa"   err
	char myp[13] = "helloweihang";
	Print(myp);
	system("pause");
	return 0;
}