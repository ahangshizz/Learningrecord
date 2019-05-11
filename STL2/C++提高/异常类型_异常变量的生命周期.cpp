#include <iostream>
using namespace std;

#if 0
void My_Strcpy(char* des, char* src) {
	if (des == NULL) {
		throw "拷贝目的出错";
	}
	if (src == NULL) {
		throw "拷贝源出错";
	}
/*
	实验失败,用throw抛出的常量字符串根本无法抛出
	失败原因未知
*/
	if (*src == 'a') {
		throw "拷贝过程出错";
	}
	while (*src !='\0') {
		*des = *src;
		des++;
		src++;
	}
	*des = '\0';
}

int main() {

	char buf1[] = "anndwoa";
	char buf2[1024] = { 0 };
	try
	{
		My_Strcpy(buf2, buf1);
	}
	catch (int e)
	{
		cout << e << "int类型错误" << endl;
	}
	catch (char *e)
	{
		cout << e << "char*类型错误" << endl;
	}
	printf("%s \n", buf2);
	cout<<"hello....."<<endl;
	system("pause");
	return 0;
}
#endif


//异常抛出类
class BadSrcType{};
class BaddesType {};
class BadProcessType {
public:
	BadProcessType() {
		cout << "调用了BadProcessType的构造函数" << endl;
	}
	BadProcessType(const BadProcessType& e) {
		cout << "调用了BadProcessType的拷贝构造函数" << endl;
	}
	~BadProcessType() {
		cout << "调用了BadProcessType的析构函数" << endl;
	}
};
void My_Strcpy(char* des, char* src) {
	if (des == NULL) {
		throw BaddesType();
	}
	if (src == NULL) {
		throw BadSrcType();
	}
	if (*src == 'a') {
		throw BadProcessType();
	}
	while (*src != '\0') {
		*des = *src;
		des++;
		src++;
	}
	*des = '\0';
}

int main() {
	char buf[] = "awdawd";
	char buf2[1024] = { 0 };
	try
	{
		My_Strcpy(buf2, buf);
	}
	catch (BaddesType e)
	{
		cout << "目标源出现异常" << endl;
	}
	catch (BadSrcType e)
	{
		cout << "拷贝源出现异常" << endl;
	}
	//结论1:如果接收异常的时候使用一个异常变量,则拷贝构造异常变量
	/*
	catch (BadProcessType e)//这个捕捉的类是通过类的拷贝构造函数创建的
	{
		cout << "拷贝过程出现异常" << endl;
	}
	*/
	//结论2:使用引用的话,会使用抛出的那个对象
	catch (BadProcessType &e)
	{
		cout << "拷贝过程出现异常" << endl;
	}
	printf("%s \n", buf2);
	system("pause");
	return 0;
}