#define _CRT_SECURE_NO_WARNINGS
#define Max_personinfo 300
#include <stdio.h>
#include <stdlib.h>
//联系人案例
typedef struct Personinfo {
	char Name[1024];
	char Phone[1024];
}Personinfo;
typedef struct Addressbook {
	Personinfo person[300];
	int size;
}Addressbook;
Addressbook g_addressbook;
void Nothing() {
	//充数的函数
}
void Addpersoninfo() {
	printf("新建联系人\n");
	if (g_addressbook.size > Max_personinfo) {
		printf("新增联系人失败,通讯录已满\n");
		return;
	}
	printf("请输入姓名\n");
	Personinfo* person_info = &g_addressbook.person[g_addressbook.size];
	scanf("%s", person_info->Name);
	printf("请输入电话\n");
	scanf("%s", person_info->Phone);
	++g_addressbook.size;
	printf("新建联系人成功\n");
}
void Delpersoninfo() {
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
void Findpersoninfo() {

}
void Modpersoninfo() {

}
void Printallpersoninfo() {
	for (int i = 0; i < g_addressbook.size; ++i) {
		printf("[%d]", i);
		printf("%s", g_addressbook.person[i].Name);
		printf("  ");
		printf("%s\n", g_addressbook.person[i].Phone);
	}
}
void Clearpersoninfo() {

}
void Sortpersoninfo() {

}
void Overapp() {
	printf("Goodbay!");
	exit(0);
}
void init() {
	g_addressbook.size = 0;
	for (int i = 0; i < Max_personinfo; ++i) {
		g_addressbook.person[i].Name[0] = '\0';
		g_addressbook.person[i].Phone[0] = '\0';
	}
}
void menu() {
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
typedef void(*Func)();
int main() {
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