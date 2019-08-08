#include <iostream>
#include <vector>
#include <algorithm>	
using namespace std;

#if 0
void MyFunc(int argc) {
	cout << argc << endl;
}
int main() {

	vector<int> v;
	v.push_back(10);	
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	vector<int>::iterator pBegin = v.begin();
	vector<int>::iterator pEnd = v.end();

	for_each(pBegin, pEnd, MyFunc);
	cout<<"hello....."<<endl;
	system("pause");
	return 0;
}
#endif


class Person {
public:
	Person(int age, int weigh) {
		this->age = age;
		this->weigh = weigh;
	}
public:
	int age;
	int weigh;
};


int main()
{
	Person p1(10, 20);
	Person p2(30, 40);
	Person p3(50, 60);
	vector<Person> v;
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	vector<Person>::iterator it = v.begin();
	for (it; it != v.end(); ++it) {
		cout << (*it).age << "  " << (*it).weigh << endl;
	}
	cout << "hello world" << endl;
	system("pause");
	return 0;
}