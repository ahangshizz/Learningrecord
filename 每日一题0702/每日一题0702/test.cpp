#include <iostream>
#include <string>
#include <algorithm>
using namespace std;



int main() {
	string s;
	while (getline(cin, s)) {
		auto it = s.begin();
		int i = 0;
		string sum;
		while (it != s.end()) {
			if (*(it) != ' ') {
				++it;
				continue;
			}
			++i;
			++it;
		}
		auto it_1 = s.rbegin();
		for (i; i >= 0; --i) {
			string _s;
			if (*(it_1) == ' ') {
				//_s += ' ';
				++it_1;
			}
			while (it_1 != s.rend()) {
				if (*(it_1) != ' ') {
					_s += *(it_1);
					++it_1;
				}
				else {
					break;
				}
			}
			if (!sum.empty()) {
				_s += ' ';
			}
			reverse(_s.begin(), _s.end());
			sum += _s;
		}
		cout << sum << endl;
	}
	return 0;
}