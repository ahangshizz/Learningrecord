#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	vector<int> v(4);
	string s;
	int a, b, c, num;
	for (int i = 0; i < 4; ++i) {
		cin >> v[i];
	}
	double temp=(v[0] + v[2]) / 2.0;
	a = (int)temp;
	if (temp-a>0) {
		cout << "No" << endl;
		return 0;
	}
	b = v[2] - a;
	c = v[3] - b;
	cout << a << " " << b << " " << c;
	system("pause");
	return 0;
}