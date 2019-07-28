#include <iostream>
using namespace std;

bool Increment(char* number);
void PrintNumber(char* number);
void PrinToMax(int n) {
	if (n <= 0)
		return;
	char* number = new char[n + 1];
	memset(number, '0', n);
	number[n] = '\0';
	while (!Increment(number)) {
		PrintNumber(number);
	}
	delete[]number;
}
bool Increment(char* number) {
	bool isOverflow = false;
	int nTakeOver = 0;
	int nlength = strlen(number);
	for (int i = nlength - 1; i >= 0; --i) {
		int nsum = number[i] - '0' + nTakeOver;
		if (i == nlength - 1) {
			nsum++;
		}
		if (nsum >= 10) {
			if (i == 0) {
				isOverflow = true;
			}
			else {
				nsum -= 10;
				nTakeOver = 1;
				number[i] = '0' + nsum;
			}
		}
		else {
			number[i] = '0' + nsum;
			break;
		}
	}
	return isOverflow;
}

void PrintNumber(char* number) {
	bool isbegin0 = true;
	int nlength = strlen(number);
	for (int i = 0; i < nlength; ++i) {
		if (isbegin0&&number[i] != '0') {
			isbegin0 = false;
		}
		if (!isbegin0) {
			printf("%c ", number[i]);
		}
	}
}

int main() {

	PrinToMax(3);

	
	cout<<"hello....."<<endl;
	system("pause");
	return 0;
}