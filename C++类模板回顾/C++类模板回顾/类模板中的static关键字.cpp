#include <iostream>
using namespace std;
//定义一个模板类
template <typename T>
class AA {
public:
	static T m_a;
private:
};
//初始化static关键字
template <typename T>
T AA<T>::m_a = 0;

int main() {
	//int类型
	AA<int> a1, a2, a3;
	a1.m_a = 10;
	a2.m_a++;
	a3.m_a++;
	cout << AA<int>::m_a << endl;
	//char类型
	AA<char> c1, c2, c3;
	c1.m_a = 'a';
	c2.m_a++;
	c3.m_a++;
	cout << AA<char>::m_a << endl;
	cout<<"hello....."<<endl;
	system("pause");
	return 0;
}