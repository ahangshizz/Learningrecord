#include <iostream>
#include <string>
using namespace std;

int main() {
	string s1;
	string s2;
	string stmp;
	int count = 0;
	cin >> s1;
	cin >> s2;
	int len = s1.size();
	for (int i = 0; i <= len; ++i) {
		stmp = s1;
		stmp.insert(i,s2);
		string::iterator it_1 = stmp.begin();
		string::iterator it_2 = stmp.end();
		--it_2;
		while (it_1 <= it_2) {
			if (*it_1 == *it_2) {
				++it_1;
				--it_2;
			}
			else {
				break;
			}
		}
		if (*it_1 == *it_2) {
			count++;
		}
	}
	cout << count << endl;
	system("pause");
	return 0;
}