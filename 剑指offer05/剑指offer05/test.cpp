#include <iostream>
#include <vector>
#include <stack>
using namespace std;



bool IsPopOrder(vector<int> pushV, vector<int> popV) {
	bool ret = false;
	if (pushV.size() <= 0 || popV.size() <= 0)
		return ret;
	auto pushit = pushV.begin();
	auto popit = popV.begin();
	std::stack<int> stack;
	while (popit!=popV.end()) {
		while (stack.empty() || stack.top() != *popit) {
			if (pushit == pushV.end())
				break;
			stack.push(*pushit);
			++pushit;
		}
		if (stack.top() != *popit)
			break;
		stack.pop();
		++popit;
	}
	if (stack.empty() && pushit == pushV.end())
		ret = true;
	return ret;
}
int main() {
	int array[] = { 1,2,3,4,5 };
	int array1[] = { 4,5,3,2,1 };
	vector<int> pushV(array, array + 5);
	vector<int> popV(array1, array1 + 5);
	bool ret = IsPopOrder(pushV, popV);
	cout << ret << endl;
	cout<<"hello....."<<endl;
	system("pause");
	return 0;
}