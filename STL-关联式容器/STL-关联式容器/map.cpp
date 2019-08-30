#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;



#if 0
int main() {
	map<string, string> m;
	m.insert(pair<string, string>("peach", "桃子"));
	m.insert(make_pair("apple", "苹果"));
	m["banan"] = "香蕉";
	cout << m.size() << endl;

	m["peach"] = "桃色";
	for (auto& e : m) {
		cout << e.first << "--->" << e.second << endl;
	}
	cout << endl;
	auto ret = m.insert(make_pair("peach", "桃色"));
	if (ret.second)
		cout << "<peach,桃色>不在map中已插入" << endl;
	else
		cout << "键值peach已经存在" << endl;

	m.erase("apple");
	if (1 == m.count("apple"))
		cout << "苹果在map中" << endl;
	else
		cout << "苹果不在map中" << endl;
	system("pause");
	return 0;
}
# endif 

#if 0
int main() {

	int array[] = { 2,5,7,8,4,3,1,9,0,5 };
	set<int> s(array, array+sizeof(array) / sizeof(int));

	for (auto& e : s) {
		cout << e << " ";
	}
	cout << endl;

	for (auto it = s.rbegin(); it != s.rend(); ++it)
		cout << *it << " ";
	cout << endl;
	auto it = s.begin();
	*it++;//set中的元素不能改变并不会报错
	for (auto& e : s) {
		cout << e << " ";
	}
	cout << endl;
	cout << s.count(3) << endl;
	system("pause");
	return 0;
}
#endif

int main() {

	int array[] = { 2,4,6,6,3,2,5,5,1,3,9,8,7,0 };
	multiset<int> s(array,array+sizeof(array)/sizeof(int));
	for (auto& e : s) {
		cout << e << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}