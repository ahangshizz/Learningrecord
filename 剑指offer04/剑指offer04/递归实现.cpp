#include <iostream>
using namespace std;

void PrintNumber(char* number) {
	bool isBegin0 = true;
	int nlength = strlen(number);
	for (int i = 0; i < nlength; ++i) {
		if (isBegin0&&number[i] != '0') isBegin0 = false;
		if (!isBegin0) {
			printf("%c", number[i]);
		}
	}
}

void Print1ToMax(char* number, int length, int index) {
	if (index == length - 1) {
		PrintNumber(number);
		return;
	}
	for (int i = 0; i < 10; ++i) {
		number[index + 1] = i + '0';
		Print1ToMax(number, length, index + 1);
	}
}
void PrintMax(int n) {
	if (n < 0)return;
	char* number = new char[n + 1];
	number[n] = '\0';
	for (int i = 0; i < 10; ++i) {
		number[0] = i + '0';
		Print1ToMax(number, n, 0);
	}
}
int main() {

	PrintMax(3);

	
	cout<<"hello....."<<endl;
	system("pause");
	return 0;
}