#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	stack<int> s;
	string str;
	while (getline(cin,str) ){
		int count = 0;
		auto it = str.begin();
		while (it != str.end()) {
			if (*it == '"') {
				str.erase(it);
			}
			else if (*it == ' ') {
				++count;
				++it;
				continue;
			}
			else {
				++it;
			}
		}
		cout << count << endl;
		string tmp;
		for (it = str.begin(); it != str.end(); ++it) {
			if (*it != ' ') {
				tmp += *it;
			}
			else if (*it == ' ' || (++it) == str.end()) {
				cout << tmp << endl;
				tmp.clear();
			}
		}
	}
	system("pause");
	return 0;
}