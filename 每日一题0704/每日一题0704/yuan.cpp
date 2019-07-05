#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
int main()
{
	int M, N;
	vector<int> v;
	scanf("%d %d", &M, &N);
	while (M != 0) {
		int temp = M % N;
		v.push_back(temp);
		M /= N;
	}
	for (auto it = v.rbegin(); it != v.rend(); ++it) {
		cout << (*it);
	}
	system("paush");
	return 0;
}