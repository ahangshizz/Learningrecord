#include <iostream>
#include <string>
#include <stack>
using namespace std;



int main() {
	string s1;
	string s2;
	while (cin >> s1 >> s2) {
		auto it_s1 = s1.begin();
		auto it_s2 = s2.begin();
		stack<char> stk1;
		stack<char> stk2;
		for (it_s1; it_s1 != s1.end(); ++it_s1) {
			stk1.push(*it_s1);
		}
		for (it_s2; it_s2 != s2.end(); ++it_s2) {
			stk2.push(*it_s2);
		}
		while (!stk2.empty()) {
			char ch2 = stk2.top();
			stk2.pop();
			if (ch2 == '.') {
				break;
			}
		}
		char ch1 = stk1.top();
		stk1.pop();
		if (ch1 != '*') {
			cout << "false" << endl;
		}
		it_s1 = s1.begin();
		it_s2 = s2.begin();
		while (*it_s2!='.') {
			if (*it_s1 != *it_s2&&*it_s1 != '?'&&*it_s1 != '*') {
				++it_s1;
				++it_s2;
				cout << "false" << endl;
				break;
			}
			if (*it_s1 != *it_s2&&*it_s1 == '?') {
				++it_s1;
				++it_s2;
				continue;
			}
			if (*it_s1 != *it_s2&&*it_s1 == '*'&&*it_s2!='.') {
				++it_s2;
			}
			if (*it_s1 == *it_s2) {
				++it_s1;
				++it_s2;
			}
		}
		if (*it_s2=='.') {
		cout << "true" << endl;
		}
	}

	return 0;
}