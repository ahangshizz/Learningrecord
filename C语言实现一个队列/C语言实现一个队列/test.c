#include "Queue.h"


int main() {
	Queue Q;
	QueueInit(&Q);
	QueuePush(&Q, 1);
	QueuePush(&Q, 2);
	QueuePush(&Q, 3);
	QueuePush(&Q, 4);
	QueuePush(&Q, 5);
	QueuePop(&Q);
	int front = QueueFront(&Q);
	int back = QueueBack(&Q);
	int size = QueueSize(&Q);
	printf("front==%d\n", front);
	printf("back==%d\n", back);
	printf("size==%d\n", size);
	QueueDestroy(&Q);
	system("pause");
	return 0;
}
