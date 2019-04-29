#include "SeqQueue.h"


typedef struct Person {
	char name[64];
	int age;
}Person;

int main() {
	SeqQueue* seq = InIt_SeqQueue();
	Person p1 = { "aaa",10 };
	Person p2 = { "bbb",20 };
	Person p3 = { "ccc",30 };
	Person p4 = { "ddd",40 };
	Person p5 = { "eee",50 };
	//数据入队列
	Push_SeqQueue(seq, &p1);
	Push_SeqQueue(seq, &p2);
	Push_SeqQueue(seq, &p3);
	Push_SeqQueue(seq, &p4);
	Push_SeqQueue(seq, &p5);
	while (Size_SeqQueue(seq) > 0) {
	Person* person = (Person*)Front_SeqQueue(seq);
	printf("name:%s  age:%d\n", person->name, person->age);
	Pop_SeqQueue(seq);
	}
	system("pause");
	return 0;
}