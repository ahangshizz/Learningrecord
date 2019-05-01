//#include <stdio.h>
//int main()
//{
//	char  i = 0;
//	while ((i = getchar()) != EOF)
//	{
//		if (i >= 'A'&& i <= 'Z')
//		{
//			putchar(i + 32);
//		} 
//		else if (i>='a' && i <='z')
//		{
//			putchar(i - 32);
//		}
//		else if (i >= '0' && i <= '9')
//		{
//			exit(0);
//		}
//	}
//	return 0;
//}
//#include <stdio.h>
//int main()
//{
//	int a = -1;
//	a = a >> 1;
//	return 0;
//}

//    10000001          11111110         11111111      ²¹ÂëµÈÓÚ·´Âë+1£»
//#include <stdio.h>
//int main()
//{
//	int a = 10;
//	printf("%p\n", &a);
//	printf("%#p", &a);
//	return 0;
//}
//#include <stdio.h>
//int main()
//{
//	printf("%d\n", sizeof(char));
//	printf("%d\n", sizeof(short));
//	printf("%d\n", sizeof(int));
//	printf("%d\n", sizeof(float));
//	printf("%d\n", sizeof(long));
//	printf("%d\n", sizeof(double));
//	return 0;
//}
//#include <stdio.h>
//int main()
//{
//	int a = -1;
//	printf("%d", ~a);
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//struct PEO {
//	char name[10];
//	char tele[10];
//	char addr[10];
//	int age;
//};
//int main()
//{
//	struct PEO p;
//	struct PEO *skt = &p;
//	strcpy(p.name, "a,b,c\n");
//	printf("%s", skt->name);
//	skt ->age = 20;
//	printf("%d\n", skt->age);
//
//	return 0;
//}