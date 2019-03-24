#include <iostream>
using namespace std;
class Test {
public:
	Test() {//创建一个无参构造函数
		cout << "调用无参构造函数" << endl;
		m_a = 0;
		m_b = 0;
	}
	Test(int x, int y) {//创建一个两个参数的构造函数
		cout << "调用了两个参数的构造函数" << endl;//测试调用的是哪个构造函数
		m_a = x;
		m_b = y;
	}
	void prinT() {
		cout << m_a << ",,," << m_b << endl;
	}
	~Test() {
		cout << "调用析构函数" << endl;
	}
private:
	int m_a;
	int m_b;
};
int main() {
	//Test *p = (Test*)malloc(sizeof(Test));
	//p->prinT();//malloc创建空间时无法进行初始化,打印出来的为随机数
	Test *p = new Test;//调用无参构造函数
	Test *tp = new Test(10, 20);//调用有参构造函数
	p->prinT();
	tp->prinT();
	if (p!=NULL) {
    free(p);//用free释放new创建的空间,可以测试到free在释放空间是不会触发析构函数
		p = NULL;
	}
	if (tp != NULL) {
		delete tp;//用delete释放new创建的空间直接触发析构函数
		tp = NULL;
	}
	return 0;
}