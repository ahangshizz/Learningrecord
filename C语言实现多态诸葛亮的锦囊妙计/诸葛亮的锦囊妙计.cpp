#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//抽象层
//打开锦囊的方法
typedef void (TIPS)(void);
struct tip {
	char from[64];
	char to[64];
	TIPS*tp;
};
//创建锦囊的方法
struct tip* creat_tip( char const*from, char const*to, TIPS*tp) {
	struct tip* temp = (struct tip*)malloc(sizeof(struct tip));
	if (temp == NULL) {
		return NULL;
	}
	strcpy(temp->from, from);
	strcpy(temp->to, to);
	temp->tp = tp;
	return temp;
}
//打开锦囊的构架函数
void open_tips(struct tip*tip_p) {
	cout << "打开了锦囊" << endl;
	cout << "此锦囊是由" << tip_p->from << "写给" << tip_p->to << "的." << endl;
	cout << "内容是" << endl;
	tip_p->tp();
}
//销毁锦囊
void destory(struct tip*tp) {
	if (tp != NULL) {
		free(tp);
		tp = NULL;
	}
}
//实现层
void tip1_func(void) {
	cout << "到东吴找乔国公" << endl;
}
void tip2_func(void) {
	cout << "刘备乐不思蜀,就说曹贼大军压境" << endl;
}
void tip3_func(void) {
	cout << "被追杀就找孙夫人帮忙" << endl;
}


int main() {
	//创建三个锦囊
	struct tip*tip1 = creat_tip("诸葛亮", "赵云", tip1_func);
	struct tip*tip2 = creat_tip("诸葛亮", "赵云", tip2_func);
	struct tip*tip3 = creat_tip("诸葛亮", "赵云", tip3_func);
	//拆锦囊
	cout << "赵云来到东吴" << endl;
	open_tips(tip1);
	cout << "到了年底" << endl;
	open_tips(tip2);
	cout << "被人追杀时" << endl;
	open_tips(tip3);
	//释放
	destory(tip1);
	destory(tip2);
	destory(tip3);
	return 0;
}