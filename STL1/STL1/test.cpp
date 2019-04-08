#include <iostream>
#include <string>
using namespace std;
//int 类型的交换
#if 0
void myswap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}
//double类型的交换
void myswap(double& a, double& b) {
	double tmp = a;
	a = b;
	b = tmp;
}
#endif 
#if 0
//方便起见使用模板函数,基本语法 template<class T> T是一个变量命,随便命名

template<class T> //告诉编译器开始写模板函数,看见奇怪的东西不要随便报错,一个模板头只对下面第一个函数生效
void Myswap(T& a, T& b) {
	T tmp = a;
	a = b;
	b = tmp;
}
void test01() {
	int a = 10;
	int b = 20;
	cout << "a:" << a<<endl;
	cout << "b:" << b<<endl;
	//自动类型推导
	Myswap(a, b);
	cout << "a:" << a<<endl;
	cout << "b:" << b<<endl;
	double c = 1.31;
	double d = 1.12;
	Myswap(c, d);//根据你传进来的值,自动类型推导
	cout << "c:" << c << endl;
	cout << "d:" << d << endl;
}
int main() {
	test01();
	return 0;
}
#endif
#if 0
template<class T>
int Add(T a, T b) {
	return a + b;
}
int Add(int a, char c) {
	return a + c;
}
void test02() {
	int a = 10;
	int b = 20;
	char c = 'a';
	char d = 'b';
	Add(a, c);//调用普通函数     普通函数会进行隐式类型转换
	Add(a, b);//调用函数模板     函数模板必须严格精确类型
	Add(c, a);//调用普通函数
	//函数模板允许重载,当普通函数也满足类型匹配,C++编译器优先使用普通函数
}
int main() {
	test02();

	return 0;
}
#endif
#if 0
//类模板    
template<class T>
class Person {
public:
	Person(T id, T age) {
		this->mId = id;
		this->mAge = age;
	}
	void show() {
		cout << "id:" << mId << endl;
		cout << "age:" << mAge << endl;
	}
public:
	T mId;
	T mAge;
};
void test01() {
	Person<int> p(10, 20);
	p.show();
}
int main() {
	test01();

	return 0;
}
#endif
#if 0
template<class T>//把打印函数定义成   函数模板
void PrintArr(T arr[], int len) {
	for (int i = 0; i < len; ++i) {
		cout << "arr[" << i << "]=" << arr[i]<<"  ";
	}
	cout << endl;
}
template<class T>//把排序函数 定义成   函数模板
void mysort(T arr[], int len) {
	for (int i = 0; i < len - 1; ++i) {
		for (int j = 0; j < len - 1 - i; ++j) {
			if(arr[j]<arr[j+1]) {
			T tmp = arr[j];
			arr[j] = arr[j+1];
			arr[j+1] = tmp;
			}
		}
	}
}
int main() {
	int arr[] = { 2,5,4,1,9,8,6 };
	int len = sizeof(arr) / sizeof(int);
	cout<<"排序之前"<<endl;
	PrintArr(arr, len);
	cout << "排序之后" << endl;
	mysort(arr, len);
	PrintArr(arr, len);
	char charr[] = { 'a','n','b','w','t' };
	len = sizeof(charr) / sizeof(char);
	PrintArr(charr, len);
	mysort(charr, len);
	PrintArr(charr, len);
	return 0;
}
#endif
#if 0
// 类模板派生普通类
template<class T> 
class Person {
public:
	Person(T age) {
		this->mAge = age;
	}
public:
	T mAge;
};
//类模板派生普通类时,要给类一个具体的类型,不然编译器无法分配内存
class people :public Person<int> {
public:
};
int main() {
	return 0;
}
#endif 
#if 0
//类模板派生类模板
//要点在类型上面
template<class T> 
class Animal {
public:
	void Jiao() {
		cout << mAge << "岁的动物在叫" << endl;
	}
public:
	T mAge;
};
template<class T>
class Cat :public Animal<T> {
	;
};
#endif
#if 0
//类内实现类模板
template<class T1,class T2>
class Person {
public:
	Person(T1 name,T2 age) {
		this->mAge = age;
		this->mName = name;
	}
	void show() {
		cout << "name:" << mName << endl;
		cout << "age:" << mAge << endl;
	}
public:
	T1 mName;
	T2 mAge;
};
void test01() {
	Person<string, int> p("aaa", 20);
	p.show();
}
int main() {

	test01();
	return 0;
}
#endif


#if 0
//类模板类外实现
//类外实现类模板,不要滥用友元函数,切记,很麻烦
template<class T>
class Person {
public:
	//友元函数也需要声明,类模板,只有windows支持这种写法
	//template<class T>
	//friend ostream& operator<<(ostream&os, Person<T> p);//定义友元函数,实现操作符重载
	//Linux通用应该是下面写法
	friend ostream& operator<< <T>(ostream& os, Person<T> p);
	Person(T age, T id);//函数声明,类外实现
	void show();
private:
	T mAge;
	T mId;
};
//继续声明类模板
template<class T>
ostream& operator<<(ostream& os, Person<T> p) {
	os << "age:" << p.mAge << " " << "id:" << p.mId << endl;
	return os;
}
template<class T>
Person<T>::Person(T age, T id) {             //一定注意类外实现时,类型所放的位置
	mAge = age;
	mId = id;
}
template<class T> 
void Person<T>::show() {                  //一定注意类外实现时,类型所放的位置
	cout << "age:" << mAge << " " << "id:" << mId << endl;
}
void test01() {
	Person<int> p(10, 20);
	//p.show();
	cout << p;//使用操作符重载实现
}
int main() {

	test01();
	return 0;
}
//类模板分文件编程时
//应该把cpp文件改成hpp文件,说明这是一个类模板文件
//原因:在编译时,类模板的函数实现是一个函数模板,函数模板需要进行两次编译,第二次编译是生成具体的函数
//	如果直接在业务cpp调用类模板的.h文件,函数模板没有进行二次编译,所以编译出错
#endif

//当类模板遇到static
template<class T>
class Person {
public:
	static int a;//每个具体的类都有自己的静态变量a,每个具体类定义的类  共享这个变量
};
template<class T>
int Person<T>::a = 0;
int main() {
	Person<int> p1, p2, p3;
	Person<char>pp1, pp2, pp3;
	p1.a = 10;
	pp1.a = 100;
	cout << p1.a << "   " << p2.a << "   " << p3.a << endl;
	cout << pp1.a << "   " << pp2.a << "   " << pp3.a << endl;
	return 0;
}