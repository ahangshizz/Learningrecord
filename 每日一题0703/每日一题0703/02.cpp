#include <iostream>
#include <vector>
using namespace std;
int main() {
	int num;
	vector<int> numbers;
	while (cin >> num&&num!=EOF) {
		numbers.push_back(num);
	}
	for (auto it = numbers.begin(); it != numbers.end(); ++it) {
		cout << *(it) << endl;
	}
}