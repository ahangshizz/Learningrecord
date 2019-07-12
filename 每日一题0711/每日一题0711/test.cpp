#include <iostream>
#include <string>
using namespace std;

class Password {
public:
	Password(string str) {
		this->pwd = str;
	}
	int SafelevelGetPwdSecurityLevel() {
		int value = 0;
		size_t len = this->pwd.size();
		//字符串长度得分
		if (len <= 4) {
			value += 5;
		}
		else if (len >= 5 && len <= 7) {
			value += 10;
		}
		else if (len >= 8) {
			value += 25;
		}
		//字符串有没有字母得分
		int A = 0;
		int a = 0;
		for (int i = 0; i < len; ++i) {
			if (this->pwd[i] >= 'a'&&this->pwd[i] <= 'z') {
				a = 1;
				continue;
			}
			if (this->pwd[i] >= 'A'&&this->pwd[i] <= 'Z') {
				A = 1;
				continue;
			}
		}
		if (a == 1 && A == 1) {
			value += 20;
		}
		else if (a == 0 && A == 0) {
			value += 0;
		}
		else {
			value += 10;
		}
		//判断数字得分
		int num=0;
		for (int i = 0; i < len; ++i) {
			if (this->pwd[i] >= '0'&&this->pwd[i] <= '9') {
				num += 1;
			}
		}
		if (num == 0) {
			value += 0;
		}
		else if (num == 1) {
			value += 10;
		}
		else {
			value += 20;
		}
		//判断符号得分
		int asc = 0;
		auto it = this->pwd.begin();
		for (it; it != this->pwd.end();) {
			if (*it >= '0'&&*it <= '9') {
				this->pwd.erase(it);
			}
			else if (*it >= 'a'&&*it <= 'z') {
				this->pwd.erase(it);
			}
			else if (*it >= 'A'&&*it <= 'Z') {
				this->pwd.erase(it);
			}
			else {
				asc++;
				++it;
			}
		}
		if (asc == 0) {
			value += 0;
		}
		else if (asc == 1) {
			value += 10;
		}
		else {
			value += 25;
		}
		//奖励
		if (a == 1 && num > 0 && asc == 0) {
			value += 2;
		}
		else if (A == 1 && num > 0 && asc == 0) {
			value += 2;
		}
		else if (a == 1 && num > 0 && asc > 0) {
			value += 3;
		}
		else if (A == 1 && num > 0 && asc > 0) {
			value += 3;
		}
		else if (a == 1 && A == 1 && num > 0 && asc > 0) {
			value += 5;
		}
		return value;
	}
public:
	string pwd;
};
int main() {
	string s;
	cin >> s;
	Password P(s);
	int value = P.SafelevelGetPwdSecurityLevel();
	if (value >= 90) {
		cout << "VERY_SECURE" << endl;
	}
	else if (value >= 80) {
		cout << "SECURE" << endl;
	}
	else if (value >= 70) {
		cout << "VERY_STRONG" << endl;
	}
	else if (value >= 60) {
		cout << "STRONG" << endl;
	}
	else if (value >= 50) {
		cout << "AVERAGE" << endl;
	}
	else if (value >= 25) {
		cout << "WEAK" << endl;
	}
	else if (value >= 0) {
		cout << "VERY_WEAK" << endl;
	}
	system("pause");
	return 0;
}