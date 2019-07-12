#if 0
#include <iostream>
#include <vector>
using namespace std;

int getLCA(int a, int b) {
	// write code here
	if (a == b) {
		return a;
	}
	vector<int> v1;
	vector<int> v2;
	while (a > 1) {
		v1.push_back(a / 2);
		a /= 2;
	}
	while (b > 1) {
		v2.push_back(b / 2);
		b /= 2;
	}
	auto it_1 = v1.begin();
	auto it_2 = v2.begin();
	for (it_1; it_1 != v1.end(); ++it_1) {
		for (it_2=v2.begin(); it_2 != v2.end(); ++it_2) {
			if (*it_1 == *it_2) {
				return *it_1;
			}
		}
	}
	return 1;
}

int main() {


	int a = getLCA(9, 11);
	cout << a << endl;
	cout<<"hello....."<<endl;
	system("pause");
	return 0;
}
#endif
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	int num;
	while (cin >> num) {
		vector<int> v;
		vector<int> v2;
		while (num > 0) {
			v.push_back(num % 2);
			num /= 2;
		}
		int count = 0;
		for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
			if (*it == 1) {
				count++;
			}
			else {
				v2.push_back(count);
				count = 0;
			}
		}
		v2.push_back(count);
		std::sort(v2.begin(), v2.end());
		auto it = v2.end();
		cout << *(--it) << endl;
	}
	return 0;
}