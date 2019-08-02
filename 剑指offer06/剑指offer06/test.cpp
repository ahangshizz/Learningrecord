#include <iostream>
using namespace std;


void Permutation(char* str, char* begin) {
	if (*begin == '\0') {
		printf("%s\n", str);
	}
	else {
		for (char* ch = begin; *ch != '\0'; ++ch) {
			char tmp = *ch;
			*ch = *begin;
			*begin = tmp;
			Permutation(str, begin + 1);
			tmp = *ch;
			*ch = *begin;
			*begin = tmp;
		}
	}
}

void Permutation(char* str) {
	if (str == NULL)
		return;
	Permutation(str, str);
}

int main() {

	char str[4] = "abc";

	Permutation(str);
	cout<<"hello....."<<endl;
	system("pause");
	return 0;
}