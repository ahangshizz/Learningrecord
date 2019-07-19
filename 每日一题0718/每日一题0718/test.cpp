#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*完美数*/
/* 
int Get_All_Num(int num) {
	vector<int> v;
	//v.resize(256);
	for (int i = 1; i <= sqrt(num); ++i) {
		if (num%i == 0) {
			v.push_back(i);
		}
		if (num / i != i && num / i != num) {
			v.push_back(num / i);
		}
	}
	auto it = v.begin();
	int sum = 0;
	for (it; it != v.end(); ++it) {
		sum += *it;
	}
	if (sum == num) {
		return 1;
	}
	return 0;
}
int main() {
	int n;
	while (cin >> n) {
		int count = 0;
		for (int i = 0; i < n; ++i) {
			count += Get_All_Num(i);
		}
		cout << count << endl;
	}
	return 0;
}
*/


/*
int main() {
	string s1;
	string s2;
	string stmp;
	while (getline(cin, stmp)) {
		s2 = stmp;
		auto it = s2.begin();
		for (it; it != s2.end();) {
			if (*it != '-') {
				s1.push_back(*it);
				s2.erase(it);
			}
			else {
				s2.erase(it);
				break;
			}
		}
	}
	return 0;
}
*/


/*扑克牌问题*/



int Get_Type(string str) {
	int lenth = str.size();
	if (lenth == 1 || (lenth == 5 && (str[0] == 'j' || str[0] == 'J'))) {
		return 1;
	}
	if (lenth == 9) {
		return 3;
	}
	if (lenth == 3 && str[0] != 'j'&&str[0] != 'J') {
		return 2;
	}
	if (lenth == 5) {
		return 4;
	}
	if (lenth == 7) {
		return 5;
	}
	if (lenth == 11) {
		return 5;
	}
	return 0;
}
int main() {
	string s1;
	string s2;
	string stmp;
	while (getline(cin, stmp)) {
		s2 = stmp;
		auto it = s2.begin();
		for (it; it != s2.end();) {
			if (*it != '-') {
				s1.push_back(*it);
				s2.erase(it);
			}
			else {
				s2.erase(it);
				break;
			}
		}
		int type1 = Get_Type(s1);
		int type2 = Get_Type(s2);
		if (type1 == type2 && type1 != 5) {
			if (s1[0] > s2[0] && (s1[0] != 'j' && s1[0] != 'J')) {
				cout << s1 << endl;
			}
			else if (s1[0] == 'j'&&s2[0] == 'J') {
				cout << s2 << endl;
			}
			else if (s1[0] == 'J'&&s2[0] == 'j') {
				cout << s1 << endl;
			}
			else if (s1[0] > s2[0]) {
				cout << s1 << endl;
			}
			else if (s1[0] < s2[0]) {
				cout << s2 << endl;
			}
		}
		else if (type1 != type2 && type1 != 5 && type2 != 5) {
			cout << "ERROR" << endl;
		}
		else if (type1 == type2 && type1 == 5) {
			int num1 = (int)s1[0];
			int num2 = (int)s2[0];
			if (num1 > num2) {
				cout << s1 << endl;
			}
			else {
				cout << s2 << endl;
			}
		}
		else if (((type1 == 1) || (type1 == 2) || (type1 == 3) || (type1 == 4)) && type2 == 5) {
			cout << s2 << endl;
		}
		else if (((type2 == 1) || (type2 == 2) || (type2 == 3) || (type2 == 4)) && type1 == 5) {
			cout << s1 << endl;
		}
		s1.clear();
	}
	return 0;
}