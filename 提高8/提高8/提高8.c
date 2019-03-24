//#include <stdio.h>
//int add(int a) {
//	if (a == 1) {
//		return a;
//	}
//	return a + add(a-1);
//}
//int main() {
//	printf("%d\n", add(100));
//	system("pause");
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//int main() {
//	char buf[] = "123456";
//	int begin = 0;
//	char tmp;
//	int i = 0;
//	int end = strlen(buf)-1;
//	while ((buf[begin] != '\0') && (end>=begin)) {
//		tmp = buf[begin];
//		buf[begin] = buf[end];
//		buf[end] = tmp;
//		begin++;
//		end--;
//	}
//	for (i = 0; i < 6; i++) {
//		printf("%c", buf[i]);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}



//int mystrlen(char* buf) {
//	if (*buf == '\0') {
//		return -1;
//	}
//	return mystrlen(++buf) + 1;
//}
//int main() {
//	char buf[] = "123456";
//	int ret=mystrlen(buf);
//	printf("%d\n", ret);
//	system("pause");
//	return 0;
//}

//#define test(a,b)  (a>b?a:b)
//#define test2(a,b,c)  ((test(a,b))>c?(test(a,b)):c)
//int main() {
//	printf("%d\n", test(1, 2));
//	printf("%d\n", test2(1, 2, 3));
//	system("pause");
//	return 0;
//}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main() {
	int i = 0;
	int count = 0;
	for (i = 1; i <= 100; i++) {
		if (i % 10 == 9) {
			count++;
		}
		if (i / 10 == 9) {
			++count;
		}
	}
	printf("1-100中出现9的次数有%d次\n", count);
	system("pause");
	return 0;
}