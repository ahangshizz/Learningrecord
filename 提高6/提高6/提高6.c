#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
//typedef struct sust
//{
//	int id;
//	char name[50];
//	struct sust *next;
//}sust;
//int main()
//{
//	sust s1 = { 12, "bit", NULL };
//	sust s2 = { 18, "mani", NULL };
//	sust s3 = { 22, "limin", NULL };
//	sust *p = NULL;
//	p = &s1;
//	s1.next = &s2;
//	s2.next = &s3;
//	s3.next = NULL;
//	while (p!=NULL)
//	{
//		printf("%d %s", p->id, p->name);
//		p = p->next;
//	}
//	system("pause");
//	return 0;
//}
typedef struct sut
{
	int id;
	struct sut *next;
}sut;
NODE *tou()
{

}
int main()
{
	NODE *head = NULL;
	return 0;
}