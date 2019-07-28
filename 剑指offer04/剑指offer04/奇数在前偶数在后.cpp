#include <iostream>
#include <vector>
using namespace std;

void reOrderArray(vector<int> &array) {
	if (array.size() < 0) {
		return;
	}
	auto pBegin = array.begin();
	auto pEnd = pBegin + array.size() - 1;
	while (pBegin < pEnd) {
		while (pBegin < pEnd && (*pBegin&1) != 0) {
			++pBegin;
		}
		while (pBegin < pEnd && (*pEnd&1) == 0) {
			--pEnd;
		}
		if (pBegin < pEnd) {
			int tmp = *pBegin;
			*pBegin = *pEnd;
			*pEnd = tmp;
		}
		++pBegin;
		--pEnd;
	}
}

int main() {

	int buf[] = { 2,5,4,8,3,4,6,7,9,10 };
	vector<int> array;
	array.insert(array.begin(), buf, buf + 9);
	reOrderArray(array);
	for (auto it = array.begin(); it != array.end(); ++it) {
		cout << *it << endl;
	}
	cout<<"hello....."<<endl;
	system("pause");
	return 0;
}