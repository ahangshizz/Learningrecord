#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string str;
	while (getline(cin, str)) {
		reverse(str.begin(), str.end());
		auto it = str.begin();
		auto start = it;
		auto end = nullptr;
		while (it != str.end()) {
			if (!((*it >= 'a'&&*it <= 'z') || (*it >= 'A'&&*it <= 'Z'))) {
				reverse(start, it);
				it = str.erase(it);
				while (!((*it >= 'a'&&*it <= 'z') || (*it >= 'A'&&*it <= 'Z'))) {
					it=str.erase(it);
				}
				str.insert(it, ' ');
				++it;
				start = it;
			}
			++it;
		}
		reverse(start, str.end());
		cout << str << endl;
	}
	return 0;
}


