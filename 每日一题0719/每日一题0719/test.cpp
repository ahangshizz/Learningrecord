#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
int main() {
	int num = 0;
	while (cin >> num) {
		vector<vector<int>> arr;
		//int arr[10][10] = { 0 };
		for (int i = 0; i < num + 1; ++i) {
			arr.push_back(vector<int>());
		}
		for (int i = 0; i < arr.size(); ++i) {
			for (int j = 0; j < num + 4; ++j) {
				arr[i].push_back(0);
			}
		}
		arr[1][num] = 1;
		for (int i = 2; i < num + 1; ++i) {
			for (int j = 1; j < num + 4-1; ++j) {
				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j] + arr[i - 1][j + 1];
			}
		}
		for (int k = 0; k < num + 4; ++k) {
			if ((arr[num][k] % 2 == 0) && (arr[num][k] != 0)) {
				cout << k << endl;
				break;
			}
		}
	}
	return 0;
}
*/

int main() {
	string s1;
	string s2;
	while (cin >> s1 >> s2) {
		string s3;
		int len1 = s1.size();
		int len2 = s2.size();
		reverse(s1.begin(), s1.end());
		reverse(s2.begin(), s2.end());
		if (len1 > len2) {
			for (int i = 0; i < len1 - len2; ++i) {
				s2.push_back('0');
			}
		}
		else if (len1 < len2) {
			for (int i = 0; i < len2 - len1; ++i) {
				s1.push_back('0');
			}
		}
		int count = 0;
		for (int i = 0; i < s1.size(); ++i) {
			int num1 = s1[i]-48;
			int num2 = s2[i]-48;
			int sum = num1 + num2 + count;
			int newstr = sum % 10;
			count = sum / 10;
			char c = newstr+48;
			s3.push_back(c);
		}
		s3.push_back((char)count+48);
		reverse(s3.begin(), s3.end());
		if (*(s3.begin()) == '0') {
			s3.erase(s3.begin());
		}
		cout << s3 << endl;
	}
	return 0;
}