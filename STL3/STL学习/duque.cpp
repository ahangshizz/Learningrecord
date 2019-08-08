#include <iostream>
#include <deque>
using namespace std;



void test() {

	deque<int> d1;
	deque<int> d2(10, 2);
	deque<int> d3(d2.begin(), d2.end());
	deque<int> d4(d3);

	for (deque<int>::iterator it = d2.begin(); it != d2.end(); ++it) {
		cout << "d2:" << *it << endl;
	}
	cout<<"hello....."<<endl;
	system("pause");
}

//赋值操作
void test01() {
	deque<int> d1(10, 5);
	deque<int> d2;
	d2.assign(d1.begin(), d2.end());//迭代器区间赋值
	deque<int> d3;
	d3 = d2;//等号赋值
}
int main() {
	test();
	system("pause");
	return 0;
}