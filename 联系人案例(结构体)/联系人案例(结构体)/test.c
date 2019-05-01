#define _CRT_SECURE_NO_WARNINGS
#define Max_personinfo 1000//设置最大联系人数为1000
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//联系人案例
typedef struct Personinfo {//定义一个结构体,结构体成员为姓名,电话
	char Name[1024];
	char Phone[1024];
}Personinfo;
typedef struct Addressbook {//这个结构体存放这上一个结构体的数组,和一个计数变量
	Personinfo person[Max_personinfo];
	int size;
}Addressbook;
Addressbook g_addressbook;//全局变量,把结构体实体化
void Nothing() {
	//充数的函数
}
void Addpersoninfo() {//添加联系人函数
	printf("新建联系人\n");
	if (g_addressbook.size > Max_personinfo) {
		printf("新增联系人失败,通讯录已满\n");
		return;
	}
	printf("请输入姓名\n");
	//用一个指针保存内容,方便后面写程序
	Personinfo* person_info = &g_addressbook.person[g_addressbook.size];
	scanf("%s", person_info->Name);
	printf("请输入电话\n");
	scanf("%s", person_info->Phone);
	++g_addressbook.size;
	printf("新建联系人成功\n");
}
void Delpersoninfo() {//删除联系人函数
	printf("删除联系人\n");
	if (g_addressbook.size <= 0) {
		printf("删除失败,通讯录为空\n");
		return;
	}
	printf("请输入要删除的序号\n");
	int id;
	scanf("%d", &id);
	if (id<0 || id>g_addressbook.size) {
		printf("删除失败,序号有误\n");
		return;
	}
	g_addressbook.person[id]=g_addressbook.person[g_addressbook.size-1];
	--g_addressbook.size;
	printf("删除联系人成功\n");
}
void Findpersoninfo() {//查找联系人函数
	printf("查找联系人\n");
	char name[1024] = { 0 };
	printf("请输入要查找联系人的姓名\n");
	scanf("%s", name);
	for(int i=0;i<g_addressbook.size;++i) {
		Personinfo* info = &g_addressbook.person[i];
		if (strcmp(name, info->Name)==0) {
			printf("[%d] %s %s\n", i, info->Name, info->Phone);
		}
	}
	printf("查找联系人成功\n");

}
void Modpersoninfo() {//修改联系人函数
	printf("修改联系人\n");
	if (g_addressbook.size <= 0) {
		printf("通讯录为空,更新失败\n");
	}
	printf("请输入要更新联系人的序号:\n");
	int id;
	scanf("%d", &id);
	Personinfo* info = &g_addressbook.person[id];
	char name[1024] = { 0 };
	printf("请输入要修改的姓名\n");
	scanf("%s", name);
	if (name != NULL) {
		strcpy(info->Name, name);
	}
	char phone[1024] = { 0 };
	printf("请输入要修改的电话\n");
	scanf("%s", phone);
	if (phone != NULL) {
		strcpy(info->Phone, phone);
	}
	printf("修改联系人成功\n");
}
void Printallpersoninfo() {//打印联系人函数
	for (int i = 0; i < g_addressbook.size; ++i) {
		printf("[%d]", i);
		printf("%s", g_addressbook.person[i].Name);
		printf("  ");
		printf("%s\n", g_addressbook.person[i].Phone);
	}
}
void Clearpersoninfo() {//清空联系人函数
	printf("清空所有联系人\n");
	printf("您确认要清空所有联系人吗? Y\\N \n");
	char choice[1024] = {0};
	scanf("%s", choice);
	if (strcmp(choice,'Y')==0) {
		g_addressbook.size = 0;
	}
	else {
		printf("清空所有联系人取消\n");
		return;
	}
	printf("清空所有联系人成功\n");
}
void Sortpersoninfo() {//按照首字母排序联系人
	int i, j;
	for (i = 0; i < g_addressbook.size - 1; ++i) {
		for (j = 0; j < g_addressbook.size - i - 1; ++j) {
			if (strcmp(g_addressbook.person[j].Name, g_addressbook.person[j + 1].Name) > 0) {
				char tmp[1024] = { 0 };
				//字符串之间的赋值需要用到strcpy
				strcpy(tmp,g_addressbook.person[j].Name);
				strcpy(g_addressbook.person[j].Name, g_addressbook.person[j + 1].Name);
				strcpy(g_addressbook.person[j + 1].Name, tmp);
			}
		}
	}
}
void Overapp() {//结束程序的函数
	printf("Goodbay!");
	exit(0);
}
void init() {//初始化通讯录函数
	g_addressbook.size = 0;
	for (int i = 0; i < Max_personinfo; ++i) {
		g_addressbook.person[i].Name[0] = '\0';
		g_addressbook.person[i].Phone[0] = '\0';
	}
}
void menu() {//菜单函数
	printf("===================\n");
	printf("1.添加联系人\n");
	printf("2.删除联系人\n");
	printf("3.查找联系人\n");
	printf("4.修改联系人\n");
	printf("5.打印联系人\n");
	printf("6.清空联系人\n");
	printf("7.排序联系人\n");
	printf("8.退出\n");
	printf("===================\n");
}
typedef void(*Func)();//定义一个函数指针
int main() {
	//把函数用转移表封装起来
	Func arr[] = {
		Nothing,
		Addpersoninfo,
		Delpersoninfo,
		Findpersoninfo,
		Modpersoninfo,
		Printallpersoninfo,
		Clearpersoninfo,
		Sortpersoninfo,
		Overapp
	};
	init();
	while (1) {
		menu();
		int choice;
		printf("请输入你的选项:");
		scanf("%d", &choice);
		if (choice < 0 || choice >= sizeof(arr) / sizeof(arr[0])) {
			printf("您输入的选项有误,请重新输入\n");
			continue;
		}
		arr[choice]();
	}
	return 0;
}