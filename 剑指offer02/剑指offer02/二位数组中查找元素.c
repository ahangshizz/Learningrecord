// #include <iostream>
// using namespace std;
#include <stdio.h>
#include <stdlib.h>
//关于每行每列递增的二维数组查找元素的方法
/*
bool FindNum(int* arr, int row, int col, int num) {
	if (arr != NULL && row > 0 && col > 0) {
		int i = 0;
		int j = col - 1;
		while (i < row&&j >= 0) {
			if (arr[i*col + j] == num) {
				return true;
			}
			else if (arr[i*col + j] > num) {
				--j;
			}
			else {
				++i;
			}
		}
		return false;
	}
}

int main() {

	int arr[][4] = { 1,2,8,9,
				  2,4,9,12,
				  4,7,10,13,
				  6,8,11,15
	};

		if (FindNum((int*)arr, 4, 4, 7)) {
			cout << "找到了\n" << endl;
	}
	cout<<"hello....."<<endl;
	system("pause");
	return 0;
}
*/


/*
void test(char* tmp) {
	char* test = tmp;
	++test;
	//test[5] = '4';
}
int main() {

	char* test1 = "12345679";
	char* test2 = "12345679";
	char* test3 = "12345679";
	test(test1);
	printf(test1);
	printf("%x\n",test1);
	printf("%x\n",test2);
	printf("%x\n",test3);
	system("pause");
	return 0;
}
*/

/*把空格替换成%20*/




void ReplaceBlank(char str[], int Capacity) {
	if (str == NULL || Capacity <= 0) {
		return;
	}
	int lenth = 0;
	int numofblank = 0;
	int i = 0;
// 	while (str[i] != '\0') {
// 		++lenth;
// 		if (str[i] == ' ') {
// 			++numofblank;
// 		}
// 		++i;
// 	}
	char* tmp = str;
	while (*tmp != '\0') {
		++lenth;
		if (*tmp == ' ') {
			++numofblank;
		}
		++tmp;
	}
	int newlenth = lenth + 2 * numofblank;
	if (newlenth > Capacity) {
		return;
	}
	int oldindex = lenth;
	int newindex = newlenth;
	while (oldindex >= 0 && newindex > oldindex) {
		if (str[oldindex] == ' ') {
			str[newindex] = '0';
			newindex--;
			str[newindex] = '2';
			newindex--;
			str[newindex] = '%';
			newindex--;
		}
		else {
			str[newindex] = str[oldindex];
			newindex--;
		}
		--oldindex;
	}
}
int main() {
	char str[256] = "we are happy.";
	ReplaceBlank(str, 256);
	printf("%s", str);
	system("pause");
	return 0;
}