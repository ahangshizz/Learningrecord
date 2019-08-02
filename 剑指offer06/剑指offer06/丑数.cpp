#include <iostream>
using namespace std;
int Min(int num1, int num2, int num3);
int GetUglyNumber_Solution(int index) {
	if (index <= 0)
		return 0;
	int *pchou = new int[index];
	pchou[0] = 1;
	int nextchou = 1;
	int* pchou2 = pchou;
	int* pchou3 = pchou;
	int* pchou5 = pchou;
	while (nextchou < index) {
		int min = Min(*pchou2 * 2, *pchou3 * 3, *pchou5 * 5);
		pchou[nextchou] = min;
		while (*pchou2 * 2 <= pchou[nextchou])
			++pchou2;
		while (*pchou3 * 3 <= pchou[nextchou])
			++pchou3;
		while (*pchou5 * 5 <= pchou[nextchou])
			++pchou5;
		++nextchou;
	}
	int chou = pchou[nextchou - 1];
	delete[] pchou;
	return chou;
}
int Min(int num1, int num2, int num3) {
	int min = (num1 < num2) ? num1 : num2;
	min = (min < num3) ? min : num3;
	return min;
}

int main() {

	int ret=GetUglyNumber_Solution(5);

	cout << ret << endl;
	cout<<"hello....."<<endl;
	system("pause");
	return 0;
}