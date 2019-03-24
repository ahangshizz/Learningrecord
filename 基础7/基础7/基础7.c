//#include <stdio.h>
//#include <string.h>
//void my_fputs()
//{
//	FILE *fp = fopen("01.txt", "w");
//	fputs("10*10=\n", fp);
//	fputs("10-10=\n", fp);
//	fputs("10+10=\n", fp);
//	fputs("10/10=\n", fp);
//	fputs("10-3=\n", fp);
//	fputs("10-2=", fp);
//	fclose(fp);
//	fp = NULL;
//}
//void my_fgets()
//{
//	char buf[1024];
//	char tmp[1024 * 4]= {0};
//	FILE *fp = fopen("01.txt", "r");
//	//memset(buf, 0, sizeof(buf));
//	while (1)
//	{
//		int a, b;
//		char ch;
//		fgets(buf, sizeof(buf), fp);
//		sscanf(buf, "%d%c%d=\n", &a, &ch, &b);
//		sprintf(buf,"%d%c%d=%d\n", a, ch, b,calc(a,b,ch));
//		strcat(tmp,buf);
//		if (feof(fp))
//		{
//			break;
//		}
//	}
//	fclose(fp);
//	FILE *ac = fopen("01.txt", "w");
//	fputs(tmp, ac);
//	fclose(ac);
//
//}
//int calc(int a, int b, char ch)
//{
//	switch (ch)
//	{
//	case '+':
//			return a + b;
//	case '-':
//		return a - b;
//	case '*':
//		return a*b;
//	case '/':
//		return a / b;
//
//	}
//}
//int main()
//{
//	my_fputs();
//	my_fgets();
//
//	return 0;
//}

//
//#include <stdio.h>
//#include <time.h>
//int main()
//{
//	int i = 0;
//	int n = 100;
//	int num;
//	FILE *fp = fopen("02.txt", "r");
//	//srand((unsigned)time(NULL));
//	//for (i = 0; i < n; i++)
//	//{
//	//	num = rand() % 101;
//	//	fprintf(fp,"%d\n", num);
//	//}
//	while (1)
//	{
//		fscanf(fp, "%d\n", &num);
//		printf("%d\n", num);
//		if (feof(fp))
//		{
//			break;
//		}
//	}
//	fclose(fp);
//	return 0;
//}


//
//#include <stdio.h>
//#include <string.h>
//typedef struct student
//{
//	int age ;
//	char name;
//	int tel;
//
//}student;
//int main()
//{
//	FILE *fp = fopen("03.txt", "w");
//	student s1[] = { 18, "welcome to bit", 177, 
//	                 19,"aaaaaaaaaaaaaaa",593,
//	                 17,"heheheheheheheh",888};
//	int ret = fwrite(s1, 1, sizeof(s1), fp);
//	//printf("ret=%d\n", ret);
//	//printf("%d\n", sizeof(s1));
//	fclose(fp);
//	return 0;
//	int i = 0;
//	int n = 3;
//	student  s2[10];
//	FILE *kz = fopen("03.txt", "r");
//	int red = fread(s2, 1, sizeof(student), fp);
//		//printf("%d", red);
//		for (i = 0; i < n; i++)
//		{
//			printf("%d,%s,%d\n", s2[i].age,s2[i].name,s2[i].tel);
//		}
//		fclose(kz);
//}


//#include <stdio.h>
//#include <string.h>
//int main(int argc, char* argv[])
//{
//	argc = 3;
//	argv[1] = "abc.jpg";
//	argv[2] = "liuting.jpg";
//	if (argc != 3)
//	{
//		perror("123");
//		return 0;
//	}
//	int len;
//	char buf[4 * 1024];
//	//打开源文件
//	FILE *rfp = fopen(argv[1], "rb");
//		//打开目标文件
//	FILE *wfp = fopen(argv[2], "wb");
//		//拷贝文件
//	while (1)
//	{
//		len = fread(buf, 1, sizeof(buf), rfp);
//		printf("len=%d", len);
//		if (len == 0)
//		{
//			break;
//		}
//		fwrite(buf, 1, len, wfp);
//	}
//		//关闭文件
//	fclose(rfp);
//	fclose(wfp);
//	return 0;
//}                                    //成功windows下要加b无法拷贝                      success



