#include <iostream>
using namespace std;


//体会缓冲区
int main01() {
	char ch;
	while ((ch = cin.get()) != EOF) {
		cout << ch << endl;
	}

	
	cout<<"hello....."<<endl;
	system("pause");
	return 0;
}

//关于系统缓冲区的小案例


int main2() {
	char a, b, c;
	//缓冲区没有数据,系统阻塞,等待输入数据
	cin.get(a);
	cin.get(b);
	cin.get(c);
	cout << a << b << c << endl;
	//当输入字符大于所需要的字符时,其他字符存在缓冲区内,供需要时直接提取
	cout << "缓冲区还有数据,系统不会阻塞" << endl;
	char d, e, f;
	cin.get(d);
	cin.get(e);
	cin.get(f);
	cout << d << e << f << endl;
	system("pause");
	return 0;
}

//cin.getline函数可以接收空格

int main() {

	char buf1[10];
	char buf2[10];
	cout << "输入一个数据可以带空格如 aa bb cc dd ee" << endl;
	//缓冲区接收所有字符,而cin不接收空格,遇到空格buf1输入完毕,
	//cin.getline接收空格,所以buf2会接收剩下的字符
	cin >> buf1;
	cin.getline(buf2,10);
	cout << "buf1:"<<buf1 << endl;
	cout << "buf2:" << buf2 << endl;
	system("pause");
	return 0;
}