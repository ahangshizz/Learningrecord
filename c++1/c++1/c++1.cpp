//#include <iostream>
////命名空间
//using namespace std;
////namespace stdccA {
////
////	namespace stdccB {
////		struct teacher
////		{
////			int id;
////			char name[64];
////		};
////	}
////}
////int g_cc;//放在bss段，里面数据全部为0
////int g_cc = 20;//.c文件可以重定义    .cpp文件不可以重定义
////void test() {
////	bool flag = true;
////	flag = false;
////	flag = true;
////	cout << "flag=" << flag << endl;
////	cout << sizeof(flag) << endl;
////}
////void test2() {
////	int a = 10;
////	int b = 20;
////	(a < b ? a : b )= 50;
////	cout << "a=" << a << endl;
////}
////void test3() {
////	const int a = 10;
////	int* p = (int*)&a;
////	*p = 20;
////	cout << "a=" << a << endl;
////}
//int main(char argc, char**argv[]) {
//	/*int a = 0;*/
//	//cout << "hello world" << endl;
//	//cin >> a;
//	////cout << "a=" << a << endl;
//	//using stdccA::stdccB::teacher;
//	//teacher t1 = { 0 };
//	//stdccA::stdccB::teacher t2;
//	//test();
//	//test2();
//	/*test3();*/
//
//	int a = 10;
//	int &r = a;//引用已经定义必须初始化
//	r = 50;
//	int &ret = r;
//	ret = 60;
//	cout << "a=" << a << endl;
//	cout << "a=" << a << endl;
//	system("pause");
//	return 0;
//}
#include <iostream>
#include <string.h>
using namespace std;
//struct student {
//	int id;
//	char name[64];
//};
//void prints(struct student &t2) {
//	cout << t2.id <<endl<< t2.name << endl;
//}
//void prints2(struct student *t2) {
//	cout << t2->id << endl << t2->name << endl;
//}
//void prints3(struct student t1) {
//	cout << t1.id << endl << t1.name << endl;
//}
//struct typeA {
//	int &a;
//};
//struct typeB {
//	int* a;
//};
//int& test() {
//	int a = 0;
//	a = 10;
//	return a;
//}
//struct student {
//	int id;
//	char name[64];
//};
//int getmem(struct student *&tp) {
//	if (tp == NULL) {
//
//		return 0;
//	}
//	tp->id = 22;
//	strcpy(tp->name, "li5");
//	return 0;
//}
//void myfree(struct student *&tp) {
//	if (tp != NULL) {
//		free(tp);
//		tp == NULL;
////	}
//}
int main(void) {
	//student t1 = {20,"weihang"};
	//prints3(t1);
	//cout << "typeA" << sizeof(struct typeA) << endl;
	//cout << "typeB" << sizeof(struct typeB) << endl;
	//int& main_a = test();
	//cout << "main_a" << main_a << endl;
	//cout << "main_a" << main_a << endl;
	//student *tp=NULL;
	//tp = (struct student *)malloc(sizeof(student));
	//getmem(tp);
	//cout << tp->id << tp->name << endl;
	//myfree(tp);
//	const int a = 10;
//	const int &re = a;//引用const修饰的变量，引用前面必须加const
//	int b = 20;
//	const int& er = b;  //安全系数更高的const可以接受安全系数不高的变量
//	cout << "er=" << er << endl;
//	cout << "b" << b << endl;
//	b = 30;//b的值不能通过引用修改，但是可以直接通过b本身进行修改
//	cout << "er=" << er << endl;
//	cout << "b" << b << endl;
//	system("pause");
//	return 0;
	cout << "我" << endl;
	return 0;
}