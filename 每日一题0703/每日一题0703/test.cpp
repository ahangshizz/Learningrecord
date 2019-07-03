#include <iostream>
#include <string>
using namespace std;


int main() {
	string str;
	string s_max;
	string s;
	while (getline(cin, str)) {
		auto it = str.begin();
		while (it != str.end()) {
			if (s.empty()) {
				if (*(it) >= 'a'&&*(it) <= 'z') {
					str.erase(it);
				}
				else if (*(it) >= '0'&&*(it) <= '9') {
					s.push_back(*(it));
					++it;
				}
			}
			else {
				if (*(it) >= 'a'&&*(it) <= 'z') {
					str.erase(it);
					if (s_max.size() == 0) {
						s_max = s;
						s.clear();
					}
					else if (s.size() > s_max.size()) {
						s_max = s;
						s.clear();
					}
					s.clear();
				}

				else if (*(it) >= '0'&&*(it) <= '9') {
					s.push_back(*(it));
					++it;
				}
			}
		}
		if (s.size() > s_max.size()) {
			s_max = s;
		}
		cout << s_max << endl;
	}
	system("pause");
	return 0;
}